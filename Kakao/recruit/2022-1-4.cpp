#include <string>
#include <vector>
#include <iostream>
using namespace std;

int score = 0;
vector<int> info, current(11), answer(11);

// info: 어피치가 맞춘 수, n: 입력된 화살 수, v: 남은 화살 수, k: 맞출 인덱스, sc: 현재 점수
void archery(vector<int> &info, int n, int v, int k, int sc)
{
    // 측정
    if (k == 11)
    {
        // 최고점수 일 경우
        if (sc > score)
        {
            score = sc;

            for (int i = 0; i < 11; i++)
                answer[i] = current[i];
            answer[10] += v;
        }
        // 같은 점수 일 경우
        else if (sc == score)
            for (int i = 10; i >= 0; i--)
            {
                // 원래 맞춘 경우가 정답일 경우 업데이트 안함
                if (answer[i] > current[i])
                    break;

                // 가장 낮은 점수를 더 많이 맞힌 경우 업데이트
                else if (current[i] > answer[i])
                {
                    for (int i = 0; i < 11; i++)
                        answer[i] = current[i];
                    answer[10] += v;
                }
            }
        return;
    }

    // k점 맞추고 다음 점수 찾기
    if (v > info[k])
    {
        current[k] = info[k] + 1;
        archery(info, n, v - current[k], k + 1, sc + (10 - k));
    }
    // 개수 부족하면 점수 안올리고 v개 맞췄다고만 표시
    else if (v)
    {
        current[k] = v;
        archery(info, n, 0, k + 1, sc - (10 - k));
    }

    // k점 안맞추고 다음 점수 찾기
    current[k] = 0;
    archery(info, n, v, k + 1, sc - (info[k] ? (10 - k) : 0));
}

vector<int> solution(int n, vector<int> info)
{
    score = 0;
    answer.assign(11, 0);
    archery(info, n, n, 0, 0);

    // 점수 차 측정
    int sc = 0;
    for (int i = 0; i < 11; i++)
        if (answer[i] || info[i])
            sc += (10 - i) * (answer[i] > info[i] ? 1 : -1);

    // return answer;
    return sc <= 0 ? vector<int>(1, -1) : answer;
}

int main()
{
    for (int n : solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution(1, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution(9, {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1}))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution(10, {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3}))
        cout << n << ' ';
    cout << '\n';

    return 0;
}