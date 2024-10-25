bool iscyclicutil(int v,vector<bool> &visited,vector<bool> &recstack,vector<int> adj[])
    {
        visited[v]=1;
        recstack[v]=1;
        for(auto node:adj[v])
        {
            if(!visited[node])
            {
                if(iscyclicutil(node,visited,recstack,adj))return true;
            }
            else if(recstack[node])return true;
        }
        recstack[v] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V,0);
        vector<bool> recstack(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(iscyclicutil(i,visited,recstack,adj))return true;
            }
        }
        return false;
    }
