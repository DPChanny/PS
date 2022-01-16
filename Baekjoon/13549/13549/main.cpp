#include<iostream>
#include<deque>

using namespace std;

constexpr int MAX = 100001;

int n, k, t, s, cq;
bool vs[MAX];

int main(void) {
	cin >> n >> k;
	deque<int> q;
	q.push_back(n);
	while (true) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			cq = q.front(); q.pop_front();
			if (cq == k) {
				cout << t;
				exit(EXIT_SUCCESS);
			}
			if (cq * 2 < MAX && !vs[cq * 2]) {
				vs[cq * 2] = true;
				q.push_front(cq * 2);
				s++;
			}
			if (cq < MAX - 1 && !vs[cq + 1]) {
				vs[cq + 1] = true;
				q.push_back(cq + 1);
			}
			if (cq > 0 && !vs[cq - 1]) {
				vs[cq - 1] = true;
				q.push_back(cq - 1);
			}
		}
		t++;
	}
}
