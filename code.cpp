#include <stdio.h> 
int main() 
{ 

	int p, r, i, j, k,flag1,i1=0; 
	printf("Enter number of processes : ");
	scanf("%d",&p);
	printf("Enter number of resources : ");
	scanf("%d",&r);
	int alloc[p][r]; //Allocation maxtrix
			for(i=0;i<p;i++)
			{
				for(j=0;j<r;j++)
				{
					printf("Enter value of alloc[%d][%d] : ",i,j);
					scanf("%d",&alloc[i][j]);
				}
			}

	int max[p][r]; //MAX matrix
	        for(i=0;i<p;i++)
	        {
	            for(j=0;j<r;j++)
				{
				  	printf("Enter value of max[%d][%d] : ",i,j);
					scanf("%d",&max[i][j]);
				}	
			}
    int avail1[p][r];
    int avail2[r];
	int avail[r]; // Available Resources 
	        for(j=0;j<r;j++)
	        {
	        	printf("Enter value of avail[%d] : ",j);
				scanf("%d",&avail[j]);
				avail2[j]=avail[j];
			}
			
	int f[p], ans[p], ind = 0; 
	for (k = 0; k < p; k++) { 
		f[k] = 0; 
	} 
	int need[p][r]; 
	for (i = 0; i < p; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < p; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				flag1=flag;
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1;
						flag1=flag; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
					{
						avail[y] += alloc[i][y]; 
						avail1[i1][y]=avail[y];
					}
					i1++;
					f[i] = 1; 
				} 
			} 
		} 
	} 
    if(flag1==0)
    {
    	printf("ALLOCATION MATRIX");
    	for(i=0;i<p;i++)
    	{   printf("\nP%d  ",i);
    		for(j=0;j<r;j++)
    		{
    			printf("%d ",alloc[i][j]);
			}
		}
		printf("\nMAX MATRIX");
    	for(i=0;i<p;i++)
    	{   printf("\nP%d  ",i);
    		for(j=0;j<r;j++)
    		{
    			printf("%d ",max[i][j]);
			}
		}
		printf("\nAVAILABLE MATRIX\n");
		for(i=0;i<r;i++)
		{
			printf("%d ",avail2[i]); 
		 } 
    	for(i=0;i<p;i++)
    	{   printf("\n");
    		for(j=0;j<r;j++)
    		{
    			printf("%d ",avail1[i][j]);
			}
		}
		printf("\nNEED MATRIX");
    	for(i=0;i<p;i++)
    	{   printf("\nP%d  ",i);
    		for(j=0;j<r;j++)
    		{
    			printf("%d ",need[i][j]);
			}
		}
	printf("\nSAFE Sequence of the given inputs is\n"); 
	for (i = 0; i < p - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[p - 1]); 
    }
    else
    {
    	printf("         It is in Deadlock state");
	}
	return (0); 

}
