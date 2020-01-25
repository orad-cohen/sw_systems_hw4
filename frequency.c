#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "frequency.h"



struct _node* new_trie(){

    _node* base = new_node();

    char letters[ALPHABET];

    int length_key=0;   
    do
    {
     length_key=GetWord(letters);
     printf("%i",length_key);
     if(length_key!=0)
     {
        insert_node(base,letters,length_key);
     }
     
    }
    while(length_key!=0);

    return base;


}
struct _node* new_node()
{
    _node* temp=(_node*)malloc(sizeof(_node));
    for(int i=0;i<ALPHABET;i++){
        temp->child[i]=NULL;
    }        
   
    temp->EndOfWord=false;
    temp->count=0;
   
    return temp;
}
int GetWord(char word[])
{
    int len=0;
    char letter;
    char* tmpword=word;
    
    printf("tadam");
    do
    {
        if(scanf("%c",&letter)==EOF)
        {
        return 0;
        }
	    if(letter>='A'&&letter<='Z')
        {
            letter+=32;
        }    
	    if(letter>='a'&&letter<='z') 					 
        {
            len++;
            *(tmpword++)=letter;
             
        }
    }
    while(letter!='\n'&&letter!='\t'&&letter!=' ');

    return len;
}
bool is_word(_node* base)
{
    
    return base->EndOfWord;
}


void insert_node(_node* base , char* word, int length){
    
    struct _node * tmp = base;

    for(int i=0;i<length;i++)
    {
        int key=word[i]-'a';
        if(tmp->child[key]==NULL)
        {
            tmp->child[key]=new_node();
       
        }
        tmp=tmp->child[key];
       
    }
    if(tmp->EndOfWord)
        tmp->count++;
    else
    {
        tmp->EndOfWord=true;
        tmp->count=1;
    }
}

void PrintWords(_node* base, int height, char word[]){

if(is_word(base)){
    word[height] = '\0';
    print(word,base->count);
}
for(int i =0; i<ALPHABET-1;i++){
    if(base->child[i]){
        word[height]='a'+i;
        PrintWords(base->child[i],height+1,word);
    }
}

    
}
void ReversePrint(_node* base, int height, char word[]){
   
    if(is_word(base)){
        word[height] = '\0';
        print(word,base->count);
    }
    

    int i;
    
    for(i =ALPHABET-1; i>=0;i--){
        
        if(base->child[i]){
            
            word[height]='a'+i;
            ReversePrint(base->child[i],height+1,word);
    }
    }
}
void print(char str[],int count)
{
    printf("%s\t%d\n",str,count);
}

void FreeMem(_node* base){

    _node* forFree = base;
    for(int i = ALPHABET; i<=0;i--){
        if (forFree->child[i])
        {
            FreeMem(forFree->child[i]);
        }
        free(forFree);
        
    } 


}
