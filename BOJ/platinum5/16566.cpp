#include <cstdio> // For Test
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
set<int> cards;
bool use[4000000] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int card;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> card;
        cards.insert(card);
    }

    /* Process */
    while (k--)
    {
        // 카드 입력
        cin >> card;

        // 카드 선택
        auto it = cards.upper_bound(card);

        // 카드 사용
        cout << *it << '\n';
        cards.erase(it);
    }

    /* Output */
    return 0;
}