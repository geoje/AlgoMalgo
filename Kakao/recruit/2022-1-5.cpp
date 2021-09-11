#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> infos;
vector<vector<int>> childs;
int answer = 0;

pair<int, int> search(int x, int sheep, int wolf)
{
    // 현재 위치 동물 추가
    if (infos[x] == 0)
        sheep++;
    else
        wolf++;

    pair<int, int> result = {sheep, wolf};

    // 늑대가 양을 잡아먹을 경우
    if (wolf >= sheep)
        return result;

    // 자식이 2개일 경우
    if (childs[x].size() == 2)
    {
        // 좌측 후 우측
        auto res = search(childs[x][0], sheep, wolf);
        if (res.first > sheep)
            res = search(childs[x][1], res.first, res.second);
        else
            res = search(childs[x][1], sheep, wolf);
        // 자식 방문 한 것이 양이 더 많을 경우
        if (res.first > result.first)
            result = res;

        // 우측 후 좌측
        res = search(childs[x][1], sheep, wolf);
        if (res.first > sheep)
            res = search(childs[x][0], res.first, res.second);
        else
            res = search(childs[x][0], sheep, wolf);
        // 자식 방문 한 것이 양이 더 많을 경우
        if (res.first > result.first)
            result = res;
    }

    // 자식이 1개일 경우
    if (childs[x].size() == 1)
    {
        auto res = search(childs[x][0], sheep, wolf);

        // 자식 방문 한 것이 양이 더 많을 경우
        if (res.first > result.first)
            result = res;
    }

    return result;
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    infos = info;
    childs.resize(info.size());

    // 엣지 세팅
    for (auto edge : edges)
        childs[edge[0]].push_back(edge[1]);

    return search(0, 0, 0).first;
}

int main()
{
    cout << solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}}) << '\n';
    cout << solution({0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}}) << '\n';
    return 0;
}