#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    vector<int> asc(priorities.begin(), priorities.end());
    sort(asc.begin(), asc.end());

    for (int i = 0; asc.size(); i = (i + 1) % priorities.size())
    {
        if (priorities[i] == asc.back())
        {
            answer++;
            if (i == location)
                break;
            asc.pop_back();
        }
    }
    return answer;
}

int main()
{
    cout << solution({2, 1, 3, 2}, 2) << '\n';
    cout << solution({1, 1, 9, 1, 1, 1}, 0) << '\n';
}