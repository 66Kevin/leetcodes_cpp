class Solution {
public:
    int nthUglyNumber(int n) {
        // 优先队列（小顶堆 -> 升序排列）
        priority_queue<long, vector<long>, greater<long>> q;
        vector<int> primeFactors = {2, 3, 5};
        unordered_set<long> s;
        s.insert(1L);
        q.push(1L);
        long ans = 0;
        for(int i = 0; i < n; i++){
            long cur = q.top();
            ans = cur;
            q.pop();
            for(int t : primeFactors){
                long next = t * cur;
                // 不重复
                if(!s.count(next)){ 
                    s.insert(next);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
