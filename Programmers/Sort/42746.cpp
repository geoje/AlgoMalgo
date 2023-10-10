#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> numbersStr;

    for (int n : numbers)
        numbersStr.push_back(to_string(n));

    sort(numbersStr.begin(), numbersStr.end(), compare);

    for (string s : numbersStr)
        answer += s;

    return answer[0] == '0' ? "0" : answer;
}

int main()
{
    cout << solution({6, 10, 2}) << '\n';
    cout << solution({3, 30, 34, 5, 9}) << '\n';
}