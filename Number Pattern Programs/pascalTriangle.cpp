//         1
//       1   1
//     1   2   1
//   1   3   3   1
// 1   4   6   4   1

#include<stdio.h>
int main(int argc, char const *argv[])
{
  int rows, i, j, k, l, value = 1;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  l = rows;
  for ( i = 0; i < rows; ++i)
  {
    for ( k = 0; k < l - 1; ++k)
    {
      printf(" ");
    }
    for ( j = 0; j <= i; ++j)
    {
      if (i == 0 || j == 0)
      {
        value = 1;
      }else{
         value = value * (i-j+1) / j;
      }
      printf("%d ", value);
    }
    l--;
    printf("\n");
  }
  return 0;
}