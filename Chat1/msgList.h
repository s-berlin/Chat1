//============== ���� msgList.h ================
#include "message.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

class msgList
{
    short msgQty = 0;          //�������� ���-�� ���������
public:
    message* Messages[100];

    void addMessage(message* msg) //���������� ��������� 
    {
//        const string lgn;
//        msg->getMemberLogin(lgn);
        Messages[msgQty] = msg;
        msgQty++;
    }
    void delMessage(int num_del, string to) //�������� ��������� ��������� 
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

    //------- ����� ��������� �� ������ � ������ --------
    /*
    int find_login(const string log, const string pswd)
    {
        for (int i = 0; i < membQty; i++)
        {
            member* mbr = Members[i];

            if (log == mbr->_login) // �������� ������
            {
                if (pswd == mbr->_password) return i + 1; // �������� ������
                else return -2;                           // �������� ������
            };
        }
        return -1;                                        // �� ������ �����
    }
    */
    //------- �������� ������ ���������  --------
    void showMsgList()
    {

        setlocale(LC_ALL, "");  //--- ?
        cout << "������ ���������:" << endl;

        for (int i = 0; i < msgQty; i++)
        {
            message* msg = Messages[i];

            cout << msg->_numb << "     �� ����: " << msg->_from << "     ����: " << msg->_to << "     �����: " << msg->_msg << endl;
        }
    }
    
    //------- �������� ������ �������� ���������  --------
    void showMsgListTo(string to)
    {
        setlocale(LC_ALL, "");  //--- ?
        cout << "������ �������� ���������:" << endl;

        for (int i = 0; i < msgQty; i++)
        {
            message* msg = Messages[i];

            if( msg->_to == to || msg->_to == "all") cout << "   " << msg->_numb << "     �� ����: " << msg->_from << "     ����: " << msg->_to << "     �����: " << msg->_msg << endl;
        }
    }


  
    void writeMsgList()
    {
        char from[20], to[20], msg[255];

        FILE* f_msg;          // ���� �������������
        setlocale(LC_ALL, "");

        f_msg = fopen("msg.dat", "w");

 //       cout << "������ ���������" << endl;

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


