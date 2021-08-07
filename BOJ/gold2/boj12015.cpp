// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

int n, num;
vector<int> v;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input & Process
    v.push_back(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (v.back() < num)
            v.push_back(num);
        else
        {
            auto it = lower_bound(v.begin(), v.end(), num);
            *it = num;
        }
    }

    // Output
    cout << v.size() - 1 << '\n';
    return 0;
}