class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //Read the notes to understand the proof :(
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
    }
};