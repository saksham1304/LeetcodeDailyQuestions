class Solution {
public:
    void create(int n,int target,int i,vector<int>&temp,vector<vector<int>> &ans)
    {
        if(i<0)return;
        if(temp.size()==n)
        {
            if(target==0)
            ans.push_back(temp);
            return;
        }
        
        create(n,target,i-1,temp,ans);
        temp.push_back(i);
        // target-i means that we added that number to our list
        // so now we need the remaining target to get a sum of 0
        create(n,target-i,i-1,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
        create(k,n,9,temp,ans);
        return ans;
    }
};
