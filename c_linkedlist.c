#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
int data; 
struct node *link; 
}; 
struct nodee *start=NULL;
struct node *head; 
void beginsert (); 
void lastinsert (); 
void randominsert(); 
void begin_delete(); 
void last_delete(); 
void random_delete(); 
void display(); 
void search(); 


void main () 
{ 
int choice=0; 
while(choice != 9) 
{ 
printf("\n Main Menu \n"); 
printf("\n Choose one option from the following list \n"); 
printf("__________________________________________\n"); 
printf("\n 1.Insert in Starting \n 2.Insert at End \n 3.Insert at any random location \n 4.Display \n 5.Delete from Starting \n 6.Delete node after specified location\n 7.Delete from End \n 8.Search an Element \n 9.Exit \n"); 
printf("\n Enter your choice : \n"); 
scanf("\n%d",&choice); 
switch(choice) 
{ 
 case 1: 
 beginsert(); 
 break; 
 case 2: 
 lastinsert(); 
 break; 
 case 3: 
 randominsert(); 
 break; 
 case 4: 
 display(); 
 break; 
 case 5: 
 begin_delete(); 
 break; 
 case 6: 
 random_delete(); 
 break; 
 case 7: 
 last_delete(); 
 break; 
 case 8: 
 search(); 
 break; 
 case 9:
 exit(0); 
 break; 
 default: 
 printf("Please enter valid choice from(1/2/3/4/5/6/7/8/9)\n"); 
} 
} 
}

 
void beginsert() 
{ 
struct node *ptr; 
int item; 
ptr = (struct node *) malloc(sizeof(struct node *)); 
if(ptr == NULL) 
{ 
 printf("\nOVERFLOW\n"); 
} 
else 
{ 
 printf("\nEnter value:\n"); 
 scanf("%d",&item); 
 ptr->data = item; 
 ptr->link= head; 
 head = ptr; 
 printf("\nNode inserted"); 
} 
} 


void lastinsert() 
{ 
struct node *ptr,*temp; 
int item; 
ptr = (struct node*)malloc(sizeof(struct node)); 
if(ptr == NULL) 
{ 
 printf("\nOVERFLOW"); 
} 
else 
{ 
 printf("\nEnter value:\n"); 
 scanf("%d",&item); 
 ptr->data = item; 
 if(head == NULL) 
 { 
 ptr -> link = NULL; 
 head = ptr; 
 printf("\nNode inserted"); 
 } 
 else 
 { 
 temp = head; 
 while (temp -> link != NULL) 
 { 
 temp = temp -> link; 
 } 
 temp->link = ptr; 
 ptr->link = NULL; 
 printf("\nNode inserted");
 } 
} 
} 


void randominsert() 
{ 
int i,loc,item; 
struct node *ptr, *temp; 
ptr = (struct node *) malloc (sizeof(struct node)); 
if(ptr == NULL) 
{ 
 printf("\nOVERFLOW"); 
} 
else 
{ 
 printf("\nEnter Element : "); 
 scanf("%d",&item); 
 ptr->data = item; 
 printf("\nEnter the location after which you want to insert: "); 
 scanf("\n%d",&loc); 
 temp=head; 
 loc=loc-1;
 for(i=0;i<loc;i++) 
 { 
 temp = temp->link; 
 if(temp == NULL) 
 { 
 printf("\ncan't insert\n"); 
 return; 
 } 
 } 
 ptr ->link = temp ->link; 
 temp ->link = ptr; 
 printf("\nNode inserted"); 
} 
} 

 


void begin_delete() 
{ 
struct node *ptr; 
if(head == NULL) 
{ 
 printf("\nList is empty\n"); 
} 
else 
{ 
 ptr = head; 
 head = ptr->link; 
 free(ptr); 
 printf("\nNode deleted from the begining : \n"); 
} 
} 
void last_delete() 
{ 
struct node *ptr,*ptr1; 
if(head == NULL) 
{ 
 printf("\n list is empty \n");
} 
else if(head -> link == NULL) 
{ 
 head = NULL; 
 free(head); 
 printf("\n Only node of the list deleted \n"); 
} 
else 
{ 
 ptr = head; 
 while(ptr->link != NULL) 
 { 
 ptr1 = ptr; 
 ptr = ptr ->link; 
 } 
 ptr1->link= NULL; 
 free(ptr); 
 printf("\n Deleted Node from the last \n"); 
} 
} 



void random_delete() 
{ 
struct node *ptr,*ptr1; 
int loc,i; 
printf("\n Enter the location of the node after which you want to perform deletion : \n"); 
scanf("%d",&loc); 
ptr=head; 
for(i=0;i<loc;i++) 
{ 
 ptr1 = ptr; 
 ptr = ptr->link; 
if(ptr == NULL) 
{ 
 printf("\n Can't delete "); 
 return; 
} 
} 
 ptr1 ->link = ptr ->link; 
 free(ptr); 
 printf("\n Deleted node %d ",loc+1); 
} 


void search() 
{ 
struct node *ptr; 
int item,i=0,flag; 
ptr = head; 
if(ptr == NULL) 
{ 
 printf("\n List is Empty \n"); 
} 
else 
{ 
 printf("\n Enter item which you want to search : \n"); 
 scanf("%d",&item); 
 while (ptr!=NULL)
 { 
 if(ptr->data == item) 
 { 
 printf("\n Item found at location %d ",i+1); 
 flag=0; 
 } 
 else 
 { 
 flag=1; 
 } 
 i++; 
 ptr = ptr -> link; 
 } 
 if(flag==1) 
 { 
 printf("\n Item not found\n"); 
 } 
} 
} 


void display() 
{ 
struct node *ptr; 
ptr = head; 
if(ptr == NULL) 
{ 
 printf("\n Nothing to print"); 
} 
else 
{ 
 printf("\nThe Elements are \n"); 
 while (ptr!=NULL) 
 { 
 printf("%d\t",ptr->data); 
 ptr = ptr -> link; 
 } 
} 
}