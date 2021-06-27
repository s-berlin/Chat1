//============== файл membList.h ==================
#include "member.h"
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class membList
{
    short membQty = 0;          //реальное кол-во участников чата
public:
    member* Members[10];

    //----------------------------- добавление участника
    void addMember(member* mbr) 
    {
    //    const string lgn;
    //    mbr->getMemberLogin(lgn);
        Members[membQty] = mbr;
        membQty++;
    }

    //---------------- ѕоиск участника по логину и паролю --------
    int find_login(const string log, const string pswd)
    {
        for (int i = 0; i < membQty; i++)
        {
            member* mbr = Members[i];
            
            if (log == mbr->_login) // проверка логина
            {
                if (pswd == mbr->_password) return i + 1; // проверка парол€
                else return -2;                           // неверный пароль
            };
        }
        return -1;                                        // не найден логин
    }
    //------- ѕоказать список участников --------
    void showMembList()
    {
    //   const string lgn, pswd;
        cout << "—писок участников" << endl;
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

    //------------------------ запись в файл списка участников
     void writeMembList()     
    {
         char lgn[20], pswd[20];

        FILE* f_usr;          // файл пользователей
        setlocale(LC_ALL, "");
       
       f_usr = fopen("users.dat", "w");
 //      cout << "«апись списка участников:" << endl;

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

