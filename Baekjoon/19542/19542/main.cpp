#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

uint32_t n, s, d, bf, bt, rds[100'000], cq, c;
vector<uint32_t> ns[100'000];
bool vs[100'000];

uint32_t grd(uint32_t _f) {
	uint32_t mcd(0);
	vs[_f] = true;
	for(uint32_t _t(0); _t < ns[_f].size(); _t++)
		if(!vs[ns[_f][_t]])
			mcd = max(mcd, grd(ns[_f][_t]));
	rds[_f] = mcd;
	return mcd + 1;
}

int32_t main(void) {
	cin >> n >> s >> d;
	for(uint32_t _n(0); _n < n - 1; _n++) {
		cin >> bf >> bt;
		ns[bf - 1].push_back(bt - 1);
		ns[bt - 1].push_back(bf - 1);
	}
	grd(s - 1);
	//정답 도출 필요
}