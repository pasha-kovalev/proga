#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
		Set ex,ex2;
		int arr1[] = { 1,2,3,5,4 };
		int arr2[] = { 0, -3, 4, 7,5 };
		int arr3[] = { 5, -4, 7, 9, 12 };
		ex.setSet(5, arr1);
		ex.showSet();
		ex.getElementFromSet();
		ex2 = ex;
		ex2.showSet();
		cout << endl;

		Integers iex,iex2;
		iex.setSet(5, arr2);
		iex.showSet();
		iex.getElementFromSet();
		iex2 = iex;
		iex2.showSet();
		iex2.showProductOfElements(2,1);
		iex.showDifferBtwElements(3,3);
		iex2.showSumOfElements(4, 0);
		cout << endl;

		Polynom pex, pex2;
		pex.setSet(5, arr3);
		pex.showSet();
		pex.getElementFromSet();
		pex2 =pex;
		pex2.showSet();
		pex2.showProductOfElements(2, 1);
		pex.showDifferBtwElements(3, 3);
		pex2.showSumOfElements(4, 0);

		return 0;
}