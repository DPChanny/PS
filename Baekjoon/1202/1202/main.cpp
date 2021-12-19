#include<iostream>
#include<algorithm>

using namespace std;

class N {
public:
	int m;
	int v;

	bool operator<(const N &_n) {
		return (float)this->v / (float)this->m > (float)_n.v / (float)_n.m;
	}
};

N ns[300000];
int ks[300000];

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int _n(0); _n < n; _n++)
		cin >> ns[_n].m >> ns[_n].v;
	for (int _k(0); _k < k; _k++)
		cin >> ks[_k];
	sort(ns, ns + n);
	sort(ks, ks + k, greater<int>());
	int ck(0);
	long long int s(0);
	for (int _n(0); _n < n && ck < k; _n++)
		if (ks[ck] + 1 > ns[_n].m) {
			s += ns[_n].v;
			ck++;
		}
	cout << s;
}