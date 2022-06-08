#include<Windows.h>
#include"Client.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	setlocale(0, "");
	

	//Account Vasya; //0 0
	/*
	Vasya.fillAccount();
	cout << "---------------------------------------\n";
	Vasya.showAccount();
	cout << "---------------------------------------\n";
	FILE* file;
	fopen_s(&file, "Vasya.txt", "w");
	if (file == NULL) cout << "������.\n";
	else
	{
		Vasya.saveToTextFile(file);
		fclose(file);
		cout << "���������.\n";
	}*/
	/*Vasya.showAccount();
	cout << "---------------------------------------\n";
	FILE* file;
	fopen_s(&file, "Vasya.txt", "r");
	if (file == NULL) cout << "������.\n";
	else
	{
		Vasya.loadToTextFile(file);
		fclose(file);
	}

	Vasya.showAccount();*/

	/*Client Vasya;
	Vasya.fillClient();
	Vasya.showClient();
	cout << "----------------------------\n";
	Vasya.addAccount();
	Vasya.showClient();
	cout << "----------------------------\n";
	FILE* fp;
	fopen_s(&fp, "Vasya.txt", "w");
	if (fp == NULL) cout << "������ ��������!\n";
	else
	{
		Vasya.saveClientToTextFile(fp);
		fclose(fp);
		cout << "��������.\n";
	}*/

	/*Client Vasya;

	FILE* fp;
	fopen_s(&fp, "Vasya.txt", "r");
	if (fp == NULL) cout << "������ ��������!\n";
	else
	{
		Vasya.loadClientFromTextFile(fp);
		fclose(fp);
	}
	Vasya.showClient();*/


	/*Client* clients = nullptr;
	int size = 0;

	loadArray(clients, size);
	cout << "���������� ��������: " << size << endl;
	cout << "������ " << clients[0].name.str << endl;*/
	
	int size = 0;
	Client* cl = NULL;
	int menu = 0;

	float cash = 0;
	int acc = 0;
	char name[100] = "";

	do
	{
		cout << "1. ��������� ���������� ���� ������.\n"; //+
		cout << "2. ������ ������� � ���� ������.\n";//+
		cout << "3. ���������� � �������.\n"; //+
		cout << "4. �������� ������� ����.\n"; //+
		cout << "5. �������� ������ ������ ���� ������.\n"; //+
		cout << "6. ������� ���� �������.\n"; //+
		cout << "7. ������� ������� �� ���� ������.\n"; //+
		cout << "8. ������ ���������� �������� �� ����.\n"; //+
		cout << "9. ���������� ���������� �������� �� ���� ������.\n"; //+
		cout << "10. ���������� ���������� �������� � ����������� �����.\n"; //+
		cout << "11. ��������� ��� ��������� � ���� ������.\n"; //+
		cout << "0. ��������� ������ � ���������� ��������.\n�����: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			loadArray(cl, size);
			break;

		case 2:
			addItem(cl, size);
			break;

		case 3:
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			printInfo(cl, size, name);
			break;

		case 4:
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			addAccToClient(cl, size, name);
			break;

		case 5:
			printInfoAllClients(cl, size); 
			break;

		case 6: 
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "��������� �������: ";
			cin >> acc;
			closeClient_sAcc(cl, size, name, acc);
			break;
		
		case 7: 
			cout << "��� ���������� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			deleteItem(cl, size, name);
			break;
		
		case 8: 
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "������� ����, �� ������� ������� ������ ���������� ��������: ";
			cin >> acc;
			cout << "������� ����� �����, ������� ������� �������� �� ���� " << acc << ": ";
			cin >> cash;
			putCashOnAccount(cl, size, name, acc, cash);
			break;

		case 9: 
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "����� � ������: ";
			cin >> cash;
			cashWithdrawal(cl, size, cash, name);
			break; 

		case 10:
			cout << "\n��� �������: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "������� ����, � �������� ������� ����� ���������� ��������: ";
			cin >> acc;
			cout << "������� ����� �����, ������� ������� ���������� �� ����� " << acc << ": ";
			cin >> cash;
			withdrawCashFromCurrentAcc(cl, size, name, acc, cash);

			break;
		
		case 11: 			
			saveArray(cl, size);
			break;

		default: if (menu > 11 && menu != 0) cout << "������� ������ ����� ����.\n\n";	break;
		}


	} while (menu != 0);




	system("pause");
	return 0;
}
