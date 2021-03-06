class Solution {
    // 从左下角向右上角搜索矩阵
    // 统计所有小于等于mid的元素个数
    bool check(vector<vector<int>>& matrix, int k, int mid) {
        int x = 0;
        int y = matrix.size() - 1;
        int num = 0;
        while(x < matrix.size() && y >= 0) {
            if (matrix[y][x] <= mid) {
                num += y + 1;
                x++;
            } else {
                y--;
            }
        }
        return num >= k;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int beg = matrix[0][0];
        int end = matrix[matrix.size()-1][matrix[0].size()-1];
        while(beg < end) {
            int mid = beg + ((end - beg) >> 1);
            if (check(matrix, k, mid)) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        return beg;
    }
};

/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> vIndex(rows, 0);
        std::vector<int> vSort;
        // init
        vSort.push_back(matrix[0][0]);
        vIndex[0] = 1;
        if (k == 1) {
            return matrix[0][0];
        } else if (k == cols * rows) {
            return matrix[rows-1][cols-1];
        }
        // run
        int x = 0, y = 0;
        while (vSort.size() < k) {
            int xmin = cols-1, ymin = rows - 1, minValue = matrix[rows-1][cols-1];
            for (int yi = rows - 1; yi >= 0; yi--) {
                int xi = vIndex[yi];
                if (xi >= cols) continue;
                if (matrix[yi][xi] < minValue) {
                    minValue = matrix[yi][xi];
                    xmin = xi;
                    ymin = yi;
                } 
            }   
            vSort.push_back(matrix[ymin][xmin]);
            if (vSort.size() == k) {
                return vSort.back();
            }
            x = xmin;
            y = ymin;
            vIndex[ymin] = xmin + 1;
        }
        return 0;
    }
};
*/