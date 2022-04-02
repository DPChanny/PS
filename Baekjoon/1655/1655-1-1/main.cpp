#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, x;
vector<int> ns;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int _n(0); _n < n; _n++) {
		cin >> x;
		ns.insert(lower_bound(ns.begin(), ns.end(), x), x); 
		cout << ns[ns.size() / 2 - (ns.size() % 2 ? 0 : 1)] << '\n';
	}
}