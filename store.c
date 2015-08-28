#include<stdio.h>
int main()
{
		int test,credit,items,price[2000],p1[50],p2[50];
		int i,j,k;
		scanf("%d",&test);
		for(i=0;i<test;i++)
		{
			scanf("%d",&credit);
			scanf("%d",&items);
			for(j=0;j<items;j++)
				scanf("%d",&price[j]);
			for(j=0;j<items;j++)
				for(k=j+1;k<items;k++)
					if((credit-price[j])==price[k])
							goto label;
			label:p1[i]=j+1;
			 p2[i]=k+1;
		}
		for(i=0;i<test;i++)
			printf("Case #%d: %d %d\n",i+1,p1[i],p2[i]);
		return 0;
}

							
						