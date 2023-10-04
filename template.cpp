#include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n;

void print(vector<int> &vs)
{
    cout << "[";
    for (auto v : vs)
        cout << v << ',';
    cout << "]\n";
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process */

    /* Output */
    cout << n << '\n';
    return 0;
}