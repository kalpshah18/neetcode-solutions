class DSU {
    std::vector<int> parent;
    std::vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        // Initially, every element is its own parent
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Find with Path Compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union by Size
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j])
                std::swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    bool is_connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> res;
        DSU dsu = DSU(n + 1);
        for(auto& edge: edges){
            if(dsu.is_connected(edge[0], edge[1])) res = edge;
            dsu.unite(edge[0], edge[1]);
        }
        return res;
    }
};
