// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, parent[100001] = {
           0,
};
vector<int> arr[100001];

void find(int cur, int prev)
{
    if (parent[cur])
        return;

    parent[cur] = prev;
    for (int i : arr[cur])
        find(i, cur);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    int a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // Process
    for (int i : arr[1])
        find(i, 1);

    // Output
    for (int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
    return 0;
}