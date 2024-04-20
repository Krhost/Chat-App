#include "../include/inc.h"

void sigint_handler()
{
    printf("Killing process %d\n", getpid());
    exit(0);
}