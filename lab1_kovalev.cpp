		/*����������� ������ ��� ��������� ���� ��������.�������� � ����� ������ set(�), get(�), show(�).���������� ������ ������.
8. Patient: �������, ���, ��������, �����, ����� ����������� �����, �������.������� ������ ��������.������� :
		�) ������ ���������, ������� ������ �������;
		�) ������ ���������, ����� ����������� ����� ������� ��������� � �������� ���������.*/

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
		cout << "������� ���������� ���������: " << endl;
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
		cout << endl<< "������� ���" << endl;
		getline(cin, name);
		cout << "������� � �����" << endl;
		cin >> medCardNum; cin.ignore(32767, '\n');
		cout << "�����" << endl;
		getline(cin, adress);
		cout << "������� �������" << endl;
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
		cout << "� ���� �� �������" << endl;
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
		if (check) cout << "��� �����, ���������((((" << endl;
}

void Patient::getByMed(Patient* dataBase, int& size)
{
		cout << "� ���� �� ����������� �������� ������ �����" << endl;
		int min;
		cin >> min;
		cout << "� ���� �� ������������ �������� ������ �����" << endl;
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
		if (check) cout << "��� �����, ���������((((" << endl;
}

void Patient::Show()
{
		cout << "���:" << name << endl;
		cout << "����� �����: �" << medCardNum << endl;
		cout << "�������:" << adress << endl;
		cout << "�������:" << diagnos << endl <<endl;


}
