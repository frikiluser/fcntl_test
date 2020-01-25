#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int pipes[2];

    pipe(pipes);

    if (argc>1) {
        fcntl(pipes[1], F_SETFD, FD_CLOEXEC);
    }

    if (!vfork()) {
        execve("./fstat", 0, 0);
    }

    return 0;
}
