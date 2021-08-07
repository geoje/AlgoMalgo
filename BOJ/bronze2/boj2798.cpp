#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    int n, m, cards[100];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    // Process
    int answer = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                for (int k = 0; k < n; k++)
                    if (i != k && j != k)
                    {
                        int sum = cards[i] + cards[j] + cards[k];
                        if (sum <= m && sum > answer)
                            answer = sum;
                    }

    // Output
    cout << answer << '\n';
    return 0;
}