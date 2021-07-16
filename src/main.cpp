#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include "extra/utils.h"
#include "extra/static_names.h"

using namespace std;
using namespace utils;


int main(int argc, char* argv[]) {
    char *current_dir = get_current_dir_name();

    if(argc < 1){
        printf(ErrorMessage);
        return 1;
    }
    else{
        vector<string> listCommand;
        for (int i = 2; i < argc; ++i) {
            listCommand.push_back((string)argv[i]);
        }

        string fileName = argv[1];
        string nameApp  = "";
        string iconApp  = "";
        string version = "";
        string progToExecute = "";

        if(fileName != ""){
            for (auto node : listCommand){
                string flag = node.substr(0,node.find('='));
                string value = node.substr(node.find('=')+1);            
                
                //[FILE_NAME] [APP_NAME] [ICON_APP] [VERSION] [PROGRAM_TO_EXECUTE]
                switch (Auxiliar::strToint(flag.c_str()))
                {
                    case Auxiliar::strToint("--name"):
                        nameApp = value;
                    break;
                    case Auxiliar::strToint("--icon"):
                        iconApp = value;
                    break;
                    case Auxiliar::strToint("--version"):
                        version = value;
                    break;
                    case Auxiliar::strToint("--exec"):
                        progToExecute = value;
                    break;
                }
            }

            Auxiliar::writeLauncherFile(fileName,(nameApp != "") ? nameApp : "Default",(iconApp != "") ? iconApp : "No icon to show",(version != "") ? version : "1.0",(progToExecute != "") ? progToExecute : "No program to execute");

            string origin;
            string dest;
            string copy_command;
            string chmod_command;
            string chown_command;
            string remove_command;

            SystemConfiguration::ConfigureSystem(current_dir,fileName,origin,dest,copy_command,chmod_command,chown_command,remove_command);
            
            free(current_dir);
        }
        else{
            printf(ErrorMessage);
        }

    }
    return 0;
}
