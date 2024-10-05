#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Topni {
	string NS;
	int left;
	int right;
};

//시계방향 회전이면 -1, 반시계방향이면 +1
void turn_left(Topni& topni, int tmp) {
	if (tmp == 1) topni.left = (topni.left + 7) % 8;
	else topni.left = (topni.left + 1) % 8;
}

void turn_right(Topni& topni, int tmp) {
	if (tmp == 1) topni.right = (topni.right + 7) % 8;
	else topni.right = (topni.right + 1) % 8;
}

int main() {
	vector<Topni> v;
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		v.push_back({ s, 6, 2 });
	}
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int num, dir;
		cin >> num >> dir;
		num--;
		int tmp = dir;
		//왼쪽으로 go
		for (int i = num-1; i >= 0; i--) {
			if (i == 2) turn_right(v[i + 1], tmp);
			//오른쪽 톱니 left, 현재 톱니 right 비교해서 돌릴지 말지 결정
			if (v[i].NS[v[i].right] != v[i+1].NS[v[i + 1].left]) {
				//오른쪽 톱니 left 바꾸기
				turn_left(v[i+1], tmp);
				//방향 바꿔서 현재 톱니 right 바꾸기
				tmp = -tmp;
				turn_right(v[i], tmp);
				//맨 왼 쪽 톱니 left 처리
				if (i == 0) turn_left(v[i], tmp);
			}
			else {
				turn_left(v[i + 1], tmp);
				break;
			}
		}
		tmp = dir;
		//오른쪽으로 go
		for (int i = num + 1; i < 4; i++) {
			if (i == 1) turn_left(v[i - 1], tmp);
			//왼쪽 톱니 right, 현재 톱니 left 비교해서 돌릴지 말지 결정
			if (v[i].NS[v[i].left] != v[i-1].NS[v[i - 1].right]) {
				turn_right(v[i - 1], tmp);
				tmp = -tmp;
				turn_left(v[i], tmp);
				if (i == 3) turn_right(v[i], tmp);
			}
			else {
				turn_right(v[i - 1], tmp);
				break;
			}
		}
	}
	int sum = 0;
	for (int i = 3; i >= 0; i--) {
		sum *= 2;
		sum += (v[i].NS[(v[i].left + 2) % 8]) == '1' ? 1 : 0;
	}
	cout << sum;
}
