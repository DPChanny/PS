#include<iostream>
#include<vector>

using namespace std;

int n, k, bx, by;
vector<pair<int, int>> ps;

int main(void) {
	cin >> n >> k;
	for (int _n = 0; _n < n; _n++) {
		cin >> bx >> by;
		ps.push_back(make_pair(bx, by));
	}

}