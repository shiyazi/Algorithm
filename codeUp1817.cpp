#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char a[20],b[20];
	char s[11];
	while ( scanf("%s", a) != EOF && scanf("%s", b) != EOF ) {
		char *post = NULL;
		while ( (post = strrchr(a,',')) != NULL ) {
			*post = '\0';
			strcpy(s, post+1);
			strcat(a, s);
		}
		while ( (post = strrchr(b,',')) != NULL ) {
			*post = '\0';
			strcpy(s, post+1);
			strcat(b, s);
		} //
		
		int a1,b1;
		sscanf(a, "%d", &a1);
		sscanf(b, "%d", &b1);
		printf("%d\n", a1+b1);
	}
	return 0;
}
		
