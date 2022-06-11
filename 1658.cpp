class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size(),ans=INT_MAX;
        
        vector<int> prefix(n);
        
        prefix[0]=nums[0];
        
        if(prefix[0]==x)
        ans=1;
        
        for(int i=1;i<n;++i){
            
        prefix[i]=prefix[i-1]+nums[i];
            
        if(prefix[i]==x)
        ans=min(ans,i+1);
            
        }
        
        for(int i=n-1;i>=1;--i)
        {
            if(prefix[n-1]-prefix[i-1]==x)
            ans=min(ans,n-i);
        }
        
        if(prefix[n-1]==x)
        return n;
        
        for(int i=n-1;i>=1;--i)
        {
            int p=x-(prefix[n-1]-prefix[i-1]);
            
          
            if(p)
            {
                int it=lower_bound(prefix.begin(),prefix.begin()+i-1,p)-prefix.begin();
                
                 // cout<<i<<" "<<p<<" "<<it<<endl;
                
                if(prefix[it]==p)
                {
                    ans=min(ans,it+1+n-(i));
                }
            }
        }
        
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
        
    }
};