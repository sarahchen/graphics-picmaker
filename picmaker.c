#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

	int r, g, b, x, y, fd;
	char info[256];

	fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

	char *header = "P3, 500, 500, 255";
	sprintf(info, header);
  write(fd, info, sizeof(info));

	x = 0;
	y = 0;
	r = 1;
	g = 2;
	b = 3;

	for(x = 0; x < 500; x++) {
		for(y = 0; y < 500; y++) {

			r = (g + b) % 255;
			g = (b + r) % 255;
			b = (r + g) % 255;
      sprintf(info, "%d %d %d", r, g, b);
      write(fd, info, sizeof(info));

			r++;
			g++;
			b++;
		}
	}

	close(fd);

	return 0;
}
