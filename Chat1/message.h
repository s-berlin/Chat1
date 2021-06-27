//===== ���� message.h =============
#pragma once
#include <iostream>
#include <string>

using namespace std;

class message
{
public:
    const string _msg;    // ����� ���������
    const string _from;   // �� ����
    const string _to;     // ����
    int _numb;            // ���������� ����� ���������

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


