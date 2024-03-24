#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

const int IOCTL_LYNE_GET_STATUS = _IOR('k', 1, int);

int main(void) {
  int fd, ret;
  fd = open("/dev/lyneguard-control", O_RDWR);

  if (fd < 0) {
    perror("unable to open lyneguard control file! Is LyneGuard running?");
    return 1;
  }

  if (ioctl(fd, IOCTL_LYNE_GET_STATUS, &ret) < 0) {
    perror("unable to get status!");
  }

  printf("ioctl return: %d\n", ret);

  close(fd);
}
