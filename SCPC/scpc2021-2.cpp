/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
// #include <cstdio>

using namespace std;

int n, t;

// A
// '0', '1': 확실히 고정된 값
// '2': 결정 못함
char A[50001], B[50001];

// A 위치 기준으로 계산해서 연쇄적으로 계산해나감
int BackwardInput(int idx)
{
    int next = idx - t * 2;
    if (next < 1)
    {
        A[idx] = '0';
        return '1';
    }
    else
    {
        A[idx] = BackwardInput(next);
        return A[idx] == '0' ? '1' : '0';
    }
}
// 순차적으로 계속 넣음
void ForwardInput(int idx)
{
    for (; idx >= 1 && A[idx] == '2'; idx -= t * 2)
        A[idx] = A[idx + t * 2] == '0' ? '1' : '0';
}

void Calc()
{
    // 확실한 양 끝 결정
    for (int i = 1; i <= t; i++)
        A[i + t] = B[i];
    for (int i = n; i > n - t; i--)
        A[i - t] = B[i];

    // 두 점으로 결정된 B 서칭 시작
    for (int i = t + 1, end = n - t; i <= end; i++)
    {
        // 내가 0일 경우 좌, 우측 모두 0 넣기
        if (B[i] == '0')
        {
            if (!A[i - t])
                A[i - t] = '0';
            // 좌측 A가 2일 경우 연쇄로 계산하기
            else if (A[i - t] == '2')
                ForwardInput(i - t);

            //우측에 0 넣기
            A[i + t] = '0';
        }
        // 내가 1일 경우
        else
        {
            // 양쪽 다 작성이 되어 있을 경우
            if (A[i - t] && A[i + t])
            {
                // 좌측이 2이고
                if (A[i - t] == '2')
                {
                    // 우측이 0이면 좌측은 무조건 1 로 되고 연쇄 작용
                    if (A[i + t] == '0')
                        ForwardInput(i - t);
                    else if (A[i + t] == '1')
                        BackwardInput(i - t);
                }
            }
            // 작성 여부가 좌X 우O 일 경우
            else if (!A[i - t] && A[i + t])
            {
                // 우측이 0이면 좌측은 무조건 1
                if (A[i + t] == '0')
                    A[i - t] = '1';
                // 우측이 1이면 좌측은 무조건 0
                else
                    A[i - t] = '0';
            }
            // 작성 여부가 좌O 우X 일 경우
            else if (A[i - t] && !A[i + t])
            {
                // 좌측이 0이면 우측은 무조건 1
                if (A[i - t] == '0')
                    A[i + t] = '1';
                // 좌측이 1이면 우측은 무조건 0
                else if (A[i - t] == '1')
                    A[i + t] = '0';
                else if (A[i - t] == '2')
                    A[i + t] = '2';
            }
            // 둘 다 없으면 양쪽 다 2 넣기
            else
            {
                A[i - t] = '2';
                A[i + t] = '2';
            }
        }
    }

    // A 마지막 부분 처리
    for (int i = n - t + 1; i <= n; i++)
        if (A[i] == '2')
            BackwardInput(i);
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, test_case;
    /*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

    // freopen("scpc2021-2.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        /////////////////////////////////////////////////////////////////////////////////////////////

        cin >> n >> t;
        for (int i = 1; i <= n; i++)
            cin >> B[i];
        fill_n(A, n + 1, 0);
        Calc();

        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        for (int i = 1; i <= n; i++)
            cout << A[i];
        cout << '\n';
    }

    return 0; //Your program should return 0 on normal termination.
}