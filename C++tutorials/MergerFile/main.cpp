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
#include <string.h>
#include <signal.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fstream>

using namespace std;

void getFiles(std::string path, std::vector<std::string>& files)
{
    std::vector<std::string> ownname;
    char path0[1000];
    char path1[1000];
    char path2[2000];
    struct dirent *dp;
    struct dirent *dp1;
    DIR *dir = opendir(path.c_str());
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            strcpy(path0, path.c_str());
            strcat(path0, "/");
            strcat(path0, dp->d_name);
            DIR *dir1 = opendir(path0);
            if (!dir1)
            return;
            while ((dp1 = readdir(dir1)) != NULL)
            {
                if (strcmp(dp1->d_name, ".") != 0 && strcmp(dp1->d_name, "..") != 0)
                {
                    sprintf(path2,"%s/%s",path0, dp1->d_name); 
                    files.push_back(std::string(path2));
                    ownname.push_back(std::string(dp->d_name));
                    strcpy(path1, path0);
                    strcat(path1, "/");
                    strcat(path1, dp1->d_name);
                }
            }
            closedir(dir1);
        }
    }
    closedir(dir);
}
int main()
{
    string a;
    std::vector<std::string> files;
    std::fstream file;
    std::fstream file1;

    std::string output = "/home/hungndn/C++tutorials/hung.txt";
    
    std::cout << "Nhap vao duong dan can gop file: " <<std::endl;
    cin >> a;
    getFiles(a, files);
    std::cout << "file size :" << files.size() <<std::endl;

    file1.open(output, std::ios::out | std::ios::app);

    for (int i = 0; i < files.size(); i++)
    {
        std::cout<< "path: " << files[i] << std::endl;
        file.open(files[i], std::ios::in);
        while (file) 
        {
            std::string line;
            std::getline(file, line);
            file1 << line << endl;
        }
        file.close();
    }
    file1.close();
    return 0; 
}