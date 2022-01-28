#include <stdio.h>
#include <stdlib.h>
// Leonardo Muntaner
// 10/10/2021 
// P3: Winning the Lottery (Linked Lists)

//Struct that forms a linked list of integers.
struct node
{
  int data;
  struct node* next;
};

//function that adds node at back of the linked list
struct node* insertAtBack(struct node* tail, int set)
{
  struct node* newPointer = malloc(sizeof(struct node));
  struct node* current = tail;
  newPointer = NULL; //this lets me access the link in the struc and replaces with NULL

  newPointer->data = set; //sets a value

  if(tail == NULL) //executes if the list is empty
  {
    newPointer->next = newPointer;
    return newPointer;
  }

  else
  {
    newPointer->next = tail;
    current = tail;

    while(current->next != tail)
      current = current->next;
    
    current->next = newPointer;

    return tail;
  }
}

//function that makes my linked list
struct node* makeLinkedList(struct node* tail, int numOfPeople)
{
  for(int i = 0; i<numOfPeople; i++)
  {
    tail = insertAtBack(tail, i+1);
  }
  return tail;
}

//prints all the elements of the list
void print(struct node* tail)
{
  int iter = 0;
  while(iter != 10) //we check if the next element is back to the front, if so, we stop!
  {
    printf("%d", tail->data); //iterate through each element, printing.
    tail = tail->next;

    iter++;
    printf("\n"); //Go to the next line.
  }
}

//function that removes the node 
struct node* RemoveNode(struct node* tail, int value)
{
  //the logic behind this functios is to make a pointer to the node i want to delete. 
  //fix the next pointer of the node before the deleted node.
  //free the node.
  if(tail == NULL)
  {
    return tail;
  }

  if(tail->data == value)
  {
    struct node* newTail = tail->next;
    struct node* deleteTail = tail;

    while(tail->next != deleteTail)
    {
      tail = tail->next;
    }
    tail->next = newTail;
    free(deleteTail);
    return newTail;
  }

  struct node* saveTail = tail;
  while(tail->next != saveTail && tail->next->data != value)
  {
    tail = tail->next;
  }

  if(tail->next->data != value) return saveTail;
  struct node* deleteTail = tail->next;
  tail->next = deleteTail->next;
  free(deleteTail);

  return saveTail;
}

int main()
{
  struct node* tail =NULL;

  int cases, NumGroups, p, s, t;
  scanf("%d", &cases);
  
  //i'm pretty sure there is something wrong here and thats why i am getting some weird outputs
  //it might also be that i forgot something in my functions above.
  for(int i = 0; i <cases; i++)
  {
    scanf("%d", &NumGroups);
    printf("Group #%d: \n", NumGroups);

    for(int i = 0; i < NumGroups; i++)
    {
      scanf("%d %d %d", &p, &s, &t);
      struct node* makeLinkedList(struct node* tail, int numOfPeople);
      void print(struct node* tail);

      for(int i = 0; i < p; i += s) //skips but does some funky stuff.
      {
        void print(struct node* tail);
        printf("%d\n", tail->data);
        tail = tail->next;

        if(p < t) break;
      }
    }
  }
  
  //this stupid printf DOES NOT WANT TO APPEAR AND I DO NOT KNOW WHYYYYYY!!!
  // :((((((((((( (CRY FACEEEEEEE!!!!!)
  printf("Lottery winner is person %d from group %d.", p, NumGroups);
  
  //who ever grades this please have mercy on your boy. 
  //I  will eternally appriciate it. 
  return 0;
}