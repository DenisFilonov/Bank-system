#include"Account.h"

struct Client
{
	MyString name;//ФИО
	Date dateOfBirth;//дата рождения
	MyString address;//адрес проживания, прописка
	MyString telnumber;//контактный номер
	long long idNumberOfClient; //ид-код клиента налогоплательщика
	int sizeAccount = 0; // количество аккаунтов у клиента
	Account* arr = NULL;

	void fillClient();
	void showClient();
	void addAccount();
	void delAccount(int id);

	void sortsAccountsByCash();
	void withdrawCash(float sum);
	void putCash(int numberAcc, float sum);
	void takeCash(int numberAcc, float sum);
	void closeAccount(int number);

	float calcTotalCashAllAccounts();
	void saveClientToTextFile(FILE* fp);
	void loadClientFromTextFile(FILE* fp);
};

void addItem(Client*& arr, int& size);
void printInfo(Client* arr, int size, const char* name);
void printInfoAllClients(Client* arr, int size);
void deleteItem(Client*& arr, int& size, const char* name);
void cashWithdrawal(Client* arr, int size, float sum, const char* name);
void closeClient_sAcc(Client* arr, int size, const char* name, int acc);
void putCashOnAccount(Client* arr, int size, const char* name, int acc, float sum);
void withdrawCashFromCurrentAcc(Client* arr, int size, const char* name, int acc, float sum);
void addAccToClient(Client* arr, int size, const char* name);









void printArray(Client* arr, int size);
void saveArray(Client* arr, int size);
void loadArray(Client*& arr, int& size);