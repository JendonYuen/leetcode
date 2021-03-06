
// 对10^9 + 7 取模
return fmod(res, 1000000007);
/*
const int kMOD = 1e9 + 7;
res %= kMOD;
*/


// 辗转相除法求最大公因数
int gcd(int a, int b) {
    if (a < b) std::swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

// 随机函数使用时间初始化种子
srand((unsigned)time(NULL));
// 从[l, r]之间随机选择一个
int i = rand % (r - l + 1) + l; 

// 字符串除法, 保留20位小数
string mod(int numerator, int denominator, int n = 20) {
    if (numerator == 0) return "0";
    string res;
    if (numerator > 0 ^ denominator > 0) {
        res.push_back('-');
    }
    if (numerator < 0) numerator = -numerator;
    if (denominator < 0) denominator = -denominator;
    while (numerator >= denominator) {
        int t = numerator / denominator;
        res += to_string(t);
        numerator = numerator % denominator; 
    }
    if (res == "" or res == "-") res.push_back('0');
    if (numerator == 0) return res;
    res.push_back('.');
    for (int i = 0; i < n; ++i) {
        if (numerator == 0) break;
        numerator *= 10;
        res.push_back(numerator / denominator + '0');
        numerator = numerator % denominator;
    }
    return res;
}

// 字符串加法
string addStrings(string num1, string num2) {
    int n = min(num1.size(), num2.size());
    int n1 = num1.size(), n2 = num2.size();
    string res;
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        char cur = num1[n1-1-i] - '0' + num2[n2-1-i] + carry;
        carry = 0;
        if (cur > '9') {
            cur -= 10;
            carry = 1;
        }
        res.push_back(cur);
    }

    if (n1 < n2) {
        num1 = num2;
        n1 = n2;
    }
    for (int i = n1 - n - 1; i >= 0; --i) {
        char cur = num1[i] + carry;
        carry = 0;
        if (cur > '9') {
            cur -= 10;
            carry = 1;
        }
        res.push_back(cur);
    }
    if (carry > 0) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}
// 字符串乘法(需调用字符串加法!!!)
string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        string res = "0";
        res.reserve(220);
        int carry = 0, d = n2 - n1, times = 0;
        for (int j = n2 - 1; j >= 0; --j) {
            string cur;
            for (int i = n1 - 1; i >= 0; --i) {
                int t = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = 0;
                if (t >= 10) {
                    carry = t / 10;
                    t = t % 10;
                }
                cur.push_back(t + '0');
            }
            // 遍历剩余carry
            while (carry > 0) {
                int t = carry % 10;
                cur.push_back(t + '0');
                carry /= 10;
            }
            reverse(cur.begin(), cur.end());
            for (int i = 0; i < times; ++i) cur.push_back('0'); // 补0
            times++;
            res = addStrings(res, cur);      // 与之前结果相加
        }
        return res[0] == '0' ? "0" : res;
    }

// 求过两点的直线
// Ax + By + C = 0
// A = y2 - y1
// B = x1 - x2
// C = x2*y1 - x1*y2
string getLine(vector<int>& p1, vector<int>& p2) {
    long long a, b, c, x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
    a = y2 - y1;
    b = x1 - x2;
    c = x2 * y1 - x1 * y2;
    // 归一化
    // cout << mod((a-c), a) << "     " << mod((b-c), a) << endl;
    if (a == 0 && b == 0) return to_string(p1[0])+","+to_string(p1[1])+"0"; // 两点相等, 返回x,y,0 
    if (a == 0) return{mod((b-c), b)};                                      // 直线水平, 返回b
    return mod((a-c), a)+","+mod((b-c), a);                                 // 返回a,b
    
}


// 求数据流的中位数
class MedianFinder {
    multiset<int> mts;
    multiset<int>::iterator mid;
public:
    void addNum(int num) {
        mts.insert(num);
        if (mts.size() == 1) {
            mid = mts.begin();
        } else if (mts.size() & 1) {
            if (num >= *mid) mid++;
        } else {
            if (num < *mid) mid--;
        }
    }
    
    double findMedian() {
        return mts.size() & 1 ? *mid : (*mid + *next(mid)) * 0.5;
    }
};