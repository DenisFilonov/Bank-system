#include"MyString.h"
#include"Date.h"

struct Account
{
	int numberAccount = 0; // ����� �����
	float money = 0;		// ����� ����� �� �����

	void fillAccount();
	void showAccount();
	void saveToTextFile(FILE* fp);
	void loadToTextFile(FILE* fp);
};