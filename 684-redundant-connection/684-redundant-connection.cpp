struct DSU {
	int components;
	vector<int> Parent, Rank;

	DSU(int n) : components(n), Parent(n), Rank(n, 1) { iota(Parent.begin(), Parent.end(), 0); }

	int find(int x) {
		while (x != Parent[x]) x = Parent[x] = Parent[Parent[x]];
		return x;
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (Rank[x] > Rank[y]) swap(x, y);
		Parent[x] = y;
		Rank[y] += Rank[x];
		--components;
		return true;
	}
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		DSU dsu(n + 1);
		for (auto &e : edges) {
			if (dsu.merge(e[0], e[1]) == false) {
				return e;
			}
		}
		return {};
	}
};