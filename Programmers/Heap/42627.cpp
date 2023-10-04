#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, time = 0;

    priority_queue<vector<int>, vector<vector<int>>, compare> pq(jobs.begin(), jobs.end());
    while (pq.size())
    {
        int s = pq.top()[0], t = pq.top()[1];
        answer += t + (s < time ? time - s : 0);
        time += t + (s > time ? s - time : 0);
        pq.pop();
    }

    return answer / jobs.size();
}

int main()
{
    cout << solution({{0, 3}, {1, 9}, {2, 6}}) << '\n';
    cout << solution({{0, 3}, {0, 4}, {4, 3}, {1, 3}, {1, 9}, {1, 2}, {2, 6}}) << '\n';
}