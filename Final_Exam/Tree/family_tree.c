
/*
Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[20];
    char parent[20];
} Person;

int countDescendants(Person people[MAX], int n, char target[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].parent, target) == 0) {
            count += 1 + countDescendants(people, n, people[i].name);
        }
    }
    return count;
}

int countGenerations(Person people[MAX], int n, char target[]) {
    int maxGenerations = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(people[i].parent, target) == 0) {
            int currentGenerations = 1 + countGenerations(people, n, people[i].name);
            if (currentGenerations > maxGenerations) {
                maxGenerations = currentGenerations;
            }
        }
    }
    return maxGenerations;
}

int main() {
    Person people[MAX];
    int n = 0;

    // Input family tree
    while (1) {
        char child[20], parent[20];
        scanf("%s", child);
        if (strcmp(child, "***") == 0) {
            break;
        }
        scanf("%s", parent);

        strcpy(people[n].name, child);
        strcpy(people[n].parent, parent);
        n++;
    }

    // Process queries
    while (1) {
        char cmd[20], param[20];
        scanf("%s", cmd);
        if (strcmp(cmd, "***") == 0) {
            break;
        }
        scanf("%s", param);

        if (strcmp(cmd, "descendants") == 0) {
            int result = countDescendants(people, n, param);
            printf("%d\n", result);
        } else if (strcmp(cmd, "generation") == 0) {
            int result = countGenerations(people, n, param);
            printf("%d\n", result);
        }
    }

    return 0;
}
