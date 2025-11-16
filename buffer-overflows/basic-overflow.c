#include <stdio.h>

int main(void) {
	// 1. Get user name
	char name[10];
	printf("What's your name?\n");
	scanf("%s", name);

	// 2. Get university name
	char university[32];
	printf("Where do you study?\n");
	scanf(" %[^\n]", university);

	// 3. Print output for debug purposes
	printf("You're %s\n", name);
	printf("and you study at %s.\n", university);
}
