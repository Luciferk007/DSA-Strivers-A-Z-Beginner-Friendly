#include<bits/stdc++.h>
using namespace std;

struct node 
{
  struct node* next;
  int data;
};


struct node* add_node(struct node* head)
{
  struct node*p1 = (struct node *) malloc(sizeof(struct node));
  p1->data = 10;
  p1->next = NULL;
  return p1;
}

struct node* add_node_at_end(struct node* head, int value)
{
  if(head == NULL)
  {
    return head;
  }
  
  struct node*p1 = (struct node *) malloc(sizeof(struct node));
  p1->data = value;
  struct node*temp = head;
  
  
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = p1;
  p1->next = NULL;
  return p1;
}

struct node* add_node_at_beginning(struct node* head, int data)
{
  
  struct node*p1 = (struct node *)malloc(sizeof(struct node));
  
  p1->data=data;
  p1->next=head;
  head = p1;
  return head;
}

void print_list(struct node* head)
{
  struct node* temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

struct node* delete_node_at_end(struct node* head)
{
  if(head == NULL)
  {
    return head;
  }
  
  struct node* temp = head;
  while(temp->next->next!=NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next =NULL;
  return head;
}

struct node*delete_node_at_front(struct node* head)
{
  if(head == NULL)
  {
    return head;
  }
  struct node* temp =head->next;
  free(head);
  head->next = NULL;
  head = temp;
  return head;
}

void middle_element(struct node* head)
{
  struct node *slow = head;
  struct node *fast = head;
  while(fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  cout<<"Middle_element_is: "<<slow->data<<endl;
}

struct node* reverse_list(struct node* head)
{
  struct node*prev = NULL;
  struct node*forward = head;
  while(head !=NULL)
  {
    forward = head->next;
    head->next = prev;
    prev = head;
    head = forward;
  }
  return prev;
}


int main()
{
  struct node*head = (struct node*) malloc(sizeof(struct node));
  head = add_node(head);
  add_node_at_end(head,20);
  add_node_at_end(head,30);
  add_node_at_end(head,40);
  add_node_at_end(head,50);
  add_node_at_end(head,60);
  head =add_node_at_beginning(head,5);
  head = delete_node_at_end(head);
  head= delete_node_at_front(head);
  print_list(head);
  cout<<endl;
  middle_element(head);
  head = reverse_list(head);
  print_list(head);
}