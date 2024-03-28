// Security_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "    Security System" << endl;

    cout << "___________________________" << endl << endl;
    cout << "|       1.Register         |" << endl;
    cout << "|       2.Login            |" << endl;
    cout << "|       3.Change Password  |" << endl;
    cout << "|_______4.End Program______|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice:-";
        cin >> a;
        switch (a) 
        {
            case 1: {
                cout << "__________________________" << endl << endl;
                cout << "|---------Register--------|" << endl;
                cout << "|_________________________|" << endl << endl;
                cout << "Please enter username:- ";
                cin >> name;
                cout << "Please enter the password:- ";
                cin >> password0;
                cout << "Please enter your age:- ";
                cin >> age;

                ofstream of1;
                of1.open("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0;
                    cout << "Registration successfull" << endl;
                    of1.close();
                }
                break;
            }
            case 2: {
                i = 0;

                cout << "______________________________" << endl << endl;
                cout << "|------------Login------------|" << endl;
                cout << "|_____________________________|" << endl << endl;

                ifstream of2;
                of2.open("file.txt");
                cout << "Please enter the username:- ";
                cin >> user;
                cout << "Please enter the password:- ";
                cin >> pass;

                if (of2.is_open()) 
                {
                    while (!of2.eof()) 
                    {
                        while (getline(of2, text)) 
                        {
                            istringstream iss(text);
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if (user == creds[0] && pass == creds[1]) 
                        {
                            cout << "---Log in successfull---";
                            cout << endl << endl;

                            cout << " Details: " << endl;


                            cout << "Username: " + name << endl;
                            cout << "Password: " + pass << endl;
                            cout << "Age: " + age << endl;
                        }

                        else 
                        {
                            cout << endl << endl;
                            cout << "Incorrect Credentails" << endl;
                            cout << "|    1. Press 2 to Login               |" << endl;
                            cout << "|    2. Press 3 to change password     |" << endl;
                            break;

                        }
                    }
                    of2.close();
                }
                break;
            }
            case 3: {
                i = 0;

                cout << "----------Change password------------" << endl;

                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the old password:- ";
                cin >> old;
                if (of0.is_open()) 
                {
                    while (of0.eof())
                    {
                        while (getline(of0, text))
                        {
                            istringstream iss(text);
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }

                        if (old == cp[1])
                        {
                            of0.close();

                            ofstream of1;

                            if (of1.is_open())
                            {
                                cout << "Enter your new password:- ";
                                cin >> password1;
                                cout << "Enter your password again:- ";
                                cin >> password2;

                                if (password1 == password2)
                                {
                                    of1 << cp[0] << "\n";
                                    of1 << password1;
                                    cout << "Password changed successfully" << endl;
                                }
                                else
                                {
                                    of1 << cp[0] << "\n";
                                    of1 << old;
                                    cout << "Password do not match" << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Please enter a valid password" << endl;
                            break;
                        }
                    }
                    of0.close();
                }

                break;
            }
            case 4:
            {
                cout << "______Thankyou!_____________";
                break;
            }
            default:
                cout << "Enter a volid choice";
        }
    }
    while (a != 4);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
