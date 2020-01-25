#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "frequency.h"


struct _node* NewTrie()
{
    _node* base = node();
    char keys[ALPHABET];
    int length_key=0;
   
    do
    {
     length_key=get_word(keys);
     if(length_key!=0)
     insert_node(base ,keys,length_key);
    }while(length_key!=0);
   
    return base;
}
struct _node* node()
{
    _node* tmp=(_node*)malloc(sizeof(_node));
    for(int i=0;i<ALPHABET;i++)
        tmp->next[i]=NULL;
   
    tmp->_EndOfWord=false;
    tmp->count=0;
   
    return tmp;
}

int get_word(char str[])
{
    
    char letter;
    char* word=str;
     int len = 0;
    do
    {
        if(scanf("%c",&letter)==EOF){
            return 0;}
	    if(letter>='A'&&letter<='Z'){
            letter+=32;}
	    if(letter>='a'&&letter<='z') 					 
        {
            *(word++)=letter;
             len++;
        }
    }while(letter!='\n'&&letter!='\t'&&letter!=' ');

    return len;
}



void insert_node(_node* base,char* word,int len)
{
    int height;
    struct _node* tmp=base;
   
    for(height=0;height<len;height++)
    {
        int i=word[height]-'a';

        if(tmp->next[i]==NULL)
        {
            tmp->next[i]=node();
       
        }
        tmp=tmp->next[i];
       
    }
    if(tmp->_EndOfWord)
        tmp->count++;
    else
    {
        tmp->_EndOfWord=true;
        tmp->count=1;
    }
}

bool EndOfWord(_node* base)
{
    return base->_EndOfWord;
}


void UpLex(_node* base,char str[],int level)
{
    if(EndOfWord(base))
    {
        str[level]='\0';
        print(str,base->count);
    }
    int i;
    for(i=0;i<ALPHABET;i++)
    {
        if(base->next[i])
        {
            str[level]=i+'a';
            UpLex(base->next[i],str,level+1);
        }
    }
   
}

void DownLex(_node* base,char str[],int level)
{
    if(EndOfWord(base))
    {
        str[level]='\0';
        print(str,base->count);
    }
   int i;
    for(i=ALPHABET-1;i>=0;i--)
    {
        if(base->next[i])
        {
            str[level]=i+'a';
            DownLex(base->next[i],str,level+1);
        }
 
    }
   
}



void freemem(_node* base)
{
    _node* tmp=base;

    int i;

    for(i=ALPHABET-1;i>=0;i--) {
        if(base->next[i])
        {
            freemem(tmp->next[i]); 
        }      
    }

free(base);

}

void print(char word[],int count)
{
    printf("%s\t%d\n",word,count);
}