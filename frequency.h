  

#define ALPHABET ((int)26)
typedef struct node
{
 char letter;
 long count;
 struct node* child[ALPHABET];
 bool EndOfWord;}
 _node;