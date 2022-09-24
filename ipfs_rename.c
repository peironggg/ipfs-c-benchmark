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
    sprintf(url, "http://localhost:5001/api/v0/files/mv?arg=%s&arg=%s", "/setup.sh", "/first/second");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    // specify the POST data which is empty for this endpoint
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");

    response = curl_easy_perform(curl);

    // cleanup
    curl_easy_cleanup(curl);
    free(url);
  }

  curl_global_cleanup();
  return 0;
}