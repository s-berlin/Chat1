//============== ���� message.cpp ==================
#include "message.h"
message::message(const string& from, const string& to, const string& msg) : _from(from), _to(to), _msg(msg) {}
message::message(const string& from, const string& to, const string& msg, int& numb) : _from(from), _to(to), _msg(msg), _numb(numb) {}
