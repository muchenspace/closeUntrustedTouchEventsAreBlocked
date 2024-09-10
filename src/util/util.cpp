#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "util.h"

std::string util::getSoPath(std::string moduleName,int pid)
{
    std::string sPid{};
    if (pid != 0)
    {
        sPid = std::to_string(pid);
    }
    else
    {
        sPid = "self";
    }
    std::string mapsPath = "/proc/" + sPid + "/maps";
    std::ifstream maps(mapsPath);
    if (!maps.is_open())
    {
        std::cerr << "not found " << mapsPath << std::endl;
        return "";
    }
    std::string line{};
    while(std::getline(maps, line))
    {
        if (line.find(moduleName) != std::string::npos)
        {
            std::string token{};
            std::istringstream tokenStream(line);
            while (std::getline(tokenStream, token, ' '))
            {
                if (token.find("/") != std::string::npos)
                {
                    return token;
                }
            }

        }
    }
    return "";
}