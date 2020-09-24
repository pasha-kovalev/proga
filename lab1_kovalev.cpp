		/*Разработать классы для описанных ниже объектов.Включить в класс методы set(…), get(…), show(…).Определить другие методы.
8. Patient: Фамилия, Имя, Отчество, Адрес, Номер медицинской карты, Диагноз.Создать массив объектов.Вывести :
		а) список пациентов, имеющих данный диагноз;
		б) список пациентов, номер медицинской карты которых находится в заданном интервале.*/

#include <iostream>
#include <string>
using namespace std;

class Patient
{
		string name;
		string adress;
		int medCardNum;
		string diagnos;
public:
		Patient();
		Patient(string, string, int, string);
		~Patient();
		void getByDiagnos(Patient*, int& );
		void getByMed(Patient*, int&);
		void Show();

private:

};



int main()
{
		setlocale(LC_ALL, "Russian");
		Patient* dataBase;
		cout << "Введите количество патиентов: " << endl;
		int n;
		cin >> n; cin.ignore(32767, '\n');
		dataBase = new Patient [n];
		
		dataBase->getByDiagnos(dataBase, n);
		dataBase->getByMed(dataBase, n);

		for (int i = 0; i < n; ++i)
		{
				dataBase[i].~Patient();
		}
		return 0;
}

Patient::Patient()
{
		cout << endl<< "Введите ФИО" << endl;
		getline(cin, name);
		cout << "Введите № карты" << endl;
		cin >> medCardNum; cin.ignore(32767, '\n');
		cout << "Адрес" << endl;
		getline(cin, adress);
		cout << "Введите диагноз" << endl;
		getline(cin, diagnos);
		cout << endl;
}
Patient::Patient(string n, string a, int m, string d) : name(n), adress(a), medCardNum(m), diagnos(d)
{ }

Patient::~Patient()
{
		cout <<  "deleted"<<endl;
}

void Patient::getByDiagnos(Patient* dataBase, int& size)
{
		cout << "В веди те диагноз" << endl;
		string dgs;
		getline(cin, dgs);
		bool check = true;
		for (int i = 0; i < size; ++i)
		{
				if (dataBase[i].diagnos == dgs)
				{
						dataBase[i].Show();
						check = false; 
				}
		}
		if (check) cout << "НОУ ДЭЙТА, СОРРИИИИИ((((" << endl;
}

void Patient::getByMed(Patient* dataBase, int& size)
{
		cout << "В веди те минимальное значение номера карты" << endl;
		int min;
		cin >> min;
		cout << "В веди те максимальное значение номера карты" << endl;
		int max;
		cin >> max;
		bool check = true;
		for (int i = 0; i < size; ++i)
		{
				if (dataBase[i].medCardNum >= min && dataBase[i].medCardNum <=max)
				{
						dataBase[i].Show();
						check = false;
				}
		}
		if (check) cout << "НОУ ДЭЙТА, СОРРИИИИИ((((" << endl;
}

void Patient::Show()
{
		cout << "Имя:" << name << endl;
		cout << "Номер карты: №" << medCardNum << endl;
		cout << "Адресок:" << adress << endl;
		cout << "Диагноз:" << diagnos << endl <<endl;


}
