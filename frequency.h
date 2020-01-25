#ifndef FREQ
#define FREQ
#define ALPHABET ((int)26)
typedef struct _node
{
 char letter;
 long count;
 struct _node* child[ALPHABET];
 bool EndOfWord;}
 _node;

 struct _node* new_trie();

 struct _node* new_node();

 void insert_node(_node* base , char* word, int length);

 void PrintWords(_node* base, int height, char word[]);

 void ReversePrint(_node* base, int height, char word[]);

 void FreeMem(_node* base);
#endif
