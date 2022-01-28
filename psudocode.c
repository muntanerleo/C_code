#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 9

//create a linked list for the nodes of the tree
struct treenode 
{
  //each of my nodes will have some data to store
  char *word;
  struct treenode *left;
  struct treenode *right;
};

//use typedef to call the compare function
typedef int (*Compare)(const char *, const char *);

//function that inserts elements into the tree
void insert(char* key, struct treenode** leaf, Compare cmp)
{
  int res;
  if( *leaf == NULL ) 
  {
    *leaf = (struct treenode*) malloc( sizeof(struct treenode));
    (*leaf)->word = malloc(strlen(key) +1);     // memory for key
    strcpy ((*leaf)->word, key);                   // copy the key
    (*leaf)->left = NULL;
    (*leaf)->right = NULL;
    
  } else 
  {
    res = cmp (key, (*leaf)->word);
    if( res < 0)
      insert( key, &(*leaf)->left, cmp);
    else if( res > 0)
      insert( key, &(*leaf)->right, cmp);
    else                                            // key already exists
      printf ("Key '%s' already in tree\n", key);
  }
}

//function that compares value of the new node against the previous node
int CmpStr(const char *a, const char *b)
{
  return (strcmp(a, b));  // string comparison instead of pointer comparison
}

//recursive function to print out the tree inorder
void in_order(struct treenode *root)
{
  if(root != NULL) 
  {
    in_order(root->left);
    printf(" %s\n", root->word);  // string type
    in_order(root->right);
  }
}

//function that searches elements in the tree
void search(char* key, struct treenode* leaf, Compare cmp)
{
  int res;
  if(leaf != NULL) 
  {
    res = cmp(key, leaf->word);
    if(res < 0)
      search(key, leaf->left, cmp);
    else if(res > 0)
      search(key, leaf->right, cmp);
    else
      printf("\n'%s' found!\n", key);     // string type
  }
    else printf("\nNot in tree\n");
    return;
}

int main ()
{
  struct node *p_root = NULL;
  char *value;


  return 0;
}