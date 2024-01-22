#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("Please provide a file");
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }

        char buffer[4096];
        int bytesRead;
        
        while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {

            for (int i = 0; i < bytesRead; ++i) {
            buffer[i] = toupper(buffer[i]);
        }

            if (write(1, buffer, bytesRead) != bytesRead) {
                perror("Error writing to stdout");
                close(fd);
                return 1;
            }
        }

        if (bytesRead == -1) {
            perror("Error reading from file");
            close(fd);
            return 1;
        }

        close(fd);
    }

    return 0;
}
