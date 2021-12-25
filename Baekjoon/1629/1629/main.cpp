#include<iostream>

using namespace std;

int a, b, c;

long long int m(int _r) {
	if (!_r) return 1;
	long long int r(m(_r / 2));
	return r * r * ((_r % 2) ? a : 1) % c;
}

int main(void) {
	cin >> a >> b >> c;
	cout << m(b);
}
