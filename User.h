//
// Created by james on 02.05.2022.
//

#include <iostream>
#include <string>


using namespace std;

class UserFunc
{
private:
    string login;
    string password;

public:
    UserFunc(string _login, string _password)
    {
        login = _login;
        password = _password;
    }

    UserFunc()
    {

    }

    bool CheckLoginAndPassword(string _login, string _password)
    {
        return login==_login && password == _password;
    }

    void CheckInfo(UserFunc *point)
    {
        cout<<"Your login: "<<point->login<<endl;
        cout<<"Your password: "<<point->password<<endl;
    }

    bool ChangeDataAboutUser(string _login, string _password, UserFunc *point)
    {
        if (NewLogin(_login, point))
        {
            cout<<"Choose new login! "<<endl;
            return false;
        }

        if (NewPassword(_password, point))
        {
            cout<<"Choose new password"<<endl;
            return false;
        }

        point->login = _login;
        point->password = _password;
        return true;
    }

private:
    bool NewLogin(string _login, UserFunc *point) //If return false is true
    {
        return _login== point->login;
    }

    bool NewPassword(string _password, UserFunc *point) //If return false is true
    {
        return _password == point->password;
    }
};
