#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int fd;
ssize_t ret;
char buffer[1024];
// Open the file for writing
fd = open("file1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (fd == -1) {
perror("open");
exit(1);
}
// Write data to the file
char *data = "Hello, this is some data!\n";
ret = write(fd, data, strlen(data));
if (ret == -1) {
perror("write");
close(fd);
exit(1);
}
// Close the file
close(fd);
// Open the file for reading
fd = open("file1.txt", O_RDONLY);
if (fd == -1) {
perror("open");
exit(1);
}
// Read data from the file
ret = read(fd, buffer, 1024);
if (ret == -1) {
perror("read");
close(fd);
exit(1);
}
// Null-terminate the buffer to print as string
buffer[ret] = '\0';
// Close the file
close(fd);
// Print the read data
printf("Data read from file: %s\n", buffer);
return 0;
}