#include <string>
#include <vector>
#include <iostream>
using namespace std;

long SecondsByTime(string str)
{
    long n = str[7] - '0';
    n += (str[6] - '0') * 10;
    n += (str[4] - '0') * 60;
    n += (str[3] - '0') * 600;
    n += (str[1] - '0') * 3600;
    n += (str[0] - '0') * 36000;
    return n;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    long maxTime = 0, ansTime;
    string answer = "";

    // Init
    long playTime = SecondsByTime(play_time);
    long advTime = SecondsByTime(adv_time);
    vector<long> times(playTime + 1, 0);

    // Logs
    for (string &log : logs)
    {
        long start = SecondsByTime(log);
        long end = SecondsByTime(log.substr(9));

        times[start]++;
        times[end]--;
    }

    // Play Count
    for (int i = 1; i < playTime; i++)
        times[i] = times[i] + times[i - 1];

    // Play Length
    for (int i = 1; i < playTime; i++)
        times[i] = times[i] + times[i - 1];

    // Answer
    for (int i = advTime - 1; i < playTime; i++)
    {
        long newTime = times[i] - (i >= advTime ? times[i - advTime] : 0);
        if (newTime > maxTime)
        {
            maxTime = newTime;
            ansTime = i - advTime + 1;
        }
    }

    answer += '0' + ansTime / 36000;
    ansTime %= 36000;
    answer += '0' + ansTime / 3600;
    ansTime %= 3600;
    answer += ':';

    answer += '0' + ansTime / 600;
    ansTime %= 600;
    answer += '0' + ansTime / 60;
    ansTime %= 60;
    answer += ':';

    answer += '0' + ansTime / 10;
    ansTime %= 10;
    answer += '0' + ansTime;

    return answer;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cout << solution("02:03:55", "00:14:15", {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"}) << '\n';
    cout << solution("99:59:59", "25:00:00", {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"}) << '\n';
    cout << solution("50:00:00", "50:00:00", {"15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45"}) << '\n';
    return 0;
}