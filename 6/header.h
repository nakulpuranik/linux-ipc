#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define FIFO_PATH "/tmp/fifo"
#define MAX_BUF 1024

void validateNumberOfArguement(const int *input);