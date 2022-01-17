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
typedef pair<int, int> pii;


class package {
public:
	int from, to, amount;

	package(int from, int to, int amount) {
		this->from = from;
		this->to = to;
		this->amount = amount;
	}

	bool operator < (package& package) {
		if (this->to == package.to) return this->from < package.from;
		else return this->to < package.to;
	}
};

vector<package> v;
int capacity[2001];


int main() {
	int n, c;
	cin >> n >> c;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back(package(x, y, z));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) capacity[i] = c;


	int cnt = 0;
	for (int i = 0; i < m; i++) {

		int min_capacity = capacity[v[i].from];
		for (int j = v[i].from; j < v[i].to; j++) {
			min_capacity = min(min_capacity, capacity[j]);
		}

		int load = v[i].amount;
		if (v[i].amount > min_capacity) load = min_capacity;


		for (int j = v[i].from; j < v[i].to; j++) {
			capacity[j] -= load;
		}

		cnt += load;
	}

	cout << cnt;

}
