#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Binary Tree example



//create a linked list for the nodes of the tree
typedef struct treenode 
{
  //each of my nodes will have some data to store
  char *str;
  int count;
  //each of the nodes can have up to 2 children
  struct treenode *left;
  struct treenode *right;

} treenode;

//function that creates a new node 
treenode *createnode(int count, char *str) 
{
  //make a result pointer that gives me back the result of the node 
  treenode* result = malloc(sizeof(treenode));

  //initializes both children to be NULL
  if(result != NULL)
  {
    result->left = NULL;
    result->right = NULL;
    result->str = str;
  }
  return result;
}

void printtabs(int numtabs)
{
  for(int i = 0; i < numtabs; i++)
  {
    printf("\t");
  }
}

//function that goes through the tree and prints its nodes
void printtree_rec(treenode *root, int level)
{
  //check if root equals NULL
  if(root == NULL)
  {
    printtabs(level);
    //print an empty tree line
    printf("---<empty>---\n");
    return;
  }

  //if the tree is not NULL then i need to go through this tree
  //i will do this in preorder traversal
  //print the data in the node first. then the left subtree. then the right subtree
  printtabs(level);
  printf("value = %s\n", root->str);
  printtabs(level);
  printf("left\n");
  
  printtree_rec(root->left, level+1);
  printtabs(level);
  printf("right\n");
  
  
  printtree_rec(root->right, level+1);

  printtabs(level);
  printf("done\n");
}

//
void printtree(treenode* root)
{
  printtree_rec(root, 0);
}

//bool function that tells me wether the node was inserted or not
//double pointer is there because if the tree is NULL then i will be able to change the adress
bool insertnumber(treenode **rootptr, int count)
{
  treenode *root = *rootptr;

  if(root == NULL)
  {
    //tree is empty
    (*rootptr) = createnode(count);
    return true;
  }

  if(count == root->str)
  {
    //do nothing 
    return false;
  }

  //this will recursively work through the tree, pick a side thats null and create a node
  if(count < root->str)
  {
    //look in the left side of the tree
    return insertnumber(&(root->left), count);
  } else {
    return insertnumber(&(root->right), count);
  }
}

//function that finds a number 
//this function will keep recursing untill the node is found with a matching value, or a null node 
bool findnumber(treenode * root, int value)
{
  if(root == NULL) return false;

  if(root->str == value)
  {
    return true;
  }

  if(value < root->str)
  {
    return findnumber(root->left, value);
  } else {
    return findnumber(root->right, value);
  }
}

int main ()
{
  //make the empty root 
  treenode *root = NULL;

  insertnumber(&root, 15);
  insertnumber(&root, 11);
  insertnumber(&root, 24);
  insertnumber(&root, 5);
  insertnumber(&root, 19);
  insertnumber(&root, 16);

  //function call that prints the tree nodes
  printtree(root);

  //number i want to search within the tree
  printf("%d (%d)\n", 16, findnumber(root, 16));
  printf("%d (%d)\n", 15, findnumber(root, 15));
  printf("%d (%d)\n", 5, findnumber(root, 5));
  printf("%d (%d)\n", 115, findnumber(root, 115));
  printf("%d (%d)\n", 1, findnumber(root, 1));
  printf("%d (%d)\n", 7, findnumber(root, 7));
  
}