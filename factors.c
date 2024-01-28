#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *stream = fopen(argv[1], "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, stream) != -1) {
		long long number = atoll(line);
		if (number < 2) {
			printf("%lld is not factorizable\n", number);
		} else {
			printf("Prime factorization of %lld: ", number);
			for (long long div = 2; div <= number; ++div) {
				while (number % div == 0) {
					printf("%lld", div);
					number /= div;
					if (number > 1) {
						printf("*");
					}
				}
			}
			printf("\n");
		}
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
