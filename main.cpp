#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student
{
    string id;
    string name;
    int score;
};

template <class T>
T getMax(T a,T b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template <class T>
T getMin(T a,T b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
}  
    }
    

int main()
{
    vector <Student> students;
    int choice;

    while(true)
    {
        cout<<"---Student Performance Management System---"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. List All Students"<<endl;
        cout<<"3. Sort By Score"<<endl;
        cout<<"4. Search By ID"<<endl;
        cout<<"5. Show Statisics"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        if(choice==0)
        {
            cout<<"Exiting..."<<endl;
            break;
        }

        switch(choice)
        {
            case 1:
            {
                Student new_stu;
                cout<<"Enter ID: "<<endl;
                cin>>new_stu.id;

                bool is_duplicate=false;
                for(int i=0;i<students.size();i++)
                {
                    if(students[i].id==new_stu.id)
                    {
                        is_duplicate=true;
                        break;
                    }
                }
                if(is_duplicate)
                {
                    cout<<"ERROR:This ID already exists!"<<endl;
                }
                else
                {
                   cout<<"Enter student's name: "<<endl;
                    cin>>new_stu.name;
                    cout<<"Enter student's score: "<<endl;
                    cin>>new_stu.score;

                    students.push_back(new_stu);
                    cout<<"Add Success!"<<endl; 
                }
                
                break;
            }
            case 2:
            {
                cout<<"---Student List---"<<endl;
                if(students.empty())
                {
                    cout<<"No students data available."<<endl;
                }
                else
                {
                    for(int i=0;i<students.size();i++)
                    {
                        cout<<"ID: "<<students[i].id<<endl;
                        cout<<"Name: "<<students[i].name<<endl;
                        cout<<"Score: "<<students[i].score<<endl;
                        cout<<endl;
                    }
                }
                break;
            }
            
            case 3:
            {
                sort(students.begin(),students.end(),[](const Student& a,const Student& b)
                {
                    return a.score>b.score;
                });
                cout<<"Sort Success!"<<endl;

                break;
            }

            case 4:
            {
                string target_id;
                cout<<"Enter the student's ID you want to find: "<<endl;
                cin>>target_id;
                bool found=false;
                for(int i=0;i<students.size();i++)
                {
                    if(target_id==students[i].id)
                    {
                        found=true;
                        cout<<"ID: "<<students[i].id<<endl;
                        cout<<"Name: "<<students[i].name<<endl;
                        cout<<"Score: "<<students[i].score<<endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout<<"Student not found!"<<endl;
                    break;
                }

                break;
            }

            case 5:
            {
                if(students.empty())
                {
                    cout<<"No students data available."<<endl;
                    break;
                }

                int sum=0;
                int max_s=-1;
                int min_s=101;
                int pass=0;
                int fail=0;

                for(int i=0;i<students.size();i++)
                {
                    sum+=students[i].score;
                    if(students[i].score>=60)
                    {
                        pass++;
                    }
                    else
                    {
                        fail++;
                    }
                    max_s=getMax(max_s,students[i].score);
                    min_s=getMin(min_s,students[i].score);
                }
                cout<<"Average Score: "<<(float)sum/students.size()<<endl;
                cout<<"Highest Score: "<<max_s<<endl;
                cout<<"Lowest Score: "<<min_s<<endl;
                cout<<"Pass: "<<pass<<endl;
                cout<<"Fail: "<<fail<<endl;

                break;
            }

            default:
                cout<<"Error,please enter again"<<endl;
        }
    }

    return 0;
}