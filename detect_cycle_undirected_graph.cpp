bool iscyclicutil(int v,vector<bool> &visited,int parent,vector<int> adj[])
    {
        visited[v]=1;
        for(auto node:adj[v])
        {
            if(!visited[node])
            {
                if(iscyclicutil(node,visited,v,adj))return true;
            }
            else if(node!=parent)return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(iscyclicutil(i,visited,-1,adj))return true;
            }
        }
        return false;
    }
