#include <stdio.h>
#include <string.h>

int main(void) {
	char correct_pass[] = "topsecret";
	char input[10];

	do {
		printf("Enter the correct password.\n");
		scanf("%s", input);
	}
	while (strcmp(input, correct_pass) != 0);

	printf("Logged in.");
}
