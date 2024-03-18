// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, s, sum = 0, ans = 1e5;
vector<int> seq;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process */
    cin >> n >> s;
    seq.resize(n);
    for (int i = 0, j = 0; j < n; j++)
    {
        cin >> seq[j];
        sum += seq[j];

        for (; sum >= s; sum -= seq[i++])
            ans = min(ans, j - i);
    }

    /* Output */
    cout << (ans == 1e5 ? 0 : ans + 1) << '\n';
    return 0;
}