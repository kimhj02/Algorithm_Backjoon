#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
public:
    UnionFind(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 1; i <= size; i++) {
            parent[i] = i;
        }
    }

    int find(int n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    void merge(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);

        if (root1 != root2) {
            if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    UnionFind uf(n);

    for (int i = 0; i < n - 2; i++) {
        int u, v;
        cin >> u >> v;
        uf.merge(u, v);
    }

    int root1 = -1, root2 = -1;
    for (int i = 1; i <= n; i++) {
        int root = uf.find(i);
        if (root1 == -1) {
            root1 = root;
        } else if (root1 != root) {
            root2 = root;
            break;
        }
    }

    cout << root1 << " " << root2 << endl;

    return 0;
}