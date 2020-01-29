#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &v1, vector<vector<int>> &v2)
{
	// cout << "LOL" << endl;
	vector<vector<int>> temp;
	vector<int> t1, t2;
	t1.push_back(v1[0][0]*v2[0][0]+v1[0][1]*v2[1][0]);
	t1.push_back(v1[0][0]*v2[0][1]+v1[0][1]*v2[1][1]);

	t2.push_back(v1[1][0]*v2[0][0]+v1[1][1]*v2[1][0]);
	t2.push_back(v1[1][0]*v2[0][1]+v1[1][1]*v2[1][1]);
	temp.push_back(t1);
	temp.push_back(t2);

	// for(int i=0; i<2; i++)
	// {
	// 	for(int j=0; j<2; j++)
	// 		cout << temp[i][j] << " ";
	// 	cout << endl;
	// }

	return temp;
}

vector<vector<int>> power(vector<vector<int>> &v, int n)
{
	// cout << " " << n << endl;
	if(n == 1)
		return v;

	if(n%2 == 0)
	{
		vector<vector<int>> v2 = power(v, n/2);
		return multiply(v2, v2);
	}
	else
	{
		vector<vector<int>> v2 = power(v, n-1);
		return multiply(v, v2);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, i, j, k, x, y;
		cin >> n >> m;
		vector<vector<int>> v;
		vector<int> v1, v2;
		v1.push_back(0);
		v1.push_back(1);
		v2.push_back(m-1);
		v2.push_back(m-1);
		v.push_back(v1);
		v.push_back(v2);

		if(n == 1)
		{
			cout << m << "\n";
			continue;
		}
		if(n == 2)
		{
			cout << m*m << "\n";
			continue;
		}


		vector<vector<int>> xn = power(v, n);
		int ans = xn[0][0]*m + xn[0][1]*m*m;
		cout << ans << "\n";

		for(i=0; i<2; i++)
			for(j=0; j<2; j++)
				cout << xn[i][j] << " ";
		cout << "\n";

	}
}