#include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, k;
vector<int> v;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    /* Process & Output */
    int x = k - 1;
    cout << "<" << v[x];
    v.erase(v.begin() + x);
    while (!v.empty())
    {
        x = (x + k - 1) % v.size();
        cout << ", " << v[x];
        v.erase(v.begin() + x);
    }
    cout << ">";
    return 0;
}
