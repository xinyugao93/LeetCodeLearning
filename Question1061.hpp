#pragma once

// Union-Find example

#include <string>
#include <vector>

/**给出长度相同的两个字符串s1 和 s2 ，还有一个字符串 baseStr 。

其中  s1[i] 和 s2[i]  是一组等价字符。

举个例子，如果 s1 = "abc" 且 s2 = "cde"，那么就有 'a' == 'c', 'b' == 'd', 'c' == 'e'。
等价字符遵循任何等价关系的一般规则：

 自反性 ：'a' == 'a'
 对称性 ：'a' == 'b' 则必定有 'b' == 'a'
 传递性 ：'a' == 'b' 且 'b' == 'c' 就表明 'a' == 'c'
例如， s1 = "abc" 和 s2 = "cde" 的等价信息和之前的例子一样，那么 baseStr = "eed" , "acd" 或 "aab"，这三个字符串都是等价的，而 "aab" 是 baseStr 的按字典序最小的等价字符串

利用 s1 和 s2 的等价信息，找出并返回 baseStr 的按字典序排列最小的等价字符串。
 */
namespace q1061 {


class Solution1061 {
public:
    std::string smallestEquivalentString(std::string s1, std::string s2, std::string baseStr) {
        UnionFind uf(26);
        for(std::size_t i = 0; i < s1.size(); ++i) {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }

        for(std::size_t i = 0; i < baseStr.size(); ++i) {
            baseStr[i] = static_cast<char>(uf.findMin(baseStr[i] - 'a') + 'a');
        }
        return baseStr;
    }

private:
    class UnionFind {
    public:
        explicit UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            minVal.resize(n);
            for(int i = 0; i < n; ++i) {
                parent[i] = i;
                minVal[i] = i;
            }
        }

        int find(int x) {
            if(parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        int findMin(int x) {
            int root = find(x);
            return minVal[root];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) {
                return;
            }

            if(rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                minVal[rootY] = std::min(minVal[rootX], minVal[rootY]);
            } else if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                minVal[rootX] = std::min(minVal[rootX], minVal[rootY]);
            } else {
                parent[rootY] = rootX;
                ++rank[rootX];
                minVal[rootX] = std::min(minVal[rootX], minVal[rootY]);
            }
        }

    private:
        std::vector<int> parent;
        std::vector<int> rank;
        std::vector<int> minVal;
    };
};

} // namespace q1061
