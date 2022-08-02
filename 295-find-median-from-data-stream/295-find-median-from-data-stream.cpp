#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using oset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//1. order_of_key(k) : number of elements lesser than k
//2. find_by_order(k) : k-th element in the set


class MedianFinder {
public:

    oset<pair<int,int>> st;
    int cnt = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert({num,cnt++});
    }
    
    double findMedian() {
        double ans = st.find_by_order(st.size()/2)->first;
        
        if(st.size()%2 ==0 )
            ans += st.find_by_order((st.size()/2)-1)->first,ans/=2;
        
        return ans;
    
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */