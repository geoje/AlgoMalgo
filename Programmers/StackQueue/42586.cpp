#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer, cost, asc;

    for (int i = 0; i < progresses.size(); i++)
        cost.push_back(ceil((100.0 - progresses[i]) / speeds[i]));

    for (int i = 0, j = 0; i < cost.size(); i = j)
    {
        for (; j < cost.size() && cost[j] <= cost[i]; j++)
            ;
        answer.push_back(j - i);
    }

    return answer;
}

int main()
{
    for (auto v : solution({93, 30, 55}, {1, 30, 5}))
        cout << v << ", ";
    cout << '\n';

    for (auto v : solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1}))
        cout << v << ", ";
    cout << '\n';
}