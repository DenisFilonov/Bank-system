#include "Client.h"

void Client::fillClient()
{
    char tmp[100] = "";
    cout << "ФИО клиента: ";
    cin.ignore();
    cin.getline(tmp,100);
    name.setMyString(tmp);

    cout << "Дата рождения ";
    dateOfBirth.fillDate();

    cout << "ИД-код клиента: ";
    cin >> idNumberOfClient;

    cout << "Номер телефона клиента: ";
    cin.ignore();
    cin.getline(tmp, 100);
    telnumber.setMyString(tmp);

    cout << "Адрес проживания, прописка: ";
    cin.getline(tmp, 100);
    address.setMyString(tmp);

    arr = new Account[1];
    sizeAccount = 1;
    arr[0].fillAccount();
}

void Client::showClient()
{
    cout << "\n\n=================================================================\n";
    cout << "ФИО клиента: " << name.str << endl;
    cout << "Дата рождения: "; dateOfBirth.printDate(); cout << endl;
    cout << "Идентификационный код клиента: " << idNumberOfClient << endl;
    cout << "Номер телефона клиента: " << telnumber.str << endl;
    cout << "Адрес проживания, прописка: " << address.str << endl;
    cout << "Количество счетов: " << sizeAccount << endl;


    for (int i = 0; i < sizeAccount; i++)
    {
        if (sizeAccount > 1)
        {
            cout << "\n================= Счёт #" << i + 1 << " =================\n";
            arr[i].showAccount();
        }
        else
        {
            cout << "\n================= Счёт клиента =================\n";
            arr[i].showAccount();
        }
    }
    cout << "\n=================================================================\n\n";

}

void Client::addAccount()
{
    Account* tmp = new Account[++sizeAccount];
    for (int i = 0; i < sizeAccount - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[] arr;
    arr = tmp;
    arr[sizeAccount - 1].fillAccount();
}

void Client::delAccount(int id)
{
    if (id >= 0 && id < sizeAccount)
    {
        Account* tmp = new Account[--sizeAccount];
        for (int i = 0; i < sizeAccount; i++)
        {
            if (i < id) tmp[i] = arr[i];
            else tmp[i] = arr[i + 1];
        }
        if (arr != NULL) delete[] arr;
        arr = tmp;
    }
}

void Client::sortsAccountsByCash()
{
    for (int i = 0; i < sizeAccount; i++)
    {
        for (int j = 0; j < sizeAccount - i - 1; j++)
        {
            if (arr[j + 1].money > arr[j].money) swap(arr[j + 1].money, arr[j].money);
        }
    }
}

void Client::withdrawCash(float sum)
{
    sortsAccountsByCash();
    if (sum > calcTotalCashAllAccounts())
    {
        cout << "\n=======================================================\n";
        cout << "==  Ошибка! Недостаточно финансовых средств на счетах ==";
        cout << "\n=======================================================\n\n";
    }
    else
    {
        float s = sum;
        int id = -1;
        for (int i = 0; i < sizeAccount; i++)
        {
            if (sum >= arr[i].money)
            {
                sum -= arr[i].money;
                arr[i].money = 0;
            }
            else
            {
                arr[i].money -= sum;
                //sum = 0;
                id = i;
            }            
        }
        if (sum > 0)
        {
            cout << "\n=======================================================\n";
            cout << "Остаток финансовых средств после снятия " << arr[id].money << " у.е.";
            cout << "\n=======================================================\n\n";
        }
        int bill;
        bill = rand() % 1000 + 1;
        Date now;
        now.getNowDate();

        cout << "\n==================================================================\n\n";
        cout << "\n\t\t Чек #" << bill << endl;
        cout << "\tПолучите снятые денежные средства: " << s << " у.е.\n";
        cout << "\n\tДата: "; now.printDate();
        cout << "\n===================================================================\n\n";
    }
}

void Client::putCash(int numberAcc, float sum)
{
    int bill;
    bill = rand() % 1000 + 1;
    Date now;
    now.getNowDate();
    //    now.printDate();

    float amount = 0;
    for (int i = 0; i < sizeAccount; i++)
    {
        if (arr[i].numberAccount == numberAcc)
        {
            arr[i].money += sum;
            amount += arr[i].money;
        }
    }
    cout << "\n==============================================\n";
    cout << "\n\t\t Чек #" << bill << endl;
    cout << "Сумма " << sum << " успешно внесена на аккаунт #" << numberAcc;
    cout << "\nДата: "; now.printDate();
    cout << "\nВаш новый баланс: " << amount << " у.е.\n";
    cout << "\n==============================================\n";

}

void Client::takeCash(int numberAcc, float sum)
{
    int id = -1;
    for (int i = 0; i < sizeAccount; i++)
    {
        if (arr[i].numberAccount == numberAcc)  id = i;
    }
    if (id == -1)
    {
        cout << "\n===========================================================================\n";
        cout << "Ошибка! Счёт [" << numberAcc << "] не найден, проверьте вводимые данные";
        cout << "\n===========================================================================\n\n";
    }
    else
    {
        int bill;
        bill = rand() % 1000 + 1;
        Date now;
        now.getNowDate();

        float rest = 0;
        if (sum == arr[id].money)
        {
            arr[id].money -= sum;
            cout << "\n============================================================\n";
            cout << "\n\t\t Чек #" << bill << endl;
            cout << "\tПолучите снятые денежные средства: " << sum << " у.е.\n";
            cout << "\tБаланс счёта [" << numberAcc << "] 0 у.е.\n";

            cout << "\n\tДата: "; now.printDate();
            cout << "\n============================================================\n\n";
        }
        else if (arr[id].money - sum > 0)
        {
            arr[id].money -= sum;
            rest = arr[id].money;
            cout << "\n============================================================\n";
            cout << "\n\t\t Чек #" << bill << endl;
            cout << "\tПолучите снятые денежные средства: " << sum << " у.е.\n";
            cout << "\tБаланс счёта [" << numberAcc << "] " << rest << " у.е.\n";
            cout << "\n\tДата: "; now.printDate();
            cout << "\n============================================================\n\n";
        }
        else
        {
            cout << "\n==================================================================\n";
            cout << "Ошибка! На данном счету недостаточно финансовых средств для снятия";
            cout << "\n==================================================================\n\n";
        }
    }
}

void Client::closeAccount(int number)
{
    int id = -1;
    for (int i = 0; i < sizeAccount; i++)
    {
        if (arr[i].numberAccount == number) id = i; break;
    }
    if (id == -1)
    {
        cout << "\n========================================================\n";
        cout << "Счёт с номером [" << number << "] не найден.\n";
        cout << "\n========================================================\n\n";

    }
    else
    {
        if (arr[id].money > 0) 
        {
            cout << "\n==================================================================\n";
            cout << "====== Невозможно закрыть счёт, пока там находятся средства ======";
            cout << "\n===================================================================\n\n";

        }
        else
        {
           delAccount(id);
           cout << "\n============================================\n";
           cout << "Счёт #" << id << " успешно закрыт.\n";
           cout << "\n============================================\n\n";

        }
    }
}

float Client::calcTotalCashAllAccounts()
{
    float sum = 0;
    for (int i = 0; i < sizeAccount; i++)
    {
        sum += arr[i].money;
    }
    return sum;
}

void Client::saveClientToTextFile(FILE* fp)
{


    fprintf(fp, "\n%s", name.str);
    fprintf(fp, "\n%d %d %d", dateOfBirth.day,dateOfBirth.month,dateOfBirth.year);
    fprintf(fp, "\n%s", address.str);
    fprintf(fp, "\n%s", telnumber.str);
    fprintf(fp, "\n%lld", idNumberOfClient);
    fprintf(fp, "\n%d", sizeAccount);

    for (int i = 0; i < sizeAccount; i++)
    {
        arr[i].saveToTextFile(fp);
    }
}

void Client::loadClientFromTextFile(FILE* fp)
{
    char tmp[100] = "";
    fscanf_s(fp, "\n");
    //fscanf_s(fp, "%100s\n%d", tmp, 100, &sizeAccount);
    fgets(tmp, 100, fp);
    name.setMyString(tmp);
    name.str[strlen(tmp) - 1] = '\0';
    fscanf_s(fp, "\n%d %d %d", &dateOfBirth.day, &dateOfBirth.month, &dateOfBirth.year);
    //fscanf_s(fp, "\n%s", address.str);
    fscanf_s(fp, "\n");
    fgets(tmp, 100, fp);
    address.setMyString(tmp);
    address.str[strlen(tmp) - 1] = '\0';


    //fscanf_s(fp, "\n%s", telnumber.str);
    fscanf_s(fp, "\n");
    fgets(tmp, 100, fp);
    telnumber.setMyString(tmp);
    telnumber.str[strlen(tmp) - 1] = '\0';


    fscanf_s(fp, "\n%lld", &idNumberOfClient);
    fscanf_s(fp, "%d", &sizeAccount);

    arr = new Account[sizeAccount];
    for (int i = 0; i < sizeAccount; i++)
    {
        arr[i].loadToTextFile(fp);
    }
}

void addItem(Client*& arr, int& size)
{
    cout << endl;
    Client* tmp = new Client[++size];
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL) delete[] arr;
    cout << "Введите данные о новом клиенте: \n";
    tmp[size - 1].fillClient();
    arr = tmp;
}

void printInfo(Client* arr, int size, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str,name)==0) arr[i].showClient();        
    }
}

void printInfoAllClients(Client* arr, int size)
{
    if (size == 0) 
    {
        cout << "\n=================================================================================\n";
        cout << "==  База данных пустая! Загрузите её, или создайте снова, или проверьте файлы  ==";
        cout << "\n=================================================================================\n\n";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            arr[i].showClient();
        }
    }
}

void deleteItem(Client*& arr, int& size, const char* name)
{
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0)
        {
            id = i;
        }
    }
    if (id == -1) 
    { 
        cout << "\n=================================================================================\n";
        cout << "Клиент \"" << name << "\" не обнаружен, проверьте введённые/запрашиваемые данные.";
        cout << "\n=================================================================================\n\n";
    }
    else
    {
        if (arr[id].calcTotalCashAllAccounts() == 0)
        {
            Client* tmp = new Client[--size];

            for (int i = 0; i < size; i++)
            {
                if (i < id) tmp[i] = arr[i];
                else tmp[i] = arr[i + 1];
            }

            if (arr != NULL) delete[] arr;
            arr = tmp;
            cout << "\n=======================================================\n";
            cout << "Клиент \"" << name << "\" удалён из базы данных банка";
            cout << "\n=======================================================\n\n";
        }
        else
        {
            cout << "\n=================================================================================\n";
            cout << "==  Ошибка! Удаление невозможно, т.к. у клиента \"" << name << "\" открыты счета ==";
            cout << "\n=================================================================================\n\n";
        }

    };
}

void cashWithdrawal(Client* arr, int size, float sum, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0) arr[i].withdrawCash(sum);
    }

}

void closeClient_sAcc(Client* arr, int size, const char* name, int acc)
{
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0)
        {
            id = i;
        }
    }
    if (id == -1)
    {
        cout << "\n=================================================================================\n";
        cout << "Клиент \"" << name << "\" не обнаружен, проверьте введённые/запрашиваемые данные.";
        cout << "\n=================================================================================\n\n";
    }
    else
    {
        arr[id].closeAccount(acc);
    }
}

void putCashOnAccount(Client* arr, int size, const char* name, int acc, float sum)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0)
        {
            arr[i].putCash(acc, sum);
        }
    }
}

void withdrawCashFromCurrentAcc(Client* arr, int size, const char* name, int acc, float sum)
{
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0) id = i;
    }

    if (id == -1)
    {
        cout << "\n========================\n";
        cout << "==  Клиент не найден  ==";
        cout << "\n========================\n\n";
    }
    else  arr[id].takeCash(acc, sum);
}

void addAccToClient(Client* arr, int size, const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, name) == 0)
        {
            arr[i].addAccount();
        }
    }
}










void printArray(Client* arr, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i].showClient();
        cout << "\n====================================================\n\n";
    }
}

void saveArray(Client* arr, int size)
{
    FILE* fp;
    fopen_s(&fp, "Bank.txt", "w");
    if (fp == NULL)
    {
        cout << "\n======================================================\n";
        cout << "==  Ошибка сохранения базы данных! Проверьте файлы  ==";
        cout << "\n======================================================\n\n";
    }
    else
    {
        fprintf(fp, "%d", size);
        for (int i = 0; i < size; i++)
        {
            arr[i].saveClientToTextFile(fp);
        }
        fclose(fp);
        cout << "\n==============================================\n";
        cout << "==  Данные успешно сохранены в базу данных  ==";
        cout << "\n==============================================\n\n";
    }
}

void loadArray(Client*& arr, int& size)
{
    FILE* fp;
    fopen_s(&fp, "Bank.txt", "r");
    if (fp == NULL)
    {
        cout << "\n=====================================================\n";
        cout << "==  Ошибка выгрузки базы данных! Проверьте файлы  ==";
        cout << "\n=====================================================\n\n";
        arr = nullptr;
        size = 0;
    }
    else
    {
        fscanf_s(fp, "%d", &size);
        arr = new Client[size];
        char tmp[5];
        for (int i = 0; i < size; i++)
        {
            //fgets(tmp, 5, fp);
            arr[i].loadClientFromTextFile(fp);
        }
        fclose(fp);
        cout << "\n==============================================\n";
        cout << "==  Данные успешно выгружены в базу данных  ==";
        cout << "\n==============================================\n\n";
    }
}
