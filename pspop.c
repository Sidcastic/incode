#include<stdio.h>
#include<malloc.h>
struct stack
{
	int *a;
	
	int top;
	int maxsize;
};
void initstack(struct stack *p,int maxsize);
void push(struct stack *p, int item);
void display(struct stack *p);
int pop(struct stack *p);
void printmenu();

int main()
{
	struct stack *p;
	int data,ch,data1,m;
	printf("Enter the maximum size of the stack\n");
	scanf("%d",&m);
	initstack(p,m);
	do
	{
		printmenu();
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be pushed\n");
				scanf("%d",&data);
				push(p,data);
				break;
			case 2:data1=pop(p);
				if(data1!=-1000)
					printf("The popped element is %d\n",data1);
				break;
			case 3:printf("the contents of the stack are");
				display(p);
				printf("\n");
				break;
			default:return 0;
		}
	}while(1);
	return 0;
}
void printmenu()
{
	printf("Choice 1 : Push\n");
	printf("Choice 2 : Pop\n");
	printf("Choice 3 : Display\n");
	printf("Any other choice : Exit\n");
}
void initstack(struct stack *p,int msize)
{
	p->a=(int *)calloc(msize,sizeof(int));	
	p->maxsize=msize-1;
	p->top=-1;
}
void push(struct stack *p,int item)
{
	if((p->top)<(p->maxsize))
		p->a[++p->top]=item;
	else
		printf("Stack Full\n");
			
}				
void display(struct stack *p)
{
	int i;
	for(i=0;i<=p->top;i++)
		printf("\t%d\t",p->a[i]);
}
int pop(struct stack *p)
{
	if(p->top==-1)
	{
		printf("Stack is empty\n");
		return -1000;
	}
	return p->a[p->top--];
}