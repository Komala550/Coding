/*
|-------------------|
|Endoscopy samsung  |
|-------------------|
Problem Statement:

You are given a grid of pipes and a starting point. Each pipe in the grid can have different configurations that define the directions in which fluid can flow through it. You need to determine how many cells in the grid can be reached from the starting cell within a given number of steps, based on the connectivity of the pipes.

Grid Configuration:

The grid is represented as a matrix where each cell contains a number indicating the pipe's configuration.
The configurations are defined as follows:
1: The pipe allows movement in all four directions (left, right, up, down).
2: The pipe allows movement up and down but not left or right.
3: The pipe allows movement left and right but not up or down.
4: The pipe allows movement left and up but not right or down.
5: The pipe allows movement right and down but not left or up.
6: The pipe allows movement left and down but not right or up.
7: The pipe allows movement right and up but not left or down.
0: The cell is blocked and not traversable.
Input:

The first line contains an integer T, the number of test cases.
For each test case:
The first line contains four integers: n, m, sX, sY, and len:
n (1 ≤ n ≤ 1000): Number of rows in the grid.
m (1 ≤ m ≤ 1000): Number of columns in the grid.
sX (0 ≤ sX < n): Starting row index.
sY (0 ≤ sY < m): Starting column index.
len (1 ≤ len ≤ 1000): Maximum number of steps that can be taken.
The next n lines contain m integers each, representing the grid configuration as described above.
Output:

For each test case, output a single integer: the number of distinct cells that can be reached from the starting cell within len steps.
Example:
Input:
1
3 3 1 1 2
1 2 3
4 5 6
7 0 1
Output:
5

code:
---------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,sx,sy,len;
struct Node
{
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
};
struct pipe{
    int x,y,dist;
};
int dx[4]={-1,1,0,0};//left,right,up,down
int dy[4]={0,0,1,-1};
bool isvalid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m;
}
int res=1;
int solve(vector<vector<bool>> &vis,vector<vector<int>> &dis,vector<vector<Node>> pipes)
{
    vis[sx][sy]=true;
    queue<pipe> q;
    q.push({sx,sy,1});
    while(!q.empty())
    {
        struct pipe p=q.front();
        int x=p.x,y=p.y,d=p.dist;
        q.pop();
        if(d>=len)continue;
        for(int i=0;i<4;i++)
        {
            int newr=x+dx[i],newc = y+dy[i],newd = d+1;
            if(isvalid(newr,newc)&&!vis[newr][newc])
            {
                if(i==0&&pipes[x][y].left&&pipes[newr][newc].right)
                {
                    vis[newr][newc]=true;res++;q.push({newr,newc,newd});
                }
                if(i==1&&pipes[x][y].right&&pipes[newr][newc].left)
                {
                    vis[newr][newc]=true;res++;q.push({newr,newc,newd});
                }
                if(i==2&&pipes[x][y].up&&pipes[newr][newc].down)
                {
                    vis[newr][newc]=true;res++;q.push({newr,newc,newd});
                }
                if(i==3&&pipes[x][y].down&&pipes[newr][newc].up)
                {
                    vis[newr][newc]=true;res++;q.push({newr,newc,newd});
                }
                
            }
        }
    }
    return res;
    
    
}
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        int ans=0;
        cin>>n>>m>>sx>>sy>>len;
        //vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<vector<Node>> pipes(n,vector<Node>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int p;
                cin>>p;
                switch(p)
                {
                    case 1:
                        pipes[i][j] = {true, true, true, true};
                        break;
                    case 2:
                        pipes[i][j] = {false, false, true, true};
                        break;
                    case 3:
                        pipes[i][j] = {true, true, false, false};
                        break;
                    case 4:
                        pipes[i][j] = {false, true, true, false};
                        break;
                    case 5:
                        pipes[i][j] = {false, true, false, true};
                        break;
                    case 6:
                        pipes[i][j] = {true, false, false, true};
                        break;
                    case 7:
                        pipes[i][j] = {true, false, true, false};
                        break;
                    default:
                        pipes[i][j] = {false, false, false, false};
                        break;
                    
                }
            }
        }
        ans=solve(vis,dis,pipes);
        for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cout<<vis[i][j]<<" ";
	        }cout<<"\n";
	    }
	    
        cout<< ans;
    }
    return 0;
}
