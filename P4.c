Writer Process
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
int fd;
char buf[1024]="Hello BIT";
char * myfifo = "/ise/Desktop/tmp";
mkfifo(myfifo, 0666);
printf("Run Reader process to read the FIFO File\n");
fd = open(myfifo, O_WRONLY);
write(fd,buf,sizeof(buf));
close(fd);
unlink(myfifo); /* remove the FIFO */
return 0;
}
Reader Process
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define MAX_BUF 1024
int main()
{
int fd;
char *myfifo = "/ise /Desktop/tmp";
char buf[MAX_BUF];
fd = open(myfifo, O_RDONLY);
read(fd, buf, MAX_BUF);
printf("Reader process has read : %s\n", buf);
close(fd);
return 0;
}


#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo = "/tmp/myfifo";  // FIFO path
    mkfifo(fifo, 0666);          // Create FIFO with read-write permissions

    int fd = open(fifo, O_WRONLY);  // Open FIFO for writing
    write(fd, "Hello BIT", 10);     // Write message to FIFO
    close(fd);                      // Close the FIFO

    unlink(fifo);  // Remove FIFO after use
    return 0;
}


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[1024];
    int fd = open("/tmp/myfifo", O_RDONLY);  // Open FIFO for reading
    read(fd, buf, sizeof(buf));              // Read message from FIFO
    printf("Reader read: %s\n", buf);        // Print the message
    close(fd);                               // Close the FIFO
    return 0;
}
