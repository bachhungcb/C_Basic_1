#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Relationship {
    char child[20];
    char parent[20];
};
int countDescendants(struct Relationship relationships[], int n, char name[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(relationships[i].parent, name) == 0) {
            count++;
            count += countDescendants(relationships, n, relationships[i].child);
        }
    }
    return count;
}

int countGenerations(struct Relationship relationships[], int n, char name[]) {
    int maxGeneration = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(relationships[i].parent, name) == 0) {
            int generation = 1 + countGenerations(relationships, n, relationships[i].child);
            if (generation > maxGeneration) {
                maxGeneration = generation;
            }
        }
    }
    return maxGeneration;
}

int main() {

    struct Relationship relationships[100];
    int n = 0;
    char buffer[45];
    char *token;
    while (fgets(buffer,45,stdin)) {
    	buffer[strcspn(buffer, "\n")] = 0;
    	if (strcmp(buffer,"***")==0) break;
        token=strtok(buffer," ");
        strcpy(relationships[n].child,token);
        token=strtok(NULL," ");
        strcpy(relationships[n].parent,token);
        n++;
	}
	char info[20],name[20];
    while (fgets(buffer,45,stdin)) {
    	buffer[strcspn(buffer, "\n")] = 0;
    	if (strcmp(buffer,"***")==0) break;
    	token=strtok(buffer," ");
    	strcpy(info,token);
    	token=strtok(NULL," ");
    	strcpy(name,token);
        if (strcmp(info, "descendants") == 0) {
            printf("%d\n", countDescendants(relationships, n, name));
        } else if (strcmp(info, "generation") == 0) {
            printf("%d\n", countGenerations(relationships, n, name));
        }
	}
    return 0;
}