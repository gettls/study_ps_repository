#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <bitset>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)
typedef unsigned long long ull;
int n, m;
bitset<100> door;
bitset<100> btn[20];


bitset<100> btnClick(bitset<100> tmp, int idx) {
	return tmp ^= btn[idx];
}

int timeMachine(bitset<100> tmp) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (tmp[i]) ret++;
		else ret--;
	}
	return ret;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; scanf("%1d", &x);
		door.set(i, x);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x; scanf("%1d", &x);
			btn[i].set(j, x);
		}
	}

	vector<vector<int>> check(2 * n + 1);
	check[timeMachine(door) + n].push_back(-1);


	// m 개 스위치의 조합 -> list 
	int set = (1 << m) - 1;
	for (int subset = set; subset; subset = (subset - 1) & set) {
		vector<int> l;
		for (int i = 0; i < m; i++) {
			if (subset & (1 << i)) l.push_back(i);
		}

		bitset<100> tmp = door;
		for (int num : l) {
			tmp = btnClick(tmp, num);
		}
		// Click 결과 확인
		int time = timeMachine(tmp);

		if (check[time + n].size() != 0) continue;
		for (int i = 0; i < l.size(); i++) {
			check[time + n].push_back(l[i]);
		}
	}


	for (int time = -n; time <= n; time++) {
		int t = time + n;

		if (check[t].size() == 0) {
			printf("-1\n");
		}
		else if (check[t][0] == -1) {
			printf("0\n");
		}
		else {
			printf("%d ", check[t].size());
			for (int i = 0; i < check[t].size(); i++) {
				printf("%d ", check[t][i] + 1);
			}
			printf("\n");
		}

	}
}