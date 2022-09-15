#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

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
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if (!ptr)
  {
    // out of memory!
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }

  mem->memory = ptr;
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
  struct MemoryStruct chunk;
  chunk.size = 0;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl)
  {
    char *url = (char *)malloc(100 * sizeof(char));
    sprintf(url, "http://localhost:5001/api/v0/files/read?arg=%s", "/setup.sh");

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
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
      return 1;
    }
    else
    {
      printf("%s\n", chunk.memory);
    }

    // cleanup
    curl_easy_cleanup(curl);
    free(chunk.memory);
    free(url);
  }

  curl_global_cleanup();
  return 0;
}