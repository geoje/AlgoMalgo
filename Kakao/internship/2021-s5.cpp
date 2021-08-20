#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links)
{
    int answer = 0;
    return answer;
}

int main()
{
    cout << solution(3, {12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1}, {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {8, 5}, {2, 10}, {3, 0}, {6, 1}, {11, -1}, {7, 4}, {-1, -1}, {-1, -1}}) << '\n';
    cout << solution(1, {6, 9, 7, 5}, {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}}) << '\n';
    cout << solution(2, {6, 9, 7, 5}, {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}}) << '\n';
    cout << solution(4, {6, 9, 7, 5}, {{-1, -1}, {-1, -1}, {-1, 0}, {2, 1}}) << '\n';
    return 0;
}