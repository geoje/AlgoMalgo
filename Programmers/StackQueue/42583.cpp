#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 0, load = 0;
    queue<int> bridge, enter;

    for (int i = 0; bridge.size() || i < truck_weights.size(); time++)
    {
        // Pop truck
        if (time - enter.front() == bridge_length)
        {
            load -= bridge.front();
            bridge.pop();
            enter.pop();
        }
        // Push truck if load is not going to over
        if (i < truck_weights.size() && load + truck_weights[i] <= weight)
        {
            load += truck_weights[i];
            bridge.push(truck_weights[i++]);
            enter.push(time);
        }
    }

    return time;
}

int main()
{
    cout << solution(2, 10, {7, 4, 5, 6}) << '\n';
    cout << solution(100, 100, {10}) << '\n';
    cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << '\n';
}