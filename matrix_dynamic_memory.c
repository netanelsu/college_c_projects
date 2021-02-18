/*assignment 4
 beer sheva
 netanel sudai
 316004878 */
#include<stdio.h>
#include<stdlib.h>
//function decleration
void BuildMatrix(int***,int,int);
void PrintMatrix(int**,int,int);
void FreeMatrix(int***,int);
void AddRow(int***,int*,int,int*,int);
void BuildGroup(int**,int);
void RemoveColumn(int***,int,int*,int);
void GetMinMax(int**,int,int,int*,int*);
//main
int main()
{
 int row,col,**matrix=NULL,i,*newRow,columns,recol,Min,Max;
 printf("please insert row number and col number\n");
 scanf("%d %d",&row,&col);
 BuildMatrix(&matrix,row,col);
 printf("the matrix is:\n");
 PrintMatrix(matrix,row,col);
 printf("please insert the new row columns size\n");
 scanf("%d",&columns);
 BuildGroup(&newRow,columns);
 AddRow(&matrix,&row,col,newRow,columns);
 printf("%d",row); 
 printf("the new matrix is:\n");
 PrintMatrix(matrix,row,col);
 printf("please choose column number to remove from 0 to %d\n",col-1);
 scanf("%d",&recol);
 RemoveColumn(&matrix,row,&col,recol);
 printf("the new matrix is:\n");
 PrintMatrix(matrix,row,col);
 GetMinMax(matrix,row,col,&Min,&Max);
 printf("the max value is:%d\nand the min value is:%d\n",Max,Min);
 FreeMatrix(&matrix,row);
 matrix=NULL;
return 0;
}
void BuildMatrix(int ***matrix,int row,int column)//this finction build the matrix
{
 int i,j;
 (*matrix)=(int**)malloc(row*sizeof(int*));
 for(i=0;i<row;i++)
   (*matrix)[i]=(int*)malloc(column*sizeof(int));
 printf("please fill the matrix\n");
 for(i=0;i<row;i++)
   for(j=0;j<column;j++)
     scanf("%d",&(*matrix)[i][j]);
}
void PrintMatrix(int **matrix,int row,int column)//print the matrix
{
 int i,j;
 for(i=0;i<row;i++)
   for(j=0;j<column;j++)
     {
      printf("%d ",matrix[i][j]);
      if(j==(column-1))
        printf("\n");
     }
}
void FreeMatrix(int ***matrix,int row)//free the dynamic memory
{
 int i;
 for(i=0;i<row;i++)
    free((*matrix)[i]);
 free((*matrix));
} 
void AddRow(int ***matrix,int *pRow,int column,int *newRow,int columns)//add row to the matrix
{
 int i;
 if(columns==column)
  {
   (*pRow)++;
   (*matrix)=(int**)realloc((*matrix),(*pRow)*sizeof(int*));
   (*matrix)[(*pRow)-1]=(int*)malloc(column*sizeof(int)); 
   for(i=0;i<columns;i++)
      (*matrix)[((*pRow)-1)][i]=newRow[i];
  }
 else
   printf("incorrect column size\n");
}
void BuildGroup(int **newRow,int columns)//build array
{
 int i;
 (*newRow)=(int*)malloc(columns*sizeof(int));
 printf("please fill the row\n");
 for(i=0;i<columns;i++)
    scanf("%d",&(*newRow)[i]);
}
void RemoveColumn(int ***matrix,int row,int *col,int recol)//remove column from the matrix
{
 int i,j,l,**mat;
 if(recol<(*col))
  {
   (*col)--;
   mat=(int**)malloc(row*sizeof(int*));
   for(i=0;i<row;i++)
      mat[i]=(int*)malloc((*col)*sizeof(int));
   for(i=0;i<row;i++)
     for(j=0,l=0;j<((*col)+1);j++)
        if(j!=recol)
         {
          mat[i][l]=(*matrix)[i][j];
          l++;
         }
   (*matrix)=NULL;
   (*matrix)=mat; 
  }
 else
   printf("incorrect col number\n");
}
void GetMinMax(int **matrix,int row,int col,int *pMin,int *pMax)//this function print the min and the max value in the matrix
{
 int i,j;
 *pMin=*pMax=matrix[0][0];
 for(i=0;i<row;i++)
   for(j=0;j<col;j++)
     {
      if(matrix[i][j]>(*pMax))
        (*pMax)=matrix[i][j];
      if(matrix[i][j]<(*pMin))
        (*pMin)=matrix[i][j];
     }
}
