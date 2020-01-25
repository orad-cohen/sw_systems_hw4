#ifndef FREQUENCYH
#define FREQUENCYH
#define ALPHABET ((int)26)
typedef struct _node
{
 char _letter;
 long count;
 struct _node* next[ALPHABET];
 bool _EndOfWord;
}_node;
struct _node* NewTrie();
struct _node* node();
void UpLex(_node* root,char str[],int level);
void DownLex(_node* root,char str[],int level);

void insert_node(_node* root,char* key,int length);

bool is_word(_node* root);

int get_word(char str[]);

void print(char str[],int count);
void freemem(_node* root);
#endif