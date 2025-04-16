#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_AMOUNT 12

enum COLOR {
    WHITE,
    YELLOW,
    GREEN,
    GREY
};

char WORD_POOL[WORD_AMOUNT][6] = {
    "beach",
    "coral",
    "ocean",
    "shore",
    "islet",
    "sunny",
    "salty",
    "drift",
    "guava",
    "mango",
    "oasis",
    "aloha"
};

void flush_stdin(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(void){

    srand(time(NULL));

    char buffer[6];
    char* selected_word = WORD_POOL[rand() % WORD_AMOUNT];
    int turns = 1;
    enum COLOR colors[26] = {0};

    while(turns <= 6){

        int numGreens = 0;

        printf("Turn %d\n", turns);
        printf("Enter your guess: ");
        scanf("%5[A-Za-z]", buffer);
        flush_stdin();

        printf("\n>> ");

        // i is our word, j is the word to guess
        for(int i = 0; i < 5; i++){ 
          
            if(buffer[i] < 'a'){
                buffer[i] += ('a' - 'A');
            }

            int color_index = buffer[i] - 'a';

            colors[color_index] = GREY;

            for(int j = 0; j < 5; j++){

                // we found a macthing character
                if(selected_word[j] == buffer[i]){

                    // same index
                    if(i == j){
                        colors[color_index] = GREEN;
                        break;
                    } else {
                        colors[color_index] = YELLOW;
                    }

                }

            }
            
            switch(colors[color_index]){
                case GREY:
                    printf("\e[2;37m");
                    break;
                case YELLOW:
                    printf("\e[33m");
                    break;
                case GREEN:
                    numGreens += 1;
                    printf("\e[32m");
                    break;
                case WHITE:
                    break;
            }

            printf("%c ", buffer[i]);
            printf("\e[0m");
            
        }

        printf("\n\n");

        if(numGreens == 5){
            break;
        }

        for(int i = 0; i < 26; i++){

            switch(colors[i]){
                case GREY:
                    printf("\e[2;37m");
                    break;
                case YELLOW:
                    printf("\e[33m");
                    break;
                case GREEN:
                    numGreens += 1;
                    printf("\e[32m");
                    break;
                case WHITE:
                    printf("\e[0m");
                    break;
            }

            printf("%c ", (i + 'a'));

            if(i % 7 == 6){
                printf("\n");
            }

            printf("\e[0m");

        }

        printf("\n\n");

        turns += 1;
    }

    if(turns > 6){
        printf("You lose! The word was '%s'\n", selected_word);
    } else {
        printf("You guessed it in %d turns!\n", turns);
    }

    return 0;

}