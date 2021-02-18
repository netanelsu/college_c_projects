/*assignment 3
campus: beer sheva
author:netanel sudai
id:316004878*/
#include<stdio.h>
#define N_ 14
#define M_ 10
//function decleration
int PrintDivided(int[],int,int);
void PrintMaxPalindrom(int[],int);
//main
int main()
{
 int value,one[N_],two[M_],i,div_num;
 float check;
 printf("please insert integer positive number\n");
 scanf("%d",&value);
 printf("please insert 14 numbers for the first array\n");
 for(i=0;i<N_;i=i)
   {
    scanf("%f",&check);
    if(check==(int)check)//input checking
     {
      one[i]=check;
      i++;
     }
   }
 printf("the divided numbers are:\n");
 div_num=PrintDivided(one,N_,value);//function activating 
 printf("\nthe number of divided in first array is:%d\n",div_num);
 printf("please insert 10 numbers for the second array\n");
 for(i=0;i<M_;)
   {
    scanf("%f",&check);
    if(check==(int)check)
     {
      two[i]=check;
      i++;
     }
   } 
 PrintMaxPalindrom(two,M_);//function activating
 return 0;
}
int PrintDivided(int arr[],int size,int value)//this function print the number are divides in the choosen integer and return the number of divides
{
 int i,j=0;
 if(value==0)
   return -1;
 else
  for(i=0;i<size;i++)
    {
     if(arr[i]%value==0)
      {
       printf("%d ",arr[i]);
       j++;
      }
    }
 return j;
}
void PrintMaxPalindrom(int arr[],int size)//this function find the longer palindrom and print it
{
 int i,j,start=0,end=0,start2=0,end2=0;
 for(i=0;i<size;i++)
   {
    for(j=size-1;j>=0;j--)
      {
       if(arr[i]==arr[j])
        {
	 start=i;
	 end=j;
         for(;i<j;i++,j--)
            {
	     if(arr[i]!=arr[j])
              {
	       i=start;
	       j=end;
               start=0;
	       end=0;
              }
	    }
         if((end-start)>(end2-start2))
  	  {
	   start2=start;
	   end2=end;
	  } 
        }
      } 
   }
 if(end2!=0)
  {
   for(;start2<=end2;start2++)
     {
      printf("%d ",arr[start2]);
     }
  }
 else
    printf("there is no palindrom\n");
}
