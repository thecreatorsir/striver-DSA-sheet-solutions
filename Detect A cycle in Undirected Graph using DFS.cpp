isCyclicUtil(int v,
				bool visited[], int parent)
{
	visited[v] = true;
	for (auto x:adj[v])
	{
		if (!visited[x])
		{
		if (isCyclicUtil(x, visited, v))
			return true;
		}
		else if (x != parent)
		return true;
	}
	return false;
}