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
  
  head =insert_node_beginning(head,40);
  
  print_list(head);
  
}