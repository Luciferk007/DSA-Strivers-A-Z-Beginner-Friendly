#include<bits/stdc++.h>
using namespace std;

struct node 
{
  int data;
  struct node* link;
};


int main()
{
  struct node* head = (struct node*)malloc(sizeof(struct node));
  head->data = 10;
  head->link =NULL;
  printf("%d->",head->data);
  
  struct node* next = (struct node*)malloc(sizeof(struct node));
  next->data = 20;
  head->link = next;
  printf("%d->",next->data);
  
  next = (struct node*)malloc(sizeof(struct node));
  next->data = 30;
  head->link->link = next;
  printf("%d",next->data);
  
  
}