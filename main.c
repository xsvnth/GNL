#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

intmain(int argc, char **argv)
{
intfd;
char*line;

fd = 0;
if (argc > 1)
fd = open(argv[1], O_RDONLY);
line = get_next_line(fd);
while (line)
{
printf("%s", line);
free(line);
line = get_next_line(fd);
}
if (fd > 2)
close(fd);
return (0);
}
