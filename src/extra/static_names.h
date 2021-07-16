//
// Created by stescobedo on 15/7/21.
//

#ifndef LAUNCHER_STATIC_NAMES_H
#define LAUNCHER_STATIC_NAMES_H

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>

#define PermissionMessage "Administrator permissions are required to be able to perform this action."
#define ErrorMessage "!!!Error!!! the format is <FILE_NAME> [--name=APP_NAME] [--icon=ICON] [--version=VERSION] [--exec=PROGRAM_TO_EXECUTE]\n"
#define RemoveCommand "rm "
#define ChownCommand "chown root:root /usr/share/applications/"
#define ChmodCommand "chmod 644 /usr/share/applications/"
#define Destination "/usr/share/applications/"
#define Extension ".desktop"
#define Slash "/"
#define CopyCommand "cp "

#endif //LAUNCHER_STATIC_NAMES_H
