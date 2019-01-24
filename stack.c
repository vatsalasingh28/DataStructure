#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node *next;
};

void push(int info,struct Node **top)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=info;
        temp->next=*top;
	*top=temp;
}

void pop(struct Node *top)
{
      struct Node *temp=top;	
      top=top->next;
      free(temp);
}


void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     printf(" %d",node->data); 
     node = node->next; 
  }
  printf("\n"); 
} 
int main(){

	struct Node *top=NULL;
   
	int option,value;
        while(1)
        {
        printf("***************************\n");
	printf("*1:push                   *\n");
        printf("*2:pop        	          *\n");
	printf("*3:Display                *\n");
	printf("*4:Exit                   *\n");
        printf("***************************\n");
	printf("\n Enter your choice        \n");
	scanf("%d",&option); 
	switch(option)
	{	
		case 1:
			printf("Enter the value to be inserted\n");
			scanf("%d",&value);
			push(value,&top);
			break;
		case 2:
                        pop(top);
			break;
                     
	        case 3: printList(top);
			break;
		case 4:
			exit(0);
			break;
      		default:
			printf("wrong input");
                	break;
 
	}
        }
	return 0;

}

