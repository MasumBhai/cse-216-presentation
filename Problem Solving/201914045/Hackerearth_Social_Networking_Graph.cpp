//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
//Solver - Md. Samir Hasan
//ID: 201914045
#include<iostream>
#include<queue>
using namespace std;

int n,e;
int adj[100][100];
int mark[100];
int dis[100];

int printDis(int dista){
    int cou=0;
for(int i=1;i<=n;i++){
    if(dis[i]==dista)
        cou++;
}
return cou;
}

void initDis(){
 for(int i=1;i<=n;i++){
    dis[i]=0;
}
}

void initMark(){
for(int i=1;i<=n;i++){
    mark[i]=0;
}
}

void initAdj(){
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        adj[i][j]=0;
    }
  }
}

void bfs(int start){
    initMark();
    initDis();
    queue <int> q;
    q.push(start);
    mark[start]=1;
    while(q.size()!=0){
        int king=q.front();

        q.pop();

        for(int i=1;i<=n;i++){
         if(adj[king][i]==1){
            int child=i;
            if(mark[child]==0){
                q.push(child);
                dis[child]=dis[king]+1;
                mark[child]=1;
            }
         }
        }
    }
}

int main(){
    cin>>n>>e;
    initAdj();
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y]=1;
        adj[y][x]=1;
    }
    int start;
    int num;
    int dista;
    cin>>num;
    int d[100];
    for(int i=0;i<num;i++){
    cin>>start>>dista;

    bfs(start);
    d[i]=printDis(dista);
    }
    for(int i=0;i<num;i++)
        cout<<d[i]<<endl;
    return 0;
}



