//shivi..coding is adictive!!
#include<shiviheaders.h>
using namespace std;

struct  Node
{
	int x;
	int y;
};

bool isSafe(int x,int y,int visited[5][4],int matrix[5][4])
{
	if(x>=0 && y>=0 && x<5 && y<4 && visited[x][y]==0 && matrix[x][y]==1)
	return 1;
	else
	return 0;
}

bool Compare(Node a,Node b)
{
	if(a.x==b.x && a.y==b.y)
	return 1;
	else
	return 0;
}

int RatTour()
{
	int matrix[][4]=
	{
		{1, 0, 0, 0},
          {1, 0, 0, 0},
          {1, 1, 1, 1},
          {1, 0, 0, 1},
          {1, 0, 0, 1}
	};
	
	int visited[5][4];
	for(int i=0;i<5;++i)
		for(int j=0;j<4;++j)
			visited[i][j]=0;
	visited[0][0]=1;
	Node root,level,k;
	root.x=0;root.y=0;
	level.x=-1;level.y=-1;
	queue<Node> st;
	st.push(root);
	st.push(level);
	int distace =1;
	while(!st.empty())
	{
		Node temp=st.front();
		st.pop();
		if(Compare(temp,level))
		{
			if(st.empty()) break;
			++distace;
			st.push(level);
			continue;
		}
		visited[temp.x][temp.y]=1;
		if(isSafe(temp.x+1,temp.y,visited,matrix))
		{
			k.x=temp.x+1;
			k.y=temp.y;
			cout<<k.x<<" "<<k.y<<" "<<distace<<endl;
			if(visited[k.x][k.y]==0)
			st.push(k);
		}
		if(isSafe(temp.x,temp.y+1,visited,matrix))
		{
			k.x=temp.x;
			k.y=temp.y+1;
			cout<<k.x<<" "<<k.y<<" "<<distace<<endl;
			if(visited[k.x][k.y]==0)
			st.push(k);
		}
	}
	return distace;
}
int main()
{
	cout<<RatTour()	;
}
