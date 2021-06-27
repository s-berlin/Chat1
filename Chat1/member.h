//===== פאיכ member.h =============
#pragma once
#include <iostream>
#include <string>

using namespace std;

class member
{
public:
    const string _login;
    const string _password;
//public:


    member(const string& login, const string& password);
    member(const string& login);
    member() = default;

    ~member() = default;
    

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


