#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    int tc;
    cin >> tc;
    int h[tc], w[tc], n[tc];
    for (int i = 0; i < tc; i++)
        cin >> h[i] >> w[i] >> n[i];

    // Process & Output
    for (int i = 0; i < tc; i++)
        cout << (((n[i] % h[i] ? n[i] % h[i] : h[i]) * 100 + (n[i] - 1) / h[i] + 1)) << '\n';
    return 0;
}