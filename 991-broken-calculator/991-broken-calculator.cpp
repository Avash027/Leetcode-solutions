class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(target>startValue)
        {
            count++;
            if(!(target&1))
                target=target/2;
            else
                target+=1;
        }
        count += (startValue-target);
        return count;
        
    }
};