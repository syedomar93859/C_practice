/**
 * @file swap_example.c
 *
 * @author meevs
 * @date 2025-09-08
 */

#include <stdio.h>

void swap_by_reference (int *p_x, int *p_y) {
	/* A fancy trick for swapping variables without needing a third variable. */
	*p_x ^= *p_y;
	*p_y ^= *p_x;
	*p_x ^= *p_y;
}

void swap_by_value (int x, int y) {
	swap_by_reference (&x, &y);
}

int main (int arg_c, char **pp_arg_v) {
	int x = 10;
	int y = 15;

	printf ("Init: x = %d, y = %d\n", x, y);
	swap_by_value (x, y);
	printf ("After sbv: x = %d, y = %d\n", x, y);
	swap_by_reference (&x, &y);
	printf ("After sbr: x = %d, y = %d\n", x, y);

	return 0;
}
