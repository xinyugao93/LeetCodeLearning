#pragma once

// Union-Find example

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf(26);
        for(int i = 0; i < s1.size(); ++i) {
            uf.unite(s1[i] - 'a', s2[i] - 'a');
        }

        for(int i = 0; i < baseStr.size(); ++i) {
            baseStr[i] = uf.find(baseStr[i] - 'a') + 'a';
        }
        return baseStr;
    }

private:
    class UnionFind{
    public:
        UnionFind(int n) {
            parent.resize(n);
            for(int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if(parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if(rootX == rootY) {
                return;
            }

            if(rootX > rootY) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
            }
        }
    private:
        std::vector<int> parent;
    };
};