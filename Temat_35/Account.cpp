#include "Account.h"

void Account::fillAccount()
{
	int bill;
	bill = rand() % 1000 + 1;
	Date now;
	now.getNowDate();
	//    now.printDate();

	numberAccount = rand() % 99999 + 10001;
	cout << "\nВнесите сумму денег: ";
	cin >> money;

	cout << "\n========================================\n";
	cout << "\n\t\t Чек #" << bill << endl;
	cout << "Счёт #" << numberAccount << " создан, баланс: " << money;
	cout << "\nДата: "; now.printDate();
	cout << "\n========================================\n\n";
}

void Account::showAccount()
{
	cout << "Номер аккаунта: " << numberAccount << endl;
	cout << "Сумма денег: " << money << endl;
}

void Account::saveToTextFile(FILE* fp)
{
	fprintf(fp, "\n%d %0.2f", numberAccount, money);
}

void Account::loadToTextFile(FILE* fp)
{
	fscanf_s(fp, "%d%f", &numberAccount, &money);
}
