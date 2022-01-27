struct Node
{
	Node* links[2];

	inline bool containsKey(const int& num)
	{
		return links[num] != NULL;
	}

	inline Node* get(const int& num)
	{
		return links[num];
	}

	inline void put(const int&num , Node* node)
	{
		links[num] = node;
	}
};


struct Trie
{
private:
	Node* root;


public:

	Trie()
	{

		root =  new Node();
	}


	void insert(int  num)
	{
		Node* node = root;
		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if (!node->containsKey(bit)) node->put(bit , new Node());

			node = node->get(bit);
		}
	}
    
    int query(int num)
	{
		Node* node = root;
		int ans = 0;

		for (int i = 31; i >= 0; i--)
		{
			int bit = (num >> i) & 1;
			if(node->containsKey(bit^1))
				ans|=(1<<i) , node = node->get(bit^1);
			else if(node->containsKey(bit))
				node =  node->get(bit);
			else return ans;
		}

		return ans;
	}
    

};


class Solution {
private:
    Trie trie;
public:
    int findMaximumXOR(vector<int>& nums) {
        
        for(int e:nums) trie.insert(e);
        
        int ans = 0;
        
        for(int e:nums) ans = max(ans , trie.query(e));
        
        return ans;
        
    }
};