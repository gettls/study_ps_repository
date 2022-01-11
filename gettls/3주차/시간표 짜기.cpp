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
typedef unsigned long long ull;
int n, m;
string door;
vector<string> btn;
int main() {
	cin >> n >> m;

	cin >> door;

	for (int i = 0; i < m; i++) {
		string str; cin >> str;
		btn.push_back(str);
	}

}