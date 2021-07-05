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
    

 //   void getMemberPassword(string pswd)
     string getMemberPassword() const      //*** new
    {
        return _password;                  //*** new
    }
    //void getMemberLogin(string lgn)
    string getMemberLogin() const          //*** new
    {
        return _login;                     //*** new
    }

    void setMemberLogin(const string& lgn);
    void setMemberPassword(const string& pswd);
};


