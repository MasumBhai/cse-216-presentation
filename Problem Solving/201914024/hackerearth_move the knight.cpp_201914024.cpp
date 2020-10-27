//grp-8 201914024
//https://www.hackerearth.com/problem/algorithm/move-the-knight/
//Sir The results are the same but differ in order
#include <bits/stdc++.h>
using namespace std;
bool IsMoveValid(int x, int y)
{
	if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
	{
		return true;
	}
	return false;
}
int main()
{
	int DirectionX[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
	int DirectionY[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c;
		vector<int> X;
		vector<int> Y;
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			if (IsMoveValid(r + DirectionX[i], c + DirectionY[i]))
			{
				count++;
				X.push_back(r + DirectionX[i]);
				Y.push_back(c + DirectionY[i]);
			}
		}
		cout << count << endl;
		for (int i = 0; i < count; i++)
		{
			cout << X[i] << " " << Y[i];
			if (i != count - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}