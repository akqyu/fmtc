#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE	500
#define PRINTI	printf("%c", letters[i])

int main (int argc, char **argv) {

	char letters[SIZE]={'\0'};
	char *k;
	int i, j, linw;
	int m = 0;
	int cnt = 0;

	if (!(argc > 1 && (linw = abs(atoi(argv[1])))))
		linw = 90;	/* set default line width */

	while (fgets(letters, SIZE, stdin)) {
		for (i = 0; i < SIZE; i++) {
			if (letters[i] == 27) {
				if (!(k = strchr(letters + i, 'm'))) {
					m = 1;
					for (; letters[i] != '\0'; i++) PRINTI;
					break;
				} else {
					j = k + 1 - letters;
					for (; i < j; i++) PRINTI;
				}
			}
			if (m && (k = strchr(letters + i, 'm'))) {
				j = k + 1 - letters;
				for (; i < j; i++) PRINTI;
				m = 0;
			}
			if (letters[i] == '\0')
				break;
			cnt++;
			if (cnt >= linw && letters[i] == ' ' || letters[i] == '\n') {
				printf("\n");
				cnt = 0;
				continue;
			}
			PRINTI;
		}
	}
}
