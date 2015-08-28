#include<stdio.h>
int fact(int x)
{
	if(x==0)
		return 1;
	return x*fact(x-1);
}
int comb(int x,int y)
{
	int res;
	res=fact(x)/(fact(y)*fact(x-y));
	return res;
}
int main()
{
	int b,l,base,i,j,arr[500],k=0,a=0;
	system("clear");
	printf("Enter the base\n");	
	scanf("%d",&b);
	base=b;
	printf("Enter the number of lines\n");	
	scanf("%d",&l);
	for(i=0;i<=l;i++)
	{

		for(j=0;j<=b;j++)
		{
			arr[k++]=comb(b,j);
		}
		b++;
	}
	b=0;
	for (i = 0; i < l; i++)
	{
		for (k = l-1; k >= i; k--)
			if(b>=base)
				printf(" ");    
        for (j = 0; j <= (i); j++)
	{
		if(b>=base)
			printf("%d ",arr[a++]);
		else
			a++;
	}
	if(b>=base)		
		printf("\n");
	b++;   
    }
	return 0;
}	