#include "Set.h"
void Set::showSet()
{
		cout << '{';
		for (int i = 0; i < size - 1; ++i)
		{
				cout << members[i] << ',';
		}
		cout << members[size - 1] << '}' << endl;
}

void Set::getElementFromSet()
{
		cout << "Enter number of element: " << endl;
		int temp;
		cin >> temp;
		if (temp < size && temp >= 0)
		{
				cout << "Element " << temp << ":" << members[temp] << endl;
		}
}

void Set::setSet()
{
		delete[] members;
		cout << "Enter number of elements: " << endl;
		cin >> size;
		members = new int[size];
		for (int i = 0; i < size; ++i)
		{
				cout << "Enter " << i + 1 << " elements: " << endl;
				cin >> members[i];
		}
}

void Set::setSet(int size, int* arr)
{
		delete[] members;
		this->size = size;
		members = new int[size];
		for (int i = 0; i < size; ++i)
		{
				members[i] = arr[i];
		}

}

Set::Set()
{
		size = 1;
		members = new int[size];
		members[0] = 0;
}


Set::~Set()
{
		delete[] members;
}

const Set& Set::operator=(const Set& set)
{
		delete[] this->members;
		this->size = set.size;
		this->members = new int[set.size];
		for (int i = 0; i < set.size; ++i)
		{
				this->members[i] = set.members[i];
		}
		return *this;
}

void Polynom::getElementFromSet()
{
		cout << "Enter degree: " << endl;
		int temp;
		cin >> temp;
		if (temp < size && temp >= 0)
		{
				cout << members[temp] << "*x^" << temp << endl;
		}
}


void Polynom::showProductOfElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] * members[num2] << "*x^" << num1 + num2 << endl;
		}
}

void Polynom::showSumOfElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] << "*x^" << num1 << " + " << members[num2] << "*x^" << num2 << endl;
		}
}

void Polynom::showDifferBtwElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] << "*x^" << num1 << " - " << members[num2] << "*x^" << num2 << endl;
		}
}

void Polynom::showSet()
{
		for (int i = 0; i < size - 1; ++i)
		{
				if (i)
				{
						cout << members[i] << "*x^" << i << " + ";
				}
				else
				{
						cout << members[i] << " + ";
				}

		}

		cout << members[size - 1] << "*x^" << size - 1 << endl;
}

void Integers::showProductOfElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] * members[num2] << endl;
		}
}

void Integers::showSumOfElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] + members[num2] << endl;
		}
}

void Integers::showDifferBtwElements(int num1, int num2)
{
		if (num1 < size && num2 < size && num2 >= 0 && num1 >= 0)
		{
				cout << members[num1] - members[num2] << endl;
		}
}

ostream& operator<<(ostream& mystream, Set& ob)
{
		mystream << "Set(";
		for (int i = 0; i < ob.size; ++i)
		{
				mystream << ob.members[i];
				if (i != ob.size - 1) mystream << ", ";
		}
		mystream << ")" << endl;
		return mystream;
}

istream& operator>>(istream& mystream, Set& ob)
{
		cout << "Enter dimension:";
		mystream >> ob.size;
		delete[] ob.members;
		ob.members = new int[ob.size];
		cout << endl;
		for (int i = 0; i < ob.size; ++i)
		{
				cout << "Enter " << i + 1 << " member:";
				mystream >> ob.members[i];
		}
		return mystream;
}

ostream& operator<<(ostream& mystream, Polynom& ob)
{
		for (int i = 0; i < ob.size - 1; ++i)
		{
				if (i)
				{
						mystream << ob.members[i] << "*x^" << i << " + ";
				}
				else
				{
						mystream << ob.members[i] << " + ";
				}

		}

		mystream << ob.members[ob.size - 1] << "*x^" << ob.size - 1 << endl;

		return mystream;
}