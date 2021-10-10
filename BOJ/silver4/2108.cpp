#include <cstdio> // For Test
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[500000], com[8001] = {0};
double sum;
int center, val = 1, low = 4000, high = -4000;
vector<int> coms;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input & Process */
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        low = min(low, arr[i]);
        high = max(high, arr[i]);

        int &c = com[4000 + arr[i]];
        c++;
        if (c == val)
            coms.push_back(arr[i]);
        else if (c > val)
        {
            coms.clear();
            coms.push_back(arr[i]);
        }
        val = max(val, c);
    }
    sort(arr, arr + n);
    sort(coms.begin(), coms.end());

    /* Output */
    cout << round(sum / n) << '\n';
    cout << arr[n / 2] << '\n';
    cout << (coms.size() >= 2 ? coms[1] : coms[0]) << '\n';
    cout << high - low << '\n';
    return 0;
}