#include <iostream>
using namespace std;

char gears[5][8];
int gearHeads[5] = {0};

void rotate(int gn, int toLeft, char prevPole, int prevRotate)
{
    if (gn < 1 || gn > 4)
        return;

    // 나도 돈다면
    if ((toLeft && (gears[gn][(gearHeads[gn] + 2) % 8] != prevPole)) || (!toLeft && (gears[gn][(gearHeads[gn] + 6) % 8] != prevPole)))
    {
        // 전의
        rotate(gn + (toLeft ? -1 : 1), toLeft, gears[gn][(gearHeads[gn] + (toLeft ? 6 : 2)) % 8], prevRotate * -1);

        // 내 것 처리
        if (prevRotate == -1)
        {
            if (gearHeads[gn]-- == 0)
                gearHeads[gn] = 7;
        }
        else if (prevRotate == 1)
        {
            if (gearHeads[gn]++ == 7)
                gearHeads[gn] = 0;
        }
    }
}

int main()
{
    // Input
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> gears[i][j];
            gears[i][j] -= '0';
        }

    // Process
    int num, gn, gr;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        // 전의
        cin >> gn >> gr;
        rotate(gn - 1, true, gears[gn][(gearHeads[gn] + 6) % 8], gr);
        rotate(gn + 1, false, gears[gn][(gearHeads[gn] + 2) % 8], gr);

        // 내 것 처리
        if (gr == 1)
        {
            if (gearHeads[gn]-- == 0)
                gearHeads[gn] = 7;
        }
        else if (gr == -1)
        {
            if (gearHeads[gn]++ == 7)
                gearHeads[gn] = 0;
        }
    }

    // Output
    int ans = 0, add = 1;
    for (int i = 1; i <= 4; i++, add *= 2)
        if (gears[i][gearHeads[i]])
            ans += add;
    cout << ans << '\n';
    return 0;
}