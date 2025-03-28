#include <stdio.h>
#include <dlfcn.h>
#include <pthread.h>
#include <link.h>
#include <stdlib.h>

#include "ghost.h"

void *thread(void *_)
{
	(void)_;

	void *handle = dlmopen(LM_ID_NEWLM, "./ghost.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "dlmopen: %s\n", dlerror());
		return NULL;
	}

	void *sym = dlsym(handle, "increment");
	typeof(increment) * increment = (typeof(increment)) (uintptr_t) sym;

	if (!increment) {
		fprintf(stderr, "dlsym: %s\n", dlerror());
		return NULL;
	}

	increment();

	dlclose(handle);

	return NULL;
}

int main(void)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, thread, NULL);
	pthread_create(&t2, NULL, thread, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
