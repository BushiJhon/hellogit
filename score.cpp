#include <fstream>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Student{
    string name;
    string sex;
    string score;
    double nscore;
    void convert(){ 
         char _temp[5];
         strcpy(_temp, score.c_str());
         nscore=atof(_temp);
         }   
};

void average(vector<Student> x){
    double sum=0;
    int count=x.size()-1;
    for(int i=0;i<x.size();++i)
    { 
       sum+=x[i].nscore;
    }
    cout<<"The average is : "<<sum/count<<endl;
}

void male_average(vector<Student> x){
     double sum=0;
     int count=0;
     for(int i=0;i<x.size()-1;++i)
     {
       if(x[i].sex=="Male")
       {
         ++count;
         sum+=x[i].nscore;
       }
     }
     cout<<"The average of male is : "<<sum/count<<endl;
}

void female_average(vector<Student> x){
     double sum=0;
     int count=0;
     for(int i=0;i<x.size()-1;++i)
     {
       if(x[i].sex=="Female")
       {
         ++count;
         sum+=x[i].nscore;
       }
     }
      cout<<"The average of female is : "<<sum/count<<endl;
}

void sort(vector<Student> x){
     for(int i=0;i<x.size()-1;++i)
     {
       for(int j=i+1;j<x.size()-1;++j)
       {
         if(x[j].nscore>x[i].nscore)
         {
           string name_temp=x[i].name;
           string sex_temp=x[i].sex;
           double nscore_temp=x[i].nscore;
           x[i].name=x[j].name;
           x[i].sex=x[j].sex;
           x[i].nscore=x[j].nscore;
           x[j].name=name_temp;
           x[j].sex=sex_temp;
           x[j].nscore=nscore_temp;
         }
         else
         {
            if(x[i].nscore==x[j].nscore)
            {
              if(x[i].name.length()>x[j].name.length())
              {
                string name_temp=x[i].name;
                string sex_temp=x[i].sex;
                x[i].name=x[j].name;
                x[i].sex=x[j].sex;
                x[j].name=name_temp;
                x[j].sex=sex_temp;
              }
            }
          }
       }
      }
      for(int i=0;i<x.size()-1;++i)
      {
        cout<<x[i].name<<endl;
        cout<<x[i].sex<<endl;
        cout<<x[i].nscore<<endl;
      }
}
vector <Student> all;
int main(){
    freopen("score.csv", "r", stdin);
    string Outline;
    getline(cin, Outline);
    string line;
    Student temp;
    string space;
    while(cin)
    {
      getline(cin, line, ',');
      temp.name=line;
      getline(cin, space, ' ');
      getline(cin, line, ',');
      temp.sex=line;
      getline(cin, space, ' ');
      getline(cin, line);
      temp.score=line;
      cout<<temp.score<<endl;
      all.push_back(temp);
    }
    for(int i=0;i<all.size()-1;++i)
    {
      all[i].convert();
    }
    fclose(stdin);
    cout<<endl;
    average(all);
    cout<<endl;
    male_average(all);
    cout<<endl;
    female_average(all);
    cout<<endl;
    sort(all);
    return 0;
}
