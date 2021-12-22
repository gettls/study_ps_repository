#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> ss;
    ss.push(s[0]);

    for (int i = 1; i < s.size(); i++) {
        if (!ss.empty() && s[i] == ss.top()) ss.pop();
        else ss.push(s[i]);
    }

    if (ss.empty()) answer = 1;
    return answer;
}