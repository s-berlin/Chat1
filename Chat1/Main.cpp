//============= ���� main.cpp ======================
//=====  ���


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
	FILE* f_usr;          // ���� �������������
	FILE* f_msg;          // ���� ��������� 

	string login, password;
	string loginp;        // ���������� ����� (����� �������� ������� ��������� ������ ��� ������ �����)
	char lgn[20] = {}, pswd[20] = {};
	string from = "sb", to = "as", msg = "Hy!";
	char from_c[20] = {}, to_c[20] = {}, msg_c[255] = {};  // ������� ��� ������ ����� 
	int num = 0;
	int act = 1; // ��� �������� ����� �����  
	long t_sec = 0;
	int numb = 0;        // ����� ���������
	int numbp = 0;       // ���������� ����� (����� �������� ������� ��������� ������ ��� ������ �����)
	int num_del = 0;     // ����� ���������� ���������

	setlocale(LC_ALL, "");

	membList* mL = new membList();

//===========================  �������� ������ ������������� �� �����
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
	//===========================  �������� ��������� �� �����
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

	int action = 1; // - ��� ��������

	while (action != 0)                              //= = = = = = = = = = = = =  ���� �����
	{
		cout << "1 - ����\n2 - �����������\n0 - ����������" << endl;
		cout << "�������� ��������:"; cin >> action;
	
		switch (action)
		{
		case 1:                                       //- - - - - - - - - - - - - - ����   
			cout << "�����:"; cin >> login;
			cout << " ������:"; cin >> password;
			num = mL->find_login(login, password);
			if (num == -1) cout << "����� �� ������" << endl; 
			if (num == -2) cout << "�������� ������" << endl;
	//		cout << "num = " << num << endl;
			if (num > 0)
			{
				int act = 1; // - ��� ��������
				string to_lgn = "sb", msg = "Hello";
				setlocale(LC_ALL, "");

//				msgList* msList = new msgList();

				message* newMessage = new message(from, to_lgn, msg, numb);

				while (act != 0)                                  //========= ���� ������ � �����������
				{
					cout << "\n   1 - ����� ���������\n   2 - �������� ���������\n   3 - ������� ���������\n   0 - ����� " << endl;
					cout << "   �������� ��������:"; cin >> act;

					switch (act)
					{
					case 1:                                       //------------------------- ����� ���������
						from = login;
						cout << "   ����:"; cin >> to_lgn;
						// ����� �������� �� ������� ��������� ������
						cout << "   �����:"; cin >> msg;
						if (msg.length() > 0)
						{
							numb++;
							message* newMessage = new message(from, to_lgn, msg, numb);
							msLst->addMessage(newMessage);
						}
						break;
					case 2:                                       //------------------------- �������� ���������
						msLst->showMsgListTo(login);
						break;

					case 3:                                       //------------------------- �������� ���������
						cout << "   ������� ����� ���������� ���������:"; cin >> num_del;
						msLst->delMessage(num_del, login);
						break;

					case 0:                                       //------------------------ ����� �� ������ � �����������
						break;
					}
//					msLst->showMsgList();
				}

			}


//			cout << "num = " << num << endl;
			break;

		case 2:                                           // - - - - - - - - - - - - - �����������
			cout << "�����:"; cin >> login;
			cout << " ������:"; cin >> password;
			if (login == "all") cout << "�� ����������� all" << endl;
			else
			{
				num = mL->find_login(login, password);
				cout << "num = " << num << endl;
				if (num != -1) cout << "����� ��� ����������" << endl;
				else                                      //     ���������� ������ ���������
				{
					member* newMember = new member(login, password);
					mL->addMember(newMember);
				}
			}
		
			break;

		case 0:
			cout << "����������" << endl;                // - - - - - - - - - - - - - - �����         
		}


	}

//	mL->showMembList();    // �������� ������ ����������

	mL->writeMembList();       

	msLst->writeMsgList();

}
