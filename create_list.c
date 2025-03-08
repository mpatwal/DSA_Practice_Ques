#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *create(int val)
{
   struct node *n = (struct node *)malloc(sizeof(struct node));
   n->data = val;
   n->next = NULL;
   return n;
}
void display(struct node *head)
{
   struct node *temp = head;
   while (temp != NULL)
   {
      printf("%d->", temp->data);
      temp = temp->next;
   }
   printf("Null");
}

struct node *insert_before_of(struct node *head, int pos_val, int val)
{
   if (head == NULL)
   {
      printf("List is empty");
   }
   if (head->data == pos_val)
   {
      struct node *my_node = create(val);
      my_node->next = head;
      return my_node;
   }
   struct node *temp = head;
   while (temp != NULL)
   {
      if (temp->next->data == pos_val)
      {
         struct node *n = create(val);
         n->next = temp->next;
         temp->next = n;
         return head;
      }
      temp = temp->next;
   }
   return head;
}

int main()
{
   struct node *head = create(12);
   head->next = create(3);
   head->next->next = create(5);
   printf("the original  list is : \n");
   display(head);
   insert_before_of(head, 5, 4);
   printf("\nthe new  list is :\n ");
   display(head);
}
