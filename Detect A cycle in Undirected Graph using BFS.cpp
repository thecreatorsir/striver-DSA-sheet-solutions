bool isCyclicConntected(vector<int> adj[], int s,
						int V, vector<bool>& visited)
{
	queue<pair<int,int>> q;
	visited[s] = true;
	q.push({s,-1});

	while (!q.empty()) {
		int node = q.front().first;
        int par = q.front().second;
		q.pop();
		for (auto v : adj[node]) {
			if (!visited[v]) {
				visited[v] = true;
				q.push({v,node});
			}
			else if (par!=v)
				return true;
		}
	}
	return false;
}