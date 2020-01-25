
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "frequency.h"

//Main method to initiate the entire program.
int main(int argc, char* argv[])
{
    _node* base = new_trie();

    int height = 0;

    char str[ALPHABET];
    if(argc == 2 && *(argv[1]) == 'r'){
        PrintWords(base,str,height);
    }     
    else if (argc == 1){
        ReversePrint(base,str,height);
    }
     
    else{
        printf("Invalid arguments\n");

    }
    free_trie(base);
    return 0;
}




