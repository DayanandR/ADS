#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 

struct Node 
{ 
    int data; 
    struct Node* ptrdiff; 
}; 
  
struct Node* XOR (struct Node *a, struct Node *b) 
{ 
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 
// @ beginning
void insert(struct Node **first, int data) 
{ 
    struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) ); 
    new_node->data = data; 
    new_node->ptrdiff = *first; 
    if (*first != NULL) 
    { 
        (*first)->ptrdiff = XOR(new_node, (*first)->ptrdiff); 
    } 
    *first = new_node; 
} 
// @ end
struct Node insert_rear(struct Node *first, int data){
    struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );  
    new_node->data = data; 
    if(first == NULL){
        new_node->ptrdiff = NULL;
        return *new_node;
    }
    if(first->ptrdiff == NULL){
        first->ptrdiff = (struct Node*) ((uintptr_t)(first->ptrdiff) ^(uintptr_t)(new_node));
        new_node->ptrdiff = first;
        return *first;
    }
    struct Node* prevPointer = first;
    struct Node* nextPointer = first->ptrdiff;
    struct Node* q;
    while(prevPointer != nextPointer->ptrdiff){
        q = (struct Node*) ((uintptr_t)(nextPointer->ptrdiff) ^ (uintptr_t)(prevPointer));
        prevPointer = nextPointer;
        nextPointer = q;
    }
    nextPointer->ptrdiff = (struct Node*) ((uintptr_t)(nextPointer->ptrdiff) ^ (uintptr_t)(new_node));
    new_node->ptrdiff = nextPointer;
    return *first;
}
//printing
void printList (struct Node *head) 
{ 
    struct Node *curr = head; 
    struct Node *prev = NULL; 
    struct Node *next; 
  
    printf (">>Linked List: >> \n"); 
  
    while (curr != NULL) 
    { 
        printf ("%d ", curr->data); 
        next = XOR (prev, curr->ptrdiff); 
        prev = curr; 
        curr = next; 
    } 
} 
  
// Driver program  
int main () 
{ 
    struct Node *head = NULL; 
    int i,ch,ele;
     
    do{printf("\n Enter choice \n 1.Inser @ beginning \n 2. Insert @ end \n 3.exit \n");
    scanf("%d",&ch);
    switch(ch){
      case 1 : printf("\n Element to insert:");
                        scanf("%d", &ele);
                        insert(&head, ele); 
                        printList (head); 
                        break;
      case 2 : printf("\n Element to insert:");
                        scanf("%d", &ele);
                        insert_rear(head, ele);
                         printList (head); 
                          break;
      case 3 : exit(0);
      default:printf("enter valid choice(1-3)");
    }
    }while(3);
    return 0; 
}