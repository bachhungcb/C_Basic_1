#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scmp(const void *a,const void *b){
	const char** str1 = (const char**)a;
    const char** str2 = (const char**)b;
    return strcmp(*str1, *str2);
}


int main() {
    char back[10];
    char input[100000];
    scanf("%s", back);
    getchar();
    char **words;
    int cnt = 0;
    int m=1000;
	words = (char**)malloc(m*sizeof(char *));
    while (fgets(input, sizeof(input), stdin) != NULL) {
    	
        char *token = strtok(input, " \n");
        while (token != NULL && cnt < 100001) {
            if (strstr(token, back) && strlen(token) > 0) {
                words[cnt] =(char *)malloc(strlen(token) + 1);
                strcpy(words[cnt], token);
                cnt++;
                if (cnt >= m) {
                	m*=2;
					words = (char **)realloc(words,m*sizeof(char *));}
            }
            token = strtok(NULL, " \n");
        }
    }
    qsort(words, cnt, sizeof(char *), scmp);
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}