#include <iostream>
#include <vector>
using namespace std;

const int INF = 2100000000;
int n, m, choice[13], answer = INF;
vector<pair<int, int>> houses, chickens;

void combination(int num, int idx)
{
    // M개 선택이 끝났을 경우 계산하고 종료
    if (num >= m)
    {
        int result = 0;
        for (pair<int, int> house : houses)
        {
            int md = INF;
            for (int i = 0; i < m; i++)
            {
                int dis = abs(house.first - chickens[choice[i]].first) +
                          abs(house.second - chickens[choice[i]].second);
                if (dis < md)
                    md = dis;
            }
            result += md;
        }
        if (result < answer)
            answer = result;
        return;
    }

    // 고를 치킨집이 없을 경우
    if (idx >= chickens.size())
        return;

    choice[num] = idx;
    combination(num + 1, idx + 1); // 선택
    combination(num, idx + 1);     // 미선택
}

int main()
{
    // Input
    int place;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> place;
            if (place == 1)
                houses.push_back({i, j});
            else if (place == 2)
                chickens.push_back({i, j});
        }

    // Process
    combination(0, 0);

    // Output
    cout << answer << "\n";
    return 0;
}