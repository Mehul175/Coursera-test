//Aim: Implement a program to solve problem of making change using dynamic programming.
 
#include<stdio.h>
#define infinite 999
int min(int a,int b)
{
	if(a<b)
		return a;
	return b; 
}
void makingChange_DP(int d, int denom[], int change)
{
	int c[d+1][change+1],i,j,k=0;
	int chnge[20];
	for(i=0;i<=d;i++)
	{
		for(j=0;j<=change;j++)
		{
			if(i==0 || j ==0)
			{
				c[i][j]=0; 
			}
			else if(i==1 && j<denom[i])
			{
				c[i][j]=infinite; //Not possible 
			}
			else if(i==1)
			{
				if(c[i][j-denom[i]]==infinite)
					c[i][j]=infinite;
				else
					c[i][j]=1+c[i][j-denom[i]];
			}
			else if(j<denom[i]) 
				c[i][j]=c[i-1][j];
			else	
				c[i][j]=min(c[i-1][j], 1+c[i][j-denom[i]]);
		}
	}
	printf("\n");
	//printing the matrix 
	
	/*for(i=0;i<change+1;i++)
	{
		printf("\t%d",i);
	}
	printf("\n");
	for(i=0;i<d+1;i++)
	{	printf("d=%d",denom[i]);
		for(j=0;j<change+1;j++)
		{
			printf("\t%d", c[i][j]);
		}
		printf("\n");
	}*/
	printf("The number of coins required are %d\n", c[d][change]);
	//estimating actual denoms required
	i=d;
	j=change;
	while(change>0)
	{
		while(c[i-1][j]==c[i][j])
		{
			i--;
		}
		change = change - denom[i]; 
		chnge[k] = denom[i];  //Add denom to solution array 
		k++;
		j=change; 		
	}
	printf("The coins used: ");
	//printing answer
	for(i=0;i<k;i++)
	{
		printf("%d\t",chnge[i]);
	}
	
}

int main()
{
	int i,j,change,denom[20],d;
	denom[0]=0;
	printf("Enter no.of denoms available: ");
	scanf("%d",&d);
	printf("Enter denoms: ");
	for(i=1;i<=d;i++)
	{
		scanf("%d",&denom[i]);
	}
	printf("Enter change that you want to make: ");
	scanf("%d",&change);
	makingChange_DP(d,denom,change);
	return 0;
}
