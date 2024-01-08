#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int test00(void);

int test01(void);

int test02(void);

int main(){
	int (*tests[50])() = {test00, test01, test02};
	char* status[4] = { "KO!", "OK!", "Nothing turned in", "Required file not found"};
	char dir[5] = "ex0?";

	for (int i = 0; i < 3; i++) {
		dir[3] = i + 48;
		if (chdir(dir) == -1) {
			printf("ex0%i: %s\n", i, status[2]);
			continue;
		}
		printf("ex0%i: %s\n", i, status[tests[i]()]);
		chdir("..");
	}
}
