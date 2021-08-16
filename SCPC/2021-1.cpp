/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer, n, d[100000];

int Calc()
{
    int ans = 0;
    bool group[n] = {0};

    for (int i = 0; i < n; i++)
    {
        // 이미 그룹이 있을 경우 패스
        if (group[i])
            continue;

        // 새로운 그룹를 만들고
        ans++;
        group[i] = true;

        for (int j = i + d[i]; j < n; j += d[j])
        {
            // 만약 다음 사람이 그룹이 있을 경우 그룹 병합하고 연쇄 초대 종료
            if (group[j])
            {
                ans--;
                break;
            }

            // 다음 사람이 그룹이 없을 경우 내 그룹에 초대
            group[j] = true;
        }
    }

    return ans;
}

int main(int argc, char **argv)
{
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

    //freopen("input.txt", "r", stdin);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {

        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////

        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> d[i];
        Answer = Calc();

        /////////////////////////////////////////////////////////////////////////////////////////////

        // Print the answer to standard output(screen).
        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0; //Your program should return 0 on normal termination.
}