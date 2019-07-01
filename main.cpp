#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Precedence(char);
void InfixToPostfix(string);
bool isOperand(char);
bool isBalanced(string);

int main()
{
	string str;
	getline(cin, str);

	if (isBalanced(str))
		InfixToPostfix(str);
	else
		cout << "The string is not Balanced.";
	
	cout << endl;
	return 0;
}

void InfixToPostfix(string str) {
	stack <char> stk;

	for (auto& x : str) {
		if (isOperand(x)) {
			cout << x;
		}
		else if (x == ')') {
			while (stk.top() != '(') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (x == '(') {
			stk.push(x);
		}
		else if (x == '}') {
			while (stk.top() != '{') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (x == '{') {
			stk.push(x);
		}
		else if (x == ']') {
			while (stk.top() != '[') {
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else if (x == '[') {
			stk.push(x);
		}
		else if ((!stk.empty() && (Precedence(x) > Precedence(stk.top()))) || stk.empty()) {
			stk.push(x);
		}
		else {
			while (!stk.empty() && (Precedence(x) <= Precedence(stk.top()))) {
				cout << stk.top();
				stk.pop();
			}
			stk.push(x);
		}
	}

	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
}

int Precedence(char ch) {
	
	switch (ch) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	default:
		return 0;
	}
}

bool isOperand(char ch) {

	switch (ch) {
	case '(':
	case ')':
	case '{':
	case '}':
	case '[':
	case ']':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return 0;
	default:
		return 1;
	}
}

bool isBalanced(string str) {
	stack<char> stk;
	for (auto& x : str) {
		if (x == '(' || x == '{' || x == '[')
			stk.push(x);
		else if(x == ')' || x == '}' || x == ']'){
			if (stk.empty())
				return false;
			if (x == ')') {
				if (stk.top() == '(')
					stk.pop();
				else
					return false;
			}
			else if (x == '}') {
				if (stk.top() == '{')
					stk.pop();
				else
					return false;
			}
			else if (x == ']') {
				if (stk.top() == '[')
					stk.pop();
				else
					return false;
			}
		}
	}
	return stk.empty();
}