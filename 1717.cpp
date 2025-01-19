#include <iostream>
#include <vector>
using namespace std;

class divset {
public:
    vector<int> parent;
    vector<int> rank;

    divset(int size) {
        parent.resize(size + 1);
        rank.resize(size + 1, 0);
        for (int i = 0; i <= size; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }

    void checkunion(int nodeA, int nodeB) {
        int a = find(nodeA);
        int b = find(nodeB);

        if (a != b) {
            if (rank[a] > rank[b]) {
                parent[b] = a;
            } else if (rank[a] < rank[b]) {
                parent[a] = b;
            } else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    divset uf(n);

    for (int i = 0; i < m; i++) {
        int cul, num1, num2;
        cin >> cul >> num1 >> num2;

        if (cul == 0) {
            uf.checkunion(num1, num2);
        } else if (cul == 1) {
            if (uf.find(num1) == uf.find(num2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
