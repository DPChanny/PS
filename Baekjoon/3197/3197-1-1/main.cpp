#include<iostream>
#include<queue>

using namespace std;

typedef long long int  lli;
typedef pair<lli, lli> P;
#define pf first
#define ps second

constexpr lli YXM = 1500;

lli y, x;
char yxs[YXM][YXM];
bool nwvs[YXM][YXM], nlvs[YXM][YXM];
P vs[4] = { {0, 1},{0, -1},{1, 0},{-1,0 } };
queue<P> nws, nls;


bool cp(lli _y, lli _x) {
	return
		_y + 1 > 0 && _y < YXM &&
		_x + 1 > 0 && _x < YXM;
}

int main(void) {
	cin >> y >> x;
	for (lli _y(0); _y < y; _y++)
		for (lli _x(0); _x < x; _x++)
			cin >> yxs[_y][_x];
}