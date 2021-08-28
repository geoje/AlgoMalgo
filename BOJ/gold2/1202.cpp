#include <cstdio> // For Test
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

int n, k;
long long ans = 0;
// first: value, second: weight
priority_queue<pair<int, int>> gems;
multiset<int> bags;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> k;
    int weight, value;
    while (n--)
    {
        cin >> weight >> value;
        gems.push({value, weight});
    }

    while (k--)
    {
        cin >> weight;
        bags.insert(weight);
    }

    /* Process */
    while (!gems.empty())
    {
        // 더 넣을 가방이 없을 경우 끝
        if (bags.empty())
            break;

        // 젬 뽑고 넣 수 있는 가방이 있는지 탐색
        tie(value, weight) = gems.top();
        gems.pop();

        auto it = bags.lower_bound(weight);

        // 최대 가치의 보석을 담을 가방이 없으면 패스
        if (it == bags.end())
            continue;

        bags.erase(it);
        ans += value;
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}