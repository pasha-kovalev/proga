#pragma once
#include <iostream>
using namespace std;
class Set {
protected:
		int size;
		int* members;
public:
		Set();
		~Set();
		virtual void showSet();
		virtual void getElementFromSet();
		virtual void setSet();
		virtual void setSet(int, int*);
		virtual const Set& operator= (const Set& set);
		friend ostream& operator<<(ostream& mystream, Set& ob);
		friend istream& operator>>(istream& mystream, Set& ob);

};

class Ring : public Set
{
public:
		virtual void showProductOfElements(int, int) = 0;
		virtual void showSumOfElements(int, int) = 0;
		virtual void showDifferBtwElements(int, int) = 0;


};

class Integers : public Ring
{
public:
		void showProductOfElements(int, int) override;
		void showSumOfElements(int, int) override;
		void showDifferBtwElements(int, int) override;
};

class Polynom : public Ring
{
public:
		void showSet() override;
		void getElementFromSet() override;
		void showProductOfElements(int, int) override;
		void showSumOfElements(int, int) override;
		void showDifferBtwElements(int, int) override;
		friend ostream& operator<<(ostream& mystream, Polynom& ob);

};

