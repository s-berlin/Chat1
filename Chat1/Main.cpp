//============= файл main.cpp ======================
//=====  Чат


#include "member.h"
#include "message.h"
#include "membList.h"
#include "msgList.h"
#include "bad_range.h"
#include <iostream>
#include <fstream>
#include <time.h>

// using namespace std;


int main()
{
	FILE* f_usr;          // файл пользователей
	FILE* f_msg;          // файл сообщений 

	string login, password;
	string loginp;        // предыдущий логин (чтобы избежать повтора последней строки при чтении файла)
	char lgn[20] = {}, pswd[20] = {};
	string from = "sb", to = "as", msg = "Hy!";
	char from_c[20] = {}, to_c[20] = {}, msg_c[255] = {};  // массивы для чтения файла 
	int num = 0;
	int act = 1; // код действия после входа  
	long t_sec = 0;
	int numb = 0;        // номер сообщения
	int numbp = 0;       // предыдущий номер (чтобы избежать повтора последней строки при чтении файла)
	int num_del = 0;     // номер удаляемого сообщения

	setlocale(LC_ALL, "");

	membList* mL = new membList();

//===========================  загрузка списка пользователей из файла
	f_usr = fopen("users.dat", "r");
	while(!feof(f_usr))
	{
		fscanf(f_usr, "%s %s", &lgn, &pswd);
		
		login = lgn;
		if (login != loginp)
		{
			password = pswd;
			member* mbr = new member(login, password);
			mL->addMember(mbr);
			loginp = login;
		}
	}
	fclose(f_usr);
	mL->showMembList();

	msgList* msLst = new msgList();
	//===========================  загрузка сообщений из файла
	f_msg = fopen("msg.dat", "r");
	while (!feof(f_msg))
	{
		fscanf(f_msg, "%s %s %s %d", &from_c, &to_c, &msg_c, &numb);
			
		if (numb != numbp)
		{
			from = from_c;
			to = to_c;
			msg = msg_c;

			message* mess = new message(from, to, msg, numb);
			msLst->addMessage(mess);
			numbp = numb;
		}		
	}
	fclose(f_msg);
	msLst->showMsgList();

	time_t now = time(0);
	char* dt = ctime(&now);
	cout << dt << endl;

	int action = 1; // - код действия

	while (action != 0)                              //= = = = = = = = = = = = =  меню входа
	{
		cout << "1 - вход\n2 - регистрация\n0 - завершение" << endl;
		cout << "Выберите действие:"; cin >> action;
	
		switch (action)
		{
		case 1:                                       //- - - - - - - - - - - - - - вход   
			cout << "Логин:"; cin >> login;
			cout << " Пароль:"; cin >> password;
			num = mL->find_login(login, password);
			if (num == -1) cout << "Логин не найден" << endl; 
			if (num == -2) cout << "Неверный пароль" << endl;
	//		cout << "num = " << num << endl;
			if (num > 0)
			{
				int act = 1; // - код действия
				string to_lgn = "sb", msg = "Hello";
				setlocale(LC_ALL, "");

//				msgList* msList = new msgList();

				message* newMessage = new message(from, to_lgn, msg, numb);

				while (act != 0)                                  //========= меню работы с сообщениями
				{
					cout << "\n   1 - новое сообщение\n   2 - входящие сообщения\n   3 - удалить сообщение\n   0 - выход " << endl;
					cout << "   Выберите действие:"; cin >> act;

					switch (act)
					{
					case 1:                                       //------------------------- новое сообщение
						from = login;
						cout << "   Кому:"; cin >> to_lgn;
						// нужна проверка на наличие вводимого логина
						cout << "   Текст:"; cin >> msg;
						if (msg.length() > 0)
						{
							numb++;
							message* newMessage = new message(from, to_lgn, msg, numb);
							msLst->addMessage(newMessage);
						}
						break;
					case 2:                                       //------------------------- входящие сообщения
						msLst->showMsgListTo(login);
						break;

					case 3:                                       //------------------------- удаление сообщения
						cout << "   Введите номер удаляемого сообщения:"; cin >> num_del;
						msLst->delMessage(num_del, login);
						break;

					case 0:                                       //------------------------ выход из работы с сообщениями
						break;
					}
//					msLst->showMsgList();
				}

			}


//			cout << "num = " << num << endl;
			break;

		case 2:                                           // - - - - - - - - - - - - - регистрация
			cout << "Логин:"; cin >> login;
			cout << " Пароль:"; cin >> password;
			if (login == "all") cout << "Не используйте all" << endl;
			else
			{
				num = mL->find_login(login, password);
				cout << "num = " << num << endl;
				if (num != -1) cout << "Логин уже существует" << endl;
				else                                      //     добавление нового участника
				{
					member* newMember = new member(login, password);
					mL->addMember(newMember);
				}
			}
		
			break;

		case 0:
			cout << "Завершение" << endl;                // - - - - - - - - - - - - - - выход         
		}


	}

//	mL->showMembList();    // показать список участников

	mL->writeMembList();       

	msLst->writeMsgList();

}
