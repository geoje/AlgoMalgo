#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (auto command : commands)
    {
        vector<int> temp(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[command[2] - 1]);
    }

    return answer;
}

void print(vector<int> vs)
{
    cout << "{";
    if (vs.size())
        cout << vs.front();
    for (int i = 1; i < vs.size(); i++)
        cout << ',' << vs.at(i);
    cout << "}\n";
}

int main()
{
    print(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}}));
}