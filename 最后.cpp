//

//  main.cpp

//  est5

//

//  Created by s20171105137 on 2018/7/10.

//  Copyright ? 2018�� s20171105137. All rights reserved.

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

    

    int number; //ѧ��ѧ��

    int judge_n; //��ί����

    char*name; //ѧ������

    char stu_sex[20];//ѧ���Ա�

    int stu_dateofbirth;//ѧ������

    char stu_class[20];//ѧ���༶

    char stu_TelNO[20];//ѧ���绰

    double score[20]; //ѧ�������ļ���

public:

    Cplayer(char*a,int n1,int jn,double fen[20]) // ���캯��,�����ݳ�ʼ��

    {

        name=new char[strlen(a)+1];

        strcpy(name,a); //������ֵ

        number=n1;//���

        judge_n=jn; //������

        int i=0;

        for(i=0;i<judge_n;i++)

            score[i]=fen[i];

        for(i=judge_n;i<20;i++)//������ֵ

            score[i]=0;

    }

    void set_name(char*a)//�������ֵ�����͸���

    {

        name=new char[strlen(a)+1];

        strcpy(name,a);

    }

    void set_score(double fen1[20]) //����������͸���

    {

        for(int i=0;i<judge_n;i++)

            score[i]=fen1[i];

    }

    void show_score()//��ʾѡ������

    {

        std::cout<<number<<"  "<<name<<"    ";

        for(int i=0;i<judge_n;i++)

        {

            

            std::cout.width (5);

            std::cout<<score[i];

        }

        std::cout<<std::endl;

    }

    friend std::ofstream & operator <<(std::ofstream & base,Cplayer & a); //��Ԫ���������������

    //��ָ���ļ�����ѡ�ֵ�����

};//�ඨ�����.





class Cresult // ������һ���ࡣ

{

private:

    int number; //ѧ��ѧ��

    int judge_n; //��ί����

    char*name; //ѧ������

    char stu_sex[20];//ѧ���Ա�

    int stu_dateofbirth;//ѧ������

    char stu_class[20];//ѧ���༶

    char stu_TelNO[20];//ѧ���绰

    double score[20]; //ѧ�������ļ���

public:

    Cresult(char*a,int n1,int jn,double fen[20])

    {

        name=new char[strlen(a)+1];

        strcpy(name,a); //������ֵ

        number=n1;//ѡ��ѧ��

        judge_n=jn;//������

        int i=0;

        for(i=0;i<judge_n;i++)

            score[i]=fen[i];

        for(i=judge_n;i<20;i++)//������ֵ

            score[i]=0;

    }

    

    double min_score()//��ͷ�

    {

        double min_score=score[0];

        for(int i=0;i<judge_n;i++)

            if(min_score>=score[i])

                min_score=score[i];

        

        return min_score;

    }

    

    

    double max_score()//��߷�

    {

        double max_score=score[0];

        for(int i=0;i<judge_n;i++)

        {

            if(max_score<=score[i])

                max_score=score[i];

        }

        return max_score;

    }

    

    

    double get_totalscore() //��ȡ�ܷ�,���з����ĺ�

    {

        double totalscore=0;

        for(int i=0;i<judge_n;i++)

            totalscore+=score[i];

        return totalscore;

    }

    

    

    double get_lastscore();//��ȡ���ĵ÷�

    double get_tscore()//ѡ�ֵ��ۻ�����

    {

        double tscore;

        if(judge_n<11)

            tscore=get_lastscore()*(judge_n-2);

        if(judge_n>=11)

            tscore=get_lastscore()*(judge_n-4);

        return tscore;

    }

    

    void show_result()//������

    {

        std::cout<<"    "<<number<<"     "<<name<<"     "<<max_score()<<"     "<<min_score()

        <<"     "<<get_tscore()<<"      "<<get_lastscore()<<std::endl;

    }

    

    friend std::ofstream & operator <<(std::ofstream & score,Cresult & a);  //�ļ�����,���������

};//�ඨ�����



double Cresult::get_lastscore()

{

    double lastscore;

    int a,b;

    if(judge_n<11)//����С��9ʱ

        lastscore=(get_totalscore()-max_score()-min_score())/(judge_n-2);

    //���÷�Ϊ�ֵܷ��ڳ�ȥ��ߺ���͵�ƽ����

    if(judge_n>=11)//���д���9ʱ

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

        score[a]=min_score();//����ڶ��͵ķ���min_score2

        for( i=0;i<judge_n;i++)

            if(score[i]==max_score())

                b=i;

        for( i=0,score[b]=1.0;i<judge_n;i++)

        {

            if(max_score2<=score[i])

                max_score2=score[i];

            else max_score2=score[i];

        }

        score[b]=max_score();//����ڶ��ߵķ���

        lastscore=(get_totalscore()-min_score()-max_score()-min_score2-max_score2)/(judge_n-4);

        //���÷�Ϊ�ֳܷ�ȥ�����߷ֺͶ����ͷֺ��ƽ����

    }

    return lastscore;//�������÷�

}







std::ofstream & operator<<(std::ofstream & base,Cplayer & a)//���������

{

    base<<a.number<<"  "<<a.name<<"    "<<a.stu_sex<<a.stu_dateofbirth<<a.stu_class<<a.stu_TelNO<<a.judge_n;

      for(int i=0;i<a.judge_n;i++)

    base<<"  "<<a.score[i];

    base<<std::endl;

    return base;

}//��ָ���ļ�����ѡ�ֵ�����









std::ofstream & operator <<(std::ofstream & score,Cresult & a) //�ļ�����,���������

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

//    /*ʹ�á�w+���򿪿ɶ�/д�ļ������ļ��������ļ�������Ϊ�㣬

//     �����ļ����ݻ���ʧ�����ļ��������������ļ�*/

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

//    /*ʹ��getc�������ļ����ж�ȡ�ַ�*/

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

//    fstream = fopen("/Users/s20171105137/Desktop/student1.csv","r");  /*���ļ�*/

//    if(fstream == NULL)

//    {

//        printf("Error opening file test.txt\n");

//        exit(1);

//    }

//    len = 0;

//    

//    len = getw(fstream);/*��ȡ����*/

//    printf("Read int is:%d\n",len);

//    fclose(fstream);

//    return 0;

//}

    

    

    double p1[20]={88,93,79,87,89,97,92,97,98,94};//ѡ��1�÷�

    double p2[20]={88,93,79,87,89,97,92,97,98,34};//ѡ��2�÷�

    double p3[20]={88,93,79,87,89,97,92,97,97,84};//ѡ��3�÷�

    double p4[20]={88,93,79,87,39,97,92,97,48,94};//ѡ��4�÷�

    double p5[20]={88,93,79,87,79,97,92,97,98,64};//ѡ��5�÷�

    std::ofstream outfile1;

    outfile1.open("/Users/s20171105137/Desktop/student1.csv",std::ios::out);//���浽D��

    std::ofstream outfile2;

    outfile2.open("/Users/s20171105137/Desktop/student3.csv",std::ios::out);//���浽D��

    Cplayer player1("edd",1,7,p1);//���ù��캯��

    Cplayer player2("lintao",2,7,p2);//���ù��캯��

    Cplayer player3("guojian",3,7,p3);//���ù��캯��

    Cplayer player4("maling",4,7,p4);//���ù��캯��

    Cplayer player5("liuyifan",5,7,p5);//���ù��캯��

    player1.show_score();//��ʾѡ��1��Ϣ

    player2.show_score();//��ʾѡ��2��Ϣ

    player3.show_score();//��ʾѡ��3��Ϣ

    player4.show_score();//��ʾѡ��4��Ϣ

    player5.show_score();//��ʾѡ��5��Ϣ



//    outfile2<<<<std::endl;//���ļ����

//    outfile2<<""<<std::endl;//���ļ����

//    outfile2<<""<<std::endl;//���ļ����

//

    Cresult result1("zfsfd",1,7,p1);//���ù��캯��

    Cresult result2("lintao",2,7,p2);//���ù��캯��

    Cresult result3("guojian",3,7,p3);//���ù��캯��

    Cresult result4("maling",4,7,p4);//���ù��캯��

    Cresult result5("liuyifan",5,7,p5);//���ù��캯��

    result1.show_result();//��ʾѡ��1���

    result2.show_result();//��ʾѡ��2���

    result3.show_result();//��ʾѡ��3���

    result4.show_result();//��ʾѡ��4���

    result5.show_result();//��ʾѡ��5���

    outfile1<<player1<<player2<<player3<<player4<<player5;//���ļ�1���5��ѡ�ֵ���Ϣ

    outfile2<<result1<<result2<<result3<<result4<<result5;//���ļ�2������

    outfile1.close();//�ر��ļ�

    outfile2.close();//�ر��ļ�

}
