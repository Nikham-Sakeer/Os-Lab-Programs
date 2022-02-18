#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3,*f4, *f5, *f6;
int lc,sa,l,op1,o,len;
char m1[20],la[20],op[20],otp[20];

f1=fopen("input.txt","r");
f3=fopen("symtab.txt","w");
f5=fopen("intermediate.txt", "w");
f6=fopen("program.txt", "w");
fscanf(f1,"%s %s %x",la,m1,&op1);
if(strcmp(m1,"START")==0)
{
 sa=op1;
 lc=sa;
 printf("-\t%s\t%s\t%x\n",la,m1,op1);
 fprintf(f5,"-\t%s\t%s\t%x\n",la,m1,op1);
 }
 else
 lc=0;
fscanf(f1,"%s %s",la,m1);
while(!feof(f1))
{
 fscanf(f1,"%s",op);
 if(strcmp(m1,"END")!=0)
 {
  fprintf(f5,"\n%x\t%s\t%s\t%s\n",lc,la,m1,op);
  printf("\n%x\t%s\t%s\t%s\n",lc,la,m1,op);
 }
 else
 {
  fprintf(f5,"\n-\t%s\t%s\t%s\n",la,m1,op);
  printf("\n-\t%s\t%s\t%s\n",la,m1,op);
 }
 if(strcmp(la,"-")!=0)
 {
 fprintf(f3,"\n%x\t%s\n",lc,la);
 }
 f2=fopen("optab.txt","r");
 fscanf(f2,"%s %x",otp,&o);
 while(!feof(f2))
 {
  if(strcmp(m1,otp)==0)
  {
    lc=lc+3;
    break;
  }
  fscanf(f2,"%s %x",otp,&o);
  }
  fclose(f2);
  if(strcmp(m1,"WORD")==0)
 
    {
   lc=lc+3;
   }
   else if(strcmp(m1,"RESW")==0)
   {
    op1=atoi(op);
    lc=lc+(3*op1);
    }
    else if(strcmp(m1,"BYTE")==0)
    {
    if(op[0]=='X')
      lc=lc+1;
      else
      {
      len=strlen(op)-2;
      lc=lc+len;}
    }
    else if(strcmp(m1,"RESB")==0)
    {
     op1=atoi(op);
     lc=lc+op1;
     }
    fscanf(f1,"%s%s",la,m1);
}
    if(strcmp(m1,"END")==0)
    {
    printf("Program length = %x",lc-sa);
    fprintf(f6, "%x", lc-sa);
    }
    fclose(f1);
    fclose(f3);
    }
