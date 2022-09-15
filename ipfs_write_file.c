#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(void)
{
  // libcurl stuff
  CURL *curl;
  CURLcode response;

  // form and file field for libcurl request
  curl_mime *form = NULL;
  curl_mimepart *field = NULL;

  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl)
  {
    // Create the form
    form = curl_mime_init(curl);

    // Fill in the file upload field
    field = curl_mime_addpart(form);
    curl_mime_name(field, "file");
    curl_mime_filedata(field, "setup.sh");

    char *url = (char *)malloc(100 * sizeof(char));
    sprintf(url, "http://localhost:5001/api/v0/files/write?arg=%s&create=true", "/setup.sh");

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:5001/api/v0");
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    response = curl_easy_perform(curl);

    // check if response completes + is written to memory
    if (response != CURLE_OK)
    {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(response));
    }

    // cleanup
    curl_easy_cleanup(curl);
    curl_mime_free(form);
    free(url);
  }

  curl_global_cleanup();
  return 0;
}