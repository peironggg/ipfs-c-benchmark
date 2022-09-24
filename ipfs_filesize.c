#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

struct MemoryStruct
{
  char *memory;
  size_t size;
};

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;

  return realsize;
}

int main(void)
{
  // libcurl stuff
  CURL *curl;
  CURLcode response;
  char *iobuf = malloc(4096);
  struct MemoryStruct chunk = {iobuf, 0};
  int filesize = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl)
  {
    char *url;
    size_t needed = snprintf(NULL, 0, "http://localhost:5001/api/v0/files/stat?arg=%s&size=true", "/first/second/setup.sh");
    url = malloc(needed + 1);
    sprintf(url, "http://localhost:5001/api/v0/files/stat?arg=%s&size=true", "/first/second/setup.sh");

    // send all data to this function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    // we pass our 'chunk' struct to the callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    // specify the POST data which is empty for this endpoint
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

    response = curl_easy_perform(curl);

    // check if response completes + is written to memory
    if (response != CURLE_OK)
    {
      fprintf(stderr, "curl_easy_perform() reading failed for %s: %s\n", "/first/second/setup.sh", curl_easy_strerror(response));
      return -1;
    }

    // cleanup
    curl_easy_cleanup(curl);
    free(url);
  }

  cJSON *stats_json = cJSON_Parse(chunk.memory);
  cJSON *size_json = cJSON_GetObjectItemCaseSensitive(stats_json, "Size");
  printf("contents: %s\n", chunk.memory);

  if (cJSON_IsNumber(size_json))
  {
    filesize = size_json->valueint;
  }
  printf("filesize: %d\n", filesize);

  free(iobuf);
  cJSON_Delete(stats_json);
  curl_global_cleanup();

  return 0;
}