#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define FAILURE 0
typedef struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;
}dnode;
int insertbeg(dnode **head,dnode **tail,int item);
int insertend(dnode **head,dnode **tail,int item);
int insertmid(dnode **head,dnode **tail,int item);
int deletebeg(dnode **head,dnode **tail);
int deleteend(dnode **head,dnode **tail);
int deletemid(dnode **head,dnode **tail,int item);
void display(dnode *head,dnode *tail);
void main(void)

{
	int b=1;
	dnode *head=NULL;
	dnode *tail=NULL;
	int r;
	while(b)
	{

		int a,r,w;
		printf(" DOUBLY-LINKED LIST\n");
		printf("choose the operation to be performed\n");
		printf("1.INSERTION AT BEGINNIG\n");
		printf("2.INSERTION AT END\n");
		printf("3.INSERTION AT MID\n");
		printf("4.DELETION  AT BEGINNING\n");
		printf("5.DELETION  AT END\n");
		printf("6.DELETION  AT MID\n");
		printf("7.DISPLAY THE LINKED LIST\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Enter the element to insert\n");
				scanf("%d",&w);
				r=insertbeg(&head,&tail,w);
				printf("data=%d\n",head->data);
				display(head,tail);
				break;

			case 2:
				printf("Enter the element to insert\n");
				scanf("%d",&w);
				r=insertend(&head,&tail,w);
				printf("data=%d\n",(head)->data);
				display(head,tail);				
				break;       
		       
			     
			case 3:	
				printf("Enter the element to insert\n");
				scanf("%d",&w);
			        r=insertmid(&head,&tail,w);
				display(head,tail);
				break;       
		       
		
			case 4:
				r=deletebeg(&head,&tail);
				if(1==r)
				{
					printf("The deleted operation at beginning is successfully performed: \n");
				}
				display(head,tail);					
				break;
									
			case 5:
				r=deleteend(&head,&tail);
				if(1==r)
				{
					printf("The deleted operation  at end is successfully performed: \n");
				}
				display(head,tail);
				break;

			case 6:
				printf("Enter the data to be deleted from the list:\n");
				scanf("%d",&w);
				r=deletemid(&head,&tail,w);
				if(r)
				{
					printf("The deleted operation is successfully performed: \n");
				}
				display(head,tail);
				break;

			case 7:
			        display(head,tail);
		       		break;

			default:
				printf("Enter choice is invalid\n");
			 	break;
		}

		printf("\nDO YOU WANT TO CONTINUE: IF YES PRESS 1 IF NO PRESS 0\n");
		scanf("%d",&b);
		}

	return;
}
int insertbeg(dnode **head,dnode **tail,int item)
{
	dnode *new;
	new=(dnode *)malloc(sizeof(dnode));
	if (NULL==new)
	{
		printf("memory allocation failure\n");
	}
	new->data=item;
	new->prev=NULL;
	if (NULL==*head)
	{
		new->next=NULL;
		*head=new;
		*tail=new;
	}
	else
	{
		new->next=*head;
		*head=new;
	}
	
	return SUCCESS;
}
int insertend(dnode **head,dnode **tail,int item)
{
	dnode *new;
	new=(dnode *)malloc(sizeof(dnode));
	if (NULL==new)
	{
		printf("memory allocation failure\n");
	}
	new->data=item;
	new->next=NULL;
	if (NULL==*head)
	{
		new->prev=NULL;
		*tail=new;
		*head=new;
	}
	else
	{
		new->prev=*tail;
		(*tail)->next=new;
		*tail=new;

	}
	
	return SUCCESS;
}
int insertmid(dnode **head,dnode **tail,int item)
{
	dnode *new;dnode *p,*q;
	new=(dnode *)malloc(sizeof(dnode));
	if (NULL==new)
	{
		printf("memory allocation failure\n");
	}
	new->data=item;
	if (NULL==*head)
	{
		new->prev=NULL;
		new->next=NULL;
		*tail=new;
		*head=new;
		return SUCCESS;
	}
	p=*head;
	if(item< (*head)->data)
	{
		new->prev=NULL;
		new->next=*head;
		(*head)->prev=new;
		(*head)=new;
		return SUCCESS;
	}
	if (item > (*tail)->data)
	{
		new->next=NULL;
		new->prev=*tail;
		(*tail)->next=new;
		*tail=new;
		return SUCCESS;
	}
	while(item > p->data)
	{	p=p->next;
	}
	q=p->prev;
	new->next=p;
	new->prev=q;
	q->next=new;
	p->prev=new;
	return SUCCESS;
}
int deletebeg(dnode **head,dnode **tail)
{
	dnode *p;int item;
	if (NULL==*head)
	{
		printf("list is empty\n");
	}
	p=*head;
	if(*head==*tail)
	{
		item=p->data;
		*head=NULL;
		*tail=NULL;
	}
	else
	{	
		item=p->data;
		*head=p->next;
		(*head)->prev=NULL;
		return SUCCESS;

	}
	free(p);
	p=NULL;
	return item;
}
int deleteend(dnode **head,dnode **tail)
{
	dnode *p;int item;
	if (NULL==*head)
	{
		printf("list is empty\n");
	}
	if(*head==*tail)
	{
		item=p->data;
		*head=NULL;
		*tail=NULL;
	}
	else
	{
		p=*tail;	
		item=p->data;
		*tail=p->prev;
		(*tail)->next=NULL;
		return SUCCESS;

	}
	free(p);
	p=NULL;
	return item;
}
int deletemid(dnode **head,dnode **tail,int item)
{
	dnode *p,*q,*r;int items;
	if (NULL==*head)
	{
		printf("list is empty\n");
	}
	p=*head;
	if (item==p->data)
	{	if(*head==*tail)
		{
			items=p->data;
			*head=NULL;
			*tail=NULL;
		}
		else
		{
			
			items=p->data;
			*head=p->next;
			(*head)->prev=NULL;
		}
		free(p);
		p=NULL;
		return items;	
	}
	p=*tail;
	if(item==p->data)
	{
		items=p->data;
		*tail=p->prev;
		(*tail)->next=NULL;
		free(p);
		p=NULL;
		return items;
	}
	p=(*head)->next;
	while(item > p->data && NULL!=p->next)
	{
		p=p->next;
	}
	if(item==p->data)
	{
		items=p->data;
		q=p->prev;
		r=p->next;
		q->next=r;
		r->prev=q;
	}
	else
	{ 
		printf("Item not found\n");
		return 0;
	}

	return items;
}
void display(dnode *head,dnode *tail)
{
	dnode *p;
	if(NULL==head)
	{
		printf("list is empty\n");
	}
	else
	{	printf("Elements in list are:\n");
		p=head;
		while(NULL!=p)
		{
			
			printf("%d\t",p->data);
			p=p->next;
		}
		return ;
	}
}


		

	

	




	







