#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
    int     fd;
    char    *res;

    fd = open("test.txt", O_RDONLY);
    res = malloc(1 * sizeof(char));
    while (res)
    {
        free(res);
        res = get_next_line(fd);
    }   
    (void)ac;
    (void)av;
    return (1);
}