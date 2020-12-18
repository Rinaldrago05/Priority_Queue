//Priority Queue.

#include<stdio.h>
#include<stdlib.h>

struct Info
{
	int data;
	int priority;
};

struct Node
{
	struct Info* details;
	struct Node* next;	
}*head=NULL;

struct Info* create_new_info()
{
	return (struct Info*)calloc(1,sizeof(struct Info));
}

struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

struct Info* get_details()
{
	struct Info* ptr=create_new_info();
	
	if(!ptr)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	printf("\n\nEnter the details below:");
	printf("\n\nEnter the data: ");
	scanf("%d",&ptr->data);
	printf("\nEnter the priority: ");
	scanf("%d",&ptr->priority);
	
	return ptr;
}

struct Node* insert(struct Info* details)
{
	struct Node* nd=create_new_node();
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(!head || (head->details->priority>details->priority))
	{
		nd->details=details;
		nd->next=head;
		head=nd;
		
		return head;
	}
	
	struct Node* ptr=head;
	
	while(ptr->next && ptr->next->details->priority<=details->priority)
	ptr=ptr->next;
	
	nd->details=details;
	nd->next=ptr->next;
	ptr->next=nd;
	
	return head;
}

struct Info* delete_e()
{
	if(!head)
	{
		printf("\n\nERROR: Priority Queue is empty.");
		return NULL;
	}
	
	struct Node* ptr=head;
	struct Info* details=create_new_info();
	
	if(!details)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	details->data=head->details->data;
	details->priority=head->details->priority;
	
	head=ptr->next;
	free(ptr->details);
	free(ptr);
	
	return details;
}

struct Node* display()
{
	if(!head)
	{
		printf("\nERROR: Priority Queue is empty.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr)
	{
		printf("\nData: %d \t Priority: %d",ptr->details->data,ptr->details->priority);
		ptr=ptr->next;
	}
	
	return head;
}

void free_all()
{
	struct Node* ptr=head;
	while(ptr)
	{
		head=head->next;
		free(ptr->details);
		free(ptr);
		ptr=head;
	}
	
	head=NULL;
}

void menu()
{
	printf("\nMenu (Priority Queue):\n------------------------");
	printf("\n\n0) Exit.");
	printf("\n1) Insert.");
	printf("\n2) Delete.");
	printf("\n3) Display.");
	printf("\n4) Re-Display the menu.");
}

int main()
{
	menu();
	
	printf("\n\n");
	int i,ch;
	struct Info* details;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		switch(ch)
		{
			case 1:		details=get_details();
						if(details)
						insert(details);
						break;
						
			case 2:		details=delete_e();
						if(details)
						{
							printf("\n\nDetails deleted from the Priority Queue is:");
							printf("\n\nData: %d \t Priority: %d",details->data,details->priority);
							free(details);
						}
						break;
			
			case 3:		printf("\n\nMESSAGE: Displaying the whole Priority Queue.\n\n");
						if(display())
						printf("\n\nMESSAGE: Successfully displayed the whole Priority Queue.");
						break;
			
			case 4:		printf("\n\nMESSAGE: Re-dipslaying the menu.");
						printf("\n\n");
						for(i=0;i<130;i++)
						putchar('-');
						printf("\n");
						menu();
						break;
						
			default:	printf("\n\nERROR: Wrong choice.");
						break;	
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	printf("\n\nMESSAGE: Program Exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	printf("\n\n");
	
	free_all();
}
