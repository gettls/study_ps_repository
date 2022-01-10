#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
using namespace std;
#pragma warning (disable:4996)

int n, m;
int alphabet;
int arr[10000];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (char c : str) {
			alphabet = alphabet | 1 << c - 'a';
			arr[i] = arr[i] | 1 << c - 'a';
		}
	}

	for (int i = 0; i < m; i++) {
		int o; char x = '.';
		cin >> o >> x;
		int cnt = 0;
		if (o == 1) { // 잊는다
			alphabet = alphabet & ~(1 << x - 'a');
		}
		else if (o == 2) { // 기억해낸다
			alphabet = alphabet | (1 << x - 'a');
		}

		for (int j = 0; j < n; j++) {
			int tmp = arr[j] & alphabet;
			if (tmp == arr[j]) cnt++;
		}
		cout << cnt << "\n";
	}

}