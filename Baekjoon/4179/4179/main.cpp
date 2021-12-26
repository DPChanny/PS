#include<iostream>
#include<queue>

using namespace std;

#define WALL '#'
#define VOID '.'
#define FIRE 'F'
#define BODY 'J'

char m[1000][1000];
int y, x;

struct M {
	int y, x;
	bool f;
};

bool check(M _m) {
	return 
		_m.y + 1 > 0 && _m.y < y &&
		_m.x + 1 > 0 && _m.x < x &&
		m[_m.y][_m.x] != WALL &&
		m[_m.y][_m.x] != FIRE &&
		(_m.f ? true : (m[_m.y][_m.x] != BODY));
}

int main(void) {
	int s, t(0);
	cin >> y >> x;
	queue<M> q;
	for (int _y(0); _y < y; _y++) {
		getchar();
		for (int _x(0); _x < x; _x++) {
			m[_y][_x] = getchar();
			if (m[_y][_x] == FIRE)
				q.push({ _y, _x, true });
			if (m[_y][_x] == BODY)
				q.push({ _y, _x, false });
		}
	}
	M c;
	while (!q.empty()) {
		t++;
		s = q.size();
		for (int _s(0); _s < s; _s++) {
			c = q.front(); q.pop();
			if (!c.f && m[c.y][c.x] == FIRE) continue;
			if (!c.f && (!c.y || c.y + 1 == y || !c.x || c.x + 1 == x)) {
				cout << t;
				return 0;
			}
			if (check({ c.y + 1, c.x, c.f })) {
				m[c.y + 1][c.x] = c.f ? FIRE : BODY;
				q.push({ c.y + 1, c.x, c.f });
			}
			if (check({ c.y - 1, c.x, c.f })) {
				m[c.y - 1][c.x] = c.f ? FIRE : BODY;
				q.push({ c.y - 1, c.x, c.f });
			}
			if (check({ c.y, c.x + 1, c.f })) {
				m[c.y][c.x + 1] = c.f ? FIRE : BODY;
				q.push({ c.y, c.x + 1, c.f });
			}
			if (check({ c.y, c.x - 1, c.f })) {
				m[c.y][c.x - 1] = c.f ? FIRE : BODY;
				q.push({ c.y, c.x - 1, c.f });
			}
		}
	}
	cout << "IMPOSSIBLE";
}
