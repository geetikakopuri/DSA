class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        vector<vector<int>>vec1;
        while(!mpp.empty())
        {
            vector<int>vec;
            for(auto it=mpp.begin();it!=mpp.end();)
            {
                if(it->second>=1)
                {
                    it->second--;
                    vec.push_back(it->first);
                    if(it->second==0)
                    {
                        it=mpp.erase(it);
                    }
                    else
                    {
                        it++;
                    }
                }
                else
                {
                    ++it;
                }
            }
            vec1.push_back(vec);
        }
        return vec1;
    }
};