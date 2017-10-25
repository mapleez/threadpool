#include <stdio.h>
#include "testmod.h"

void testmod_display_version () {
	puts (VERSION);
}

int testmod_add_int (int a, int b) {
	return a + b;
}
