class Solution {
public:
bool DFS(vector<int>& arr, int start,vector<bool>&visited)
{
	if (start < 0 || start >= arr.size() || visited[start])
		return false;
	if (arr[start] == 0)
		return true;
	visited[start] = true;
	return DFS(arr, start-arr[start],visited) || DFS(arr, start + arr[start],visited);
}
bool canReach(vector<int>& arr, int start) {
	vector<bool>visited(arr.size(), false);
	return DFS(arr, start,visited);
}

};
