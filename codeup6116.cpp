/* 题目描述
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
输入
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.
输出
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
样例输入
5 1 2 4 14 9
3
1 3
2 5
4 1
样例输出
3
10
7 */

#include<cstdio>

void swap(int &a, int &b)
{
	if ( a > b) {
		int temp = b;
		b = a;
		a = temp;
	}
}
int lowbit(int x)  //利用树状数组快速求和 
{
	return x&(-x);
}

void change(int x, int p, int n, int t[])
{
	while ( x <= n ) {
		t[x] += p;
		x += lowbit(x);
	}
}

int sum(int k, int t[])
{
	int ans = 0;
	while ( k > 0 ) {
		ans += t[k];
		k -= lowbit(k);
	}
	return ans;
}

int main()
{
	int N,M,sumD;
	while ( scanf("%d", &N) != EOF ) {
		int D[N+1] = {0},t[N+1] = {0};
		sumD = 0;
		for ( int i= 1; i < N+1; i++ ) {
			scanf("%d", &D[i]);
			change(i, D[i], N+1, t);
			sumD += D[i];
		}
		scanf("%d", &M);
		for ( int i = 0; i < M; i++ ) {
			int a, b;
			scanf("%d %d", &a, &b);
			swap(a, b);
			int ans = sum(b-1,t) - sum(a-1, t);
			int _ans = sumD - ans;
			swap(ans, _ans);
			printf("%d\n", ans);
		}
	}
	return 0;
}
