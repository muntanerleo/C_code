#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256 //this is for how many different values a single bit can have 

//struct that defines my node
typedef struct trienode 
{
  //the children will be child links for all the different come after
  //they will be an array of trienode pointers
  //each of these pointers will tell us where to find the node for a particular character
  //they will also be set to NULL if there is no child for that character
  struct trienode *children[NUM_CHARS]; //this will be like a look up table
  
  //marks the node to see wether it is the end of a word
  //terminal node for a particular string
  bool terminal;

}trienode;

//function that creates nodes
trienode *createnode()
{
  //creates a new node and allocates a pointer to it
  trienode *newnode = malloc(sizeof *newnode);

  //for loop that goes through the children/ my characters
  for(int i = 0; i < NUM_CHARS; i++)
  {
    newnode->children[i] =NULL;
  }
  newnode->terminal = false;
  return newnode;
}

//function that inserts things into our trees
//returns a bool that tells us wether or not a new word was inserted
//if its false then the word is already inside the set. true if its new
//the reason for using a double pointer is for changing the root if i need to
bool trieinsert(trienode **root, char *signedtext)
{
  if(*root == NULL)
  {
    *root = createnode();
  }

  //this forces all these characters to be unsigned rather than signed
  //that prevents me from having issues where i end up getting negative indexes
  unsigned char *text = (unsigned char *)signedtext;
  
  //i will use this for traversing my tree and it will start at the root
  //thats why i set it to root.
  trienode *tmp = *root;

  //this tells us how far i need to go
  int length = strlen(signedtext);

  //for loop tells me how long my string is
  for(int i = 0; i < length; i++)
  {
    if(tmp->children[text[i]] == NULL)
    {
      //create new node
      tmp->children[text[i]] = createnode();
    }
    tmp = tmp->children[text[i]];
  }

  //now try to figure out if the word is already in the trie
  //check terminal value of the node
  if(tmp->terminal)
  {
    return false;
  }else 
  {
    tmp->terminal = true;
    return true;
  }

}

void printtrie_rec(trienode *node, unsigned char *prefix, int length)
{
  //makes new prefix for when we call to the next level
  unsigned char newprefix[length+2];

  //copy old prefix into the new prefix
  memcpy(newprefix, prefix, length);
  newprefix[length+1] = 0;

  //base case
  if(node->terminal)
  {
    printf("WORD: %s\n", prefix);
  }

  //there might be more children below this node so recurse as well
  for(int i = 0; i < NUM_CHARS; i++)
  {
    if(node->children[i] != NULL)
    {
      newprefix[length] = i;
      printtrie_rec(node->children[i], newprefix, length+1);
    }
  }
}

void printtrie(trienode * root)
{
  if(root == NULL)
  {
    printf("TRIE EMPTY!\n");
    return;
  }

  printtrie_rec(root, NULL, 0);
}

//search function for the trie. will return true if its there and false if it isnt 
bool searchtrie(trienode *root, char *signedtext)
{
  unsigned char *text = (unsigned char *)signedtext;
  int length = strlen(signedtext);
  trienode * tmp = root;

  for(int i = 0; i < length; i++)
  {
    if(tmp->children[text[i]] == NULL) 
    {
      return false;
    }
    tmp = tmp->children[text[i]];
  }

  //check the termonal value
  return tmp->terminal;
}

bool node_has_children(trienode *node)
{
  if(node == NULL)return false;

  for(int i = 0; i < NUM_CHARS; i++)
  {
    if(node->children[i] != NULL)
    {
      //there is at least one child 
      return true;
    }
  }
  return false;
}

//delete function
bool deletestr(trienode** root, char *signedtext)
{
  unsigned char *text = (unsigned char *)signedtext;
  bool result = false;

  if(*root == NULL)return false;

  //allows me to pass a single pointer into the recursive function
  *root = deletestr_rec(*root, text, &result);
  return result;
}

int main ()
{
  trienode * root = NULL;

  trieinsert(&root, "KIT");
  trieinsert(&root, "CATTLE");
  trieinsert(&root, "KIN");
  trieinsert(&root, "CAT");
  trieinsert(&root, "HAPPY");

  printtrie(root);

  printf("search for CATTLE: %d\n", searchtrie(root, "CATTLE"));
  printf("search for CAT: %d\n", searchtrie(root, "CAT"));
  printf("search for KITTEN: %d\n", searchtrie(root, "KITTEN"));

  deletestr(&root, "KIN");
  deletestr(&root, "CAT");
  printtrie(root);


}