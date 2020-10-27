//grp-8 201914024
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/description/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int cost[n];
        for (int i = 0; i < n; i++)
        {
            cost[i] = -1;
        }
        cost[0] = 0;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({i});
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v[a - 1].push_back(b - 1);
            v[b - 1].push_back(a - 1);
        }
        int from = 0, to = n - 1;
        queue<int> q;
        q.push(from);
        while (!q.empty())
        {
            for (int i = 1; i < v[q.front()].size(); i++)
            {
                if (cost[v[q.front()][i]] == -1)
                {
                    q.push(v[q.front()][i]);
                    cost[v[q.front()][i]] = cost[q.front()] + 1;
                }
            }
            q.pop();
        }
        cout << cost[to] << endl;
    }
    return 0;
}
