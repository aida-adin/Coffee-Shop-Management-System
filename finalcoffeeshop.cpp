#include <iostream>
#include<fstream>

using namespace std;

class product{
public:
    string name;
    double price;
    product(string n,int p):name(n),price(p){}
    product()
    {}
};

class food {
    public:
        product s[3];

        food()
        {
        s[0]=product("hot dog",70000);
        s[1]=product("hamburger",90000);
        s[2]=product("caesar salad",65000);
        }

};

class hotdrink{
    public:
       product s[5];

       hotdrink()
       {
           s[0]=product("lstte",70000);
           s[1]=product("hotchocolate",55000);
           s[2]=product("espresso coffee",60000);
           s[3]=product("tea",30000);
           s[4]=product("cappucino",50000);
       }
};

class colddrink{
    public:
        product s[5];
        colddrink()
        {
            s[0]=product("ice americano",65000);
            s[1]=product("ice latte",75000);
            s[2]=product("orange juice",55000);
            s[3]=product("pomegranate juice",45000);
            s[4]=product("water",5000);
        }
};

class customer{
public:
    string name;
    string phone;
    customer(string n,string p):name(n),phone(p){}
};

void menu(food &f,hotdrink& h,colddrink &c)
{
    ofstream menufile("menu.txt");
    if(!menufile.is_open())
    {   cout<<"error opening file!";
        return;}
        cout<<"food menu:\n";
        menufile<<"food menu:\n";
        int i;
        for(i=0;i<3;i++){
            cout<<f.s[i].name<<": "<<f.s[i].price<<endl;
            menufile<<f.s[i].name<<": "<<f.s[i].price<<endl;}
        cout<<"\nhot drink menu:\n";
        menufile<<"\nhot drink menu:\n";
        for(i=0;i<5;i++){
           cout<<h.s[i].name<<": "<<h.s[i].price<<endl;
            menufile<<h.s[i].name<<": "<<h.s[i].price<<endl;}
        cout<<"\ncold drink menu:\n";
        menufile<<"\ncold drink menu:\n";
        for(i=0;i<5;i++){
            cout<<c.s[i].name<<": "<<c.s[i].price<<endl;
            menufile<<c.s[i].name<<": "<<c.s[i].price<<endl;}
        menufile.close();
    }

void order(customer&cu,product ord[],int n,string date)
{
    string filen="order_"+date+"-"+cu.name+".txt";
    ofstream file(filen,ios::app);
    if(!file.is_open())
    {
        cout<<"error opening file!"<<endl;
        return;
    }
    double total=0.0;
    cout<<"\n\ncustomer name: "<<cu.name<<endl;
    file<<"customer name: "<<cu.name<<endl;
    cout<<"phone Number: "<<cu.phone<<endl;
    file<<"phone Number: "<<cu.phone<<endl;
    cout<<"order Details:\n";
    file<<"order Details:\n";
    for(int i=0;i<n;i++)
    {
        cout<<ord[i].name<<"-"<<ord[i].price<<"t\n";
        file<<ord[i].name<<"-"<<ord[i].price<<"t\n";
        total+=ord[i].price;

    }
    cout<<"total: "<<total<<"t\n";
    file<<"total: "<<total<<"t\n";
    file.close();

    string incomefilen="daily_income.txt";
    ofstream incomefile(incomefilen,ios::app);
    if(!incomefile.is_open())
       {
           cout<<"error opening file!"<<endl;
            return;
       }
    incomefile<<date<<" "<<total<<endl;
    incomefile.close();}


void dailyreport(string date){
    string incomefilen="daily_income.txt";
    ifstream incomefile(incomefilen);
    if(!incomefile.is_open())
       {
           cout<<"error opening file!"<<endl;
            return;
       }
    double dailyincome=0.0;
    string file_date;
    double amount;
    while(incomefile>>file_date>>amount)
    {
        if(file_date==date)
            dailyincome+=amount;
    }
    incomefile.close();

    string reportfilen="daily_report_"+date+".txt";
    ofstream reportfile(reportfilen);
    if(!reportfile.is_open())
       {
           cout<<"error opening file!"<<endl;
            return;
       }
       reportfile<<"daily income for "<<date<<" : "<<dailyincome<<"t\n";
       reportfile.close();
       cout<<"\ndaily income for "<<date<<" : "<<dailyincome<<"t\n";
    }
int main()
{
    food f;
    hotdrink h;
    colddrink c;
    menu(f,h,c);

    string date;
    cout<<"\nenter the date (YYYY-MM-DD): ";
    cin>>date;

   string name,phone;
   cout<<"enter customer name: ";
   cin>>name;
   cout<<"enter customer phone: ";
   cin>>phone;
   customer cu(name,phone);

   int n;
   cout<<"enter number of products to order: ";
   cin>>n;

   product orders[n];
   int choice,item,i;
   for(i=0;i<n;i++){
    cout<<"\nchoose a product to order from:\n";
    cout<<"1-food\n2-hot dreink\n3-cold drink\n";
    cout<<"enter choice: ";
    cin>>choice;

    switch(choice){
    case 1:
        cout<<"Enter food item number(0-2): ";
        cin>>item;
        if(item>=0&&item<3)
            orders[i]=f.s[item];
        else
            cout<<"invalid choice!\n";
        break;
    case 2:
        cout<<"Enter hot drink item number(0-4): ";
        cin>>item;
        if(item>=0&&item<5)
            orders[i]=h.s[item];
        else
            cout<<"invalid choice!\n";
        break;
    case 3:
        cout<<"Enter cold drink item number(0-4): ";
        cin>>item;
        if(item>=0&&item<5)
            orders[i]=c.s[item];
        else
            cout<<"invalid choice!\n";
        break;
    default:
        cout<<"invalid choice!";
        i--;
        }
        }
    order(cu,orders,n,date);
    dailyreport(date);
    return 0;
}