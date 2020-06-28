// 第195场周赛

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        long long sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
        }
        if (sum % k) return false;
        return true;
    }
};