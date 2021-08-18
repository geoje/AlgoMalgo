#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct row
{
    int prev, next;
};

string solution(int n, int k, vector<string> cmds)
{
    string answer = "";

    // Linked List 테이블 생성
    vector<row> table;
    for (int i = 0; i < n; i++)
    {
        table.push_back({i - 1, i + 1});
        answer.push_back('O');
    }
    table[n - 1].next = -1;

    // 삭제한 행을 담아둘 Stack
    vector<int> trash;

    // 명령어 실행
    for (string cmd : cmds)
        if (cmd[0] == 'U' || cmd[0] == 'D')
        {
            // 2째 인자를 정수로 바꾼 뒤 이동 명령 실행
            int count = stoi(cmd.substr(2));
            if (cmd[0] == 'U')
                while (count--)
                    k = table[k].prev;
            else
                while (count--)
                    k = table[k].next;
        }
        else if (cmd[0] == 'C')
        {
            // 쓰레기통에 넣고
            trash.push_back(k);

            // 이전과 다음 테이블을 서로 연결
            int prev = table[k].prev;
            int next = table[k].next;
            if (prev != -1)
                table[prev].next = next;
            if (next != -1)
                table[next].prev = prev;

            // 커서 위치 이동
            k = next == -1 ? prev : next;
        }
        else if (cmd[0] == 'Z')
        {
            // 쓰레기통에서 꺼낸 후
            int recover = trash.back();
            trash.pop_back();

            // 이전과 다음 테이블을 서로 연결
            int prev = table[recover].prev;
            int next = table[recover].next;
            if (prev != -1)
                table[prev].next = recover;
            if (next != -1)
                table[next].prev = recover;
        }

    // 쓰레기통 전부 꺼내서 정답에 반영
    for (int t : trash)
        answer[t] = 'X';

    return answer;
}

int main()
{
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"}) << '\n';
    cout << solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"}) << '\n';
    return 0;
}