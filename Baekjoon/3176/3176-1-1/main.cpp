#include<iostream>
#include<vector>

using namespace std;

#define ps second
#define pf first

typedef long long int lli;
typedef pair<lli, lli> P;

constexpr lli STM(20);

struct S {
	lli n, min, max;
};

vector<P> es[100'000];
lli n, k, bf, bt, bw, ds[100'000];
S st[STM][100'000];

void gst(P _n, lli _d, lli _p) {
	ds[_n.pf] = _d; st[0][_n.pf] = { _p, _n.ps, _n.ps };
	for (lli _e(0); _e < es[_n.pf].size(); _e++)
		if (es[_n.pf][_e].pf != _p) gst(es[_n.pf][_e], _d + 1, _n.pf);
} 

int main(void) {
	cin.tie(nullptr); cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n;
	for (lli _n(0); _n < n; _n++) {
		cin >> bf >> bt >> bw;
		es[bf - 1].push_back({ bt - 1, bw });
		es[bt - 1].push_back({ bf - 1, bw });
	}
	gst({ 0, 0 }, 0, 0);
	for (lli _i(1); _i < STM; _i++)
		for (lli _n(0); _n < n; _n++)
			st[_i][_n] = {
				st[_i - 1][st[_i - 1][_n].n].n,
				max(st[_i - 1][_n].max, st[_i - 1][st[_i - 1][_n].n].max),
				min(st[_i - 1][_n].min, st[_i - 1][st[_i - 1][_n].n].min) };
	cin >> k;
}