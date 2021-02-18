/*
assignment 5
beer sheva
netanel sudai
316004878
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ZERO 0
#define TWO 2
#define TEN 10
#define LEN 80
#define FIVE 5
typedef enum{false,true}BOOL;
//finction decleration
int MinDigit(long);
int DecToBin(int);
int BuildGroup(int**,int*);
BOOL Odd(int*,int);
int EvenSum(int*,int);
void SumGroup(int*,int);
int StringLen(char*);
int StrComp(char*,char*);
void MaxLen(char**,int,int*,int*);
//main
int main()
{
 long num1;
 int minDigit,DecNum,*group,arSize,i=0,evenSum=0,len,cmp=0,longwords=0,maxlen=0;
 char str[LEN],str1[LEN],str2[LEN];
 char *text[]={"test","correct","data","one","replace"};
 BOOL odd;
 printf("please insert integer number\n");
 scanf("%ld",&num1);
 if(num1==ZERO)
   minDigit=ZERO;
 else
 minDigit=MinDigit(num1);
 printf("the min dig is:%d\n",minDigit);
 printf("please insert decimal number\n");
 scanf("%d",&DecNum);
 DecNum=DecToBin(DecNum);
 printf("the number in binary base is: %d\n",DecNum);
 BuildGroup(&group,&arSize);
 odd=Odd(group,arSize);
 if(odd==false)
   printf("not all the numbers are odd\n");
 else
   printf("all the numbers are odd\n");
 evenSum=EvenSum(group,arSize);
 printf("the sum of the even digits is:%d\n",evenSum);
 printf("the group of sums is:\n");
 SumGroup(group,arSize);
 for(i=ZERO;i<arSize;i++)
    printf("%d ",group[i]);
 printf("\n");
 getchar();
 printf("please insert string\n");
 fgets(str,LEN,stdin);
 if(str[strlen(str)-1]=='\n')
   str[strlen(str)-1]='\0';
 len=StringLen(str);
 printf("the size of the string '%s' is:%d\n",str,len);
 printf("please insert two string for comparing\n");
 fgets(str1,LEN,stdin);
 if(str1[strlen(str1)-1]=='\n')
   str1[strlen(str1)-1]='\0';
 fgets(str2,LEN,stdin);
 if(str2[strlen(str2)-1]=='\n')
   str2[strlen(str2)-1]='\0';
 cmp=StrComp(str1,str2);
 switch (cmp)
      {
       case 1:
             printf("the string '%s' is bigger then the string '%s'\n",str1,str2);
             break;
       case -1:
             printf("the string '%s' is bigger then the string '%s'\n",str2,str1);
	     break;
       case 0:
             printf("the string '%s' is equal to the string '%s'\n",str1,str2);
             break;
      }
 MaxLen(text,FIVE,&longwords,&maxlen);
 printf("in the text:\n");
 for(i=0;i<FIVE;i++)
    printf("%s\n",text[i]);
 printf("there is %d words  with %d letters\n",longwords,maxlen);
 return ZERO;
}
int MinDigit(long num)//return the little digit of the number
{
 int y,x;
 if(num<ZERO)
   num*=(-1);
 if(num>ZERO)
  {
   y=num%TEN;
   x=MinDigit(num/TEN);
   if(y<x)
     return y;
   else
     return x;
  }
 else
   return TEN; 
}
int DecToBin(int dec)//get decimal number and convert it to binary
{
 if(dec==ZERO||dec==1)
   return dec;
 if(dec%TWO==ZERO)
   return DecToBin(dec/TWO)*TEN;
 return 1+DecToBin(dec/TWO)*TEN;
}
int BuildGroup(int **arr,int *size)//build a group
{
 int i;
 printf("please insert group size\n");
 scanf("%d",&(*size));
 (*arr)=(int*)malloc((*size)*sizeof(int));
 printf("please insert numbers to the group\n");
 for(i=ZERO;i<(*size);i++)
   scanf("%d",&(*arr)[i]);
}
BOOL Odd(int *arr,int size)//check if all the number in a group are odd
{
 int i=size-1;
 if(i>=ZERO)
  {
   if(arr[i]%TWO==ZERO)
     return false;
   else
     return (true*Odd(arr,i));
  }
 else return true;
}
int EvenSum(int *arr,int size)//return the sum of the even numbers in a group
{
 int sum,i;
 i=size-1;
 if(i>=ZERO)
  {
   if(arr[i]%TWO==ZERO)
    {
     sum=arr[i];
     return (sum+EvenSum(arr,i));
    }
   else
     return ZERO+EvenSum(arr,i);
  }
 else 
   return ZERO;
}
void SumGroup(int *arr,int size)//make a group of the some of group numbers
{
 int l=size-1,i;
 if(l>=ZERO)
  {
   for(i=ZERO;i<l;i++)
      arr[l]+=arr[i];
   SumGroup(arr,l);
  }
}
int StringLen(char *str)//calculate and return the lenght of string
{
 if(str[ZERO]=='\0')
   return ZERO;
 else
   return 1+StringLen(str+1);
}
int StrComp(char *str1,char *str2)//compare lexicography between two strings
{
 if(*str1!='\0'&&*str2!='\0')
  {
   if(*str1>*str2)
     return 1;
   if(*str1<*str2)
     return -1;
   else
     return StrComp(str1+1,str2+1);
  }
 else if(*str1=='\0'&&*str2=='\0')
        return 0;
 else
   {
    if(*str1=='\0')
      return -1;
    else
      return 1;
   }
}
void MaxLen(char **text,int size,int *words,int *len)//fine the lenght of the longest string and how much word are longest
{
 int i=size-1;
 if(i>=0)
  {
   if((*len)<StringLen(text[i]))
    {
     (*words)=0;
     (*len)=StringLen(text[i]);
    
     while(i>=0)
         {
          if(StringLen(text[i])==(*len))
            (*words)++;
          i--;
         }
     MaxLen(text,size-1,words,len);
    }
  }
}
