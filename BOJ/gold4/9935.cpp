// #include <cstdio> // For Test
#include <vector>
#include <iostream>
using namespace std;

string str, bomb, ans;
vector<int> pos = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> str >> bomb;

    // Process
    for (char c : str)
    {
        // 일단 넣어
        ans.push_back(c);

        // 폭탄 제거 중일 때
        if (c == bomb[pos.back()])
        {
            pos.back()++;

            // 폭탄이 완성 되었을 때
            if (pos.back() == bomb.length())
            {
                ans.erase(ans.length() - bomb.length());
                if (pos.size() > 1)
                    pos.pop_back();
                else
                    pos[0] = 0;
            }
        }
        // 폭탄 발굴 도중 새로운 폭탄 시작이 나왔을 때
        else if (c == bomb[0])
            pos.push_back(1);
        // 폭탄을 완성하지 못했을 때 탐지하던 폭탄 전체 초기화
        else
            pos = {0};
    }

    // Output
    cout << (ans.empty() ? "FRULA" : ans) << '\n';
    return 0;
}