#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

bool isvisit[100];
pair<int, int> place[100];
int end_x, end_y;

bool bfs(int a, int b, int cnt) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		if (abs(tmp.first - end_x) + abs(tmp.second - end_y) <= 1000) return true;
		for (int i = 0; i < cnt; i++) {
			if (!isvisit[i]) {
				if (abs(place[i].first - tmp.first) + abs(place[i].second - tmp.second) <= 1000) {
					q.push({ place[i] });
					isvisit[i] = true;
				}
			}
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int home_x, home_y;
		int cnt;
		cin >> cnt >> home_x >> home_y;
		for (int i = 0; i < cnt; i++) {
			int x, y;
			cin >> x >> y;
			place[i] = { x, y };
		}
		cin >> end_x >> end_y;
		if (bfs(home_x, home_y, cnt)) cout << "happy\n";
		else cout << "sad\n";
		memset(isvisit, false, cnt);
	}
}
