#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int d[100][100];
int min(int a, int b) {
	return (a < b) ? a : b;
}
int main() {
	int i, j, str1_len, str2_len, temp, tracker;
	string str1 = "Support";
	string str2 = "Suppose";
	str1_len = str1.length();
	str2_len = str2.length();
	for (i = 0; i <= str1_len; i++)
		d[0][i] = i;
	for (j = 0; j <= str2_len; j++)
		d[j][0] = j;
	for (j = 1; j <= str1_len; j++) {
		for (i = 1; i <= str2_len; i++) {
			if (str1[i - 1] == str2[j - 1]) {
				tracker = 0;
			}
			else {
				tracker = 1;
			}
			temp = min((d[i - 1][j] + 1), (d[i][j - 1] + 1));
			d[i][j] = min(temp, (d[i - 1][j - 1] + tracker));
		}
	}
	cout << "The Levinstein distance " << d[str2_len][str1_len];
	return 0;
}

