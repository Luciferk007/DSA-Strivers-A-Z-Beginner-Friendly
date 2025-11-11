#include<bits/stdc++.h>
using namespace std;


// Doubly linked list 

struct node 
{
  int data;
  struct node* prev;
  struct node* next;
};

struct node* insert_node_empty_list(struct node* head, int value)
{
  struct node* temp = (struct node* )malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = value;
  temp->next = NULL;
  return temp;
}

struct node* add_node_at_begining(struct node*head, int value)
{
  //Now if you want to have connection between two nodes:
  //1. First node prev should be connected to 2nd node next
  //2. Second Node next should be connected to 1st node prev.
  //3. Update the head to the new pointer.
  
  struct node* temp =(struct node* ) malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->data = value;
  temp->next = NULL;
  head->prev = temp;
  temp->next = head;
  head = temp;
  return head;
}

struct node* add_node_at_end(struct node* head, int value)
{
  struct node*temp = (struct node*) malloc(sizeof(struct node));
  temp->prev = NULL;
  temp->next = NULL;
  temp->data = value;
  if(head == NULL)
  {
    head =temp;
    return head;
  }
  struct node* ptr = head;
  while(ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = temp;
  temp->prev = ptr;
  return head;
}

// struct node* delete_node_at_end(struct node* head)
// {
//     if (head == NULL)  // case: empty list
//         return NULL;

//     if (head->next == NULL)  // case: only one node
//     {
//         free(head);
//         head = NULL;
//         return head;
//     }

//   struct node*temp = head;
//   struct node*temp2;
//   while(temp->next != NULL)
//   {
//     temp = temp->next;  // Will point to the last node
//   }
//   temp2  = temp->prev;  //Second last node
//   free(temp);
//   temp2->next = NULL;
//   return head;
  
// }

struct node* delete_node_at_starting(struct node* head)
{
   //Already head is pointing to the first node so we dont need loop
   if (head == NULL)  // case: empty list
        return NULL;

    if (head->next == NULL)  // case: only one node
    {
        free(head);
        return NULL;
    }
    
    
    struct node* temp = head;       // old head
    head = head->next;              // move head to the second node
    head->prev = NULL;              // detach old head
    free(temp);                     // free old head

    return head;
}

//Old Method: Both of them are working
struct node* delete_node_at_end(struct node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    struct node* last = temp->next;
    free(last);
    temp->next = NULL;

    return head;
}

void  print_list_forward(struct node* head)
{ 
  while(head!=NULL)
  {
    cout<<head->data<<"<->";
    head = head->next;
  }
  //cout<<"NULL";
}

//Just as we swap two numbers similarly we can swap the next and prev pointers of each node to reverse the DLL.

struct node* reverse_dll(struct node* head)
{
  struct node* temp = NULL:
  struct node* current = head;
  while(current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    //Move to next node
    current = current->next;
  }
  //To avoid having head at NULL position we will check if temp is not NULL then only we will update head.
  if(temp != NULL)
  {
    head = temp->prev;
  }
  return head;
}

int main()
{
  struct node* head = (struct node*)malloc(sizeof(struct node));
  
  head = insert_node_empty_list(head,10);
  head =  add_node_at_begining(head,20);
  head = add_node_at_begining(head,30);
  print_list_forward(head);
  head = add_node_at_end(head,40);
  cout<<endl;
  print_list_forward(head);
  head=delete_node_at_end(head);
  cout<<endl;
  print_list_forward(head);
  cout<<endl;
  head = delete_node_at_starting(head);
  print_list_forward(head);
  reverse_dll(head);
  print_list_forward(head);
  return 0;
}