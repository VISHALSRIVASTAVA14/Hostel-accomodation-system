#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class hostel
{
    private:
    string name;
    int rent;

    public:
    int bed;

    public:
    hostel(string n,int r,int b)
    {
        name=n;
        rent=r;
        bed=b;
    }
    string put_n()
    {
        return name;
    }
    int put_rent()
    {
        return rent;
    }
    int put_bed()
    {
        return bed;
    }
};

class student
{
    private:
    string name,roll_no,address;

    public:
    student():name(""),roll_no(""),address(""){}
    void get_name(string n)
    {
        name=n;
    }
    void get_roll_no(string r)
    {
        roll_no=r;
    }
    void get_address(string a)
    {
        address=a;
    }
    string put_name()
    {
        return name;
    }
    string put_roll_no()
    {
        return roll_no;
    }
    string put_address()
    {
        return address;
    }
};

void add(student a,hostel h)
{
    system("cls");
    string n,r,ad;
    cout<<"\t ENTER NAME:";
    cin>>n;
    cout<<"\t ENTER ROLL NO:";
    cin>>r;
    cout<<"\t ENTER ADDRESS:";
    cin>>ad;
    a.get_name(n);
    a.get_roll_no(r);
    a.get_address(ad);
    if(h.bed>0)
    {
        ofstream out("student.txt",ios::app);
        if(!out)
        {
            cout<<"error in opening the file";
        }
        else
        {
            out<<a.put_name()<<"|"<<a.put_roll_no()<<"|"<<a.put_address()<<"|"<<endl;
            cout<<"\t BED RESERVED SUCCESSFULLY!!!"<<endl;
            Sleep(3000);
            h.bed=h.bed-1;   
        }
    }
    else
    {
        cout<<"SORRY BED NOT AVAILABLE"<<endl;
    }
    
}

int main()
{
    hostel h("surajmal",5000,2);
    student a;
    bool code=true;
    while(code)
    {
        int choice;
        system("cls");
        cout<<"\t WELCOME TO HOSTEL ACCOMODATION SYSTEM"<<endl;
        cout<<"\t *************************************"<<endl;
        cout<<"\t 1. RESERVE A BED"<<endl;
        cout<<"\t 2. EXIT"<<endl<<endl;
        cout<<"\t Enter choice:";
        cin>>choice;
        if(choice==1)
        {
            add(a,h);
        }
        else if(choice==2)
        {
            system("cls");
            code=false;
            cout<<"GOOD LUCK";
        }
    }
}