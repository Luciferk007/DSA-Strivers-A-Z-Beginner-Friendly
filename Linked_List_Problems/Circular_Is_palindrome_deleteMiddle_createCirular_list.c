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
void print_list(struct node* head)
{
  struct node* temp = head;
  while(temp != NULL)
  {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<endl;
}

bool loop_detect(struct node* head)
{
  struct node* fast = head, *slow = head;
  while(fast!= NULL && fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
    {
      return true;
    }
  }
    return false;
}

struct node* create_circular_linked_list(struct node* head)
{
  struct node* temp = head;
  while(temp->next!=NULL)
  {
    temp = temp->next;
  }
  temp->next = head;
  return head;
}

struct node* delete_middle_node(struct node* head)
{
  if (head == NULL || head->next == NULL)
  {
    free(head);
    return NULL;
  }
    
  struct node *fast = head, *slow = head;
  struct node*prev = NULL;
  while(fast!= NULL && fast->next!=NULL)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = slow->next;
  free(slow);
  slow->next = NULL;
  return head;
}

bool is_palindrome(struct node* head)
{
  stack<int>s;
  struct node* temp = head;
  while(temp!=NULL)
  {
    s.push(temp->data);  
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL) 
  {
    int val = s.top();
    s.pop();
    if (temp->data != val)
    return false;
    temp = temp->next;
  }

  return true;
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
  print_list(head);
  if(loop_detect(head))
  {
    cout<<"Is a loop"<<endl;
  }
  else
  {
    cout<<"Not a loop"<<endl;
  }
  delete_middle_node(head);
  print_list(head);
  if(is_palindrome)
  {
    cout<<"List is a palindrome"<<endl;
  }
  else
  {
    cout<<"List is not a palindrome"<<endl;
  }
}
