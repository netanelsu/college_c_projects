/*assignment 5
beer sheva
netanel sudai
316004878
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME 20
#define FIVE 5
typedef enum{false,true}BOOL;
//structs
typedef struct{
 char *name;
 int Class;
 float salary;
}employee;
//function decleration
BOOL initEmployee(employee*);
int buildFactory(employee**);
void printEmployees(employee*,int);
void calcAverage(employee*,int,float*);
void freeAll(employee*,int);
//main
int main()
{
 employee *factory=NULL;
 int workers;
 float res[FIVE];
 workers=buildFactory(&factory);
 printEmployees(factory,workers);
 calcAverage(factory,workers,res); 
 freeAll(factory,workers);
 return 0;
} 
BOOL initEmployee(employee *person)//this function fill employee details
{
 person->name=(char*)malloc(NAME*sizeof(char));
 if((person->name)==NULL)
  {
   return false;
   exit (1);
  }
 else
  {
   printf("please insert employee name\n");
   fgets(person->name,NAME,stdin);
   if(person->name[strlen(person->name)-1]=='\n')
     person->name[strlen(person->name)-1]='\0';
   printf("please insert employee class\n");
   scanf("%d",&person->Class);
   while(person->Class<1 || person->Class>5)
       {
        printf("please insert employee class\n");
        scanf("%d",&person->Class);
       }
   printf("please insert employee salary\n");
   scanf("%f",&person->salary);
   getchar();
   return true;
  }
}
int buildFactory(employee **factory)//create array of employees
{
 int people,i;
 BOOL flag;
 printf("please insert how many workers there are in the factory\n");
 scanf("%d",&people);
 getchar();
 (*factory)=(employee*)malloc(people*sizeof(employee));
 for(i=0;i<people;i++)
   {
    flag=initEmployee(&(*factory)[i]);
    if(flag==false)
     {
      printf("no memory available");
      exit (1);
     }
   }
 return people;
}
void printEmployees(employee *factory,int people)//print the factory employees
{
 int i;
 for(i=0;i<people;i++)
   {
    printf("employee number %d:\n",i+1);
    printf("employee name is:%s\n",factory[i].name);
    printf("employee class is:%d\n",factory[i].Class);
    printf("employee salary is:%.2f\n",factory[i].salary);
    printf("\n");
   }
}
void calcAverage(employee *factory,int people,float *result)//calculate and print the salary average of every class
{
 int i,j,counter=0,salary=0; 
 for(i=0;i<FIVE;i++)
   {
    counter=0;
    salary=0;
    for(j=0;j<people;j++)
      {
       if(factory[j].Class==(i+1))
        {
	 counter++;
	 salary+=factory[j].salary;
        }
      }
    if(counter!=0)
     {
      result[i]=salary/counter;
      printf("the salary average of class %d is %.2f\n",i+1,result[i]);
     }
    else
      result[i]=-1;
      printf("no workers in class %d\n",i+1);
   }
} 
void freeAll(employee *factory,int people)//free all the dinamic memory
{
 int i;
 for(i=0;i<people;i++)
    free(factory[i].name);
 free(factory);
 factory=NULL;
}
