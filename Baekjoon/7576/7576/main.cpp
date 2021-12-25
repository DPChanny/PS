#include<iostream>
#include<queue>

using namespace std;

int ts[1000][1000],
	x,
	y;

bool check_point(int _y, int _x) {
	return 
		_y + 1 > 0 && _y < y && 
		_x + 1 > 0 && _x < x && 
		!ts[_y][_x];
}

int main(void) {
	int t(0), s;
	cin >> x >> y;
	queue<pair<int, int>> q;
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++) {
			cin >> ts[_y][_x];
			if (ts[_y][_x])
				q.push(make_pair(_y, _x));
		}
	pair<int, int> c;
	while (!q.empty()) {
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			c = q.front(); q.pop();
			ts[c.first][c.second] = 1;
			if (check_point(c.first + 1, c.second + 1))
				q.push(make_pair(c.first + 1, c.second + 1));
			if (check_point(c.first + 1, c.second - 1))
				q.push(make_pair(c.first + 1, c.second - 1));
			if (check_point(c.first - 1, c.second + 1))
				q.push(make_pair(c.first - 1, c.second + 1));
			if (check_point(c.first - 1, c.second - 1))
				q.push(make_pair(c.first - 1, c.second - 1));
		}
		t++;
	}
	for (int _y(0); _y < y; _y++)
		for (int _x(0); _x < x; _x++)
			if (!ts[_y][_x]) {
				cout << '-1';
				return 0;
			}
	cout << t;
}