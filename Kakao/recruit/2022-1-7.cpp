#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> board;

int play(int r1, int c1, int r2, int c2, int count)
{
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
    int answer = -1;

    return answer;
}

int main()
{
    cout << solution({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << '\n';
    cout << solution({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << '\n';
    cout << solution({{1}}, {0, 0}, {0, 0}) << '\n';
    return 0;
}