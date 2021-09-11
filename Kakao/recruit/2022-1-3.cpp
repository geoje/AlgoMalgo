#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Input Type: 00:00
int toM(string ts)
{
    return (ts[0] - '0') * 600 + (ts[1] - '0') * 60 + (ts[3] - '0') * 10 + (ts[4] - '0');
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    unordered_map<int, int> parkStart, parkTime;
    map<int, int> parkFees;

    // 입출고 내역 처리
    for (string record : records)
    {
        int t = toM(record.substr(0, 5));
        int car = stoi(record.substr(6, 4));
        bool in = record[11] == 'I';

        // 입차
        if (in)
            parkStart[car] = t;
        // 출차
        else
        {
            parkTime[car] += t - parkStart[car];
            parkStart.erase(car);
        }
    }

    // 입고만 한 차량 처리
    int maxTime = toM("23:59");
    for (auto it = parkStart.begin(); it != parkStart.end(); it++)
        parkTime[it->first] += maxTime - it->second;

    // 주차비 정산
    for (auto it = parkTime.begin(); it != parkTime.end(); it++)
    {
        int parkFee = fees[1];
        if (it->second > fees[0])
            parkFee += ceil((double)(it->second - fees[0]) / fees[2]) * fees[3];

        // 주차비 입력
        parkFees[it->first] += parkFee;
    }

    // 정답 처리
    for (auto it = parkFees.begin(); it != parkFees.end(); it++)
        answer.push_back(it->second);
    return answer;
}

int main()
{
    for (int n : solution({180, 5000, 10, 600}, {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"}))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution({120, 0, 60, 591}, {"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"}))
        cout << n << ' ';
    cout << '\n';

    for (int n : solution({1, 461, 1, 10}, {"00:00 1234 IN"}))
        cout << n << ' ';
    cout << '\n';
}