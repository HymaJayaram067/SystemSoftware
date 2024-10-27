/*
============================================================================
Name :20a.c
Author : Hymavathi Jayaramappa
Description : Write two programs so that both can communicate by FIFO -Use one way communication
Date: 13th sept, 2024.
============================================================================
*/



#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); // File descriptor of the FIFO file

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
    }
}

/*

output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 20b.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
hello hyma
how are you doing


*/