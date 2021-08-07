// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, inorder[100000], postorder[100000];

void preorder(int ioLeft, int ioRight, int poLeft, int poRight)
{
    // root 출력
    int rootNum = postorder[poRight];
    cout << rootNum << ' ';

    // 자식 노드가 없으면 출력만 하고 끝
    if (poLeft == poRight)
        return;

    // inorder 에서 루트 위치 찾기
    // 하지만 더 좋은 풀이가 있었다.
    // 수는 1부터 10만까지 이므로 배열의 인덱스를 이용해서 inorder 입력받을 때 해당 숫자의 위치를 따로 저장해놓으면 됨
    // 참조: https://www.acmicpc.net/source/31790232
    // 반례: https://bingorithm.tistory.com/5
    int ioRoot = (ioLeft + ioRight) / 2;
    int sr = ioRoot, sl = ioRoot;
    while (true)
    {
        if (inorder[sr] == rootNum)
        {
            ioRoot = sr;
            break;
        }
        if (inorder[sl] == rootNum)
        {
            ioRoot = sl;
            break;
        }

        sr++;
        sl--;
    }

    // 왼쪽 트리와 우측 트리 순서대로 실행
    int leftLength = ioRoot - ioLeft;
    if (leftLength)
        preorder(ioLeft, ioRoot - 1, poLeft, poLeft + leftLength - 1);
    if (ioRight - ioRoot > 0)
        preorder(ioRoot + 1, ioRight, poLeft + leftLength, poRight - 1);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> inorder[i];
    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    // Process & Output
    preorder(0, n - 1, 0, n - 1);
    return 0;
}