/*
auther : Abdullah Al Masum
MIST_roll : 201914044
problem Link : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/oliver-and-the-battle-1/submissions/
*/
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int n,m;
int mat[MAX][MAX];
int visited[MAX][MAX];

int bfs(int x, int y) {
    visited[x][y] = 1;
    int countt = 1;
    queue<pair<int,int> > Queue;
    Queue.push(make_pair(x,y));
    while(!Queue.empty()) {
        x = Queue.front().first;
        y = Queue.front().second;
        Queue.pop();

        for(int i = -1 ; i<=1; i++ ) {
            for(int j = -1; j<=1; j++) {
                if(!visited[x+i][y+j] && mat[x+i][y+j]) {
                    countt++;
                    Queue.push(make_pair(x+i,y+j));
                    visited[x+i][y+j] = 1;
                }
            }
        }
    }
    return countt;
}
int main() {
    int test;
    cin>>test;
    while(test--) {
        cin>>n>>m;
        memset(mat,0,sizeof(mat));
        memset(visited,0,sizeof(visited));
        for(int i = 1; i<=n ; i++) {
            for(int j = 1; j<= m; j++) {
                int res;
                cin>>res;
                mat[i][j] = res;
            }
        }
        int maxZomniKill = 0;
        int zomnitroops = 0;
        for(int i = 1; i <= n ; i++)
            for(int j = 1; j<= m; j++) {
                if(!visited[i][j] && mat[i][j]) {
                    maxZomniKill = max( bfs(i,j), maxZomniKill  );
                    zomnitroops++;
                }
            }
        cout<<zomnitroops<<" "<<maxZomniKill<<endl;
    }
    return 0;
}

