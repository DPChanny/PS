#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	stack<char> s;
	string input, result;
	cin >> input;
	for (int i(0); i < input.length(); i++)
	{
		if (input[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				result += s.top(); s.pop();
			}
			s.pop();
		}
		else if (input[i] == '+' || input[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				result += s.top(); s.pop();
			}
			s.push(input[i]);
		}
		else if (input[i] == '*' || input[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				result += s.top(); s.pop();
			}
			s.push(input[i]);
		} 
		else if (input[i] == '(') s.push(input[i]);
		else result += input[i];
	}   
	while (!s.empty()) {
		result += s.top(); s.pop();
	}
	cout << result;
}
