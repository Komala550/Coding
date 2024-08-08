/*
https://blog.csdn.net/lihenair/article/details/17227667
http://www.mamicode.com/info-detail-995985.html
https://www.oipapio.com/cn/article-8650635
https://blog.csdn.net/broadCE/article/details/47959227
--------------------------------------------------------
There is a maze that has one entrance and one exit. Jewels are placed in passages of the maze. 
You want to pick up the jewels after getting into the maze through the entrance and before getting 
out of it through the exit. You want to get as many jewels as possible, but you don’t want to take 
the same passage you used once.

When locations of a maze and jewels are given, find out the greatest number of jewels you can get 
without taking the same passage twice, and the path taken in this case.

Input
There can be more than one test case in the input file. The first line has T, the number of test cases.
Then the totally T test cases are provided in the following lines (T ≤ 10 ).

In each test case, In the first line, the size of the maze N (1 ≤ N ≤ 10) is given. 
The maze is N×N square-shaped. From the second line through N lines, information of the maze is given.
“0” means a passage, “1” means a wall, and “2” means a location of a jewel. The entrance is located 
on the upper-most left passage and the exit is located on the lower-most right passage. 
There is no case where the path from the entrance to the exit doesn’t exist.

Output
From the first line through N lines, mark the path with 3 and output it. In N+1 line, output the 
greatest number of jewels that can be picked up. Each test case must be output separately as a empty.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n,ans=0;
vector<vector<int>> bestpath;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void printMatrix(vector<vector<int>> path)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<path[i][j]<<" ";
        cout<<"\n";
    }
}
bool isvalid(int i,int j)
{
    return i<n&&i>=0&&j>=0&&j<n;
}
void solve(int i,int j,vector<vector<int>> &maze,vector<vector<int>> &path,int currans)
{
    if(i==n-1&&j==n-1)
    {
        if(currans>ans)
        {
            path[i][j]=3;
            ans=currans;
            bestpath=path;
        }
    }
    for(int k=0;k<4;k++)
    {
        int newi=dx[k]+i,newj=dy[k]+j;
        if(isvalid(newi,newj)&&(maze[newi][newj]==0||maze[newi][newj]==2)&&path[newi][newj]!=3)
        {
            path[i][j]=3;
            solve(newi,newj,maze,path,currans+maze[newi][newj]);
            path[i][j]=0;
        }
    }
}
int main()
{
    int t;cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        vector<vector<int>> maze(n,vector<int> (n,0));
        vector<vector<int>> path(n,vector<int> (n,0));
        bestpath=vector<vector<int>>(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>maze[i][j];
            }
        }
        ans=0;
        path[0][0]=3;
        solve(0,0,maze,path,maze[0][0]);
        printMatrix(bestpath);
        cout<<"\n"<<ans<<"\n";
    }
    return 0;
}
