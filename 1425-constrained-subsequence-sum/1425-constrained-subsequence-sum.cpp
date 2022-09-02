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
            // We will use max_prev to store the previous k sum of subsequences
            
            set<pair<int, int>> max_prev;
            
            max_prev.insert({ dp[0], 0 });
            int ans = dp[0];

            for (int i = 1; i < N; i++)
            {
                
                // We want elements in the range [i-k , i], since i-k-1 is out of bounds we remove it
                if (i - k - 1 >= 0)
                    max_prev.erase({ dp[i - k - 1],i - k - 1 });

                
                int mx = max_prev.rbegin()->first; // We find the subsequence with maximum sum

                // Here if we want to append nums[i] to the previous subsequence we will get sum mx + nums[i]
                // If we want to start a new subsequence from nums[i] we will get nums[i]
                // We take the best of two 
                
                dp[i] = max(mx + nums[i], nums[i]);
                ans = max(ans, dp[i]);
                
                //We will use this value in the future
                max_prev.insert({ dp[i],i });
            }

            return ans;
        }
};