//
// Created by stescobedo on 15/7/21.
//

#ifndef LAUNCHER_UTILS_H
#define LAUNCHER_UTILS_H

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "static_names.h"

namespace utils{
    class Auxiliar{
        public:
            Auxiliar(){}

            bool static fileExists( std::string const& name )
            {
                std::ifstream f(name.c_str());
                return f.good();
            }

            constexpr static unsigned int strToint(const char* str, int h = 0)
            {
                return !str[h] ? 5381 : (strToint(str, h+1) * 33) ^ str[h];
            }

            void static writeLauncherFile(std::string fileName,std::string nameApp, std::string iconApp, std::string version,std::string progToExecute){
                std::ofstream launcherFile;

                launcherFile.open(fileName + ".desktop");
                launcherFile<<"[Desktop Entry]"<<std::endl;
                launcherFile<<"Version="<<version<<std::endl;
                launcherFile<<"StartupNotify=true"<<std::endl;
                launcherFile<<"Type=Application"<<std::endl;
                launcherFile<<"Terminal=False"<<std::endl;
                launcherFile<<"Icon[en_US]="<<iconApp<<std::endl;
                launcherFile<<"Name[en_US]="<<nameApp<<std::endl;
                launcherFile<<"Exec="<<progToExecute<<std::endl;
                launcherFile<<"Name="<<nameApp<<std::endl;
                launcherFile<<"Icon="<<iconApp<<std::endl;

                launcherFile.close();
            }
    };
    class SystemConfiguration{
        public:
            void static ConfigureSystem(char *current_dir,std::string fileName,std::string origin,std::string dest,std::string copy_command,std::string chmod_command,std::string chown_command,std::string remove_command){
                origin =  (std::string)current_dir + Slash + fileName;
                dest =  Destination + fileName;
                copy_command = CopyCommand + origin.append(Extension) + " " +dest.append(Extension);
                chmod_command = ChmodCommand + fileName.append(Extension);
                chown_command = ChownCommand + fileName;
                remove_command = RemoveCommand + origin;

                std::system(copy_command.c_str());
                std::system(remove_command.c_str());

                if(Auxiliar::fileExists(dest)){
                    std::system(chmod_command.c_str());
                    std::system(chown_command.c_str());
                }
                else{
                    printf(PermissionMessage);
                    printf("\n");
                }
            }
    };
}

#endif //LAUNCHER_UTILS_H
