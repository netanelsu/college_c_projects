/*assignment 4
 beer sheva
 netanel sudai
 316004878 */
#include<stdio.h>
#include<stdlib.h>
//function decleration
void BuildGroup(int**,int*);
int OrganChecker(int,int**,int);
void PrintGroup(int*,int);
int* Union(int*,int,int*,int,int*);
int* Intersection(int*,int,int*,int,int*);
int* Diff(int*,int,int*,int,int*);
//main program
int main()
{
 int *group1,size1,size2,*group2,UnionSize,intersize=0;
 int *diffgroup,*uniongroup,*intergroup,diffsize;
 printf("please insert group 1 size\n");
 scanf("%d",&size1);
 if(size1==0)
  {
   printf("group 1 is:\n");
   printf("{}\n");
  }
 else
  BuildGroup(&group1,&size1);
 if(group1==NULL)
   return 0;
 printf("please insert group 2 size\n");
 scanf("%d",&size2);
 if(size2==0)
  {
   printf("group 2 is:\n");
   printf("{}\n");
  }
 else
  BuildGroup(&group2,&size2);
 if(group2==NULL)
   return 0;
 printf("group 1 is:\n");
 PrintGroup(group1,size1);
 printf("group 2 is:\n");
 PrintGroup(group2,size2);
 uniongroup=Union(group1,size1,group2,size2,&UnionSize);
 printf("the union group is:\n");
 PrintGroup(uniongroup,UnionSize);
 intergroup=Intersection(group1,size1,group2,size2,&intersize);
 printf("the intersection group is:\n");
 PrintGroup(intergroup,intersize);
 diffgroup=Diff(group1,size1,group2,size2,&diffsize);
 printf("the diff group is:\n");
 PrintGroup(diffgroup,diffsize);
 free(group1);
 free(group2);
 free(uniongroup);
 free(intergroup);
 free(diffgroup);
 return 0;
} 
void BuildGroup(int **group,int *pCount)//build group
{
 int i,organ,check,count=0;
 *group=(int*)malloc(*pCount*sizeof(int));
 if(*group==NULL)
  {
   printf("not enough memory\n");
   exit(1);
  }
 else
  {
   printf("please insert group organs\n");
   for(i=0;i<*pCount;i++)
     {
      check=0;
      scanf("%d",&organ);
      if(organ==0)
        count++; 
      check=OrganChecker(organ,&(*group),i+1);
      if((check!=i+1&&organ!=0)||(count>1&&organ==0))
       {
       printf("the number already exist, insert new one\n");
        i--;
       }
      else
    (*group)[i]=organ;
     }
  }
}
int OrganChecker(int organ,int **group,int pCount)//check if the number already exist in the group
{
 int i,check=0;
 for(i=0;i<pCount;i++)
    if((*group)[i]!=organ)
      check++;
 return check;
}
void PrintGroup(int *group,int size)//print group
{
 int i;
 if(size>0)
  {
   printf("{%d",group[0]);
   for(i=1;i<size;i++)
      printf(",%d",group[i]);
   printf("}\n");
  }
}
int* Union(int *group1,int size1,int *group2,int size2,int *PsizeUnion)//create the union group
{
 int i,j,*unigroup,l,count=0,count2=0;
 for(i=0;i<size1;i++)
   for(j=0;j<size2;j++)
     if(group1[i]==group2[j])
       count++;
 *PsizeUnion=size1+size2-count;
 unigroup=(int*)malloc(*PsizeUnion*sizeof(int));
 for(i=0;i<size1;i++)
    unigroup[i]=group1[i];
 l=size1;
 for(j=0;j<size2;j++)
   {
    count2=0;
    for(i=0;i<size1;i++)
      if(group2[j]!=group1[i])
        count2++;
    if(count2==size1)
     {
      unigroup[l]=group2[j];
      l++;
     } 
   }
 return unigroup;
}
int* Intersection(int *group1,int size1,int *group2,int size2,int *PsizeInter)//create the intersection group
{
 int *intergroup,i,j,l=0;
 for(i=0;i<size1;i++)
  for(j=0;j<size2;j++)
    if(group1[i]==group2[j])
      (*PsizeInter)++; 
 intergroup=(int*)malloc(*PsizeInter*sizeof(int));
 for(i=0;i<size1;i++)
  for(j=0;j<size2;j++)
    if(group1[i]==group2[j])
     {
      intergroup[l]=group1[i];
      l++;
     }
 return intergroup;
}
int* Diff(int *group1,int size1,int *group2,int size2,int *PsizeDiff)//create the diffrence group
{
 int i,j,l=0,count=0,*diffgroup,count2=0;
 for(i=0;i<size1;i++)
   for(j=0;j<size2;j++)
     if(group1[i]==group2[j])
       count++;
 *PsizeDiff=size1-count; 
 diffgroup=(int*)malloc(*PsizeDiff*sizeof(int));
 for(i=0;i<size1;i++)
   {
    count2=0;
    for(j=0;j<size2;j++)
      if(group1[i]!=group2[j])
        count2++;
    if(count2==size2)
     {
      diffgroup[l]=group1[i];
      l++;
     } 
   } 
 return diffgroup;
}
