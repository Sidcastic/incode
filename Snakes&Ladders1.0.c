#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int p1,p2,snl[101],i,taunt=0,nbrd[11][11],cross=0;
char player1[20],player2[20],cbrd[11][11],bbrd[11][11];
void assign()
{
	for(i=1;i<=100;i++)
	{
		snl[i]=0;
	}
	snl[4]=10;snl[9]=22;snl[16]=-10;snl[21]=21;snl[28]=56;snl[36]=8;snl[47]=-21;snl[49]=-38;snl[51]=16;snl[56]=-3;snl[62]=-43;snl[64]=-4;
	snl[71]=20;snl[80]=20;snl[93]=-20;snl[95]=-20;snl[98]=-20;
}
void board()
{
	int j,i,m=100,x;
	x=1;
	for(i=1;i<=10;i++)
	{
		x=0-x;
		for(j=1;j<=10;j++)
		{
			nbrd[i][j]=m;
			bbrd[i][j]='#';
			m=m+x;
		}
		if(x>0)
		{
			m=m-11;
			
		}
		if(x<0)
		{
			m=m-9;
		}
	}
	for(i=1;i<=10;i++)
	 {
		printf("\n\t\t\t");
		for(j=1;j<=10;j++)
			printf("%d\t",nbrd[i][j]);
	 }
		
	
}
				
void setboard()
{
	int i,j;
	 for(i=1;i<=10;i++)
	 {
		for(j=1;j<=10;j++)
			cbrd[i][j]=bbrd[i][j];
	 }
	 for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
		{
			if(nbrd[i][j]%10==0&&nbrd[i][j]!=100)
			{
				cbrd[i][j]='^';
				if(j==10)
					cbrd[i-1][j]='<';
				if(j==1)
					cbrd[i-1][j]='>';
			}
					
		}
			cbrd[1][1]='E';
			cbrd[10][1]='A';
} 			
int delay()
{
	char yuy;
	printf("\npress enter\n");
	scanf("%c",&yuy);
	return 1;
}
int csnl(int cp)
{	int vp;
	vp=cp+snl[cp];
	if(snl[cp]<0)
		printf("\n\t\t\toohhh!!...you've hit a snake, you go down %d \n",abs(snl[cp]));
	if(snl[cp]>0)
		printf("\n\t\t\tYaay!!...you've hit a ladder, climb up %d \n",snl[cp]);	
	return vp;
}
void taunts(int cp,int diff)
{
	int sdm;
	if (taunt==1)
	{
		if(diff>0)
		{
			if(diff==0)
			{
				printf("\n\t\t!!ITS STILL ANYONE'S GAME!!\n\n\t");
			}
			else if(diff>0&&diff<=10)
			{
				printf("\n\t\t!!KEEP GOING, DEM PLAYERZ JUST BEHIND YOU!!\n\n\t");
			}
			else if(diff>10&&diff<=20)
			{
				printf("\n\t\t!!YOU CAN BREATHE!!\n\n\t");
			}	
			else if(diff>20&&diff<=49)
			{
				printf("\n\t\t!!GETTING BETTER!!\n\n\t");
			}
			else if(diff==50)
			{
				printf("\n\t\t!!YOU ARE HALF THE BOARD AWAY FROM THE LOSER ;-)!!\n\n\t");
			}
			else if(diff>50&&diff<=70)
			{
				printf("\n\t\t!!SMOOTH SAILING!!\n\n\t");
			}
			else if(diff<94)
			{
				printf("\n\t\t!!JUST FINISH IT!!\n\n\t");
			}
		}
		if(diff<0)
		{
			diff=abs(diff);
			if(diff==0)
			{
				printf("\n\t\t!!ITS STILL ANYONE'S GAME!!\n\n\t");
			}
			else if(diff>0&&diff<=10)
			{
				printf("\n\t\t!!YOU ARE BEING LEFT BEHIND!!\n\n\t");
			}
			else if(diff>10&&diff<=20)
			{
				printf("\n\t\t!!YOU DAMN FAR!!\n\n\t");
			}	
			else if(diff>20&&diff<=49)
			{
				printf("\n\t\t!!YOU SO FUCKIN FAR!!\n\n\t");
			}
			else if(diff==50)
			{
				printf("\n\t\t!!YOU DAMN REALLY FUCKIN FAR NOW ;-)!!\n\n\t");
			}
			else if(diff>50&&diff<=70)
			{
				printf("\n\t\t!!WHATS THE POINT OF YOU ROLLING!!\n\n\t");
			}
			else if(diff<94)
			{
				printf("\n\t\t!!GIVE UP NOW!!\n\n\t");
			}
		}	
		if(cp>94&&cp<100)
			printf("\n\t\t!!YOU ARE JUST A ROLL AWAY!!\n\n\t");
	}
	if(p1-p2>0&&cross<0||p1-p2<0&&cross>0)
	{
		printf("\n\t\t!!THE TABLES HAVE TURNED!!\n\n\t");
		cross=-cross;
	}
		
}
		
int dice(int cp)
{
	int v,w,n,rem,track=0,x,y,z;
	char key;
	chance:
	taunt=0;
	scanf("%c",&key);
			
	while(1)
	{
		srand(time(NULL));
		v=rand();
		rem=v%10;
		w=rand();
		x=w%15;
		y=w%23;
		z=(x+y+47)/8;
		if(z%2==0)
			taunt=1;
		if(rem<=6&&rem>0)
		{
			printf("\n %d has been rolled\n",rem); 
			break;
		}
	}
	if(rem==6)
	{		
		track+=6;
		if(track==18)
			printf("\n\t HATRICK!!!\t\n");
		if(track==30)
			printf("\n\t YOU ON FIRE!!\t\n");
		if(cp+track>100)
		{	
				printf("\n\tJust missed the finish line!!!!..But you still have a roll..try again ;-D");
				track=rem=0;
				goto chance;
		}
		printf("\nYou get another chance!!..ROLL again\n");
		goto chance;
	}
	track+=rem;
	if(cp+track>100)
	{
		printf("\n\tJust missed the finish line!!!!..Better luck next round ;-D");
		track=0;
	}
	return track;
}

void scored()
{
	printf("\n\t\t\t %s at %d and %s at %d\n",player1,p1,player2,p2);
}
void printboard()
{
	 int i,j;
	 for(i=1;i<=10;i++)
	 {
		printf("\n\t\t\t");
		for(j=1;j<=10;j++)
			printf("%c\t",cbrd[i][j]);
	 }
}
void boardisp(int cp,int np,int mode)
{
	int i,j,k;
	char x,y;
	setboard();
	if(mode==1)
		{
			x='1';
			y='2';
		}
	else if(mode==0)
		{
			x='2';
			y='1';
		}
	else if(cp==np)	
		x=y='&';		
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
		{
			if(snl[nbrd[i][j]]>0)
				cbrd[i][j]='L';
			if(snl[nbrd[i][j]]<0)
				cbrd[i][j]='S';
			if(nbrd[i][j]==cp)
				cbrd[i][j]=x;
			else if(nbrd[i][j]==np)
				cbrd[i][j]=y;
				
		}
		printboard();
}
int main()
{
	int j,set,count=0;
	assign();
	start:
	p1=p2=0;
	system("clear");
	printf("Enter the name of the 1st player: ");
	scanf("%s",player1);
	printf("\n\nEnter the name of the 2nd player: ");
	scanf("%s",player2);
	delay();
	system("clear");
	board();
	delay();
	system("clear");
	while(1)
	{
		if(count==6)
		{
			printf("\n\tCOME ON!!...SOMEONE ROLL A ONE!!!\n");
			count=0;
		}
			
		printf(" %s, roll (press enter) 1 to start \n",player1);		
			if(dice(p1)==1)
			{
				p1=1;
				p2=0;
				printf("\n\t\t %s starts\n",player1);
				break;
			}
		delay();
		system("clear");
		printf("%s, roll (press enter) 1 to start \n",player2);		
			if(dice(p2)==1)
			{
				p2=1;
				p1=0;
				printf("\n\t\t %s starts\n",player2); 
				break;
			}
		delay();
		system("clear");
		count++;
	}
	delay();
	system("clear");
	printf("\t\t\t\tLET THE GAMES BEGIN \n");
	scored();
	cross=p1-p2;
	if(p1==1) goto start1;
	if(p2==1) goto start2;
	while(1)
	{
		start1: printf("\n %s ,Press enter to roll the dice\n ",player1);
		p1=p1+dice(p1);
		p1=csnl(p1);
		boardisp(p1,p2,1);
		if(p1==100) break;
		taunts(p1,p1-p2);
		scored();
		delay();
		system("clear");
		scored();
		
		start2: printf("\n %s ,press any key to roll the dice\n ",player2);
		p2=p2+dice(p2);
		p2=csnl(p2);
		boardisp(p2,p1,0);
		if(p2==100) break;
		taunts(p2,p2-p1);
		scored();
		delay();
		system("clear");
		scored();
	}
	i=0;
	scored();
	while(i<1000)
	{
		if(p1==100)
			printf("\t\t %s WINS!!!!!!!",player1);
		if(p2==100)
			printf("\t\t %s WINS!!!!!!!",player2);
		for(j=0;j<=999999;j++);
		i++;
	}
	printf("Press 1 to play again");
	scanf("%d",&set);
	if(set==1)
		goto start;
	return 0;
}