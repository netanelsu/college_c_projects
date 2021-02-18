/*assignment:2
campus: beer sheva
author:netanel sudai
ID: 316004878*/
#include<stdio.h>
#define MAX 1000
//functions declerations
void CountIntersectDigits();
void PrintFriend();
long ReverseDigits(long);
void ReverseDigitsAndAdd5();
long RemoveMaxDigits(long);
int PrintSpecialNumbers();
int MakeNewNumber(int,int);
void PrintPattern(int);
//main
int main()
{
//variables setting
 long num4;
 int menu,num6,counter,int1,int2,new_num;
 do//loop for menu until the user press on exit option (8)
 {
  printf("please select option:\n1.same digits\n2.friend numbers\n3.reverse the digits and add 5\n4.remove all max digits\n5.print special number\n6.make a new number\n7.print numbers in a pattern\n8.exit\n");//menu
  scanf("%d",&menu);
  switch (menu)//start a option by the user selection 
  {
   case 1:
   CountIntersectDigits();//call to function
   break;
   case 2:
   PrintFriend();
   break;
   case 3:
   ReverseDigitsAndAdd5();
   break;
   case 4:
   printf("please insert positive integer number\n");
   scanf("%lu",&num4);//get a number
   num4=RemoveMaxDigits(num4);//send the number to the function
   printf("the new number is:%lu\n",num4);
   break;
   case 5:
   counter=PrintSpecialNumbers();
   printf("there are %d special numbers\n",counter); 
   break;
   case 6:
   do//this loop check if the input is correct (two positive numbers)
   {
    printf("please insert 2 positive integers numbers\n");
    scanf("%d%d",&int1,&int2);
   }
   while(int1<=0||int2<=0);
   new_num=MakeNewNumber(int1,int2);
   printf("the new number is:%d\n",new_num);
   break;
   case 7:
   printf("please insert positive number between 1-9\n");
   scanf("%d",&num6);
   PrintPattern(num6);
   break;
   case 8://exit option
   printf("have a nice day\n");
   break;
   default ://if the user select wrong option number
   printf("invalid value\n");
   break;
  }
 }
 while (menu!=8);
 return 0; 
}
void CountIntersectDigits()//function1 this function get two numbers and check how many digits are the same until it get 0 0
{
 int int1,int2,int2b,int1b,dig1,dig2,i;//variables setting
 do 
 {
  printf("please insert two positives integers numbers or two zeros for exit\n");//request for number selection
  scanf("%d%d",&int1,&int2);
  dig1=int1%10;
  int2b=int2;
  int1b=int1;
  i=0;
  do//this loop work on the first number
  {
   do//this loop work on the second number
    {
     dig2=int2%10;
     if(dig2==dig1)
     {
      i++;
     }
    int2/=10;
   }
   while(int2>0);
   int1/=10; 
   dig1=int1%10;
   int2=int2b;
  }
  while(int1>0);
  printf("there are %d same digits\n",i);
 }
 while(int1b!=0||int2b!=0);
}
void PrintFriend()//function2 this function check if number are friend (if the sum of the number's divides equal to the second number and vice versa
{
 int i,l,j,sum1=0,x,y,sum2=0;
 for(i=1;i<=MAX;i++)//i its the first number
 {
  for(j=1;j<=MAX;j++)
  {
   if(i%j==0)
    sum1+=j;
  }
  sum1-=i;//sum1 its the second number(sum of the first number divides)
  for(l=1;l<=MAX;l++)
  {
   if(sum1%l==0)
    sum2+=l;
  }
  sum2-=sum1;//sum2 its the sum of the second number divides
  if(sum2==i)//if the sum of the second number divides equal to the first number, they are friends.
   printf("%d  %d\n",sum2,sum1);
 sum1=0;
 sum2=0;
 }
}
long ReverseDigits(long num1)//this function take number and change the order of the digits
{
 long x=0;
 do
 {
  x*=10;
  x=x+num1%10;
  num1/=10;
 }
 while(num1!=0);
 return x;
}
void ReverseDigitsAndAdd5()//this function send number to reverse function,get it back after the reverse and add 5 to the new number
{
 long num;
 printf("please insert positive long integer number\n");
 scanf("%lu",&num);
 num=ReverseDigits(num);
 num+=5;
 printf("the new number is:%lu\n",num);
}
long RemoveMaxDigits(long num1)//this function chek the higher digit value and remove it from the number
{
 long new_num=0,save_num;
 int max;
 save_num=num1;
 max=num1%10;
 do//this loop check the value of the higher digit
 {
  num1/=10;
  if(num1%10>max)
   max=num1%10;
 }
 while(num1>0);
 num1=save_num;
 do//this loop compare between every digit to the value of the max digit
 {
  if(num1%10!=max)
  {
   new_num*=10;
   new_num+=num1%10;
  }
  num1/=10;
 }
 while(num1>0);
 new_num=ReverseDigits(new_num); //we get the new number from the end to start so we do reverse to get the correct number
 return new_num;
}
int PrintSpecialNumbers()//this function print all 5 digits number that every digit difrrent from the others
{
 int i,i2,num,num1,j,counter=0;
 for(i=10000;i<=99999;i++)//this loop chek every number in the spectrum
 {
  j=0;
  i2=i;
  num=i;
  num1=i;
  do//this loop  take the next digit every check loop
  {
   do//this loop check every digit and the digits after her
   {
    i2/=10;
    if(num%10!=i2%10)
     j++;
   }
   while(i2>9);
   num/=10;
   i2=num;
  }
  while(num>9);
  if(j==10)
  {
   counter++;
   printf("%d\n",num1);
  }
 } 
 return counter;
}
int MakeNewNumber(int numA,int numB)//this loop get two  umbers and make new one with the bigger digit in every place
{
 int new_num=0;
 do
 {
  if(numA%10>numB%10)
   new_num+=numA%10;
  else
  new_num+=numB%10;
  new_num*=10;
  numA/=10;
  numB/=10;
 }
 while(numA>0||numB>0);
 new_num=ReverseDigits(new_num);//we get the new num in  reverse order so we do reverse to him
 return new_num;
}
void PrintPattern(int num6)//this function get number and print pattern like this (number of lines is the value of the input number and in each line we add number from 1-the input number and the oposite in the next side
{
 int i,j,sum=0,sum2=0,num_save;
 num_save=num6;
 for(i=1;i<=num6;i++)
 {
  sum+=i;
  sum2=ReverseDigits(sum);
  printf("%d",sum);
  for(j=2*num_save-2;j>0;j--)
  {
   printf(" ");
  }
  printf("%d\n",sum2);
  num_save-=1;
  sum*=10;
 }
}
