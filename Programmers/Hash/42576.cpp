#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> m;
    for (string c : completion)
        m[c]++;
    for (string p : participant)
        if (--m[p] < 0)
            return p;
    return "";
}

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << '\n';
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << '\n';
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << '\n';
    return 0;
}