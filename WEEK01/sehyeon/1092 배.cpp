#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int crain[50];

int main() {
	int n;
	cin >> n;
	vector<int> v;
	//크레인 무게 입력받고 정렬
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	//박스 무게 입력받아 무게 구간별로 분배
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if (v[j] >= tmp) {
				crain[j]++;
				break;
			}
			else if (j == n - 1) {
				cout << -1;
				return 0;
			}
		}
	}
	int cnt = 0;
	while (1) {
		cnt++;
		for (int i = n - 1; i >= 0; i--) {
			if (crain[i] > 0) {
				crain[i]--;
				m--;
			}
			else {
				int j = i;
				while (j >= 0 && crain[j] == 0) j--;
				if (crain[j] > 0) {
					crain[j]--;
					m--;
				}
			}
			if (m == 0) {
				cout << cnt;
				return 0;
			}
		}
	}
}
