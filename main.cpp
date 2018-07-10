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
    
    int* result = (int*)malloc(sizeof(int)*1);//”√malloc∫Ø ˝∂ØÃ¨∑÷≈‰ƒ⁄¥Ê
    
    int max;
    
    int min;
    
    int Average;
    
    int score=0;
    
};

struct student s[200];//∂®“Â“ª∏ˆ—ß…˙Ω·ππÃÂ



int main()

{
    int i=0;
    int j=0;
    int a=0;
    int b=0;
    int d=0;
    char header[100];//≈≈≥˝±ÌÕ∑
    
    FILE *filep1,*filep2;
    
    filep1 =fopen("/Users/s20171105137/Desktop/studentdata1.csv","r");
    
    if(filep1==NULL)//ºÏ≤ÈŒƒº˛ «∑Ò¥Ê‘⁄
        
        
    {
        printf("NO SUCH FILE");
        exit(-1);//÷–∂œ≥Ã–Ú‘À––
    }
    
    else
        
    {
        
        fscanf(filep1,"%s",header);
        
        while(!feof(filep1))//≈≈≥˝±ÌÕ∑
        {
            fscanf(filep1,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",s[i].Stu_num,s[i].Name,s[i].Sex,&s[i].Birth,s[i].Class,s[i].Telph,s[i].Judge);
            
            i++;
            
        }
        
    }
    
    
    int fs;
    j=i;//qiegecishu
    char delims[]=",";
    char *result=NULL;
    for(i=0;i<j;i++)
	   {
           
           result=strtok(s[i].Judge,delims);
           while(result!=NULL)
           {
               fs=atoi(result);
               result = strtok(NULL, delims);//÷’÷π«–∏Ó
               b++;
               s[i].result[a]=fs;
               a++;
           }
  	        a=0;
       }
    d=b/i;//øÿ÷∆±»¥Û–°¥Œ ˝
    j=i;
     for(i=0;i<j;i++)
     {
    s[i].max=s[i].min=s[i].result[0];
     }
    i=j;
    for(i=0;i<j;i++)
    {
        for(a=i;a<d;a++)
        {
            if(s[i].result[a]>s[i].max)
                s[i].max=s[i].result[a];
            if(s[i].result[a]<s[i].min)
                s[i].min=s[i].result[a];
        }
    }
    i=j;
    for(i=0;i<j;i++)   //º∆À„≥…º®
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
            fprintf(filep2,"%s,%s,%s,%s,%s,%s,",s[i].Stu_num,s[i].Name,s[i].Sex,s[i].Birth,s[i].Class,s[i].Telph);//¥Ú”°∏ˆ»À–≈œ¢
            printf("%s,%s,%s,%s,%s,%s,",s[i].Stu_num,s[i].Name,s[i].Sex,s[i].Birth,s[i].Class,s[i].Telph);
            
            for(a=0;a<d;a++)
            {
                fprintf(filep2,"%d,",s[i].result[a]);//¥Ú”°∏ˆ»À≥…º®
                printf("%d,",s[i].result[a]);
            }
            fprintf(filep2,"%d",s[i].Average);
            printf("%d",s[i].Average);
            fprintf(filep2,"\n");//Ω´◊Ó÷’Ω·π˚¥Ú”°‘⁄∆¡ƒª
            //  printf("\n");
            i++;
        }
        
    }
    fclose(filep2);
    
    return 0;     
}
