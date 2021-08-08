// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int n, m, ans;
queue<int> knows;
vector<bool> reputed;
vector<vector<int>> people;
vector<vector<int>> partys;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    ans = m;
    reputed.resize(m + 1);
    people.resize(n + 1);
    partys.resize(m + 1);

    // 아는 사람 입력
    int k, p;
    cin >> k;
    while (k--)
    {
        cin >> p;
        knows.push(p);
    }

    // 각 사람의 참여 파티 입력
    for (int i = 1, j; i <= m; i++)
    {
        cin >> j;
        while (j--)
        {
            cin >> p;
            // p번 사람은 i번 파티에 참여함
            people[p].push_back(i);
            partys[i].push_back(p);
        }
    }

    // Process
    // 이야기를 아는 모든 사람 체크
    while (!knows.empty())
    {
        p = knows.front();
        knows.pop();

        // 이 사람이 참여하는 모든 파티 체크
        for (int party : people[p])
        {
            // 이미 소문난 파티이면 패스
            if (reputed[party])
                continue;
            reputed[party] = true;

            // 해당 파티의 사람들을 아는사람들로 추가
            for (int know : partys[party])
                knows.push(know);

            // 정답 갱신
            ans--;
        }
    }

    // Output
    cout << ans << '\n';
    return 0;
}