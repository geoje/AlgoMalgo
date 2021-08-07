// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 1e6;
int n, maxDP[2][3] = {0}, minDP[2][3] = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input & Process
    cin >> n;
    fill_n(&minDP[0][0], 3, INF);

    // Boundary Condition
    int a, b, c;
    cin >> a >> b >> c;
    maxDP[1][0] = minDP[1][0] = a;
    maxDP[1][1] = minDP[1][1] = b;
    maxDP[1][2] = minDP[1][2] = c;

    // Recursive Property
    for (int i = 2; i <= n; i++)
    {
        // Init Array
        int *pMax = maxDP[!(i % 2)];
        int *pMin = minDP[!(i % 2)];
        int *cMax = maxDP[i % 2];
        int *cMin = minDP[i % 2];

        // Calc Max
        cin >> a >> b >> c;
        cMax[0] = a + max(pMax[0], pMax[1]);
        cMax[1] = b + max(max(pMax[0], pMax[1]), pMax[2]);
        cMax[2] = c + max(pMax[1], pMax[2]);

        // Calc Min
        cMin[0] = a + min(pMin[0], pMin[1]);
        cMin[1] = b + min(min(pMin[0], pMin[1]), pMin[2]);
        cMin[2] = c + min(pMin[1], pMin[2]);
    }

    // Output
    cout << max(max(maxDP[n % 2][0], maxDP[n % 2][1]), maxDP[n % 2][2]) << ' ';
    cout << min(min(minDP[n % 2][0], minDP[n % 2][1]), minDP[n % 2][2]) << '\n';
    return 0;
}