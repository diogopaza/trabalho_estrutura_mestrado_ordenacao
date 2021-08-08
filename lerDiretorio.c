#include <stdio.h>
#include <time.h>
#include <math.h>
#include <dirent.h>


int main(void)
{

    DIR *dir;
    struct dirent *lsdir;

    dir = opendir("c:\\Users\\HP\\Documents\\mestrado_estrutura_de_dados\\trabalho_estrutura_mestrado_ordenacao\\aleatorios\\");

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        printf ("%s\n", lsdir->d_name);
    }

    closedir(dir);

    return 0;

}