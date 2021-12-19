#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	string ns;
	cin >> ns;
	while (k) {
		stack<int> s;
		s.push(ns[0]);
		ns = ns.substr(1);
		while (!ns.empty() && k > 0) {
			if (s.top() < ns[0]) {
				s.pop();
				k--;
			}
			s.push(ns[0]);
			ns = ns.substr(1);
		}
		while (!s.empty()) {
			ns = (char)s.top() + ns;
			s.pop();
		}
	}
	cout << ns;
}
