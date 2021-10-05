#include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int cards[4000000];
bool use[4000000] = {0};

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> cards[i];
    sort(cards, cards + m);

    /* Process */
    int card;
    while (k--)
    {
        // 카드 입력
        cin >> card;

        // 카드 선택
        int i = 0;
        while (cards[i] <= card || use[i])
            i++;

        // 카드 사용
        cout << cards[i] << '\n';
        use[i] = true;
    }

    /* Output */
    return 0;
}