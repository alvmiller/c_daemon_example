#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define _BSD_SOURCE
#include <unistd.h>

int main()
{
    const int nochdir = 1;
    const int noclose = 1;
    if(daemon(nochdir, noclose) == -1) {
		int error = errno;
        perror("Daemon Failed");
		if (error == ENOSYS) {
			exit(-1);
		}
		return (-2);
    } else {
        printf("\tDaemon Started...\n");
    }

    sleep(5);
	printf("\tDaemon Finished\n");

    return (0);
}