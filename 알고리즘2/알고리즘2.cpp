#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
#include<stack>
#include<string>
#include<stdio.h>
using namespace std;
int map[16][16] = { 0 }; //1이면 x자리 
int arr[16];
int n;
int i, j;
int blank = 0;
int cnt = 0;
void dfs(int x,int y) {
	if (map[x][y] == 1 || (x==n-1 && y==n-1)) {
		return;
	}
	cnt++;
	for (i = 0; i < n; i++) {
		if (map[i][y] == 0) {
			map[i][y] = 1;
		}
	}
	for (j = 0; j < n; j++) {
		if (map[x][j] == 0) {
			map[x][j] = 1;
		}
	}
	while (x >= 0 && y >= 0 && x < n && y < n) {
		map[x - 1][y - 1] = 1;
		map[x + 1][y + 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				blank++;
			}
		}
	}
	if (blank > 0) {
		if (x >= n - 1) {
			dfs(x + 1, y);
		}
		else{
			dfs(x, y + 1);
			
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; i++) {
			cnt = 1;
			dfs(i, j);
		}
	}
	cout << cnt << endl;
}