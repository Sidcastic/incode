#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned long int cell[10008],brb,q,p,cdno[108];
	unsigned long int i,j,k,u,d,ulr,llr,cu,cl,x,y;
	int test;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		scanf("%lu",&p);
		scanf("%lu",&q);
		for(j=1;j<=q;j++)
			scanf("%lu",&cdno[j]);
		for(j=1;j<=p;j++)
			cell[j]=1;	
		brb=0;
		cl=cdno[1];
		cu=cdno[q];
		x=1;
		y=q;
		llr=1;
		ulr=p;
		for(k=1;k<=q;k++)
		{	
			if((cl-llr)>(ulr-cu))
			{
				j=cl;
				llr=cl+1;
				cl=cdno[++x];
			}
			else if((cl-llr)<=(ulr-cu))
			{
				j=cu;
				ulr=cu-1;
				cu=cdno[--y];
			}		
			
			cell[j]=0;
			for(u=j+1;u<=p;u++)
			{
				if(cell[u]==0) break;
				brb++;
			}
			for(d=j-1;d>0;d--)
			{
				if(cell[d]==0) break;
				brb++;
			}
		}
		printf("Case #%lu: %lu\n",i,brb);
	}
	return 0;
}		
				
				