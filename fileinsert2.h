#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
namespace file_insert2
{
        class location
        {
        public:
            char dumpyard[20];
            char vehicle[20];
            char location[20];
            int daily;
            int monthly;
            int type1;
            int type2;
            int type3;
        };
    int main()
    {
        fstream f;
        location obj;
        f.open("data2.csv",ios::app);
        cout<<"Enter new dumpyard: ";
        getchar();
        cin.getline(obj.dumpyard,20,'\n');
        f<<obj.dumpyard;
        f<<',';
        cout<<"Enter new vehicle no.: ";
        cin.getline(obj.vehicle,20,'\n');
        f<<obj.vehicle;
        f<<',';
        cout<<"Enter new location:";
        cin.getline(obj.location,20,'\n');
        f<<obj.location;
        f<<',';
        cout<<"Enter Daily garbage amount: ";
        cin>>obj.daily;
        f<<obj.daily;
        f<<',';
        cout<<"Enter Monthly garbage amount: ";
        cin>>obj.monthly;
        f<<obj.monthly;
        f<<',';
        cout<<"Enter amount of biodegradable waste: ";
        cin>>obj.type1;
        f<<obj.type1;
        f<<',';
        cout<<"Enter amount of non biodegradable waste: ";
        cin>>obj.type2;
        f<<obj.type2;
        f<<',';
        cout<<"Enter amount of chemical waste: ";
        cin>>obj.type3;
        f<<obj.type3;
        f<<'\n';
        f.close();
    }
}




