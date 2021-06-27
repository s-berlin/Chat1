//=== פאיכ memper.cpp =======
#include "member.h"
#include "message.h"

member::member(const string& login, const string& password) : _login(login), _password(password) {}
member::member(const string& login) : _login(login) {}

