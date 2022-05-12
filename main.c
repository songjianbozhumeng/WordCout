#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

void Count(char * file); 
int Zicount=0;
int Wordcount=0;
int Hangcount=0;

void Count(char * file)
{
    FILE * fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);

        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')
            Zicount++;
        if(a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')
        {
            if(a=='=')                      
                Wordcount--;
            Wordcount++;
        }
    }
    Zicount--;         
    fclose(fp);
}


int main(int argc, char* argv[])              
{
    FILE *fp;
    Count(argv[2]);
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {    
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(strcmp(argv[1],"-c")==0)                   
            printf("文件%s字符数为:%d\n",argv[2],Zicount);
        else if(strcmp(argv[1],"-w")==0)                   
            printf("文件%s单词数为:%d\n",argv[2],Wordcount);
        else if(strcmp(argv[1],"exit")==0)
        {
            printf("程序结束!\n");
            break;
        }
        else 
            printf("该指令不存在，请重新输入\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}
