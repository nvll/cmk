#include <unistd.h>
#include "units.h"

#include <vector>

std::vector<testDesc> tests;

int run_tests(void)
{
    for (auto f : tests) {
        uint32_t local_cnt = 0, local_pass = 0;
        bool asserted = false;
        int fds[2];
        int status;

        if (pipe(fds) < 0)
            exit(1);

        pid_t pid = fork();

        if (pid) {
            close(fds[1]);
            read(fds[0], &local_cnt, sizeof(local_cnt));
            read(fds[0], &local_pass, sizeof(local_cnt));
            read(fds[0], &asserted, sizeof(asserted));

            waitpid(pid, &status, 0);

            if (asserted) {
                printf("%15s results:\t" RED "aborted by assert\n" RESET, f.first.c_str());
            } else {
                printf("%15s results:\t%d/%d passed", f.first.c_str(), local_pass, local_cnt);

                if (local_pass != local_cnt)
                    printf(" %d failed", local_cnt - local_pass);

                putchar('\n');
            }

            close(fds[0]);
        } else {
            close(fds[0]);
            (*f.second)(&local_cnt, &local_pass, &asserted);
            write(fds[1], &local_cnt, sizeof(local_cnt));
            write(fds[1], &local_pass, sizeof(local_pass));
            write(fds[1], &asserted, sizeof(asserted));
            break;

        }
    }

    return 0;
}
