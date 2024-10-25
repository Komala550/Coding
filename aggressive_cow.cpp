 bool isfeasible(int mid,int n, int k, vector<int> &stalls)
    {
        int count=1;
        int last_position = stalls[0];
        for (int i = 1; i < n; ++i)
        {
            if(stalls[i]-last_position>=mid)
            {
                count++;
                last_position=stalls[i];
            }
            if(count==k)return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) 
    {
        sort(stalls.begin(),stalls.end());
        int diff=stalls[n-1]-stalls[0];
        int left=1,right=diff,result=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isfeasible(mid,n,k,stalls))
            {
                left=mid+1;
                result=mid;
            }
            else right=mid-1;
        }
        return result;
    }
