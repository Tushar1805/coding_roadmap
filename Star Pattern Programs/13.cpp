// * * * * *   * * * * *    *     * 
//     *       *       *    *   *
//     *       * * * * *    * *
//     *       *   *        *   * 
//     *       *     *      *     *
//     *       *       *            

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int n, m, o;  
  	printf("Enter any number: ");  
  	scanf("%d", &n);  
  	m = n * 2 - 1;
  	o = (n +1 ) / 2;
  	int count = (n/2) + 2;

  	// Initial 'T'
  	for(int i = 0;i <n+1;i++){
  		if (i == 0)
  		 {
  		     for (int j = 0; j < n; ++j)
  		     {
  		     	printf("* ");
  		     }
  		 } else{
  		 	for (int k = 0; k < n-1; ++k)
  		 	{
  		 		printf(" ");
  		 	}
  		 	printf("*");
		}
    printf("\n");  
  }  

  // // For Space between initials
  // for (int i = 0; i < n; ++i)
  // {
  // 	for (int j = 0; j < 2; ++j)
  // 	{
  // 		printf(" ");
  // 	}
  // 	printf("\n");
  // }
  printf("\n\n");

  // Initial 'R'
  // Upper part
  for (int i = 1; i <= n; ++i)
  {
  	for (int j = 1; j <= m; ++j)
  	{
  		if (i==1 || j==m || i == n || j == 1)
  			printf("* ");
  		else
  			printf("  ");
  	}
  	printf("\n");
  }
  //Lower part
  for (int i = 1; i < m; ++i)
  {
  	for (int j = 0; j < m; ++j)
  	{
  		if (i==j || j==0)
  			printf("* ");
  		else
  			printf("  ");
  	}
  	printf("\n");
  }
  printf("\n\n");

  // Initial 'K'

  for (int i = 1; i <= n; ++i)
  {
  	for (int j = 1; j <= n; ++j)
  	{
  		if (j==1 || count == j)
  		 	printf("* ");
  		else
  			printf("  ");
  	}
  	if (i < (n/2) + 1)
  	{
  		count--;
  	}else{
  		count++;
  	}
  	printf("\n");
  }
  return 0; 
}