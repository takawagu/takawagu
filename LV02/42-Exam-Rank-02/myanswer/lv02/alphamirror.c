#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i])
        {
            char c = av[1][i];
            if ('a' <= c && c <= 'z')
                c = 'a' + ('z' - c);
            else if ('A' <= c && c <= 'Z')
                c = 'A' + ('Z' - c);
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

