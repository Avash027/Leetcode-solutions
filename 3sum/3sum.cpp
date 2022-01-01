class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
             
        int n = nums.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        
        
        sort(nums.begin() , nums.end());
        
        for(int i = 0;i<n;i++)
        {
            int target = -nums[i];
            int front = i+1;
            int back = n-1;
            
            while(front<back)
            {
                int sum = nums[front] + nums[back];
            
                if(sum<target) front++;
                else if(sum>target) back--;
                
                else
                {
                    vector<int> tempAns{nums[i] , nums[front] , nums[back]};
                    ans.push_back(tempAns);
                    while(front<back and nums[front] == tempAns[1]) front++;//remove duplicates from start
                    while(back>front and tempAns[2] == nums[back]) back--;
                }
                
                while(i+1<n and nums[i] == nums[i+1]) i++;//remove duplicates
            }
        }
        return ans;
    }
};