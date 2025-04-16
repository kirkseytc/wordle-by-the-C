#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char wordpool[12][6] = {
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
    
    flush_stdin();

    return 0;

}