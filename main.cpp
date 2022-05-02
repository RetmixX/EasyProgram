#include <iostream>
#include <string>
#include <time.h>
#include "User.h"

using namespace std;
string GenerateRandomPassword();
void ShowMenu();

int main()
{
    UserFunc test;//Для использования функций класса
    UserFunc UserArray[3];//Массив класса
    ////////////////////////Псевдо БД/////////////////////
    UserArray[0] = UserFunc("retmix", "123");
    UserArray[1] = UserFunc("vadim", "qwe");
    UserArray[2] = UserFunc("test", "test");
    //////////////////////////////////////////////////////
    UserFunc *ptrLoginUser;//Хранит в себе указатель на нужный класс
    string inputLogin, inputPassword;
    int command;
    bool b = false;

    cout<<"Write your login: ";
    cin>>inputLogin;
    cout<<"Write your password: ";
    cin>>inputPassword;

    for (int i = 0; i < 3; ++i) {
        if (UserArray[i].CheckLoginAndPassword(inputLogin, inputPassword))
        {
            ptrLoginUser = &UserArray[i];
            b = true;
        }
    }


    if (b)
    {
        while (true)
        {
            ShowMenu();
            cout<<"Your choose: ";
            cin>>command;
            if (command==0)
            {
                cout<<"Your exit from program";
                break;
            }
            switch (command) {

                case 1:
                {
                    test.CheckInfo(ptrLoginUser);
                    break;
                }

                case 2:
                {
                    string newLogin, newPassword, yes;
                    cout<<"Write your new login: ";
                    cin>>newLogin;
                    cout<<"Do you want to generate a password?\n>";
                    cin>> yes;
                    if (yes=="yes"|| yes == "Yes" || yes == "YES")
                    {
                        newPassword = GenerateRandomPassword();
                        cout<<"Your password: "<<newPassword<<endl;
                    }
                    else
                    {
                        cout<<"Write your new password: ";
                        cin>> newPassword;
                    }
                    test.ChangeDataAboutUser(newLogin, newPassword, ptrLoginUser);
                    break;
                }

                default:
                {
                    cout<<"Action not found!\n";
                    break;
                }
            }
        }
    }
    else
    {
        cout<<"Wrong login or password!"<<endl;
    }

    return 0;
}

string GenerateRandomPassword()
{
    srand(time(0));
    string dataSymbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "abcdefghijklmnopqrstuvwxyz"
                         "0123456789"
                         "!@#$";

    string newPassword;

    for (int i = 0; i <=10 ; ++i)
    {
        newPassword+= dataSymbols[rand()%66];
    }

    return newPassword;
}

void ShowMenu()
{
    cout<<"<===Commands===>"<<endl;
    cout<<"1 - Show my profile\n2 - Change my data\n0 - Exit from program\n";
    cout<<"<===Commands===>\n";
}


