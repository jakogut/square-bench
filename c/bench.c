#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define COUNT 32000000

double *rand_matrix(const size_t size)
{
	double *mat = calloc(size, sizeof(double));

	for (unsigned i = 0; i < size; i++)
		mat[i] = rand() / (double)RAND_MAX;

	return mat;
}

unsigned timespec_to_nsec(const struct timespec *start,
			  const struct timespec *end)
{
	return (end->tv_nsec - start->tv_nsec) +
	      ((end->tv_sec - start->tv_sec) * 1000000000);
}

double test(double *values)
{
	double sum = 0.0;
	for (int i = 0; i < COUNT; i++) {
		double v = values[i] * values[i];
		sum += v;
	}

	return sum;
}

int main(int argc, char **argv)
{
	struct timespec start, end;
	double *mat, result;

	srand(time(NULL));

	mat = rand_matrix(COUNT);

	clock_gettime(CLOCK_MONOTONIC, &start);
	result = test(mat);
	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("Result: %f\n", result);
	printf("Completed in %f ms\n", timespec_to_nsec(&start, &end) / 1000000.0f);
	return 0;
}
