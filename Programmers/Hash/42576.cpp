#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    return answer;
}

int main()
{
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << '\n';
    cout << solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}) << '\n';
    cout << solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}) << '\n';
    return 0;
}