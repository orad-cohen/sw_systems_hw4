#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "frequency.h"


int main(int argc, char* argv[])
{
    _node* base = new_trie();

    int height = 0;

    char word [ALPHABET];
    if(argc == 2 && *(argv[1]) == 'r'){
        PrintWords(base,height,word);
    }     
    else if (argc == 1){
        ReversePrint(base,height,word);
    }
     
    else{
        printf("Invalid arguments\n");

    }
    FreeMem(base);
    return 0;
}



