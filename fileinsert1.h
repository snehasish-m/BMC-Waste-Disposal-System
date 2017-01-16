#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
namespace file_insert1
{
    class veh
    {
    public:
        char veh_num[10];
        char veh_type[10];
        char driver[20];
        int max_cap;
    };
    int main()
    {
        fstream f;
        veh obj;
        f.open("data1.csv",ios::app);
        cout<<"Enter vehicle number: ";
        getchar();
        cin.getline(obj.veh_num,10,'\n');
        f<<obj.veh_num;
        f<<',';
        cout<<"Enter vehicle type: ";
        cin.getline(obj.veh_type,10,'\n');
        f<<obj.veh_type;
        f<<',';
        cout<<"Enter driver name: ";
        cin.getline(obj.driver,20,'\n');
        f<<obj.driver;
        f<<',';
        cout<<"Enter max capacity: ";
        cin>>obj.max_cap;
        f<<obj.max_cap;
        f<<'\n';
        f.close();
        cout<<"Details Updated"<<endl;
}
}

