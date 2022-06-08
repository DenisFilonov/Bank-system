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
	if (file == NULL) cout << "Ошибка.\n";
	else
	{
		Vasya.saveToTextFile(file);
		fclose(file);
		cout << "Сохранено.\n";
	}*/
	/*Vasya.showAccount();
	cout << "---------------------------------------\n";
	FILE* file;
	fopen_s(&file, "Vasya.txt", "r");
	if (file == NULL) cout << "Ошибка.\n";
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
	if (fp == NULL) cout << "Ошибка открытия!\n";
	else
	{
		Vasya.saveClientToTextFile(fp);
		fclose(fp);
		cout << "Записано.\n";
	}*/

	/*Client Vasya;

	FILE* fp;
	fopen_s(&fp, "Vasya.txt", "r");
	if (fp == NULL) cout << "Ошибка открытия!\n";
	else
	{
		Vasya.loadClientFromTextFile(fp);
		fclose(fp);
	}
	Vasya.showClient();*/


	/*Client* clients = nullptr;
	int size = 0;

	loadArray(clients, size);
	cout << "Количество клиентов: " << size << endl;
	cout << "Клиент " << clients[0].name.str << endl;*/
	
	int size = 0;
	Client* cl = NULL;
	int menu = 0;

	float cash = 0;
	int acc = 0;
	char name[100] = "";

	do
	{
		cout << "1. Загрузить клиентскую базу данных.\n"; //+
		cout << "2. Внести клиента в базу данных.\n";//+
		cout << "3. Информация о клиенте.\n"; //+
		cout << "4. Добавить клиенту счёт.\n"; //+
		cout << "5. Показать полный список базы данных.\n"; //+
		cout << "6. Закрыть счёт клиента.\n"; //+
		cout << "7. Удалить клиента из базы данных.\n"; //+
		cout << "8. Внести финансовые средства на счёт.\n"; //+
		cout << "9. Обналичить финансовые средства со всех счетов.\n"; //+
		cout << "10. Обналичить финансовые средства с конкретного счёта.\n"; //+
		cout << "11. Сохранить все изменения в базу данных.\n"; //+
		cout << "0. Завершить работу с банковской системой.\nВыбор: ";
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
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			printInfo(cl, size, name);
			break;

		case 4:
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			addAccToClient(cl, size, name);
			break;

		case 5:
			printInfoAllClients(cl, size); 
			break;

		case 6: 
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "Удаляемый аккаунт: ";
			cin >> acc;
			closeClient_sAcc(cl, size, name, acc);
			break;
		
		case 7: 
			cout << "ФИО удаляемого клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			deleteItem(cl, size, name);
			break;
		
		case 8: 
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "Введите счёт, на который желаете внести финансовые средства: ";
			cin >> acc;
			cout << "Введите сумму денег, которую желаете положить на счёт " << acc << ": ";
			cin >> cash;
			putCashOnAccount(cl, size, name, acc, cash);
			break;

		case 9: 
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "Сумма к выдаче: ";
			cin >> cash;
			cashWithdrawal(cl, size, cash, name);
			break; 

		case 10:
			cout << "\nФИО клиента: ";
			cin.ignore();
			cin.getline(name, 100);
			cout << "Введите счёт, с которого желаете снять финансовые средства: ";
			cin >> acc;
			cout << "Введите сумму денег, которую желаете обналичить со счёта " << acc << ": ";
			cin >> cash;
			withdrawCashFromCurrentAcc(cl, size, name, acc, cash);

			break;
		
		case 11: 			
			saveArray(cl, size);
			break;

		default: if (menu > 11 && menu != 0) cout << "Неверно выбран пункт меню.\n\n";	break;
		}


	} while (menu != 0);




	system("pause");
	return 0;
}
