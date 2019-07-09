/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
// LD_PRELOAD=./libinjection-so.so ./code-injection or export LD_PRELOAD=./libinjection-so.so

/*
 * File:   main.c
 * Author: root
 *
 * Created on June 21, 2019, 2:50 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 *
 */
int main(int argc, char** argv)
{
    char buffer[1000];
    int amount_read;
    int fd;

    fd = fileno(stdin);
    if ((amount_read = read(fd, buffer, sizeof buffer)) == -1) {
        perror("error reading");
        return EXIT_FAILURE;
    }

    printf("hello__%d\n", amount_read);
    if (fwrite(buffer, sizeof(char), amount_read, stdout) == -1) {
        perror("error writing");
        return EXIT_FAILURE;
    }
    return (EXIT_SUCCESS);
}

