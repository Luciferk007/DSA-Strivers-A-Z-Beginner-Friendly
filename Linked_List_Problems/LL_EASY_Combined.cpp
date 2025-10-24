#include<bits/stdc++.h>
using namespace std;

struct node 
{
  int data;
  struct node* link;
};

struct node* insert_node_beginning(struct node * head, int data)
{
  struct node*p1 = (struct node*)malloc(sizeof(struct node));
  p1->data = data;
  p1->link = head;
  return p1;
}

void print_list(struct node* head)
{
  while(head != NULL)
  {
    printf("%d->",head->data);
    head = head->link;
  }
}

struct node* delete_node(struct node* head)
{
  //Case1: Empty Linked List:
  if(head == NULL)
  {
    printf("Empty Linked List\n");
  }
  
  //Case2: Only one node
  if(head->link == NULL)
  {
    return head;
  }
  
  struct node*temp = head;
  
  while(temp->link->link != NULL)
  {
    temp = temp->link;
  }
  free(temp->link);
  temp->link = NULL;
  return head;
  //10     20       30           NULL 
  //head   temp     temp->link   temp->link->link = NULL
}


int length_of_node(struct node* head)
{
  int length = 0;
  while(head!= NULL)
  {
    length++;
    head = head->link;
  }
  return length;
}


bool search_element(struct node* head, int target)
{
  while(head!= NULL)
  {
    if(head->data == target)
    {
      return true;
    }
    else
    {
      head = head->link;
    }
  }
  return false;
}

int main()
{
  struct node* head = (struct node*)malloc(sizeof(struct node));
  head->data = 10;
  head->link =NULL;
  
  struct node* next = (struct node*)malloc(sizeof(struct node));
  next->data = 20;
   next->link = NULL;
  head->link = next;
 
  
  next = (struct node*)malloc(sizeof(struct node));
  next->data = 30;
  next->link = NULL;
  head->link->link = next;
  
  print_list(head);
  cout<<endl;
  cout<<"Length of LL: "<<length_of_node(head)<<endl;
  
  head =insert_node_beginning(head,40);
  
  print_list(head);
  cout<<endl;
  cout<<"Length of LL: "<<length_of_node(head)<<endl;
  
  head= delete_node(head);
  //head->link = NULL;
  print_list(head);
  cout<<endl;
  
  cout<<"Length of LL: "<<length_of_node(head)<<endl;
  
  print_list(head);
  cout<<endl;
  if(search_element(head,40))
  {
    cout<<"Element:"<<head->data<<" is Present"<<endl;
  }
  else
  {
    cout<<"Element is not there"<<endl;
  }
  
}