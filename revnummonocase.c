#include<stdio.h>
#include<string.h>
int main()
{
	char space[20],instr[25],outstr[25];
	int i,j,k,c,l;
		k=0;
		c=0;
		for(i=0;i<10;i++)
			scanf("%c",&instr[i]);
		for(j=0;j<10;j++)
		{
			if(instr[j]=='\t')
			{
				space[k]=j;
				k++;
				c++;
			}
		}
		l=0;
		for(k=c-1;k>=0;k--)
		{
			j=k+1;
			while(instr[j]!='\t')
			{
				outstr[l++]=instr[j++];
			}
			if(instr[j]=='\t') outstr[l++]='\t';
		}
	
		for(i=0;i<10;i++)
			printf("%c",outstr[i]);
	return 0;
}