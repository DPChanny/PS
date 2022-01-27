#include<iostream>
#include<vector>
#include<queue>

constexpr uint16_t A = 0;
constexpr uint16_t B = 1;
constexpr uint16_t C = 2;
constexpr uint16_t D = 3;

using namespace std;

char bt;
uint32_t n, k, bu;
priority_queue<uint32_t> ns[4];
uint64_t dp[200001][4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for(uint16_t _t(A); _t < D + 1; _t++)
		cin >> dp[0][_t];

	for(uint32_t _n(0); _n < n; _n++) {
		cin >> bt >> bu;
		ns[bt - 'A'].push(bu);
	}


}