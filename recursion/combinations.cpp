

/*
   Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    
    void combinations(vector<vector<int>>&res,vector<int> &local,int n,int k,int start)
    {
         if(k==0)
         {
             res.push_back(local);
         }
        
        
        for(int i=start;i<=n;i++)
        {
            local.push_back(i);
            combinations(res,local,n,k-1,i+1);
            local.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> local;
        combinations(res,local,n,k,1);
        return res;
    }
    
};