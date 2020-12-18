#include <iostream>   
#include <string>   
#include <malloc.h>
using namespace std;

template <typename T>
class Stack {
		T* ptr;
		int top;

public:
		Stack();
		~Stack();
		void pushToStack(const T&);
		T pullFromStack();
		int getTopF() const;
		void printF() const;

};

int main()
{
		Stack<char> chStack;
		Stack<string> strStack;

		char* ch = new char[2];
		ch[0] = 'u';
		ch[1] = 'h';

		int strSize = 3;
		string* str = new string[strSize];
		str[0] = ":(((((";
		str[1] = "sessiya ochno((((";
		str[2] = "algebru s diskretkoy blin uchit (((( help ";

		//ch
		chStack.pullFromStack();
		for (int i = 0; i < int (_msize(ch) / sizeof(ch[0])); ++i)
		{
				chStack.pushToStack(ch[i]);
		}
		chStack.printF();
		cout << chStack.getTopF() << endl;
		cout << chStack.pullFromStack() << endl;
		cout << chStack.getTopF() << endl;
		chStack.pushToStack('?');
		chStack.printF();

		cout << "==================" << endl;
		//str
		for (int i = 0; i < strSize; ++i)
		{	
				strStack.pushToStack(str[i]);
		}
		strStack.printF();
		cout << strStack.getTopF() << endl;
		cout << strStack.pullFromStack() << endl;
		cout << strStack.getTopF() << endl;
		strStack.pushToStack("have a nice day :/");
		strStack.printF();


		delete[] str;
		delete[] ch;

}



template <typename T> 
Stack<T>::Stack()
{
		try
		{
				ptr = new T[20];
				top = 0;
				cout << "very nice. yout damn perfect stack has been created here." << endl << endl;
		}
		catch (std::bad_alloc & ba)
		{
				std::cerr << ba.what() << std::endl;
		}
		
}

template <typename T> 
Stack<T>::~Stack()
{
		delete[] ptr;
		cout << "bye brooooo ^_^"<<endl;
}

 template <typename T> 
 void Stack<T>::pushToStack(const T& val)
{
		
		 try
		 {
				 if (top == 20)
						 throw "stack full :((( sorry bro :(((((( only 20 elements broooooo :(((";
				
				 ptr[top] = val;
				 ++top;
		 }
		 catch (const char* exception) {
				 cerr << exception << endl;
				 return;
		 }
		
}

 template <typename T> 
 T Stack<T>::pullFromStack()
{
		 try
		 {
				 if (top == 0)
						 throw "eeeee... kuda? ne vidish tut stek pustoy???";
				
				 --top;
				 return ptr[top];
						
		 }
		 catch (const char* exception) {
				 cerr << exception << endl;
				 return 0;
		 }
		
}

 template<typename T>
 int Stack<T>::getTopF() const
 {
		 return top;
 }



 template<typename T>
 void Stack<T>::printF() const
 {
		 cout << "Look at this damn good stack:" << endl;
		 for (int i = top-1; i >= 0; --i)
		 {
				 cout << ptr[i]<<' ';
		 }
		 cout << endl;
 }


