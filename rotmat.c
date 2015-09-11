#include<stdio.h>
#include<omp.h>
int a[100][100],temp;

void dcol(int i,int m,int n)
{
	int x,y;
	y=a[i][i];
	for(x=i+1;x<=m;x++)
	{
		temp=a[x][i];
		a[x][i]=y;
		y=temp;
	}
	temp=y;
		
}
void rrow(int i,int m,int n)
{
	int x,y;
	y=temp;
	for(x=i+1;x<=n;x++)
	{
		temp=a[m][x];
		a[m][x]=y;
		y=temp;
	}
	temp=y;
}
void ucol(int i,int m,int n)
{
	int x,y;
	y=temp;
	for(x=m-1;x>=i;x--)
	{
		temp=a[x][n];
		a[x][n]=y;
		y=temp;
	}
	temp=y;
}
void lrow(int i,int m,int n)
{
	int x,y;
	y=temp;
	for(x=n-1;x>i;x--)
	{
		temp=a[i][x];
		a[i][x]=y;
		y=temp;
	}
	a[i][i]=y;
}	
int main()
{
	int b,c,i=1,m,n,j,k,r;
	printf("Enter the matrix dimension:\n rows :");
	scanf("%d",&m);
	printf("\ncolumns :");
	scanf("%d",&n);
	printf("Enter the matrix:\n");
	for(j=1;j<=m;j++)
		for(k=1;k<=n;k++)
			scanf("%d",&a[j][k]);
	printf("Enter the number of anticlockwise rotations :");
	scanf("%d",&r);
	printf("\nThe original matrix :\n");
	for(j=1;j<=m;j++)
	{
		for(k=1;k<=n;k++)
			printf("\t%d",a[j][k]);
		printf("\n");
	}
	b=m;
	c=n;
	#pragma omp parallel for
	for(;i!=m&&i!=n;i++,m--,n--)
	{
		for(j=0;j<r;j++)
		{
			dcol(i,m,n);
			rrow(i,m,n);
			ucol(i,m,n);
			lrow(i,m,n);	
		}
	}
	printf("\nThe matrix rotated %d times anticlockwise :\n",r);
	for(j=1;j<=b;j++)
	{
		for(k=1;k<=c;k++)
			printf("\t%d",a[j][k]);
		printf("\n");
	}
	return 0;
}	