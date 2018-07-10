//
//  main.cpp
//  zuizhong
//
//  Created by s20171105137 on 2018/7/10.
//  Copyright © 2018年 s20171105137. All rights reserved.
//

#include<cstdlib>
#include<fstream>
#include<cstdio>
#include<string.h>

using namespace std;

struct student

{
    
    
    char Stu_num[15];
    
    char Name[10];
    
    char Sex[10];
    
    char Birth[10];
    
    char Class[15];
    
    char Telph[12];
    
    char Judge[200];
    
    int* result = (int*)malloc(sizeof(int)*1);//用malloc函数设定评委
    
    int max;
    
    int min;
    
    int Average;
    
    int score=0;
    
};

struct student s[200];//定义一个学生结构体



int main()

{
    int i=0;
    int j=0;
    int a=0;
    int b=0;
    int d=0;
    char header[100];//定义存放表头的
    
    FILE *filep1,*filep2;
    
    filep1 =fopen("/Users/s20171105137/Desktop/studentdata1.csv","r");
    
    if(filep1==NULL)//检查文件是否存在
        
        
    {
        printf("NO SUCH FILE");
        exit(-1);//中断终端程序
    }
    
    else
        
    {
        
        fscanf(filep1,"%s",header);
        
        while(!feof(filep1))//读取表头
        {
            fscanf(filep1,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",s[i].Stu_num,s[i].Name,s[i].Sex,s[i].Birth,s[i].Class,s[i].Telph,s[i].Judge);
            for(a=0;a<d;a++)
            {
                fscanf(filep1,",%d",&s[i].result[a]);//按照，分隔符
            }
            i++;
            
        }
        
    }
    
    
    int fs;
    j=i;//qiegecishu
    char delims[]=",";
    char *result=NULL;
    for(i=0;i<j;i++)
	   {
           
           result=strtok(s[i].Judge,delims);//youshu
           while(result!=NULL)
           {
               fs=atoi(result);
               result = strtok(NULL, delims);//切割到文件末尾
               b++;
               s[i].result[a]=fs;
               a++;
           }
  	        a=0;
       }
    d=b/i;//控制循环
    j=i;
     for(i=0;i<j;i++)
     {
    s[i].max=s[i].min=s[i].result[0];
     }
    i=j;
    for(i=0;i<j;i++)
    {
    for(a=i;a<d;a++)//找最大最小值
        {
            if(s[i].result[a]>s[i].max)
                s[i].max=s[i].result[a];
            if(s[i].result[a]<s[i].min)
                s[i].min=s[i].result[a];
        }
    }
    i=j;
        for(i=0;i<j;i++)   //计算成绩
        {
            for(a=0;a<d;a++)
            {
                    s[i].score=s[i].result[a]+s[i].score;
            }
            s[i].Average=(s[i].score-s[i].max-s[i].min)/(d-2);
        }
    j=i;
    i=0;
    filep2=fopen("/Users/s20171105137/Desktop/studentdata2.csv","w");//chuangjianxinwenjian
    
    {
        fprintf(filep2,"%s,Average\n",header);
        printf("%s,Average\n",header);
        while(i<j)
        {
            fprintf(filep2,"%s,%s,%s,%s,%s,%s,",s[i].Stu_num,s[i].Name,s[i].Sex,s[i].Birth,s[i].Class,s[i].Telph);//打印学生信息
            printf("%s,%s,%s,%s,%s,%s,",s[i].Stu_num,s[i].Name,s[i].Sex,s[i].Birth,s[i].Class,s[i].Telph);
            
            for(a=0;a<d;a++)
            {
                fprintf(filep2,"%d,",s[i].result[a]);//打印原成绩
                printf("%d,",s[i].result[a]);
            }
            fprintf(filep2,"%d\n",s[i].Average);
            printf("%d\n",s[i].Average);//打印计算好的成绩
            fprintf(filep2,"\n\n");
            //  printf("\n");
            i++;
        }
        
    }
    fclose(filep2);
    
    return 0;     
}
