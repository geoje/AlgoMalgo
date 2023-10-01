#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> map;
    for (auto c : clothes)
        map[c[1]]++;

    int answer = 1;
    for (auto it = map.begin(); it != map.end(); ++it)
        answer *= (it->second + 1);
    return --answer;
}
void main()
{
    cout << solution({}) << '\n';
}