class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here
        if (u == v) return true;

                int V = adj.size();
                vector<bool> visited(V, false);
                queue<int> q;

                q.push(u);
                visited[u] = true;

                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();

                    for (int neighbor : adj[curr]) {
                        if (neighbor == v) return true;

                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                return false;
            }
        };
    
