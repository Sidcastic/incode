#include<stdio.h>
#include<string.h>
typedef struct
{
	char instr[25],outstr[25];
}str;
int main()
{
	char space[20];
	int test,i,j,k,c,l;
	str s[5];
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		k=0;
		c=0;
		scanf("%s",s[i].instr);
		for(j=0;j<strlen(s[i].instr);j++)
		{
			if(s[i].instr[j]=='\t')
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
			while((s[i].instr[j]!='\t')&&(s[i].instr[j]!='\0'))
			{
				s[i].outstr[l++]=s[i].instr[j++];
			}
			if(s[i].instr[j]=='\t') s[i].outstr[l++]='\t';
		}
	}
	for(i=0;i<test;i++)
		printf("Case #%d: %s\n",i+1,s[i].outstr);
	return 0;
}