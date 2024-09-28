#include<iostream>

using namespace std;

int n;
bool has_robot[200];
int power[200];

int next_up(int a) {
	return (a - 1 + 2 * n) % (2 * n);
}
int next_down(int a) {
	return (a + n - 1) % (2 * n);
}
int next_point(int a) {
	return (a + 1) % (2 * n);
}
int prev_point(int a) {
	return (a - 1 + 2 * n) % (2 * n);
}


int main() {
	int k;
	int cnt_zero = 0;
	int up_point = 0, down_point;
	int step = 1;

	cin >> n >> k;
	down_point = up_point + n - 1;
	for (int i = 0; i < 2*n; i++) {
		cin >> power[i];
	}
	while (cnt_zero < k) {
		//포인터 이동
		up_point = next_up(up_point);
		//내리는 위치면 로봇 내려
		down_point = next_down(up_point);
		if (has_robot[down_point]) has_robot[down_point] = 0;
		//내리는 위치에서 반복문 -> 로봇 이동(내구도 확인, 마지막 확인)
		for (int i = prev_point(down_point); i != up_point;) {
			if (has_robot[i] && !has_robot[next_point(i)] && power[next_point(i)]>0) {
				//로봇 위치 바꾸기
				has_robot[i] = 0;
				if(next_point(i) !=down_point) has_robot[next_point(i)] = 1;
				//내구도 바꾸기
				power[next_point(i)]--;
				//내구도 0 확인
				if (power[next_point(i)] == 0) cnt_zero++;
			}
			i = prev_point(i);
		}
		//올리는 위치(내구도 확인)
		if (power[up_point] > 0) {
			has_robot[up_point] = 1;
			power[up_point]--;
			if (power[up_point] == 0) cnt_zero++;
		}
		if (cnt_zero >= k) cout << step;
		step++;
	}
}
