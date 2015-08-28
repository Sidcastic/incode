#include<stdio.h>
#include<string.h>
int main()
{
	char txt[9][4],mess,strin[100];
	int numrep[100],i,j,k=0,l,m=0,n=0,t;
	txt[2][1]='a';txt[2][2]='b';txt[2][3]='c';txt[3][1]='d';txt[3][2]='e';txt[3][3]='f';txt[4][1]='g';txt[4][2]='h';txt[4][3]='i';txt[5][1]='j';txt[5][2]='k';txt[5][3]='l';txt[6][1]='m';txt[6][2]='n';txt[6][3]='o';txt[7][1]='p';txt[7][2]='q';txt[7][3]='r';txt[7][4]='s';txt[8][1]='t';txt[8][2]='u';txt[8][3]='v';txt[9][1]='w';txt[9][2]='x';txt[9][3]='y';txt[9][4]='z';txt[0][1]='\t';
	scanf("%[^\n]",strin);
	for(t=0;t<strin[t]!='\0';t++)
		printf("%c",strin[t]);
	for(t=0;strin[t]!='\0';t++)
	{
		for(i=0;i<=9;i++)
		{
			for(j=1;j<=4;j++)
			{
				if(strin[t]==txt[i][j])
					goto label;
			}				
		}		
		label:if(n==i)
		{
			numrep[k]=-1;
			k++;
			m++;
		}
		n=i;
		for(l=0;l<j;l++)
		{
			numrep[k]=i;
			k++;
			m++;
		}
		
	}
	for(i=0;i<m;i++)
		printf("%d",numrep[i]);
	return 0;
}	
					
				
	
		