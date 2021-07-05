//===== файл message.h =============
#pragma once
#include <iostream>
#include <string>

using namespace std;

class message
{
public:
    const string _from;   // от кого  //***  поменял порядок
    const string _to;     // кому
    const string _msg;    // текст сообщения
    int _numb;            // порядковый номер сообщения

    message(const string& from, const string& to, const string& msg);
    message(const string& from, const string& to, const string& msg, int& numb);  

    message() = default;

    ~message() = default;
};

/*
    void getMemberPassword(string pswd)
    {
        pswd = _password;
    };
    void getMemberLogin(string lgn)
    {
        lgn = _login;
    };

    void setMemberLogin(const string& lgn);
    void setMemberPassword(const string& pswd);
};
*/


