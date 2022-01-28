#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Leonardo Muntaner
//11/14/2021
//P5: Word Sorting, Searching (BST)

//struct holding word frequency information
typedef struct node  
{
  char *str; //the word
  int count; //number of times word occurs 
  
  //each of the nodes can have up to 2 children
  struct node *left;
  struct node *right;
}node;
struct node *root=NULL;

//use typedef to call the compare function
typedef int (*Compare)(const char *, const char *);

//function that prints the tree in order
void inorder(struct node *temp)
{
  if(temp==NULL)
    return;
  inorder(temp->left);
  printf("%s ", temp->str);
  inorder(temp->right);
}

// Function to create new node
struct node* create(char *str) 
{
  struct node *new1;
  
  new1 = (struct node*)malloc(sizeof(struct node));
  new1->str = malloc(strlen(str)+1); //plus 1 for null terminator
  
  strcpy(new1->str,str);
  new1->left = NULL;
  new1->right = NULL;
  
  return new1;
}

// Function to insert a node
struct node* insert(struct node *root,char *str)
{
  if(root==NULL)
  {
    root = create(str);
  }
  else if(strcmp(str,root->str)<0)
  {
    root->left = insert(root->left,str);
  }
  else if(strcmp(str,root->str)>0)
  {
    root->right =  insert(root->right,str);
  }
  
  return root;
}

//comparison function for quicksort. This lets quicksort sort words by descending order of count, from most to least frequent
int wordcmp (node *a, node *b) 
{
	if (a->count < b->count) return +1;
	if (a->count > b->count) return -1;
	return 0;
}

//function that searches elements in the tree
void search(char* key, struct node* leaf, Compare cmp)
{
  int res;
  if(leaf != NULL) 
  {
    res = cmp(key, leaf->str);
    if(res < 0)
      search(key, leaf->left, cmp);
    else if(res > 0)
      search(key, leaf->right, cmp);
    else
      printf("\n'%s' found!\n", key); // string type
  }
  else printf("\nNot in tree\n");
    return;
}

//return 1 if c is alphabetic (a..z or A..Z), 0 otherwise
int is_alphabetic (char c) 
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return 1;
	return 0;
}

int main()
{
  char *str;
  while(1)
  {
    printf("Enter value to insert: ");
    scanf("%s",str);
    
    if(strcmp(str,"-1")==0)
    {
      break;
    }
    else
    {
      root = insert(root,str);
    }
  }
  
  return 0;
}