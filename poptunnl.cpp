#include<bits/stdc++.h>
using namespace std;

//code from cp algorithms
void dijkstra(int s, vector<int> &d, vector<int> &p, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    d.assign(n, 999999999);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == 999999999)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, i, j, x, y;
		cin >> n >> k;
		string arr[n];
		for(i=0; i<n; i++)
			cin >> arr[i];

		int graph[n][n];
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				graph[i][j] = 0;

		for(i=0; i<n; i++)
		{
			for(j=i-1; j>-1 && j>=i-k; j--)
			{
				if(arr[i][j] == '1')
					graph[i][j] = 1;
			}

			for(j=i+1; j<n && j<=i+k; j++)
			{
				if(arr[i][j] == '1')
					graph[i][j] = 1;
			}
		}

		// for(i=0; i<n; i++)
		// {
		// 	for(j=0; j<n; j++)
		// 		cout << graph[i][j] << " ";
		// 	cout << "\n";
		// }

		vector<vector<pair<int, int>>> adj;

		for(i=0; i<n; i++)
		{
			vector<pair<int, int>> ttempv;
			for(j=0; j<n; j++)
			{
				if(graph[i][j] == 1)
				{
					pair<int, int> temp;
					temp.first = j;
					temp.second = 1;
					ttempv.push_back(temp);
				}
			}
			adj.push_back(ttempv);
		}
		vector<int> d, p;
		dijkstra(0, d, p, adj);

		// for(i=0; i<n; i++)
		// 	cout << d[i] << " ";
		// cout << "\n";
		if(d[n-1] == 999999999)
			cout << "-1\n";
		else
			cout << d[n-1] << "\n";
	}
}