#pragma once

// Union-Find example

#include <string>
#include <vector>

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
