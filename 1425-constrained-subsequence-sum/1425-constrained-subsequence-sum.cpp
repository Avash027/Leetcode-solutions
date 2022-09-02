//Time Complexity : O(N) (Because we get maximum element in O(1))
//Spcae complexity: O(N)

class Solution
{
    public:
        int constrainedSubsetSum(vector<int> &nums, int k)
        {
            const int N = nums.size();
            vector<int> dp(N);

            /**
            * dp[i] = Maximum sum of subsequence if we take the element at index i
            */
            
            dp[0] = nums[0];
            
            // dq will always store values in non-increasing (descending order)
            //So dq.front() will have greatest value in the range
            deque<int> dq;
            dq.push_back(dp[0]);
            
            int ans = dp[0];

            for (int i = 1; i < N; i++)
            {
                
                // We want elements in the range [i-k , i], since i-k-1 is out of bounds we remove it
                if (i - k - 1 >= 0 and dq.front() == dp[i-k-1])
                    dq.pop_front();


                // Here if we want to append nums[i] to the previous subsequence we will get sum mx + nums[i]
                // If we want to start a new subsequence from nums[i] we will get nums[i]
                // We take the best of two 
                
                dp[i] = max(dq.front() + nums[i], nums[i]);
                ans = max(ans, dp[i]);
                
                //If dp[i] is greater then dq.back() then the values in dq wont be non-increasing, so we remove them
                while(!dq.empty() and dp[i] > dq.back())
                    dq.pop_back();
                
                dq.push_back(dp[i]);
                
            }

            return ans;
        }
};