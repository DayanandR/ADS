#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
	vector<int> parent;
	public:
	int count;
	DisjointSet(int n){
		for(int i=0; i<n; i++){
			parent.push_back(i);
		}
		count = 0;
	}
	int find(int x){
		if(parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}
	void add(int x, int y){
		int rootx = find(x);
		int rooty = find(y);
		if(rootx != rooty){
			parent[rootx] = rooty;
			count--;
		}

	}
	void setCount(int n){
		count = n;
	}

};

int numIslands(vector<vector<int>> mat)
{
	int count = 0;
	int m = mat.size();
	int n = mat[0].size();
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j])
				count++;
		}
	}
	DisjointSet *ds = new DisjointSet(m*n);
	ds->setCount(count);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[i][j]){
				if(i>0 && mat[i-1][j]){
					ds->add(n*i+j, n*(i-1)+j);
				}
				if(i<m-1 && mat[i+1][j]){
					ds->add(n*i+j, n*(i+1)+j);
				}
				if(j>0 && mat[i][j-1]){
					ds->add(n*i+j, n*i+j-1);
				}
				if(j<n-1 && mat[i][j+1]){
					ds->add(n*i+j, n*i+j+1);
				}
				if(i>0 && j>0 && mat[i-1][j-1]){
					ds->add(n*i+j, n*(i-1)+j-1);
				}
				if(i<m-1 && j<n-1 && mat[i+1][j+1]){
					ds->add(n*i+j, n*(i+1)+j+1);
				}
				if(i>0 && j<n-1 && mat[i-1][j+1]){
					ds->add(n*i+j, n*(i-1)+j+1);
				}
				if(i<m-1 && j>0 && mat[i+1][j-1]){
					ds->add(n*i+j, n*(i+1)+j-1);
				}
			}

		}
	}
	return ds->count;
}

int main(){
	vector<vector<int>>mat;
	int m,n,val;
	cout<<"Enter the no. of rows: ";
	cin>>m;
	cout<<"Enter the no. of columns: ";
	cin>>n;
	cout<<"Enter the boolean matrix"<<endl;
	for(int i=0;i<m; i++){
		vector<int> row;
		for(int j=0; j<n; j++){
			cin>>val;
			row.push_back(val);
		}
		mat.push_back(row);
	}

	cout<<"Number of Islands: "<< numIslands(mat)<<endl;
	return 0;

}