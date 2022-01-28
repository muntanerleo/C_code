// Leonardo Muntaner
// 12/6/2021
// Program #6: Priority Hair Salon (Binary Heap)
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Node 
{ 
	char name[100]; //name of customer
	int time; //arrival time
	int priority; //priority

}CUSTOMER;

//function to calculate priority of a customer
int getPriority(char name1[],char name2[]) 
{ 
	int i = 0, j = 0; //for iterations
	int c = 0; //to store count of characters

	int matched1[strlen(name1)]; //record of matched characters
	int matched2[strlen(name2)];
	
  for(i = 0;i < strlen(name1); i++)
		matched1[i] = 0;	//intialisations
	
  for(i = 0; i < strlen(name2); i++)
		matched2[i] = 0;
	
	for(i = 0; i < strlen(name1); i++) 
  { 
		for(j = 0; j < strlen(name2); j++)
    {
			if(abs(name1[i]-name2[j])%32==0 && matched1[i]==0 && matched2[j]==0)
      {
				c++;
				matched1[i]++;
				matched2[j]++;
			}
		}
	}
	
	return c; //returning the numbers of characters matched 1 to 1
}

//recursive function to create max-heap for implementation of priority queue
void max_heapfy(CUSTOMER* heap,int index,int heapSize) 
{
  int leftChild =2*index+1; //indexes of children
	int rightChild =2*index+2;
	int largest = index;
	
	if(leftChild<heapSize && heap[leftChild].priority>heap[index].priority) //checking max-heap properties
		largest=leftChild;
	else if(leftChild<heapSize && heap[leftChild].priority==heap[index].priority && heap[leftChild].time<heap[index].time)
		largest=leftChild;
	if(rightChild<heapSize && heap[rightChild].priority>heap[largest].priority)
		largest=rightChild;
	else if(rightChild<heapSize && heap[rightChild].priority==heap[largest].priority && heap[rightChild].time<heap[largest].time)
		largest=rightChild;

	if(largest != index) //in case of violation of max-heap property
  { 
		CUSTOMER temp = heap[index];
		heap[index] = heap[largest];
		heap[largest] = temp;
		max_heapfy(heap,largest,heapSize); //recursive function call
	}
}

//function to prioritize queue using max-heap
void prioritize(CUSTOMER* heap,int heapSize) 
{
  int i = (heapSize-2)/2; //last parent node index
	while(i >= 0)
  {
		max_heapfy(heap,i,heapSize); //checking max-heap properties
		i--;
	}
}

int main()
{ 
  int c; //to store number of customers
	int i; //for iterations
	int heapSize = 0; 
	int clock = 8*60; //clock timer
	
	char stylistName[100]; //to store stylist name
	
  //Enter number of customers: 
  //printf("\n");
	scanf("%d",&c);

  //Enter name of the Stylist: 
	//printf("\n"); 
	scanf("%s",stylistName);
	
  //Name & arrival time (format: hh:mm ) of customers:
  printf("\n\n");
	int hh,mm;

	CUSTOMER input[c]; //customer input array
	for(i = 0; i < c; i++)
  {
		printf("(%d) ",i+1);
		scanf("%s\t%d:%d",input[i].name,&hh,&mm);
		
    input[i].priority = getPriority(input[i].name, stylistName);
		input[i].time = hh*60+mm;
		
    if(input[i].time <= clock)
			heapSize++;
	}

  //Order of haircuts based on loyalty points
	printf("\n\n:- \n");
	
	CUSTOMER *heap; //using max-heap to simulate priority queue
	heap = (CUSTOMER*)calloc(heapSize,sizeof(CUSTOMER)); //heap initialization
	for(i = 0; i < heapSize; i++)
		heap[i] = input[i];
	
	i = 0; 
	int idx1, idx2; //to store beginning and end index of currently available customer 
	idx1 = idx2 = heapSize-1;
	
	while( i < c) //looping for each customer
  { 
		
		prioritize(heap,heapSize); //putting customers in priority queue
		
		if(heapSize > 0) //if customer is available for (hair-cut)
    { 
			
			printf("(%d) %s \n",(i+1),heap[0].name);
			i++;
			clock+=9; //haircut time
			heap[0] = heap[heapSize-1];
			heapSize--;
			
      heap = realloc(heap,(heapSize)*sizeof(CUSTOMER)); //decreasing queue size
		}
		clock++; 

		idx1++;
		while(idx2<c-1 && input[idx2+1].time<=clock)
			idx2++; //arrival of new customer
		
		int j;
		for(j = idx1; j <= idx2; j++) //putting new customer in heap
    {
			heapSize++;
			if(heapSize == 1)
				heap = calloc(1,sizeof(CUSTOMER));
			else
				heap = realloc(heap,(heapSize)*sizeof(CUSTOMER));
			heap[heapSize-1]=input[j];
		}
		
		idx1 = idx2;
	}
	putchar('\n');
	
  return 0; 
}