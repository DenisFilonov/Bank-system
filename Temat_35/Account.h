#include"MyString.h"
#include"Date.h"

struct Account
{
	int numberAccount = 0; // Номер счёта
	float money = 0;		// Сумма денег на счету

	void fillAccount();
	void showAccount();
	void saveToTextFile(FILE* fp);
	void loadToTextFile(FILE* fp);
};