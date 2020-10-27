//201914019
//https://codeforces.com/problemset/problem/939/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int data[5010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i + 1]);
    bool notGet = false;
    for (int i = 1; i < n + 1; i++)
    {
        if (i == data[data[data[i]]])
        {
            printf("YES");
            notGet = true;
            break;
        }
    }
    if (notGet == false)
        printf("NO");

    return 0;
}
