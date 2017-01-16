#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
namespace file_insert3
{
        class location
{
public:
    char veh_num[20];
    char start_time[10];
    char end_time[10];
    char location[20];
};
int main()
{
    fstream f;
    location obj;
        f.open("data3.csv",ios::app);
        cout<<"Enter vehicle number: ";
        getchar();
        cin.getline(obj.veh_num,20,'\n');
        f<<obj.veh_num;
        f<<',';
        cout<<"Enter start time: ";
        cin.getline(obj.start_time,10,'\n');
        f<<obj.start_time;
        f<<',';
        cout<<"Enter end time: ";
        cin.getline(obj.end_time,10,'\n');
        f<<obj.end_time;
        f<<',';
        cout<<"Enter location: ";
        cin>>obj.location;
        f<<obj.location;
        f<<'\n';
        f.close();
}
}



