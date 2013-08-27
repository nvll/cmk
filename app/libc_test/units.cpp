#include <unistd.h>
#include "units.h"

#include <vector>

std::vector<testDesc> tests;

int main (int argc, char *argv[])
{
    for (auto f : tests) {
        uint32_t local_cnt = 0, local_pass = 0;
        int fds[2];

        if (pipe(fds) < 0)
            exit(1);

        pid_t pid = fork();

        if (pid) {
            close(fds[1]);
            read(fds[0], &local_cnt, sizeof(local_cnt));
            read(fds[0], &local_pass, sizeof(local_cnt));
            printf("%10s results:\t%d/%d passed\n", f.first.c_str(), local_pass, local_cnt);
            close(fds[0]);
        } else {
            close(fds[0]);
            (*f.second)(&local_cnt, &local_pass);
            write(fds[1], &local_cnt, sizeof(local_cnt));
            write(fds[1], &local_pass, sizeof(local_pass));
            break;
        }
    }

    return 0;
}
