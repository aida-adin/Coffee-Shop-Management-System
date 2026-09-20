#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class product {
public:
    string name;
    double price;

    product(string n, double p) : name(n), price(p) {}

    product() : name(""), price(0.0) {}
};

class food {
public:
    product s[3];

    food() {
        s[0] = product("hot dog", 70000);
        s[1] = product("hamburger", 90000);
        s[2] = product("caesar salad", 65000);
    }
};

class hotdrink {
public:
    product s[5];

    hotdrink() {
        s[0] = product("latte", 70000);
        s[1] = product("hot chocolate", 55000);
        s[2] = product("espresso coffee", 60000);
        s[3] = product("tea", 30000);
        s[4] = product("cappuccino", 50000);
    }
};

class colddrink {
public:
    product s[5];

    colddrink() {
        s[0] = product("ice americano", 65000);
        s[1] = product("ice latte", 75000);
        s[2] = product("orange juice", 55000);
        s[3] = product("pomegranate juice", 45000);
        s[4] = product("water", 5000);
    }
};

class customer {
public:
    string name;
    string phone;

    customer(string n, string p) : name(n), phone(p) {}
};

void menu(food& f, hotdrink& h, colddrink& c) {
    ofstream menufile("menu.txt");

    if (!menufile.is_open()) {
        cout << "Error opening menu file!" << endl;
        return;
    }

    cout << "Food menu:\n";
    menufile << "Food menu:\n";

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << f.s[i].name
             << ": " << f.s[i].price << " T" << endl;

        menufile << i + 1 << ". " << f.s[i].name
                 << ": " << f.s[i].price << " T" << endl;
    }

    cout << "\nHot drink menu:\n";
    menufile << "\nHot drink menu:\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << h.s[i].name
             << ": " << h.s[i].price << " T" << endl;

        menufile << i + 1 << ". " << h.s[i].name
                 << ": " << h.s[i].price << " T" << endl;
    }

    cout << "\nCold drink menu:\n";
    menufile << "\nCold drink menu:\n";

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << c.s[i].name
             << ": " << c.s[i].price << " T" << endl;

        menufile << i + 1 << ". " << c.s[i].name
                 << ": " << c.s[i].price << " T" << endl;
    }

    menufile.close();
}

void order(customer& cu, const vector<product>& ord, const string& date) {
    string filen = "order_" + date + "-" + cu.name + ".txt";

    ofstream file(filen, ios::app);

    if (!file.is_open()) {
        cout << "Error opening order file!" << endl;
        return;
    }

    double total = 0.0;

    cout << "\nCustomer name: " << cu.name << endl;
    file << "Customer name: " << cu.name << endl;

    cout << "Phone number: " << cu.phone << endl;
    file << "Phone number: " << cu.phone << endl;

    cout << "Order details:\n";
    file << "Order details:\n";

    for (const product& p : ord) {
        cout << p.name << " - " << p.price << " T" << endl;
        file << p.name << " - " << p.price << " T" << endl;

        total += p.price;
    }

    cout << "Total: " << total << " T" << endl;
    file << "Total: " << total << " T" << endl;

    file.close();

    ofstream incomefile("daily_income.txt", ios::app);

    if (!incomefile.is_open()) {
        cout << "Error opening income file!" << endl;
        return;
    }

    incomefile << date << " " << total << endl;
    incomefile.close();
}

void dailyreport(const string& date) {
    ifstream incomefile("daily_income.txt");

    if (!incomefile.is_open()) {
        cout << "Error opening income file!" << endl;
        return;
    }

    double dailyincome = 0.0;
    string file_date;
    double amount;

    while (incomefile >> file_date >> amount) {
        if (file_date == date) {
            dailyincome += amount;
        }
    }

    incomefile.close();

    string reportfilen = "daily_report_" + date + ".txt";

    ofstream reportfile(reportfilen);

    if (!reportfile.is_open()) {
        cout << "Error opening report file!" << endl;
        return;
    }

    reportfile << "Daily income for " << date
               << ": " << dailyincome << " T" << endl;

    reportfile.close();

    cout << "\nDaily income for " << date
         << ": " << dailyincome << " T" << endl;
}

int main() {
    food f;
    hotdrink h;
    colddrink c;

    menu(f, h, c);

    string date;

    cout << "\nEnter the date (YYYY-MM-DD): ";
    cin >> date;

    string name;
    string phone;

    cin.ignore();

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter customer phone: ";
    cin >> phone;

    customer cu(name, phone);

    int n;

    do {
        cout << "Enter number of products to order (1-20): ";
        cin >> n;

        if (n < 1 || n > 20) {
            cout << "Invalid number. Please enter a number between 1 and 20.\n";
        }

    } while (n < 1 || n > 20);

    vector<product> orders;

    for (int i = 0; i < n; i++) {
        int choice;
        int item;
        bool valid = false;

        while (!valid) {
            cout << "\nChoose a product category:\n";
            cout << "1 - Food\n";
            cout << "2 - Hot drink\n";
            cout << "3 - Cold drink\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {

            case 1:
                cout << "Enter food item number (1-3): ";
                cin >> item;

                if (item >= 1 && item <= 3) {
                    orders.push_back(f.s[item - 1]);
                    valid = true;
                }
                else {
                    cout << "Invalid food item!\n";
                }
                break;

            case 2:
                cout << "Enter hot drink item number (1-5): ";
                cin >> item;

                if (item >= 1 && item <= 5) {
                    orders.push_back(h.s[item - 1]);
                    valid = true;
                }
                else {
                    cout << "Invalid hot drink item!\n";
                }
                break;

            case 3:
                cout << "Enter cold drink item number (1-5): ";
                cin >> item;

                if (item >= 1 && item <= 5) {
                    orders.push_back(c.s[item - 1]);
                    valid = true;
                }
                else {
                    cout << "Invalid cold drink item!\n";
                }
                break;

            default:
                cout << "Invalid category choice!\n";
            }
        }
    }

    order(cu, orders, date);
    dailyreport(date);

    return 0;
}
