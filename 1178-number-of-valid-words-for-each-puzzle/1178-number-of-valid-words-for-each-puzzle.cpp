class Solution {
public:
    
    int makeMask(string s)
    {
        int mask = 0;
        
        for(const char&c:s)
            mask|=(1<<(c-'a'));
        
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        //This maps the mask of the string -> frequency of the mask
        unordered_map<int,int> ump;
        
        vector<int> result;
        
        for(const string&s:words)
            ump[makeMask(s)]++;
        
        for(const string&s:puzzles){
            int firstLetter = 1<<(s[0]-'a'); // This is the first condition
            string temp = s.substr(1);
            
            int mask = makeMask(temp);
            //This is to handle the edge case
            int curAns = ump[firstLetter];
            
            //We are generating all the submask of the puzzle
            //A word is valid if mask (word) = submask(puzzle[i]) 
            //And word[0] = puzzle[0]
            //We find all valid word
            for(int submask = mask;submask>0;submask=(submask-1)&mask)
                curAns+= ump[firstLetter | submask];
            
            result.push_back(curAns);
            
        }
        
        return result;
    }
};