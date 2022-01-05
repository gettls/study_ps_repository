#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#pragma warning (disable:4996)

int parent[50], v[50];
int n, ans;

void go(int num) {
	int flag = 0;
	v[num] = 1;
	if (parent[num] != -2) {
		for (int i = 0; i < n; i++) {
			if (parent[i] == num && !v[i]) {
				go(i);
				flag = 1;
			}
		}
		if (!flag) ans++;
	}
}

void remove(int num) {
	parent[num] = -2;
	for (int i = 0; i < n; i++) {
		if (parent[i] == num) remove(i);
	}
}

int main() {
	int num;
	cin >> n;
	int root;
	for (int i = 0; i < n; i++) {
		cin >> parent[i];
		if (parent[i] == -1) { root = i; }
	}
	cin >> num;
	remove(num);
	go(root);
	cout << ans;
}