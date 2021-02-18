/*assignment3
beer sheva
netanel sudai
316004878*/
#include<stdio.h>
#define SIZE1 15
#define SIZE2 100
#define WORDL 15//max chars for word
//functions decleratios
int StringChecker(char[SIZE1]);
int WordCmp(char[WORDL],char[WORDL]);
void FindSimiliarWords(char[SIZE2]);
//main
int main()
{
 char string1[SIZE1],string2[SIZE2];
 int res;
 printf("please insert string of 14 '(' and ')' chars\n"); 
 fgets(string1,SIZE1,stdin);//get string
 res=StringChecker(string1);//function call
 if(res==1)
   printf("valid string brackets\n");
 else
   printf("invalid string brackets\n");
 getchar();
 printf("please insert sentence not bigger then 15 chars for word and max total of 100 chars\n"); 
 fgets(string2,SIZE2,stdin);//get string 2
 FindSimiliarWords(string2);//fuction call
 return 0;
}
int StringChecker(char str[SIZE1])//firs function check ')' '(' string legalliti
{
 int i,counter_op=0,counter_cl=0,sum_op=0,sum_cl=0;
 for(i=0;i<SIZE1;i++)//check the quantity of each bracket type and the sum of there place in the array
   {
    if(str[i]=='(')
     {
      counter_op++;
      sum_op+=i;
     }
    if(str[i]==')')
     {
      counter_cl++;
      sum_cl+=i;
     }
   }
    if(counter_op==counter_cl&&counter_op+counter_cl==SIZE1-1&&sum_op<sum_cl)//if there is equal number of each type of bracket and the sum of the close bigger them open bracket and the sum of all the bracket equal to the number of cells im array , the string is valid
      return 1;
    else
      return 0;
}
int WordCmp(char str1[WORDL],char str2[WORDL])//this function check if two word have the same letters,capital letter equal to small letter
{
int i,j,flag=1,flag2=1;
for(i=0;str1[i]!='\0'&&flag==1;i++)
  {
   flag=0;
   for(j=0;str2[j]!='\0';j++)
     {
      if(str1[i]==str2[j]||str1[i]==str2[j]+32||str1[i]==str2[j]-32)
        flag=1;
     }
  }
for(i=0;str2[i]!='\0'&&flag2==1;i++)
  {
   flag2=0;
   for(j=0;str1[j]!='\0';j++)
     {
      if(str2[i]==str1[j]||str2[i]==(str1[j]+32)||str2[i]==(str1[j]-32))
        flag2=1;
     }
  }
if(flag==flag2&&flag!=0){
  printf("%s  %s\n",str1,str2);
  return 1;}
else
return 0;
}
void FindSimiliarWords(char str[SIZE2])//this fuction check same words in sentence
{
 int i=0,j,l,k,check=0,check2=0;
 char word1[WORDL],word2[WORDL];
 while(str[i]!='\n'&&str[i]!='\0')
 {
  for(l=0;str[i]!=' '&&str[i]!='\n';i++)
    {
     word1[l]=str[i];
     l++; 
    }
    word1[l]='\0';
    j=i+1;
  while(str[j]!='\n'&&str[j]!='\0')
  { 
   for(k=0;str[j]!=' '&&str[j]!='\n';j++)
     {
      word2[k]=str[j];
      k++;
     }
   word2[k]='\0';
   check=WordCmp(word1,word2);
   check2+=check;
   j++;
  }
  i++; 
 }
 if(check2==0)
   printf("no similiar words\n");
}
