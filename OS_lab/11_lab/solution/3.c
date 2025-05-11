#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Please enter the source file name and the destination directory name\n");
    return 0;
  }
  int source_fd = open(argv[1], O_RDONLY);
  if (source_fd == -1)
  {
    printf("Error opening the source file\n");
    return 0;
  }
  int destination_fd = open(argv[2], O_WRONLY | O_CREAT);
  if (destination_fd == -1)
  {
    printf("Error opening the destination file\n");
    return 0;
  }
  char buffer[1024];
  int bytes_read;
  printf("Copying file...\n");
  while ((bytes_read = read(source_fd, buffer, sizeof(buffer))) > 0)
  {
    write(destination_fd, buffer, bytes_read);
  }
  close(source_fd);
  close(destination_fd);
  printf("File copied successfully\n");

  return 0;
}