// #include <cstdio> // For Test
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num, ans;

void sequence(int count, int idx)
{
    ans[count] = num[idx];

    if (++count == m)
    {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    else
        for (int i = idx; i < n; i++)
            sequence(count, i);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    num.resize(n);
    ans.resize(m);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    n = num.size();

    // Process & Output
    for (int i = 0; i < n; i++)
        sequence(0, i);
    return 0;
}