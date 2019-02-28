  # 题目
  ## [链接](https://leetcode.com/problems/super-egg-drop/discuss/158974/C%2B%2BJavaPython-2D-and-1D-DP-O(KlogN))
  ## 思路
  ```c++
  int superEggDrop(int K, int N) {
        vector<int> dp(K + 1, 0);
        int m;
        for (m = 0; dp[K] < N; m++)
            for (int k = K; k > 0; --k)
                dp[k] += dp[k - 1] + 1;
        return m;
    }
    ```