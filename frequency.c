#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "frequency.h"



struct _node* new_trie(){

    _node* base = new_node();
    char keys[ALPHABET];
    int length_key=0;   
    do{
     length_key=get_word(keys);
     if(length_key!=0)
     insert_node(base,keys,length_key);
    }while(length_key!=0);

    return base;


}
struct _node* new_node()
{
    _node* temp=(_node*)malloc(sizeof(_node));
    for(int i=0;i<ALPHABET;i++)
        temp->child[i]=NULL;
   
    temp->EndOfWord=false;
    temp->count=0;
   
    return temp;
}
void insert_node(_node* base , char* word, int length){
    int i = 0;
    struct _node* tmp = base;

    while (i<length)
    {
        int key = word[i]-'a';
        if(tmp->child[key]==NULL ){
            tmp->child[key]=new_node();
        }
        tmp=tmp->child[key];
        i++;

    }
    if(tmp->EndOfWord){
        tmp->count++;
    }
    else{
        tmp->letter=word[i];
        tmp->EndOfWord=true;
        tmp->count=1;
    }
}

void PrintWords(_node* base, int height, char word[]){

if(base->EndOfWord){
    word[height] = '\0';
    print(word,base->count);
}
for(int i =0; i<ALPHABET;i++){
    if(base->child!=NULL){
        word[height]='a'+i;
        PrintWords(base->child[i],height+1,word);
    }
}

    
}
void ReversePrint(_node* base, int height, char word[]){
    if(base->EndOfWord){
        print(word,base->count);
    }
    for(int i =ALPHABET-1; i>=0;i--){
    if(base->child!=NULL){
        word[height]='a'+i;
        ReversePrint(base->child[i],height+1,word);
    }
    }
}

void FreeMem(_node* base){

    _node* forFree = base;
    for(int i =0; i<ALPHABET;i++){
        if (forFree->child[i]!=NULL)
        {
            FreeMem(forFree->child[i]);
        }
        free(forFree);
        
    } 


}















