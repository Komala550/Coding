bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=0;
            }
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                for(auto u:graph[x])
                {
                    if(color[u]==-1)
                    {
                        color[u]=1-color[x];
                        q.push(u);
                    }
                    else if(color[u]==color[x])return false;
                }
            }
        }
        return true;
    }
