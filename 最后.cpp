//

//  main.cpp

//  est5

//

//  Created by s20171105137 on 2018/7/10.

//  Copyright ? 2018年 s20171105137. All rights reserved.

//

#include<cstdio>

#include<cstdlib>

#include<fstream>

#include<cstring>

#include<iomanip>

#include<iostream>

class Cplayer

{

private:

    

    int number; //学生学号

    int judge_n; //评委人数

    char*name; //学生姓名

    char stu_sex[20];//学生性别

    int stu_dateofbirth;//学生生日

    char stu_class[20];//学生班级

    char stu_TelNO[20];//学生电话

    double score[20]; //学生分数的集合

public:

    Cplayer(char*a,int n1,int jn,double fen[20]) // 构造函数,对数据初始化

    {

        name=new char[strlen(a)+1];

        strcpy(name,a); //姓名赋值

        number=n1;//序号

        judge_n=jn; //裁判数

        int i=0;

        for(i=0;i<judge_n;i++)

            score[i]=fen[i];

        for(i=judge_n;i<20;i++)//分数赋值

            score[i]=0;

    }

    void set_name(char*a)//控制名字的输入和更改

    {

        name=new char[strlen(a)+1];

        strcpy(name,a);

    }

    void set_score(double fen1[20]) //分数的输入和更改

    {

        for(int i=0;i<judge_n;i++)

            score[i]=fen1[i];

    }

    void show_score()//显示选手资料

    {

        std::cout<<number<<"  "<<name<<"    ";

        for(int i=0;i<judge_n;i++)

        {

            

            std::cout.width (5);

            std::cout<<score[i];

        }

        std::cout<<std::endl;

    }

    friend std::ofstream & operator <<(std::ofstream & base,Cplayer & a); //友元函数，运算符重载

    //向指定文件输入选手的资料

};//类定义完毕.





class Cresult // 定义另一个类。

{

private:

    int number; //学生学号

    int judge_n; //评委人数

    char*name; //学生姓名

    char stu_sex[20];//学生性别

    int stu_dateofbirth;//学生生日

    char stu_class[20];//学生班级

    char stu_TelNO[20];//学生电话

    double score[20]; //学生分数的集合

public:

    Cresult(char*a,int n1,int jn,double fen[20])

    {

        name=new char[strlen(a)+1];

        strcpy(name,a); //姓名赋值

        number=n1;//选手学号

        judge_n=jn;//裁判数

        int i=0;

        for(i=0;i<judge_n;i++)

            score[i]=fen[i];

        for(i=judge_n;i<20;i++)//分数赋值

            score[i]=0;

    }

    

    double min_score()//最低分

    {

        double min_score=score[0];

        for(int i=0;i<judge_n;i++)

            if(min_score>=score[i])

                min_score=score[i];

        

        return min_score;

    }

    

    

    double max_score()//最高分

    {

        double max_score=score[0];

        for(int i=0;i<judge_n;i++)

        {

            if(max_score<=score[i])

                max_score=score[i];

        }

        return max_score;

    }

    

    

    double get_totalscore() //获取总分,所有分数的和

    {

        double totalscore=0;

        for(int i=0;i<judge_n;i++)

            totalscore+=score[i];

        return totalscore;

    }

    

    

    double get_lastscore();//获取最后的得分

    double get_tscore()//选手的累积分数

    {

        double tscore;

        if(judge_n<11)

            tscore=get_lastscore()*(judge_n-2);

        if(judge_n>=11)

            tscore=get_lastscore()*(judge_n-4);

        return tscore;

    }

    

    void show_result()//结果输出

    {

        std::cout<<"    "<<number<<"     "<<name<<"     "<<max_score()<<"     "<<min_score()

        <<"     "<<get_tscore()<<"      "<<get_lastscore()<<std::endl;

    }

    

    friend std::ofstream & operator <<(std::ofstream & score,Cresult & a);  //文件操作,结果的输入

};//类定义完毕



double Cresult::get_lastscore()

{

    double lastscore;

    int a,b;

    if(judge_n<11)//裁判小于9时

        lastscore=(get_totalscore()-max_score()-min_score())/(judge_n-2);

    //最后得分为总分等于除去最高和最低的平均分

    if(judge_n>=11)//裁判大于9时

    {

        double min_score2,max_score2;

        int i=0;

        for(i=0;i<judge_n;i++)

            if(score[i]==min_score())

                a=i;

        for( i=0,score[a]=20.0;i<judge_n;i++)

        {

            if(min_score2>=score[i])

                min_score2=score[i];

        }

        score[a]=min_score();//求出第二低的分数min_score2

        for( i=0;i<judge_n;i++)

            if(score[i]==max_score())

                b=i;

        for( i=0,score[b]=1.0;i<judge_n;i++)

        {

            if(max_score2<=score[i])

                max_score2=score[i];

            else max_score2=score[i];

        }

        score[b]=max_score();//求出第二高的分数

        lastscore=(get_totalscore()-min_score()-max_score()-min_score2-max_score2)/(judge_n-4);

        //最后得分为总分除去二个高分和二个低分后的平均分

    }

    return lastscore;//返回最后得分

}







std::ofstream & operator<<(std::ofstream & base,Cplayer & a)//运算符重载

{

    base<<a.number<<"  "<<a.name<<"    "<<a.stu_sex<<a.stu_dateofbirth<<a.stu_class<<a.stu_TelNO<<a.judge_n;

      for(int i=0;i<a.judge_n;i++)

    base<<"  "<<a.score[i];

    base<<std::endl;

    return base;

}//向指定文件输入选手的资料









std::ofstream & operator <<(std::ofstream & score,Cresult & a) //文件操作,结果的输入

{

    score<<"    "<<a.number<<"      "<<a.name<<"       "<<a.max_score()<<"      "<<a.min_score();

    score<<"       "<<a.get_tscore()<<"       "<<a.get_lastscore()<<std::endl;

    return score;

}



int  main()

{

    

    

//    

//    int ch;

//    int len;

//   // int i=0;

//    FILE* fstream;

//    /*使用“w+”打开可读/写文件，若文件存在则文件长度清为零，

//     即该文件内容会消失。若文件不存在则建立该文件*/

//    

//    std::ofstream outfile1;

//    outfile1.open("/Users/s20171105137/Desktop/student1.csv",std::ios::out);

//    

//    fstream=fopen("/Users/s20171105137/Desktop/student3.csv","w+");

//    if(fstream==NULL)

//    {

//        printf("read file test.txt failed!\n");

//        exit(1);

//    }

//    

//    

//    

//    /*使用getc函数从文件流中读取字符*/

//    while( (ch = getc(fstream))!=EOF)

//    {

//        putchar(ch);

//    }

//    putchar('\n');

//    len =0;

//    putw(len,fstream);

//    if(ferror(fstream))

//    {

//        printf("Error writing to file.\n");

//    }

//    else

//    {

//        printf("Success writing to file.\n");

//    }

//    fclose(fstream);

//    

//    fstream = fopen("/Users/s20171105137/Desktop/student1.csv","r");  /*打开文件*/

//    if(fstream == NULL)

//    {

//        printf("Error opening file test.txt\n");

//        exit(1);

//    }

//    len = 0;

//    

//    len = getw(fstream);/*读取整数*/

//    printf("Read int is:%d\n",len);

//    fclose(fstream);

//    return 0;

//}

    

    

    double p1[20]={88,93,79,87,89,97,92,97,98,94};//选手1得分

    double p2[20]={88,93,79,87,89,97,92,97,98,34};//选手2得分

    double p3[20]={88,93,79,87,89,97,92,97,97,84};//选手3得分

    double p4[20]={88,93,79,87,39,97,92,97,48,94};//选手4得分

    double p5[20]={88,93,79,87,79,97,92,97,98,64};//选手5得分

    std::ofstream outfile1;

    outfile1.open("/Users/s20171105137/Desktop/student1.csv",std::ios::out);//保存到D盘

    std::ofstream outfile2;

    outfile2.open("/Users/s20171105137/Desktop/student3.csv",std::ios::out);//保存到D盘

    Cplayer player1("edd",1,7,p1);//调用构造函数

    Cplayer player2("lintao",2,7,p2);//调用构造函数

    Cplayer player3("guojian",3,7,p3);//调用构造函数

    Cplayer player4("maling",4,7,p4);//调用构造函数

    Cplayer player5("liuyifan",5,7,p5);//调用构造函数

    player1.show_score();//显示选手1信息

    player2.show_score();//显示选手2信息

    player3.show_score();//显示选手3信息

    player4.show_score();//显示选手4信息

    player5.show_score();//显示选手5信息



//    outfile2<<<<std::endl;//向文件输出

//    outfile2<<""<<std::endl;//向文件输出

//    outfile2<<""<<std::endl;//向文件输出

//

    Cresult result1("zfsfd",1,7,p1);//调用构造函数

    Cresult result2("lintao",2,7,p2);//调用构造函数

    Cresult result3("guojian",3,7,p3);//调用构造函数

    Cresult result4("maling",4,7,p4);//调用构造函数

    Cresult result5("liuyifan",5,7,p5);//调用构造函数

    result1.show_result();//显示选手1结果

    result2.show_result();//显示选手2结果

    result3.show_result();//显示选手3结果

    result4.show_result();//显示选手4结果

    result5.show_result();//显示选手5结果

    outfile1<<player1<<player2<<player3<<player4<<player5;//向文件1输出5个选手的信息

    outfile2<<result1<<result2<<result3<<result4<<result5;//向文件2输出结果

    outfile1.close();//关闭文件

    outfile2.close();//关闭文件

}
