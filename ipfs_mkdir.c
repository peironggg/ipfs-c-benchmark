#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(void)
{
  // libcurl stuff
  CURL *curl;
  CURLcode response;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl)
  {
    char *url = (char *)malloc(100 * sizeof(char));
    sprintf(url, "http://localhost:5001/api/v0/files/mkdir?arg=%s&parents=true", "/first/second");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    // specify the POST data which is empty for this endpoint
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

    response = curl_easy_perform(curl);

    // check if response completes + is written to memory
    if (response != CURLE_OK)
    {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
    }

    // cleanup
    curl_easy_cleanup(curl);
    free(url);
  }

  curl_global_cleanup();
  return 0;
}