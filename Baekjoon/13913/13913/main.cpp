#include<iostream>
#include<queue>
#include<string>

using namespace std;

int visit[100001]{};

int main(void) {
	int n, k, t(0);
	cin >> n >> k;

	queue<pair<int, string>> q;
	q.push(pair<int, string>(n, to_string(n)));
	while (true) {
		int s = q.size();
		for (int _q(0); _q < s; _q++) {
			if (q.front().first == k) {
				cout << t << '\n' << q.front().second;
				return 0;
			}
			if (q.front().first < 0 ||
				q.front().first > 100000 ||
				visit[q.front().first]) {	
				q.pop();
				continue;
			}
			visit[q.front().first] = 1;
			q.push(pair<int, string>(
				q.front().first + 1, 
				q.front().second + ' ' + to_string(q.front().first + 1)));
			q.push(pair<int, string>(
				q.front().first - 1, 
				q.front().second + ' ' + to_string(q.front().first - 1)));
			q.push(pair<int, string>(
				q.front().first * 2,
				q.front().second + ' ' + to_string(q.front().first * 2)));
			q.pop();
		}
		t++;
	}
}