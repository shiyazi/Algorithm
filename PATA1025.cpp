#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[15];
	int score;	//分数 
	int locationNum;	//考场号 
	int localRank;	//考场排名 
}stu[30010];

bool cmp(Student a, Student b)
{
	if ( a.score != b.score ) {
		return a.score > b.score;
	} else {
		return strcmp(a.id,b.id) < 0;
	}
}
int main()
{
	int n,k,num = 0;
	scanf("%d", &n);	//读入考场数
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &k);	//读入考生人数 
		for ( int j = 0; j < k; j++ ) {
			scanf("%s %d", stu[num].id,&stu[num].score);
			stu[num].locationNum = i + 1;
			num++;
		}
		sort(stu + num - k,stu + num,cmp);
		stu[num - k].localRank = 1;
		for ( int j = 1; j < k; j++ ) {	//比较成绩给出考场内排名 
			if ( stu[num - k + j].score < stu[num - k + j - 1].score ) {
				stu[num - k + j].localRank = j + 1;
			} else {
				stu[num - k + j].localRank = stu[num - k + j - 1].localRank;
			}
		}
	}
	//printf("%d", num-1);
	sort(stu,stu + num,cmp);
	printf("%d\n",num);
	int r = 1;
	for ( int i = 0; i < num; i++ ) {
		if ( i > 0 && stu[i].score != stu[i-1].score ) {
			r = i + 1 ;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].locationNum, stu[i].localRank);
	}
	return 0;
}

