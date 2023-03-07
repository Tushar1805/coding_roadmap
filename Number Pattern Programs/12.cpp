// ************* 1 **************

//     1
//    2 1
//   3 2 1
//  4 3 2 1
// 5 4 3 2 1

// ************* 2 **************

//     1
//    2 2
//   3 3 3
//  4 4 4 4
// 5 5 5 5 5

#include<stdio.h>
int main(int argc, char const *argv[])
{
  int rows, i, j, k, l;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  l = rows;
  for ( i = 1; i <= rows; ++i)
  {
    for ( k = 0; k < l - 1; ++k)
    {
      printf(" ");
    }

    // for 1
    for ( j = i; j >= 1; --j)
    {
      printf("%d ", j);
    }

    // for 2
    // for ( j = i; j >= 1; --j)
    // {
    //   printf("%d ", i);
    // }

    l--;
    printf("\n");
  }
  return 0;
}