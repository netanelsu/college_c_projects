/*assignment 4
beer sheva
netanel sudai
316004878
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define WORD 10 //word max lenght
//function decleration
void BuildText(char***,int);
void wordFrequency(char***,int);
void textPreprocessing(char***,int*,char**,int);
void freeAll(char***,int,char***,int);
//main
int main()
{
 char **text=NULL,**stopWord=NULL;
 int countWord,i,stopwords;
 printf("how many words you whould like to insert?\n");
 scanf("%d",&countWord);
 getchar();
 printf("please insert the words\n");
 BuildText(&text,countWord);
 printf("how many stop words you whould like to insert?\n");
 scanf("%d",&stopwords);
 getchar();
 printf("please insert the words\n");
 BuildText(&stopWord,stopwords);
 textPreprocessing(&text,&countWord,stopWord,stopwords);
 printf("the new text is:\n");
 for(i=0;i<countWord;i++)
    puts(text[i]);
 printf("the words frequency is:\n");
 wordFrequency(&text,countWord);
 freeAll(&text,countWord,&stopWord,stopwords);
 return 0;
}
void BuildText(char ***text,int words)//this function get strings array adress and fill the lines 
{
 int i,j;
 char word[WORD];
 (*text)=(char**)malloc(words*sizeof(char*));
 if((*text)==NULL)
  {
   printf("no memory available\n");
   exit (1);
  }
 for(i=0;i<words;i++)
   {
    scanf("%s",word);
    getchar();
    (*text)[i]=(char*)malloc(WORD*sizeof(char));
    strcpy((*text)[i],word);
   }
}
void wordFrequency(char ***text,int words)//this function get text adress and print how many times every word appears
{
 int i=0,j,count;
 char **check;
 check=(char**)malloc(words*sizeof(char*));
 if(check==NULL)
   {
    printf("no memory available");
    exit (1);
   }
 for(i=0;i<words;i++)
    check[i]=(char*)malloc(WORD*sizeof(char));
 for(i=0;i<words;i++)
   {
    count=0;
    for(j=0;j<words;j++)
       if(strcmp((*text)[i],check[j])!=0)
         count++;
    if(count==words)
     {
      count=1;
        for(j=i+1;j<words;j++)
          {
           if(strcmp((*text)[i],(*text)[j])==0)
             count++;
          }
        printf("%s:%d\n",(*text)[i],count);
     }
    strcpy(check[i],(*text)[i]);
   }
}
void textPreprocessing(char ***text,int *countwords,char **stopword,int stopwords)//this function make filtering to the text
{
 int i,j,k,l=0,count=0,count2=0;
 for(i=0;i<(*countwords);i++)
   for(j=0;j<(strlen((*text)[i])+1);j++)
     {
      if((*text)[i][j]>='A'&&(*text)[i][j]<='Z')
        (*text)[i][j]+=32;
     }
 for(i=0;i<(*countwords);i++)
  { 
   for(j=0;j<stopwords;j++)
     {
      count=0;
      count2=0;
      for(k=0;k<stopwords;k++)
       if(strcmp((*text)[i],stopword[k])!=0)
       	count++;
      for(l=0;l<(strlen((*text)[i])+1);l++)
        if((*text)[i][l]>='0'&&(*text)[i][l]<='9')
          count2++;
      if(count!=stopwords||count2!=0)//drop words that not meet with the conditions
       {
 	strcpy((*text)[i],(*text)[(*countwords)-1]);
        free((*text)[(*countwords)-1]); 
        (*countwords)--;
       }
     }
  }
 (*text)=(char**)realloc((*text),(*countwords)*sizeof(char*));
}
void freeAll(char ***text,int countwords,char ***stopword,int stopwords)//free all the dynamic memory
{
 int i,j;
 for(i=0;i<countwords;i++)
    free((*text)[i]);
 for(j=0;j<stopwords;j++)
    free((*stopword)[i]);
}
