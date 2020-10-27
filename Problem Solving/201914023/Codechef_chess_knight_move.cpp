/// Name : Syed Taha Yeasin Ramadan
/// ID : 201914023
/// Codechef Username : tahayeasin
/// Problem Link : https://www.codechef.com/problems/PRGCUP01


#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int destx,desty;
int visited[10][10];
int dist[10][10];
int pathx[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int pathy[] = { 1, 2, 2, 1,-1,-2,-2,-1};

bool isValidMove(int x,int y){
    if(x<1 || x>8 || y<1 || y>8) return false;
    if(visited[x][y]==1) return false;

    return true;
}

int BFS(int x , int y){
    queue<pair<int,int>> que;

    dist[x][y] = 0;
    visited[x][y] = 1;
    que.push({x,y});
    if(x==destx && y == desty) return dist[x][y];

    while(!que.empty()){
        int curx = que.front().first;
        int cury = que.front().second;
        que.pop();
        for(int i=0;i<8;i++){
            if(isValidMove(curx +pathx[i],cury+pathy[i])){
                x = curx + pathx[i];
                y = cury + pathy[i];
                dist[x][y] = dist[curx][cury] +1;
                visited[x][y]=1;
                que.push({x,y});
                if(x==destx && y==desty) return dist[x][y];
            }
        }
    }
}

int main(){

    int q;
    cin>>q;
    while(q--){
        string in;
        cin>>in;
        int srcx = in[0] - 'a' +1;
        int srcy = in[1] -'0';
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                visited[i][j]=0;
            }

        }
        cin>>in;
        destx = in[0]-'a'+1;
        desty = in[1]-'0';

        cout<<BFS(srcx,srcy)<<"\n";
    }

}
