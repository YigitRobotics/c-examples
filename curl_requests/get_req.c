#include <stdio.h>
#include <curl/curl.h>
#include "../defines/colors.h"
#include <stdlib.h>

size_t write_stdout(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total = size * nmemb;
    size_t *totalpointer = malloc(sizeof(size_t)); // Heap used for education and dynamic mem management practices. It's unnecessary but I want to use it for practice. It will cause memory leaks. Don't use heap in real systems!
    if (totalpointer == NULL) {
        printf(ANSI_COLOR_RED "Null Pointer!");
        exit(EXIT_FAILURE);
    }
    *totalpointer = total;
    fwrite(ptr, 1, *totalpointer, stdout);
    free(totalpointer);
    totalpointer = NULL;
    return total;
}

int main() {
    CURL *curl_proj;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_proj = curl_easy_init();

    if (!curl_proj) {
        printf(ANSI_COLOR_RED "Error while setup curl!");
        exit(EXIT_FAILURE);
    }

    curl_easy_setopt(curl_proj, CURLOPT_URL, "https://linux.org");
    curl_easy_setopt(curl_proj, CURLOPT_WRITEFUNCTION, write_stdout);
    
    response = curl_easy_perform(curl_proj);
    
    if (response != CURLE_OK) {
        printf(ANSI_COLOR_RED "Response not ok.");
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl_proj);
    curl_global_cleanup();

    return 0;
}