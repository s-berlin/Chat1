//============== файл msgList.h ================
#include "message.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

class msgList
{
    short msgQty = 0;          //реальное кол-во сообщений
public:
    message* Messages[100];

    void addMessage(message* msg) //добавление сообщения 
    {
//        const string lgn;
//        msg->getMemberLogin(lgn);
        Messages[msgQty] = msg;
        msgQty++;
    }
    void delMessage(int num_del, string to) //удаление заданного сообщения 
    {
        int i_del = -1;

        for (int i = 0; i < msgQty; i++)
        {
            message* msg = Messages[i];
            if (msg->_numb == num_del && msg->_to == to)
            {
                i_del = i;
                break;
            }
        }
        if (i_del != -1)
        {
            for (int i = i_del; i < msgQty - 1; i++) Messages[i] = Messages[i + 1];
            msgQty--;
        }      
    }

    //------- Поиск участника по логину и паролю --------
    /*
    int find_login(const string log, const string pswd)
    {
        for (int i = 0; i < membQty; i++)
        {
            member* mbr = Members[i];

            if (log == mbr->_login) // проверка логина
            {
                if (pswd == mbr->_password) return i + 1; // проверка пароля
                else return -2;                           // неверный пароль
            };
        }
        return -1;                                        // не найден логин
    }
    */
    //------- Показать список сообщений  --------
    void showMsgList()
    {

        setlocale(LC_ALL, "");  //--- ?
        cout << "Список сообщений:" << endl;

        for (int i = 0; i < msgQty; i++)
        {
            message* msg = Messages[i];

            cout << msg->_numb << "     От кого: " << msg->_from << "     Кому: " << msg->_to << "     Текст: " << msg->_msg << endl;
        }
    }
    
    //------- Показать список входящих сообщений  --------
    void showMsgListTo(string to)
    {
        setlocale(LC_ALL, "");  //--- ?
        cout << "Список входящих сообщений:" << endl;

        for (int i = 0; i < msgQty; i++)
        {
            message* msg = Messages[i];

            if( msg->_to == to || msg->_to == "all") cout << "   " << msg->_numb << "     От кого: " << msg->_from << "     Кому: " << msg->_to << "     Текст: " << msg->_msg << endl;
        }
    }


  
    void writeMsgList()
    {
        char from[20], to[20], msg[255];

        FILE* f_msg;          // файл пользователей
        setlocale(LC_ALL, "");

        f_msg = fopen("msg.dat", "w");

 //       cout << "Запись сообщений" << endl;

        for (int i = 0; i < msgQty; i++)
        {
            message* mess = Messages[i];

 //           cout << mess->_from << "   " << mess->_to << "   " << mess->_msg << endl;

            strcpy(from, mess->_from.c_str());
            strcpy(to, mess->_to.c_str());
            strcpy(msg, mess->_msg.c_str());

            fprintf(f_msg, "%s %s %s %d\n", from, to, msg, i + 1);
        }
        fclose(f_msg);
    }

};


