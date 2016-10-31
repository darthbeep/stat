#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
int main() {
  //Creates a file (or lets you read it if it already exists)
  int fd = open("genericfile", O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    int fd = open("genericfile",  O_RDWR, 0644);
  }
  //Creates the struct stat you get information from and gets the information
  struct stat * stbuf = (struct stat *) malloc(sizeof(struct stat));
  int st = stat("genericfile",  stbuf);
  //Prints out the file size
  printf("File size: %d\n" , stbuf->st_size);
  //Prints out the permissions
  char fullmode[11] = "";
  int m = stbuf->st_mode;
  if (S_ISDIR(stbuf->st_mode)) {
    fullmode[0] = 'd';
  }
  else {
    fullmode[0] = '-';
  }
  if (m & S_IRUSR) {
    fullmode[1] = 'r';
  }
  else {
    fullmode[1] = '-';
  }
  if (m & S_IWUSR) {
    fullmode[2] = 'w';
  }
  else {
    fullmode[2] = '-';
  }
  if (m & S_IXUSR) {
    fullmode[3] = 'x';
  }
  else {
    fullmode[3] = '-';
  }
  if (m & S_IRGRP) {
    fullmode[4] = 'r';
  }
  else {
    fullmode[4] = '-';
  }
  if (m & S_IWGRP) {
    fullmode[5] = 'w';
  }
  else {
    fullmode[5] = '-';
  }
  if (m & S_IXGRP) {
    fullmode[6] = 'x';
  }
  else {
    fullmode[6] = '-';
  }
  if (m & S_IROTH) {
    fullmode[7] = 'r';
  }
  else {
    fullmode[7] = '-';
  }
  if (m & S_IWOTH) {
    fullmode[8] = 'w';
  }
  else {
    fullmode[8] = '-';
  }
  if (m & S_IXOTH) {
    fullmode[9] = 'x';
  }
  else {
    fullmode[9] = '-';
  }
  printf("Permissions (mode): %s\n", fullmode);
  //Prints out the time
  char * ct = ctime(&stbuf->st_atime);
  printf("Time of last access: %s\n", ct);
  close(fd);
  return 0;
}
