#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    for (; pq.size() > 1 && pq.top() < K; answer++)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
    }
    return pq.top() < K ? -1 : answer;
}

int main()
{
    // cout << solution({1, 2, 3, 9, 10, 12}, 7) << '\n';
    cout << solution({1, 1, 1, 1, 1, 1, 1, 2}, 7) << '\n';
    // cout << solution({2, 3}, 7) << '\n';
}