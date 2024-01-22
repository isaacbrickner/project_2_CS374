#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
   
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
    perror("open");
    }

    char buf[158];  // Buffer to hold the data
    int count;
    count = read(fd, buf, sizeof buf);
    write(1, buf, sizeof buf);
    close(fd);
    return 0;
}