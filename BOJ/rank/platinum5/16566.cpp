#include <cstdio> // For Test
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int cards[4000000], p[4000000];

int find(int x)
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        p[x] = y;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> cards[i];
        p[i] = i;
    }
    sort(cards, cards + m);

    /* Process */
    int card;
    while (k--)
    {
        cin >> card;
        int i = find(upper_bound(cards, cards + m, card) - cards);
        cout << cards[i] << '\n';
        join(i, i + 1);
    }

    /* Output */
    return 0;
}