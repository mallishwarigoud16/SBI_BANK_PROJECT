#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	int alloc[10][10],max[10][10],need[10][10];
	int available[10],safeseq[10];
	int finished[10]={0};
	int count=0;
	printf("enter number of processes:");
	scanf("%d",&n);
	printf("enter number of resource type:");
	scanf("%d",&m);
	printf("enter allocation matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("enter max matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("enter available resource:\n");
	for(i=0;i<m;i++)
	   scanf("%d",&available[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\nNeed matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d",need[i][j]);
		}
		printf("\n");
	}
	while(count<n)
	{
		int found=0;
		for(i=0;i<n;i++)
		{
			if(!finished[i])
			{
				int flag=1;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>available[j])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				{
					for(k=0;k<m;k++)
					available[k]=available[k]+alloc[i][k];
					
					safeseq[count++]=i;
					finished[i]=1;
					found=1;
				}
			}
		}
		if(!found)
        {
        	printf("\nsystem is in DEADLOCK state!\n");
        	return 0;
		}
	}
	printf("\nsystem is in SAFE state.\nsafesequence:");
	for(i=0;i<n;i++)
	{
		printf("p%d",safeseq[i]);
	}
	printf("\n");
	return 0;
}
