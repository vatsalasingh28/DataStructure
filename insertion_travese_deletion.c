#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *next;
};

void insertion_at_beginning(int info,struct Node **head)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=info;
	temp->next=*head;
	*head=temp;
}

void insertion_at_last(int info,struct Node *node)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=info;
        temp->next=NULL;
	while (node->next != NULL)
	  {
     		node = node->next;
  	  }

          node->next=temp;
}
void insertion_at_middle(int info,int pos,struct Node *node)
{
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        struct Node *prev=NULL,*last=NULL;
        temp->data=info;
        int counter=0;
        while (counter != pos)
          {     prev=node;
                node = node->next;
		counter=counter+1;
          }

          temp->next=node;
          prev->next=temp;
}
void delete_beginning(struct Node *head)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp=head->next;
        free(head);
        head=temp;
}
void delete_last(struct Node *node)
{
	while (node->next!= NULL)
	  {
           node = node->next;
          }
          free(node);

}
void delete_middle(int pos,struct Node *node)
{
        struct Node *prev=NULL,*last=NULL;
        int counter=0;
        while (counter != pos)
          {     prev=node;
                node = node->next;
                counter=counter+1;
          }
          prev->next=node->next;
}

void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d ", node->data); 
     node = node->next; 
  }
  printf("\n"); 
} 
int main(){

	struct Node *head=NULL;
   
	int position,option,value;
        while(1)
        {
        printf("***************************\n");
	printf("*1:Insertion At Beginneing*\n");
        printf("*2:Insertion At Last      *\n");
 	printf("*3:Insertion at middle    *\n");
	printf("*4:Remove from beginning  *\n");
        printf("*5:Remove from middle     *\n");
        printf("*6:Remove from end        *\n");
	printf("*7:Display                *\n");
	printf("*8:Exit                   *\n");
        printf("***************************\n");
	printf("\nEnter your choice        \n");
	scanf("%d",&option); 
	switch(option)
	{	
		case 1:
			printf("Enter the value to be inserted\n");
			scanf("%d",&value);
			insertion_at_beginning(value,&head);
			break;
		case 2:
                        printf("Enter the value to be inserted\n");
                        scanf("%d",&value);
                        insertion_at_last(value,head);
                        break;
                case 3:
                        printf("Enter the value to be inserted\n");
                        scanf("%d",&value);
			printf("Enter the position to be inserted\n");
                        scanf("%d",&position);

                        insertion_at_middle(value,position,head);
                        break;
                case 4:
                        printf("Delete from beginning\n");
                        delete_beginning(head);
                        break;
		case 5:
                        
			printf("Enter the position to be deleted\n");
                        scanf("%d",&position);

                        delete_middle(position,head);
                        break;
		case 6:
                        printf("Delete from last\n");
                        delete_last(head);
                        break;
		case 7: printList(head);
			break;
		case 8:
			exit(0);
			break;
      		default:
			printf("wrong input");
                	break;
 
	}
        }
	return 0;

}

