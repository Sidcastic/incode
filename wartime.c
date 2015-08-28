#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int test,i,value[100],j,k,n,m,temp;
	unsigned long long int ans;
	double c,x,y;
	char strin[100];
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		m=-1;
		scanf("%s",strin);
		n=strlen(strin);
		for(j=0;j<n;j++)
			value[j]=-1;
		value[0]=1;
		for(j=0;j<n;j++)
		{	
			if((value[j]<0)||(j==0))
			{
				if(m==1) m++;
				if(j!=0)
					value[j]=m;
				for(k=j+1;k<n;k++)
				{
					if(strin[j]==strin[k])
					{
						value[k]=value[j];
					}
				}
				m++;
			}
		}
		ans=0;
		if(m==1||m==0) m=2;
		x=m;
		k=n-1;
		j=0;
		while(k>=0)
		{	
			y=k;
			c=pow(x,y);
			ans+=(value[j]*c);
			j++;
			k--;
		}
		printf("Case #%d: %llu\n",i+1,ans);
		
			
		
	}
	return 0;
}			
					
		
			