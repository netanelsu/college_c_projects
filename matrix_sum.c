/*assignment 3
beer sheva
netanel sudai
316004878
*/
#include<stdio.h>
#define N_ 4
//function decleration
void MatrixFill(int[][N_],int);
int Ring(int[][N_],int);
int AllRings(int[][N_]);
//main program
int main()
{
 int matrix[N_][N_],id,sum=0;
 MatrixFill(matrix,N_);//fuction activating
 printf("please insert integer for ring number\n");
 scanf("%d",&id); 
 sum=Ring(matrix,id);//function activating
 if(sum!=0)
   printf("the sum of ring %d is:%d\n\n",id,sum);
 else
   printf("illigal number of ring\n\n");
 sum=AllRings(matrix);
 printf("the sum of all the matrix is:%d\n",sum);
 return 0;
}
void MatrixFill(int mat[][N_],int size)//this function filling the matrix
{
 int i,j;
 printf("please insert integers numbers for matrix\n"); 
 for(i=0;i<N_;i++)
   {
    for(j=0;j<N_;j++)
      {
       scanf("%d",&mat[i][j]);
      }
   }
}
int Ring(int mat[][N_],int ring)//this function calculate the sum of choosen ring
{
 int rings,sum=0,i,j;
 if(N_%2==0)
   rings=N_/2;
 else
     rings=N_/2+1;
 if(ring>=0&&ring<rings)
  {
   for(i=ring;i<=N_-ring-1;i++)
     {
      for(j=ring;j<=N_-ring-1;j++)
        {
         if(i==ring||i==N_-ring-1||j==ring||j==N_-ring-1)
           sum+=mat[i][j];
	}
     }
   return sum;
  }
 else
    return 0; 
}
int AllRings(int mat[][N_])//this function calculate the sum of all rings
{
 int i,sum=0,total_sum=0,rings;
 if(N_%2==0)
   rings=N_/2;
 else
     rings=N_/2+1;
 for(i=0;i<rings;i++)
   {
    sum=Ring(mat,i);
    printf("the sum of ring %d is: %d\n",i,sum);
    total_sum+=sum;
   }
 return total_sum;
}
