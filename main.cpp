#include "Money.h"
#include <iostream>
#include "Complex.h"
#include <windows.h> 
using namespace std;
void pause() {
    bool flag = true;
    int way;
    do {
        cout << "Enter 0 to go back" << endl;
        cin >> way;
        switch (way) {
        case 0:
            flag = false;
            break;
        default:
            break;
        }
    } while (flag);
}

void showMenuComplex() {
    cout << "Select a method to execute:" << endl;
    cout << "1. Sum" << endl;
    cout << "2. Sub" << endl;
    cout << "3. Mult" << endl;
    cout << "4. conj" << endl;
    cout << "5. divide" << endl;
    cout << "0. Exit" << endl;
}
void showMenuMoney() {
    cout << "Select a method to execute:" << endl;
    cout << "1. Sum" << endl;
    cout << "2. Sub" << endl;
    cout << "3. Mult" << endl;
    cout << "4. Divide" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    //printLogo();
    int a,b;
    int way = 0;

    cout << "Let's start!" << endl;
    cout << "Stack or ueue?" << endl;
    cout << "1. Complex" << endl;
    cout << "2. Money" << endl;
    cout << "Enter 1 or 2" << endl;
    cin >> way;
    system("cls");
    
    bool flag = false;

    Pair* pt;
    Pair* el;
    Complex* el2;
    int choice = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (way == 1) {
        pt = new Complex();
        do {
            system("cls");
            cout << "Current Complex:" << '\t';
            SetConsoleTextAttribute(hConsole, 12);
            cout << *pt << endl;
            SetConsoleTextAttribute(hConsole, 15);
            showMenuComplex();

            cout << "Enter your choice: " << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter a and b for complex to sum" << endl;
                cin >> a >> b;
                el = new Complex(a,b);
                pt = pt->sum(el);
                break;
            case 2:
                cout << "Enter a and b for complex to sub" << endl;
                cin >> a >> b;
                el = new Complex(a, b);
                pt = pt->sub(el);
                break;
            case 3:
                cout << "Enter a and b for complex to multiply" << endl;
                cin >> a >> b;
                el2 = new Complex(a, b);
                pt = (dynamic_cast<Complex*>(pt))->multiply(*el2);
                break;
            case 4:
                cout << *((dynamic_cast<Complex*>(pt))->conj()) << endl;
                pause();
                break;
            case 5:
                cout << "Enter a and b for complex to divide" << endl;
                cin >> a >> b;
                el2 = new Complex(a, b);
                pt = (dynamic_cast<Complex*>(pt))->divide(*el2);
                break;
            case 0:
                cout << "Leaving the programm." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 0);
    }
    else if (way == 2) {
        pt = new Money();
        do {
            system("cls");
            cout << "Current money:" << '\t';
            SetConsoleTextAttribute(hConsole, 12);
            cout << *pt << endl;
            SetConsoleTextAttribute(hConsole, 15);
            showMenuMoney();

            cout << "Enter your choice: " << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter a and b for money to sum" << endl;
                cin >> a >> b;
                el = new Money(a, b);
                pt = pt->sum(el);
                pause();
                break;
            case 2:
                cout << "Enter a and b for complex to sub" << endl;
                cin >> a >> b;
                el = new Complex(a, b);
                pt = pt->sub(el);
                break;
            case 3:
                cout << "Enter a number to multiply" << endl;
                cin >> a;
                pt = dynamic_cast<Money*>(pt)->multiply(a);
                break;
            case 4:
                cout << "Enter a number to divide" << endl;
                cin >> a;
                pt = dynamic_cast<Money*>(pt)->divide(a);
                break;
            case 0:
                cout << "Leaving the programm." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 0);
    }
    else {
        throw invalid_argument("пу пу пу");
    }
}


