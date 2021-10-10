#include <cstdio> // For Test
#include <unordered_map>
#include <iostream>
using namespace std;

int n, m, x;
unordered_map<int, int> cards;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process */
    cin >> n;
    while (n--)
    {
        cin >> x;
        cards[x]++;
    }
    cin >> m;

    /* Input & Output */
    while (m--)
    {
        cin >> x;
        cout << cards[x] << ' ';
    }
    return 0;
}