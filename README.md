## Snehasish Mishra

##Code Snipet

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<conio.h>

#include "mainpage.h"
#include "cursor.h"
#include "fileinsert1.h"
#include "fileinsert2.h"
#include "fileinsert3.h"
using namespace std;
static int top=0,top2=0,top3=0;
class login
{
public:
    login(){}
    void login_page();
    virtual void function1(){}
    virtual void function2(){}
    virtual void function3(){}
    virtual void after_login(){}
};
class sup: public login
{
public:
    sup(){}
    void function1();
    void function2();
    void function3();
private:
    void after_login();
    void file_delete1();
    void file_delete3();
};
class cit: public login
{
public:
    cit(){}
    void function1();
    void function2();
    void function3();
    void after_login();
};
void login::login_page()
{
    login *ob;
    ob= new login;
    sup ob_sup;
    cit ob_cit;
    cout<<endl;
    cout<<"\n\t1.SUPERVISOR(Login Required)\t\t\t2.CITIZEN\t\t\t3.EXIT";
    int check;
    cout<<"\n\n\n********"<<endl;
    cout<<"Your choice: ";
    cin>>check;
    if(check == 1)
    {
        ob=&ob_sup;
        ob->after_login();
    }
    else if(check == 2)
    {
        ob=&ob_cit;
        ob->after_login();
    }
    else if(check == 3)
        exit(0);
    else
    {
        system("CLS");
        cout<<"Invalid Choice"<<endl;
        mainpage::display();
        ob->login_page();
    }
        delete ob;
}
void cit::function1()
{
    login *ob;
    ob = new login;
    cit ob_cit;
    fstream file;
	file.open("data1.csv");
	char str[30][20][30];
	int r=0,i;
	while(file)
    {
        for(i=0;i<3;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
    veh_no:
    system("CLS");
    mainpage::display();
    bool status=false;
    char *ch=NULL;
    ch=new char[20];
    cout<<"\n\nThe vehicles registered are: \n";
    for(i=1;i<20+top;i=i+5)
    {
        cout<<str[i][0]<<"\t"<<str[i+1][0]<<"\t"<<str[i+2][0]<<"\t"<<str[i+3][0]<<"\t"<<str[i+4][0]<<endl;
    }
	cout<<"\n\nEnter the vehicle no: ";
	cin>>ch;
    for(i=0;i<20+top;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    cout<<"\n\n\n";
    if(status)
        {
            status = 0;
            cout<<"\t\t\t\tThe driver name is: "<<str[i][2]<<endl;
            cout<<"\t\t\t\tThe vehicle type is: "<<str[i][1]<<endl;
            cout<<"\t\t\t\tMaximum loading capacity is: "<<str[i][3]<<" kg."<<endl;
            cout<<"\n\n\tDo you want to continue with vehicle enquiry: (1 for yes, 2 for no)-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto veh_no;
            else
            {
                ob=&ob_cit;
                ob->after_login();
            }
        }
    else
        {
            status = 0;
            cout<<"Invalid Entry.\nDo you want to try again? (1 for yes  2 for no)\n****Your choice:";
            int c;
            cin>>c;
           if(c==1)
                goto veh_no;
           else
             {
                ob=&ob_cit;
                ob->after_login();
             }
        }
    delete ob;
    delete [] ch;
}
void cit::function2()
{
    login *ob;
    ob=new login;
    cit ob_cit;
    fstream file;
	file.open("data2.csv");
	char str2[30][20][30];
	int r=0,i;
	while(file)
    {
        for(i=0;i<7;i++)
            file.getline(str2[r][i],19,',');
        file.getline(str2[r][i],19,'\n');
        r++;
    }
    location:
    system("CLS");
    mainpage::display();
    bool status=false;
    char *ch2=NULL;
    ch2=new char[20];
    cout<<"\nThe locations are- \n\n";
    int j=2;
    for(i=1;i<20+top2;i+=2){
        cout<<str2[i][2]<<"\t\t"<<str2[j][2]<<endl;
        j++;
    }
	cout<<"\n\nEnter the location: ";
    getchar();
    cin.getline(ch2,99);
    for(i=0;i<20+top2;i++)
    {
        if(!strcasecmp(ch2,str2[i][2]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            int opt;
            cout<<"\n\n\t\tThe vehicle associated is "<<str2[i][1]<<endl;
            cout<<"\t\tThe dumpyard for the location is at "<<str2[i][0]<<endl;
                    link:
            cout<<"\n\t\t1.Disposal Amount    2.Garbage Type   3.Back\n\t****Your choice: ";
            cin>>opt;
            if(opt==1)
            {
                dis_check:
                    cout<<"\t\t\t1. Daily Disposal   2.Monthly Disposal  3.Return\n\t***Your choice: ";
                    int dispose;
                    cin>>dispose;
                    if(dispose==1)
                        cout<<"\n\t\t\tThe daily disposal amount is "<<str2[i][3]<<" kg\n"<<endl;
                    else if(dispose ==2)
                        cout<<"\n\t\t\tMonthly disposal amount is "<<str2[i][4]<<" kg\n"<<endl;
                    else if(dispose==3)
                        goto link;
                    else
                        {
                            cout<<"Invalid Choice"<<endl;
                            goto dis_check;
                        }
                goto dis_check;
            }
            else if(opt==2)
            {
                cout<<"\t***Type 1(Biodegradable) Garbage-> "<<str2[i][5]<<" kg"<<endl;
                cout<<"\t***Type 2(Non-Biodegradable) Garbage-> "<<str2[i][6]<<" kg"<<endl;
                cout<<"\t***Type 3(Chemical) Garbage-> "<<str2[i][7]<<" kg"<<endl;
                goto link;
            }
            else if(opt==3)
                {
                    system("CLS");
                    mainpage::display();
                    ob=&ob_cit;
                    ob->after_login();
                }
        }
    else
        {
            cout<<"\nInvalid Entry.. Do you want to try again? 1.Yes  2.No.\n****Your choice:";
            int c;
            cin>>c;
           if(c==1)
                goto location;
           else
           {
               system("CLS");
               mainpage::display();
               ob=&ob_cit;
               ob->after_login();
           }
        }
        delete ob;
        delete [] ch2;
}
void cit::function3()
{
    login *ob;
    ob= new login;
    cit ob_cit;
    fstream file3; fstream file2;
	file3.open("data3.csv");
	char str3[30][20][30];
	int r=0,i;
	while(file3)
    {
        for(i=0;i<3;i++)
            file3.getline(str3[r][i],19,',');
        file3.getline(str3[r][i],19,'\n');
        r++;
    }
    file2.open("data2.csv");
	char str2[20][20][20];
    r=0;int j;
	while(file2)
    {
        for(j=0;j<7;j++)
            file2.getline(str2[r][j],19,',');
        file2.getline(str2[r][j],19,'\n');
        r++;
    }
    bool status=false;
    char *ch3=NULL;
    ch3=new char[20];
    veh_no3:
    system("CLS");
    cout<<"\n\nThe vehicles registered are: \n";
    for(i=1;i<20+top3;i=i+5)
    {
        cout<<str2[i][1]<<"\t"<<str2[i+1][1]<<"\t"<<str2[i+2][1]<<"\t"<<str2[i+3][1]<<"\t"<<str2[i+4][1]<<endl;
    }
	cout<<"\n\nEnter the vehicle no: ";
	cin>>ch3;
    for(i=0;i<20+top3;i++)
    {
        if(!strcasecmp(ch3,str3[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
            cout<<"\n\t\t\tStarting time from "<<str3[i][3]<<" is "<<str3[i][1]<<" hours"<<endl;
            cout<<"\t\t\tArrival time at "<<str2[i][0]<<" is "<<str3[i][2]<<" hours"<<endl;
            int cho;
            cout<<"\n\nDo you wish to continue with transportation time:(1 for yes, 2 for no)-> ";
            cin>>cho;
            if(cho==1)
                goto veh_no3;
            else
                {
                    ob=&ob_cit;
                    ob->after_login();
                }
        }
    else
        {
            status = 0;
            cout<<"Invalid Entry.\nDo you want to try again? (1 for yes  2 for no) \nYour choice:";
            int c;
            cin>>c;
           if(c==1)
                goto veh_no3;
           else
           {
               system("CLS");
               mainpage::display();
               ob=&ob_cit;
               ob->after_login();
           }
        }
        delete ob;
        delete [] ch3;
}
void sup::function1()
{
    login *ob;
    ob=new login;
    sup ob_sup;
    fstream file;
	file.open("data1.csv");
	char str[30][20][30];
	int r=0,i;
	while(file)
    {
        for(i=0;i<3;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
    veh_no:
    system("CLS");
    mainpage::display();
    bool status=false; char ch[20];
    cout<<"\n\nThe vehicles registered are: \n";
    for(i=1;i<20+top;i=i+5)
    {
        cout<<str[i][0]<<"\t"<<str[i+1][0]<<"\t"<<str[i+2][0]<<"\t"<<str[i+3][0]<<"\t"<<str[i+4][0]<<endl;
    }
    cout<<"top= "<<top;
	cout<<"\n\nEnter the vehicle no: ";
	cin>>ch;
    for(i=0;i<20+top;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    cout<<"\n\n\n";
    if(status)
        {
            status = 0;
            cout<<"\t\t\t\tThe driver name is: "<<str[i][2]<<endl;
            cout<<"\t\t\t\tThe vehicle type is: "<<str[i][1]<<endl;
            cout<<"\t\t\t\tMaximum loading capacity is: "<<str[i][3]<<" kg."<<endl;
            cout<<"\n\n\tDo you want to continue with vehicle enquiry: (1 for yes, 2 for no)-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto veh_no;
            else
            {
                ob=&ob_sup;
                ob->after_login();
            }
        }
    else
        {
            status = 0;
            cout<<"Invalid Entry.\nDo you want to try again? (1 for yes  2 for no)\n****Your choice:";
            int c;
            cin>>c;
           if(c==1)
                goto veh_no;
           else
             {
                ob=&ob_sup;
                ob->after_login();
             }
        }
        delete ob;
}
void sup::function2()
{
    login *ob;
    ob=new login;
    sup ob_sup;
    fstream file;
	file.open("data2.csv");
	char str2[30][20][30];
	int r=0,i;
	while(file)
    {
        for(i=0;i<7;i++)
            file.getline(str2[r][i],19,',');
        file.getline(str2[r][i],19,'\n');
        r++;
    }
    location:
    system("CLS");
    mainpage::display();
    bool status=false; char ch2[20];
    cout<<"\nThe locations are- \n\n";
    for(i=1;i<20+top2;i++){
        cout<<str2[i][2]<<endl;
    }
	cout<<"\n\nEnter the location: ";
    getchar();
    cin.getline(ch2,99);
    for(i=0;i<20+top2;i++)
    {
        if(!strcasecmp(ch2,str2[i][2]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            int opt;
            cout<<"\n\n\t\tThe vehicle associated is "<<str2[i][1]<<endl;
            cout<<"\t\tThe dumpyard for the location is at "<<str2[i][0]<<endl;
                    link:
            cout<<"\n\t\t1.Disposal Amount    2.Garbage Type   3.Back\n\t****Your choice: ";
            cin>>opt;
            if(opt==1)
            {
                dis_check:
                    cout<<"\t\t\t1. Daily Disposal   2.Monthly Disposal  3.Return\n\t***Your choice: ";
                    int dispose;
                    cin>>dispose;
                    if(dispose==1)
                        cout<<"\n\t\t\tThe daily disposal amount is "<<str2[i][3]<<" kg\n"<<endl;
                    else if(dispose ==2)
                        cout<<"\n\t\t\tMonthly disposal amount is "<<str2[i][4]<<" kg\n"<<endl;
                    else if(dispose==3)
                        goto link;
                    else
                        {
                            cout<<"Invalid Choice"<<endl;
                            goto dis_check;
                        }
                goto dis_check;
            }
            else if(opt==2)
            {
                cout<<"\t***Type 1(Biodegradable) Garbage-> "<<str2[i][5]<<" kg"<<endl;
                cout<<"\t***Type 2(Non-Biodegradable) Garbage-> "<<str2[i][6]<<" kg"<<endl;
                cout<<"\t***Type 3(Chemical) Garbage-> "<<str2[i][7]<<" kg"<<endl;
                goto link;
            }
            else if(opt==3)
                {
                    system("CLS");
                    mainpage::display();
                    ob=&ob_sup;
                    ob->after_login();
                }
        }
    else
        {
            cout<<"\nInvalid Entry.. Do you want to try again? 1.Yes  2.No\n****Your choice:";
            int c;
            cin>>c;
           if(c==1)
                goto location;
           else
           {
               system("CLS");
               mainpage::display();
               ob=&ob_sup;
               ob->after_login();
           }
        }
        delete ob;
}
void sup::function3()
{
    login *ob;
    ob= new login;
    sup ob_sup;
    fstream file3; fstream file2;
	file3.open("data3.csv");
	char str3[30][20][30];
	int r=0,i;
	while(file3)
    {
        for(i=0;i<3;i++)
            file3.getline(str3[r][i],19,',');
        file3.getline(str3[r][i],19,'\n');
        r++;
    }
    file2.open("data2.csv");
	char str2[30][20][20];
    r=0;int j;
	while(file2)
    {
        for(j=0;j<7;j++)
            file2.getline(str2[r][j],19,',');
        file2.getline(str2[r][j],19,'\n');
        r++;
    }
    bool status=false; char ch3[20];
    veh_no3:
    system("CLS");
    cout<<"\n\nThe vehicles registered are: \n";
    for(i=1;i<20+top3;i++)
    {
        cout<<"\t\t"<<str2[i][1]<<endl;
    }
	cout<<"\n\nEnter the vehicle no: ";
	cin>>ch3;
    for(i=0;i<20+top3;i++)
    {
        if(!strcasecmp(ch3,str3[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
            cout<<"\n\t\t\tStarting time from "<<str3[i][3]<<" is "<<str3[i][1]<<" hours"<<endl;
            cout<<"\t\t\tArrival time at "<<str2[i][0]<<" is "<<str3[i][2]<<" hours"<<endl;
            int cho;
            cout<<"\n\nDo you wish to continue with transportation time:(1 for yes, 2 for no)-> ";
            cin>>cho;
            if(cho==1)
                goto veh_no3;
            else
                {
                    ob=&ob_sup;
                    ob->after_login();
                }
        }
    else
        {
            status = 0;
            cout<<"Invalid Entry.\nDo you want to try again? (1 for yes  2 for no) \nYour choice:";
            int c;
            cin>>c;
           if(c==1)
                goto veh_no3;
           else
           {
               system("CLS");
               mainpage::display();
               ob=&ob_sup;
               ob->after_login();
           }
        }
        delete ob;
}
void sup::file_delete1()
{
    char *veh_nbr=NULL;
    veh_nbr = new char[30];
    fstream file, file2;
    file.open("data1.csv",ios::in);
    ofstream file1("temp.csv");
    file1.close();
    file2.open("temp.csv",ios::in|ios::out);
    char str[30][20][30];
    char temp[30][20][30];
    int r=0,i;
    while(file)
    {
        for(i=0;i<3;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
    cout<<"\n\nThe vehicles registered are: \n";
    for(i=1;i<20+top;i=i+5)
    {
        cout<<str[i][0]<<"\t"<<str[i+1][0]<<"\t"<<str[i+2][0]<<"\t"<<str[i+3][0]<<"\t"<<str[i+4][0]<<endl;
    }
    cout<<"\nEnter the vehicle no, you want to remove: ";
    cin>>veh_nbr;
    r=0;
    int j;
    for(i=0;i<20+top;i++)
    {
        if(strcasecmp(veh_nbr ,str[i][0])) //compares the veh_nbr and str. if it doesn't matches then it stores the line in the temp.csv
        {
            for(j=0;j<3;j++)
            file2<<str[i][j]<<",";
        file2<<str[i][j]<<"\n";
        }
    }

    file.close();
        file2.close();

    //delete the original file and rename the temp file to the original
    remove("data1.csv");
    rename("temp.csv","data1.csv");
    r=0;
    file2.open("data1.csv");
    while(file2)
    {
        for(i=0;i<3;i++)
            file2.getline(temp[r][i],19,',');
        file2.getline(temp[r][i],19,'\n');
        r++;
    }
//    cout<<"The vehicles registered are : ";
//    for(i=1;i<20;i++)
//        cout<<temp[i][0]<<" ";
    delete [] veh_nbr;
}
void sup::file_delete3()
{
    char *loc=NULL;
    loc = new char[30];
    fstream file, file2;

    ofstream file1("temp1.csv");
    file1.close();

	file.open("data3.csv",ios::in);
	file2.open("temp1.csv",ios::in|ios::out);
	char str[30][20][30];
	char temp[30][20][30];
	int r=0,i;
	while(file)
    {
        for(i=0;i<3;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
    cout<<"The location registered are : \n\n";
    for(i=1;i<20+top3;i++)
        cout<<"\t\t"<<str[i][3]<<endl;
    cout<<"\nEnter the location, you want to remove: ";
    getchar();
    cin.getline(loc,20,'\n');
    r=0;
    int j;
    for(i=0;i<20+top3;i++)
    {
        if(strcasecmp(loc ,str[i][3])) //compares the veh_nbr and str. if it doesn't matches then it stores the line in the temp.csv
        {
        	for(j=0;j<3;j++)
        	file2<<str[i][j]<<",";
        file2<<str[i][j]<<"\n";
    	}
	}
    file.close();
    file2.close();
    //delete the original file and rename the temp file to the original
    remove("data3.csv");
    rename("temp1.csv","data3.csv");

    r=0;
    file2.open("data3.csv");
    while(file2)
        {
            for(i=0;i<3;i++)
                file2.getline(temp[r][i],19,',');
            file2.getline(temp[r][i],19,'\n');
            r++;
        }

    delete loc;
}
void sup::after_login()
{
     sup1:
     system("CLS");
     using namespace cursor;
     sup ob_sup;
     login *ob;
     ob = new login;
     int c=0;
     char pass[8];
     char r[9] = "password";
     int p;
     move_pointer();
     cout<<"------------------\n";
     move_pointer();
     cout<<"Password: ";

     for (int i=0;i<8;i++)
     {
          pass[i] = getch();
          cout<<"*";
     }
     for (int j=0;j<8;j++)
      {
        if (pass[j]==r[j])
        c++;
      }

     if (c == 8)
     {
         sup:
         system("CLS");
         mainpage::display();
         cout<<"\n\t\t\t\t\t\t----------------------------"<<endl;
         cout<<"\n\t\t\t\t\t\t### WELCOME SUPERVISOR ###"<<endl;
         cout<<"\n\t\t\t\t\t\t----------------------------"<<endl;
         cout<<"\n\t\t\t\t1.VEHICLE DETAILS\n\t\t\t\t2.GARBAGE TRANSPORT LOG\n\t\t\t\t3.TRANSPORTATION TIME\n\t\t\t\t4.BACK TO LOGIN PAGE";
         cout<<"\n\n\t***Your Choice: ";
         int cho2;
         cin>>cho2;
         if(cho2==1)
            {
                cout<<"\n\t\t1.VIEW DETAILS\n\t\t2.UPDATE DETAILS\n\t\t\t\t*****Your Choice: ";
                int cho3;
                cin>>cho3;
                if(cho3==2)
                    {
                        system("CLS");
                        cout<<"\n-----------------------------------------"<<endl;
                        cout<<"\t\tPress 1 to add a new vehicle detail."<<endl;
                        cout<<"\t\tPress 2 to delete a vehicle detail."<<endl;
                        cout<<"\n-----Your choice: ";
                        int cho4;
                        cin>>cho4;
                        if(cho4==1)
                            {file_insert1::main(); top++;}
                        else if(cho4==2)
                            {file_delete1(); top--;}
                        else
                            {
                                cout<<"Invalid Entry"<<endl;
                                goto sup;
                            }
                        goto sup;
                    }
                else if(cho3==1)
                {
                    ob=&ob_sup;
                    ob->function1();
                }
                else
                    {
                        cout<<"Invalid Entry"<<endl;
                        goto sup;
                    }
            }
         else if(cho2==2)
            {
                cout<<"\n\t\t1.VIEW DETAILS\n\t\t2.UPDATE DETAILS\n\t\t\t\t*****Your Choice: ";
                int cho3;
                cin>>cho3;
                if(cho3==2)
                    {
                        system("CLS");
                        cout<<"\n-----------------------------------------"<<endl;
                        cout<<"\t\tPress 1 to add a new garbage transport log."<<endl;
                        cout<<"\n-----: ";
                        int cho4;
                        cin>>cho4;
                        if(cho4==1)
                            {
                                file_insert2::main();
                                top2++;
                            }
                        else
                            {
                                cout<<"Invalid Entry"<<endl;
                                goto sup;
                            }
                        goto sup;
                    }
                else if(cho3==1)
                {
                    ob=&ob_sup;
                    ob->function2();
                }
                else
                            {
                                cout<<"Invalid Entry"<<endl;
                                goto sup;
                            }
            }
         else if(cho2==3)
            {
                cout<<"\n\t\t1.VIEW DETAILS\n\t\t2.UPDATE DETAILS\n\t\t\t\t*****Your Choice: ";
                int cho3;
                cin>>cho3;
                if(cho3==2)
                    {
                        system("CLS");
                        cout<<"\n-----------------------------------------"<<endl;
                        cout<<"\t\tPress 1 to add a new vehicle detail."<<endl;
                        cout<<"\t\tPress 2 to delete a vehicle detail."<<endl;
                        cout<<"\n-----Your choice: ";
                        int cho4;
                        cin>>cho4;
                        if(cho4==1)
                            {
                                file_insert3::main();
                                top3++;
                            }
                        else if(cho4==2)
                            {
                                file_delete3();
                                top3--;
                            }
                        else
                            {
                                cout<<"Invalid Entry"<<endl;
                                goto sup;
                            }
                        goto sup;
                    }
                else if(cho3==1)
                {
                    ob=&ob_sup;
                    ob->function3();
                }
                else
                            {
                                cout<<"Invalid Entry"<<endl;
                                goto sup;
                            }
            }
         else if(cho2==4)
         {
             system("CLS");
             mainpage::display();
             ob->login_page();
         }
     }
     else
        {
            cout<<"\nDo you want to try again? (1.Yes  2.No)\n ";
            cout<<"***Your Choice: ";
            int c_pass; cin>>c_pass;
            if(c_pass==1)
                goto sup1;
            else
            {
                system("CLS");
                ob->login_page();
            }
        }
        delete ob;
}

void cit::after_login()
{
    login *ob;
    ob= new login;
    cit ob_cit;
    system("CLS");
    mainpage::display();
    cout<<"\n\t\t\t\t\t\t----------------------------"<<endl;
    cout<<"\n\t\t\t\t\t\t### Welcome Dear Citizen ###"<<endl;
    cout<<"\n\t\t\t\t\t\t----------------------------"<<endl;
    cout<<"\n\t\t\t\t1.Vehicle Details\n\t\t\t\t2.Garbage Transport Log\n\t\t\t\t3.Transportation Time\n\t\t\t\t4.Back to Login page";
    cout<<"\n\n\t***Your Choice: ";
    int chc;
    cin>>chc;
    if(chc==1)
        {
            ob=&ob_cit;
            ob->function1();
        }

    else if(chc==2)
        {
            ob=&ob_cit;
            ob->function2();
        }

    else if(chc==3)
        {
            ob=&ob_cit;
            ob->function3();
        }

    else
    {
        system("CLS");
        mainpage::display();
        ob->login_page();
    }
    delete ob;
}
int main()
{
    mainpage::display();
    login ob_log;
    ob_log.login_page();
}

