/*
============================================================================
Name : 10b.c
Author : Hymavathi Jayaramappa
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 12th sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("Caught SIGINT\n");
}
void main()
{
    int status;
    struct sigaction act;

    act.sa_handler = print; // function that replace default action of signal SIGSEGV
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act, NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT);
    }
}
/*
output:
hyma@hyma-Latitude-7390:~/Handson2$ cc 10b.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
Caught SIGINT

*/