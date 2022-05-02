#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class shopping {
    private:
        int pcode;
        float price;
        float dis;
        string pname;
     
        public:
            void menu();
            void administrator();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping :: menu() 
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t       SuperMarket Main Menu        \n";                       
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\n\t\t\t|_____1) Administrator _____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____1) Buyer _____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____1) Exit _____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t Please select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Enter Email  \n";
            cin>>email;
            cout<<"\t\t\t Password     \n";
            cin>>password;

            if(email=="capo44@gmail.com" && password=="capo@44")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password";
            }
            break;

        case 2: 
        {
            buyer();
        }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout<< " Please select from the given options ";
        }
    }
goto m;
}

void shopping :: administrator() 
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____1) Add the Product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the Product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to Main Menu___|";

    cout<<"\n\t\t Please enter your choice ";
    cin>>choice;

    switch(choice) 
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<< "Invalid choice";
    }
    goto m;
}

void shopping :: buyer() 
{
    m:
    int choice;
    cout<<"\t\t\t   Buyer   \n";
    cout<<"\t\t\t________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t1)  Buy Product \n";
    cout<<"                      \n";
    cout<<"\t\t\t2)  Go Back     \n";
    cout<<"\t\t\t Enter Your Choice : ";
    
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();

        default:
            cout<< "Invalid Choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product code of product";
    cin>>pcode;
    cout<<"\n\n\t Name of Product";
    cin>>pname;
    cout<<"\n\n\t Discount on Product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data<< " "<<pcode<< " "<<pname<< " "<<price<< " "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode) 
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }

    if(token==1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data<< " "<<pcode<< " "<<pname<< " "<<price<< " "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t Record Inserted";
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product Code :";
    cin>>pkey;

    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<"\n\n File Doesn't exit! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product ne code :";
                cin>>pcode;
                cout<<"\n\t\t Name of Product :";
                cin>>pname;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>dis;
                data1<< " "<< " "<<n<< " "<<p<< " "<<d<<"\n";
                cout<<"\n\t\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<< " "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found sorry! ";
        }
    }
}

void shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token=0;

    cout<<"\n\n\t\t Delete Product";
    cout<<"\n\n\t\t Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<" File doesn't exist ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product Deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<< " "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found! ";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n|____________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice \n";
    cout<<"\n\n|____________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database ";
    }
    else
    {
        data.close();

        list();
        cout<<"\n\n__________________________________\n";
        cout<<"\n\n|                                  \n";
        cout<<"\n\n|         Please Place Order        \n";
        cout<<"\n\n|                                    \n";
        cout<<"\n\n|____________________________________\n";
        do 
        {
            cout<<"\n\n Enter Product Code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the Product Quantity : ";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code. Please Try Again ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes press y else no ";
            cin>>choice;
        }
        while(choice == 'y');
        
        cout<<"\n\n\t\t\t|____________RECEIPT_____________\n";
        cout<<"\n Product No\t Product Name\t Product Quantity \tprice \t Amount \t Amount with discount\n";
        
        for(int i=0; i<c; i++)
        {
            data.open("database1.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis/100);
                    total = total + dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n___________________________________________";
    cout<<"\n Total Amount :"<< total;
}

int main()
{
    shopping s;
    s.menu();
}