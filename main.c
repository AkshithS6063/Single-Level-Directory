//SINGLE LEVEL Directory
//**********************************************************
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
  char directory[10];
  char filename[10][10];
  int fcnt;
}dir;
void main()
{
  int i,ch;
  char f[30];
 
  dir.fcnt = 0;
  printf("\n\nEnter name of directory->\n\n");
  printf("*******************************\n");
  scanf("%s", dir.directory);
  while(1)
  {
    printf("\n1. Create File\n2. Delete File\n3. Search File\n4. Display Files\n5. Exit\nEnter your choice->> ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\n**Enter the name of the file**\n");
      scanf("%s",dir.filename[dir.fcnt]);
      dir.fcnt++;
      break;

      case 2: printf("\n**Enter the name of the file**\n");
      scanf("%s",f);
      for(i=0;i<dir.fcnt;i++)
      {
        if(strcmp(f, dir.filename[i])==0)
        {
          printf("**File %s deleted**\n",f);
          strcpy(dir.filename[i],dir.filename[dir.fcnt-1]);
          break;
        }
      }
      if(i==dir.fcnt)
      printf("**File %s not found**\n",f);
      else
      dir.fcnt--;
      break;

      case 3: 
      if(dir.fcnt==0)
      {
        printf("\n**Directory Empty**\n");
        break;
      }
      printf("\n**Enter the name of the file**\n");
      scanf("%s",f);
      for(i=0;i<dir.fcnt;i++)
      {
        if(strcmp(f, dir.filename[i])==0)
        {
          printf("**File %s is found**\n", f);
          break;
        }
      }
      if(i==dir.fcnt)
        printf("**File %s not found**\n",f);
      break;

      case 4: if(dir.fcnt==0)
      printf("\n**Directory Empty**\n");
      else
      {
        printf("\n**The Files are**\n");
        for(i=0;i<dir.fcnt;i++)
        printf("\t%s",dir.filename[i]);
      }
      break;
      default: exit(0);
    }
  }
  getch();
}