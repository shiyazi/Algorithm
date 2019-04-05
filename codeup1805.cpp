#include<cstdio>
#include<cstring>
#include<ctype.h>
#include<iostream>
using namespace std;

int main()
{
	char str1[101];
	while ( fgets(str1, 101, stdin) != NULL ) {

		if ( str1[0] <= 'z' && str1[0] >= 'a' ) {
			str1[0] -= 32;
		}
		for ( int i = 1; i < (signed int )strlen(str1); i++ ) {
			if ( isspace(str1[i]) ) {
				if ( str1[i+1] <= 'z' && str1[i+1] >= 'a' && (i + 1) < (signed int)strlen(str1) ) {
					str1[i+1] -= 32;
				}
			}
		}
		printf("%s", str1);
	}
	return 0;
}
