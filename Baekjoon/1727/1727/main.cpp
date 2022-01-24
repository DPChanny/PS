#include<iostream>
#include<algorithm>

using namespace std;

int n, m, nmgs[1000][1000], ns[1000], ms[1000];

int main(void) {
	cin >> n >> m;
	for(int _n(0); _n < n; _n++)
		cin >> ns[_n];
	for(int _m(0); _m < m; _m++)
		cin >> ms[_m];
	sort(ns, ns + n); sort(ms, ms + m);
	if(n < m) {
		swap(ns, ms);
		swap(n, m);
	}
	for(int _n(0); _n < n; _n++)
		for(int _m(0); _m < m; _m++)
			nmgs[_n][_m] = abs(ns[_n] - ms[_m]);
	for(int _n(0); _n < n; _n++) {
		for(int _m(1); _m < m; _m++) {
			int min(1e9);
			for(int i(0); i < _n; i++)
				min = min > nmgs[i][_m - 1] ? nmgs[i][_m - 1] : min;
			nmgs[_n][_m] += min;
		}
	}
	cout << nmgs[n - 1][m - 1];
}