#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int main(){
    srand(time(NULL));
    char *article[5] = {"the", "a", "one", "some","any"};
    char *noun[5] = {"boy", "girl", "dog", "town","car"};
    char *verb[5] = {"drove", "jumped", "ran", "walked","skipped"};
    char *preposition[5] = {"to", "from", "over", "under","on"};

    for(int i = 0; i < 10; i++){
        int article_index = rand() % 5;
        int article2_index = rand() % 5;
        int noun_index = rand() % 5;
        int verb_index = rand() % 5;
        int preposition_index = rand() % 5;
        int noun2_index = rand() % 5;

        // Print the selected words in a sentence
        printf("%d: %s %s %s %s %s %s\n", i + 1,
                article[article_index], noun[noun_index],
                verb[verb_index], preposition[preposition_index],
                article[article2_index],
                noun[noun2_index]);
    }

    return 0;
}