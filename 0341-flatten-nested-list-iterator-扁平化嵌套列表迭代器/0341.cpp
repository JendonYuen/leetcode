/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    int _i = 0;
    vector<int> res;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto &a: nestedList) {
            if (a.isInteger()) {
                res.emplace_back(a.getInteger());
            } else {
                NestedIterator it(a.getList());
                while (it.hasNext()) res.emplace_back(it.next());
            }
        }
    }
    
    int next() {
        return res[_i++];
    }
    
    bool hasNext() {
        return _i < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */