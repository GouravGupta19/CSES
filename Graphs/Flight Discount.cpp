#include <bits/stdc++.h>
using namespace std;

#define hurry_up ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define int long long
#define pi pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pi>
#define INF 1e18

vi dijkstra(int st, vector<vpi> &adj, int n) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vi dist(n, INF);
    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        auto t = pq.top();
        int dis=t.first, node= t.second;
        pq.pop();
        
        if (dist[node] < dis) continue;  
        
        for (auto &it: adj[node]) {
            int neigh= it.first, wt= it.second;
            if (dist[neigh] > dis + wt) {
                dist[neigh] = dis + wt;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    return dist;
}

int solve() {
    int n, m;
    cin >> n >> m;

    vector<vpi> adj(n), radj(n);
    vvi edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;  // Convert to 0-based index

        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
        edges.push_back({u, v, w});
    }

    vi dist1 = dijkstra(0, adj, n);
    vi dist2 = dijkstra(n - 1, radj, n);

    int ans = INF;
    for (auto &it : edges) {
        int u = it[0], v = it[1], w = it[2];
        if (dist1[u] == INF || dist2[v] == INF) continue;  
        ans = min(ans, dist1[u] + (w / 2) + dist2[v]);
    }

    return ans;
}

int32_t main() {
    hurry_up
    cout << solve() << endl;
    return 0;
}
