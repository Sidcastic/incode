#include<stdio.h>
int main()
{
	int i,j,x=0,y=0,a[20];
	scanf("%d",&a[0]);
	for(i=1;i<=a[0];i++)
	{
		scanf("%d",&a[i]);
	}
	i=1;
	for(i=1;i<a[0];i++)
	{
		j=a[i+1]-a[i];
		if(j>0)
			x=1;
		else if(j<0)
			y=1;
		if(x==1&&y==1)
			break;
	}
	if(x==1&&y==1)
		printf("\nNO\n");
	else
		printf("\nYES\n");
	return 0;
}
