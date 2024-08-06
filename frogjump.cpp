/*
https://www.careercup.com/question?id=14989765
http://ideone.com/oXdBaF

Given a 2 D matrix where 1 represent the places where the frog can jump and 0 represent the empty spaces,
the frog can move freely in horizontal direction (on 1’s only) without incurring any cost (jump). 
A vertical jump from a given point of the matrix to other point on the matrix can be taken (on 1’s only) 
with cost as the number of jumps taken.
Given a source and destination, the frog has to reach the destination minimizing the cost (jump).
*/

#include <iostream>
#include <vector>
#include<queue>
#include <climits> // For INT_MAX
using namespace std;
int dx[4]={-1,1,0,0};//l,r,u,d
int dy[4]={0,0,-1,1};
int n,sx,sy,tx,ty;
int isvalid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<n;
}
int main()
{
    cin>>n>>sx>>sy>>tx>>ty;
    vector<vector<int>> mat(n,vector<int> (n,0));
    vector<vector<bool>> vis(n,vector<bool> (n,false));
    vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=0;
    dis[sx][sy]=0;
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        int x=top.first,y=top.second,d=dis[x][y];
        if(x==tx&&y==ty){cout<<d;return 0;}
        for(int i=0;i<4;i++)
        {
            int newx = x+dx[i],newy = y+dy[i];
            if(isvalid(newx,newy)&&!vis[newx][newy]&&mat[newx][newy])
            {
                vis[newx][newy]=true;
                if(i==0||i==1)
                {
                    if(d<dis[newx][newy])
                    {
                        dis[newx][newy]=d;
                        q.push({newx,newy});
                    }
                }
                else
                {
                    if(d+1<dis[newx][newy])
                    {
                        dis[newx][newy]=d+1;
                        q.push({newx,newy});
                    }
                }
            }
        }
    }
    int res= dis[tx][ty]==INT_MAX?-1:dis[tx][ty];
    cout<<res;
    return 0;
}
