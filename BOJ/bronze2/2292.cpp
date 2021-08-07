#include <iostream>
using namespace std;

int calc(int n)
{
    n--;
    int ans = 1;
    for (int i = 6; n > 0; i += 6, ans++)
        n -= i;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    int n;
    cin >> n;

    // Process & Output
    cout << calc(n) << '\n';
    return 0;
}