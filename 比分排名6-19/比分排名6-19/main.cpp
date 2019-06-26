//
//  main.cpp
//  比分排名6-19
//
//  Created by s2018 on 2019/6/19.
//  Copyright © 2019 s2018. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream stu("/Users/nianqingren/Desktop/accurac/stu.txt");
ifstream juge("/Users/nianqingren/Desktop/accurac/juge.txt");
ofstream final_s("/Users/nianqingren/Desktop/accurac/final.txt");

struct student
{
    string school;
    string name_s;
    string name_j;
    string num;
    string phonenum;
    double scor[7];
    double ave;
}s[10];

int main(int argc, const char * argv[]) {

    int n=0,i=0;
    
    while(!stu.eof())
    {
        n++;
        stu >> s[i].school >> s[i].num >> s[i].name_s >>s[i].phonenum;
        getline(juge,s[i].name_j,' ');
        for(int j=0; j<7; j++)
        {
            juge >> s[i].scor[j];
        }
        i++;
    }
    
    for(int i=0; i<n; i++)
    {
        double sum=0;
        double max=s[i].scor[0],min=s[i].scor[0];
        for(int j=0; j<7; j++)
        {
            if(s[i].scor[j]>max)
                max=s[i].scor[j];
            
            if(min>s[i].scor[j])
                min=s[i].scor[j];
            
            sum+=s[i].scor[j];
        }
      //  cout << sum <<" "<<min <<" " << max <<endl;
        s[i].ave=(sum-min-max)/5;
    }
    student sm;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(s[i].ave<s[j].ave)
            {
                sm=s[j];
                s[j]=s[i];
                s[i]=sm;
            }
        }
    }
 
     final_s << left << setw(22) << "学院" << left << setw(22) << "学号" << left << setw(15) << "姓名" << left << setw(15) << "平均成绩" << left << setw(15) << "联系方式" << endl;
    cout << left << setw(22) << "学院" << left << setw(22) << "学号" << left << setw(15) << "姓名" << left << setw(15) << "平均成绩" << setw(15) << "联系方式" << endl;

    for(int i=0; i<n; i++)
    {
        final_s << left << setw(20) << s[i].school << left << setw(20) << s[i].num << left << setw(15) << s[i].name_s << left << setw(10) << s[i].ave << left << setw(15) << s[i].phonenum<<endl;
        
        cout << left << setw(20) << s[i].school << left << setw(20) << s[i].num << left << setw(15) << s[i].name_s << left << setw(10) << s[i].ave << left << setw(15) << s[i].phonenum << endl;
    }

    final_s.close();
    return 0;
}
