#include <iostream>   
#include <string>   

using namespace std;

class Stack {
		char* symbols;
		int top;
		
public:
		Stack();
		~Stack();
		void pushToStack(char& sym);
		char pullFromStack();
		bool checkBrackets(string&);
};

int main()
{
		Stack ex;
		string* covid = new string[7];
		covid[0] = "{Yes!} (- 2 weeks!) [Yuhuu] ! ";
		covid[1] = "({{mama}ya{na}samoizolyacii})";
		covid[2] = "[{()}]";
		covid[3] = "[{()}";
		covid[4] = "{(})"; 
		covid[5] = ")";
		covid[6] = "[";
		cout << boolalpha;
		for (int i = 0; i < 7; ++i)
		{
				cout << ex.checkBrackets(covid[i])<<endl;
		}
		
		delete[] covid;

}



Stack::Stack()
{
		symbols = new char[20];
		top = 0;
		cout << "very nice"<<endl<<endl;
}

Stack::~Stack()
{
		delete[] symbols;
}

void Stack::pushToStack(char& sym)
{
		if (top == 20)
		{
				cout << "stack full:(((sorry bro:((((((" << endl;
				return;
		}
		symbols[top] = sym;
		++top;
}

char Stack::pullFromStack()
{
		if (top == 0)
		{
				return '0';
		}
		--top;
		return symbols[top];
}

bool Stack::checkBrackets(string& str)
{
		for (int i=0; i < str.length(); ++i)
		{
						switch (str[i]) {
								case '{':
								case '[':
								case '(':
										pushToStack(str[i]);
										break;
								case '}': 
										if (pullFromStack() != '{') return false;
										break;
								case ')':
										if (pullFromStack() != '(') return false;
										break;
								case ']':
										if (pullFromStack() != '[') return false;
										break;
						}
			
		}
		if (pullFromStack() == '0') return true;
		return false;
}
