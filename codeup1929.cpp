#include<cstdio>
#include<cstring>

int main()
{
	int day, year,k;
	char name[10];
	struct name2Num {
		int Num;
		char Name[10];
	} month[12] = { { 1, "January"},
					{ 2, "February"},
					{ 3, "March"},
					{ 4, "April"},
					{ 5, "May"},
					{ 6, "June"},
					{ 7, "July"},
					{ 8, "August"},
					{ 9, "September"},
					{ 10, "October"},
					{ 11, "November"},
					{ 12, "December"} };
	name2Num week[7] = {	{ 0, "Sunday"},
							{ 1, "Monday"},
							{ 2, "Tuesday"},
							{ 3, "Wednesday"},
							{ 4, "Thursday"},
							{ 5, "Friday"},
							{ 6, "Saturday"} };
	while ( scanf("%d %s %d", &day, &name, &year) != EOF ) {
		for ( int i = 0; i < 12; i++  ) {
			if ( strcmp(name, month[i].Name) == 0 ) {
				k = month[i].Num;
				break;
			}
		}
		if ( k <= 2 ) {
			k += 12;
			year--;
		}
		int w = ( day + 2 * k + 3 * ( k + 1 ) / 5 + year + \
			year / 4 - year / 100 + year / 400 + 1 ) % 7;
		printf("%s\n", week[w].Name);
	}
	return 0;
}
