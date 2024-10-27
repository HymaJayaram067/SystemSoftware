/*
============================================================================
Name : 10c.c
Author : Hymavathi Jayaramappa
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call
Date: 13th sept, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void main()
{
    int status;

    printf("ignoring the SIGINT signal for 5 seconds\n");
    struct sigaction act;

    act.sa_handler = SIG_IGN; // Ignoring SIGINT
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }

    printf("reseting the default action of the SIGINT signal\n");
    struct sigaction actdefault;

    actdefault.sa_handler = SIG_DFL; // setting default SIGINT
    actdefault.sa_flags = 0;
    status = sigaction(SIGINT, &actdefault,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        sleep(5);
    }
}

/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 11.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
ignoring the SIGINT signal for 5 seconds
reseting the default action of the SIGINT signal

*/