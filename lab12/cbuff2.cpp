// cbuff.cpp
// A simple linked-list example: STACK
// 
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
const int NDATA=20000;
 
struct Node{              // a data element
  int nbytes;
  char buffer[NDATA];     // some data
  struct Node *next;      // a pointer to another element of this type
};
 
typedef struct Node Node;
 
 
int main(int argc,char *argv[]){
  if (argc<2){
    printf("Usage: stack <datafile>\n");
    return 1;
  }
 
  Node* head=NULL;    // pointer to the head of our list
                      // initially it points to nothing
 
  // open a data file in binary mode
  // The structure of our data file is:
  // An Integer: nbytes
  // char buffer[nbytes]
  // An Integer: nbytes
  // char buffer[nbytes]
  // ...
  FILE *input=fopen(argv[1],"rb");
 
  int nnodes=0;

  Node *oldNode = head;
  int a=0,b=0;

  while (!feof(input)){
    // first we allocate memory and create a new data node
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));

    if(!a){
      head = newNode;
      a++;}
    if(b)
      oldNode->next=newNode;  // new node is added to the head of the list
    b=1;    
    oldNode=newNode;

    int nbytes=0;        
 
    //fread(&nbytes,sizeof(int),1,input);  // number of bytes to read
    // newNode->nbytes=nbytes;
    do{
    fread(&newNode->buffer[nbytes],1,1,input); // read nbytes from file
    nbytes++;
    }while(newNode->buffer[nbytes-1]!='#'&&newNode->buffer[nbytes-1]!='%');
    newNode->nbytes=nbytes-1;

    nnodes++;                  // number of nodes created from file
  }

  oldNode->next = head;

  printf("created %d nodes\n",nnodes);
 
  // print the nodes
  system("clear");  // clear the screen
  Node* handle;
  handle=head;

  int j=0;

  while (j<5){
    for (int i=0; i<handle->nbytes; i++)
      putchar(handle->buffer[i]);
    handle = handle->next;
    usleep(200000);  //0.2 seconds delay
    system("clear");
    if(handle == head) j++;
  }
 
  return 0;
}
