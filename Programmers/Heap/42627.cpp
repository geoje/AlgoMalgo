#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct compareStart
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
    }
};
struct compareTake
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0, time = 0;

    priority_queue<vector<int>, vector<vector<int>>, compareStart> pq(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, compareTake> tpq;
    while (pq.size())
    {
        while (pq.size() && pq.top()[0] <= time)
        {
            tpq.push(pq.top());
            pq.pop();
        }
        vector<int> cur_task;
        if (tpq.size())
        {
            cur_task = tpq.top();
            tpq.pop();
        }
        else
        {
            cur_task = pq.top();
            pq.pop();
        }

        int s = cur_task[0], t = cur_task[1];
        answer += t + (s < time ? time - s : 0);
        time += t + (s > time ? s - time : 0);

        while (tpq.size())
        {
            pq.push(tpq.top());
            tpq.pop();
        }
    }

    return answer / jobs.size();
}

int main()
{
    cout << solution({{0, 3}, {1, 9}, {2, 6}}) << '\n';
    cout << solution({{0, 3}, {0, 4}, {4, 3}, {1, 3}, {1, 9}, {1, 2}, {2, 6}}) << '\n';
}