  

#define NUM_LETTERS ((int)26)
typedef struct node //Declaring the struct node that we will use in our code.
{
 char _etter;
 long count;
 struct node* child[NUM_LETTERS];
 bool isWord}
 _node