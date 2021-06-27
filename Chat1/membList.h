//============== ���� membList.h ==================
#include "member.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class membList
{
    short membQty = 0;          //�������� ���-�� ���������� ����
public:
    member* Members[10];

    //----------------------------- ���������� ���������
    void addMember(member* mbr) 
    {
    //    const string lgn;
    //    mbr->getMemberLogin(lgn);
        Members[membQty] = mbr;
        membQty++;
    }

    //---------------- ����� ��������� �� ������ � ������ --------
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
    //------- �������� ������ ���������� --------
    void showMembList()
    {
    //   const string lgn, pswd;
        cout << "������ ����������" << endl;
        for (int i = 0; i < membQty; i++)
        {
            member* mbr = Members[i];

            cout <<  "     lgn = " << mbr->_login << "     pswd = " << mbr->_password << endl;
        }
    }
    
    int getMembQty()
    {
        return membQty;
    }

    //------------------------ ������ � ���� ������ ����������
     void writeMembList()     
    {
         char lgn[20], pswd[20];

        FILE* f_usr;          // ���� �������������
        setlocale(LC_ALL, "");
       
       f_usr = fopen("users.dat", "w");
 //      cout << "������ ������ ����������:" << endl;

        for (int i = 0; i < membQty; i++)
        {
            member* mbr = Members[i];

 //           cout << mbr->_login << " (" << mbr->_login.length() << ") " <<"      " << mbr->_password << endl;
            
            strcpy(lgn, mbr->_login.c_str());
            strcpy(pswd, mbr->_password.c_str());
        

             fprintf(f_usr, "%s %s\n", lgn, pswd); 
        }
        fclose(f_usr);
    }

};

