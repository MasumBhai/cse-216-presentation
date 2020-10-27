//grp-8 201914024
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/big-p-and-party-1/submissions/?fbclid=IwAR0Er7VSzntkkdM918epkH88sbzlYzXAMUssKFnaFIj7nMuB8taOTsSlhgI
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
        int n,m;
        cin>>n>>m;
        int cost[n];
        for(int i=0;i<n;i++){
            cost[i]=-1;
        }
        cost[0]=0;
        vector<int> v[n];
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int from=0,to=n-1;
        queue<int>q;
        q.push(from);
        while(!q.empty()){
            for(int i=0;i<v[q.front()].size();i++){
                if(cost[v[q.front()][i]]==-1){
                    q.push(v[q.front()][i]);
                    cost[v[q.front()][i]]=cost[q.front()]+1;
                }
            }
            q.pop();
        }
        for(int i=1;i<n;i++){
			cout<<cost[i]<<endl;
		}
    return 0;
}