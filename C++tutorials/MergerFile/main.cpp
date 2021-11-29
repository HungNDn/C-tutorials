#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <dirent.h>
#include <vector>
#include <cstdlib>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <string>
#include <signal.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fstream>

using namespace std;

void listFilesRecursively(char *basePath, std::vector <std::string>& directories)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        // printf("%s\n", dp->d_name);
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            DIR *dir1 = opendir(path);
            if(!dir1)
            {
                directories.push_back(path);
            }
            else
            {
                listFilesRecursively(path, directories);
            }
            closedir(dir1);
        }
    }
    closedir(dir);
}

int strContains(char* string, char* toFind)
{
    int slen = strlen(string);
    int tFlen = strlen(toFind);
    int found = 0;

    if( slen >= tFlen )
    {
        for(int s=0, t=0; s<slen; s++)
        {
            do{

                if( string[s] == toFind[t] )
                {
                    if( ++found == tFlen ) return 1;
                    s++;
                    t++;
                }
                else { s -= found; found=0; t=0; }

            }while(found);
        }
        return 0;
    }
    else return -1;
}


int main()
{
    std::fstream fileIn;
    std::fstream fileOut;

    char path[100];
    std::vector <std::string> directories;
    
    printf("Enter path to list files: ");
    scanf("%s", path);
    listFilesRecursively(path, directories);

    fileOut.open("/home/hungndn/Videos/C++github/C++tutorials/MergerFile/hung.txt", std::ios::out | std::ios::app);
    for (int i = 0; i < directories.size(); i++)
    {
        if(strContains((char*)directories[i].c_str(),(char*)".cpp") == 1 || strContains((char*)directories[i].c_str(),(char*)".hpp") == 1)
        {
            std::cout << "Path :" <<  directories[i] << std::endl;
            fileIn.open(directories[i], std::ios::in);
            while (fileIn) 
            {
               std::string line;
               std::getline(fileIn, line);
               fileOut << line << endl;
               std::cout << "line :" << line << std::endl;
            }
            fileIn.close();
        }
    }
    fileOut.close();
    return 0;
}
