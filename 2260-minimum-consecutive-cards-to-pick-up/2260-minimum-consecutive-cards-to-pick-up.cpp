constexpr int INF = 1e7;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> last_index;
        int ans = INF;
        const int N = cards.size();
        
        
        for(int i = 0;i<N;i++){
            if(last_index.find(cards[i]) != last_index.end())
                ans = min(ans ,i - last_index[cards[i]]+1);
            
            last_index[cards[i]] = i;
        }
        
        return ans ==INF ? -1:ans;
        
    }
};