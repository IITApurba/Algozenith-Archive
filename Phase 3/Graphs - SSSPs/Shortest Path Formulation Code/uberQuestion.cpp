#include<bits/stdc++.h>
using namespace std;
#define mp make_pair 
#define f first
#define s second
using ii = pair<int, int>;


vector<vector<pair<int, ii>>> g;


using state = pair<int, int>;
int n, m, k; 


int dist [1001][1001];
int vis [1001][1001];
int c[1001];


// by default priority queue is a max heap. (Top index has the max valued element)
// pirority queue ke liye comparator function ke jagah prioritize class likhte hai


void dijkstra (state st) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dist[i][j] = 1e9;
            vis[i][j] = 0;
        }
    }
    priority_queue<pair<int, state>> pq; // distance, [state -> node, petrol] (sorted by -ve dist, for min value on top)


    dist[st.f][st.s] = 0;
    pq.push(mp(-0, st));


    while (!pq.empty()) {
        auto val = pq.top(); pq.pop();
        int cur_dist = -val.f; // distance
        state cur_state = val.s; // val.s => [f -> curr_node, s -> remaining_petrol]


        // check visited
        if (vis[cur_state.f][cur_state.s] == 1) continue;
        vis[cur_state.f][cur_state.s] = 1;
        // -- very crucial


        // try and go to neighbour
        for (auto v : g[cur_state.f]) {


            // pre-condition []
            if (cur_state.s >= v.s.f) {


                // relaxation dijkstra
                if (dist[v.f][cur_state.s - v.s.f] > cur_dist + (0)) {
                    dist[v.f][cur_state.s - v.s.f] = cur_dist + (0);
                    pq.push(mp (-dist[v.f][cur_state.s - v.s.f], mp (v.f, cur_state.s - v.s.f)));
                }
            }
        }


        // refill


        // pre-condition
        if (cur_state.s < k) {
            // relaxation dijkstra
            if (dist[cur_state.f][cur_state.s + 1] > cur_dist + c[cur_state.f]) {
                dist[cur_state.f][cur_state.s + 1] = cur_dist + c[cur_state.f];
                pq.push(mp (-dist[cur_state.f][cur_state.s + 1], mp (cur_state.f, cur_state.s + 1)));
            }
        }         
    }
}


void solve() {
    cin >> n >> m >> k;
    g.resize(n+1);


    int st_node = 1, en_node = n;


    for (int i = 1; i <= n; i++) cin >> c[i];


    for (int i = 0;i < m; i++){
        int p, d, a, b;
        cin >> a >> b >> p >> d;
        g[a].push_back(mp(b, mp(p,d))); // a -> b [petrol kharch, distance]
        g[b].push_back(mp(a, mp(p,d))); // b -> a [petrol kharch, distance]
    }
    
    state st = {st_node, 0}; // [curr node, current petrol amount]
    dijkstra(st);


    cout << dist[en_node][0]; 
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
    
return 0;
}
