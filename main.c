#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "frequency.h"

//Main method to initiate the entire program.
int main(int argc, char* argv[])
{
    _node* base=NewTrie();
    int level=0;
    char str[ALPHABET];
    if(argc == 2 && *(argv[1]) == 'r') {
        DownLex(base,str,level);}
    else if (argc == 1) {
        UpLex(base,str,level);}
    else {
        printf("Something went wrong with the arguments\n");}
    freemem(base);
    return 0;
}