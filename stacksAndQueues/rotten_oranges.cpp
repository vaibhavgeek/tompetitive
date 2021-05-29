#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct  Node
{
	int timeframe;
	int x,y;
};
int main()
{
	int m,n;
	cin>>m>>n;
	int matrix[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];

	deque<Node> de(m*n);
	de.clear();
	int timeframe = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j] == 2)
			{
				Node n;
				n.timeframe = 1;
				n.x = i;
				n.y = j;
				de.push_back(n);
			}
		}
	}
	Node temp;
	temp.timeframe = 1;
	temp.x = -1;
	temp.y = -1;
	de.push_back(temp);

	while(!de.empty()){

		bool flag = false;
		while(de.front().x != -1 && de.front().y != -1)
		{
			temp = de.front();
			if(matrix[temp.x + 1][temp.y] == 1)
			{
				if(flag == false) { timeframe++; flag = true; }

				matrix[temp.x+1][temp.y] = 2;
				temp.x = temp.x + 1;
				de.push_back(temp);
				temp.x = temp.x - 1;
			}
			if(matrix[temp.x - 1][temp.y] == 1)
			{
				if(flag == false) { timeframe++; flag = true; }

				matrix[temp.x+1][temp.y] = 2;
				temp.x = temp.x - 1;
				de.push_back(temp);
				temp.x = temp.x + 1;
			}
			if(matrix[temp.x][temp.y + 1] == 1)
			{
				if(flag == false) { timeframe++; flag = true; }

				matrix[temp.x][temp.y + 1] = 2;
				temp.y = temp.y + 1;
				de.push_back(temp);
				temp.y = temp.y - 1;
			}
			if(matrix[temp.x][temp.y - 1] == 1)
			{
				if(flag == false) { timeframe++; flag = true; }

				matrix[temp.x][temp.y - 1] = 2;
				temp.y = temp.y - 1;
				de.push_back(temp);
				temp.y = temp.y + 1;
			}

			de.pop_front();

		}
		de.pop_front();
		if (!de.empty()) {
            temp.x = -1;
            temp.y = -1;
            de.push_back(temp);
        }

	}
	bool impossible = false;
	for(int i = 0;i<m;i++)
		for(int j=0;j<n;j++)
			if(matrix[i][j] == 1)
				impossible = true;

	if(impossible)
		cout<<"impossible!"<<endl;
	else
		cout<<timeframe<<endl;

}