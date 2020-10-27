/*
auther : Abdullah Al Masum   MIST_roll : 201914044
problem Link : https://www.hackerearth.com/problem/algorithm/move-the-knight/

It gives me wrong answer but i couldn't find the expected output
*/
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y)
{
    if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
    {
        return true;
    }
    return false;
}
int main(){
	int Dx[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
    int Dy[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
	int t;
	cin>>t;
	while(t--){
		int row,col;
		cin>>row>>col;
		vector<int> X,Y;
		int step=0;
		for(int i=0;i<8;i++){
			if(isSafe(row+Dx[i],col+Dy[i])){
				step++;
				X.push_back(row + Dx[i]);
				Y.push_back(col + Dy[i]);
			}
		}
		cout<<step<<endl;
		for(int i=0;i<step;i++){
			cout<<X[i]<<" "<<Y[i];
			if(i!=step-1){
				 cout<<" ";
			}
		}
		cout<<endl;
	}
}
