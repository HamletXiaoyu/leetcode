// utl_dp.cpp --- 
// Filename: utl_dp.cpp
// Created: Wed Oct 24 22:53:13 2018 (+0800)
// 
// 
// Copyright Hamlet zheng.
// 
// 允许免费使用，拷贝，修改，发布，但在所有的拷贝上必须保留上述
// copyright部分和本使用声明部分，除非显示声明，copyright的持有者
// 不得作为再发布软件的广告。copyright的持有者对使用本软件的适用范围不做任何声明，
// 
// THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
// INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
// EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
// DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
// TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
// 
// 

#include "utl_dp.h"
#include <string>
#include <vector>

using namespace std;

int rob(int* num, int n)
{
    if (n <= 1)
        return n == 0 ? 0 : num[0];
    int *dp = (int*)malloc(sizeof(int) * n);
    int ret, i;
    dp[0] = num[0];
    dp[1] = num[0] > num[1] ? num[0] : num[1];

    for (i = 2; i < n; ++i)
        dp[i] = (num[i] + dp[i - 2]) > dp[i - 1] ? num[i] + dp[i - 2] : dp[i - 1];

    ret = dp[n - 1];
    free(dp);

    return ret;
}

int unique_paths(int m, int n)
{
    int *dp = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i)
        dp[i] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] += dp[j - 1]; 
        }
    }
    int ret = dp[n - 1];
    free (dp);
    return ret;
}

int num_decodings(string s)
{
    if (s.empty() || (s.size() > 1 && s[0] == '0')) 
        return 0;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i) {
        dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }
    return dp.back();
}

int find_max_form(vector<string>& strs, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (string str : strs) {
        int zeros = 0, ones = 0;
        for (char c : str) (c == '0') ? ++zeros : ++ones;
        for (int i = m; i >= zeros; --i) {
            for (int j = n; j >= ones; --j) {
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }
    return dp[m][n];
}
