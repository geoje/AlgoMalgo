#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0, j; i < prices.size(); i++)
    {
        for (j = i; j < prices.size() - 1; j++)
            if (prices[i] > prices[j])
                break;
        answer.push_back(j - i);
    }

    return answer;
}

int main()
{
    for (auto v : solution({1, 2, 3, 2, 3}))
        cout << v << ", ";
    cout << '\n';
}