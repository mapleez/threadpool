#include <stdio.h>
#include "header.h"

/* Check creation. */
int _t_ez_joblist_create1 () {
	pez_joblist list = ez_joblist_create ();
	free (list);
	return 1;
}

/* Main entry */
int main (int argc, char * argv []) {
	if (
			_t_ez_joblist_create1 ()
	) puts ("t_ez_joblist ... ok!");
	else
		exit (1);

	return 0;
}
