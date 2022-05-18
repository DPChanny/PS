#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> B;
#define pt first
#define pw second

constexpr lli MN = 1'000;

lli n, m, bf, bt, bw, nws[MN], cn, nhs[MN];
bool nvs[MN];
vector<B> bs[MN];
struct c {
	bool operator()(lli &_a, lli &_b){
		return nws[_a] > nws[_b];
	}
};
priority_queue<lli, vector<lli>, c> ns;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int _m(0); _m < m; _m++) {
		cin >> bf >> bt >> bw;
		bs[bf - 1].push_back({ bt - 1 , bw });
	}
	fill(nws, nws + MN, INT64_MAX);
	fill(nhs, nhs + MN, -1);
	cin >> bf >> bt;
	nws[bf - 1] = 0;
	ns.push(bf - 1);
	while (!ns.empty()) {
		cn = ns.top(); ns.pop();
		if (nvs[cn]) continue;
		nvs[cn] = true;
		for (lli _b(0); _b < bs[cn].size(); _b++)
			if (nws[cn] + bs[cn][_b].pw < nws[bs[cn][_b].pt]) {
				nws[bs[cn][_b].pt] = nws[cn] + bs[cn][_b].pw;
				nhs[bs[cn][_b].pt] = cn;
				ns.push(bs[cn][_b].pt);
			}
	}
	stack<lli> rhs;
	rhs.push(bt - 1);
	while (nhs[rhs.top()] != -1)
		rhs.push(nhs[rhs.top()]);
	cout << nws[bt - 1] << '\n' << rhs.size() << '\n';
	while (!rhs.empty()) {
		cout << rhs.top() + 1 << ' '; rhs.pop();
	}
}