#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void writeLauncherFile(string fileName,string nameApp, string iconApp, string version,string progToExecute){
    ofstream launcherFile;

    launcherFile.open(fileName + ".desktop");
    launcherFile<<"[Desktop Entry]"<<endl;
    launcherFile<<"Version="<<""<<version<<endl;
    launcherFile<<"Type=Application"<<endl;
    launcherFile<<"Terminal=False"<<endl;
    launcherFile<<"Icon[en_US]="<<""<<iconApp<<endl;
    launcherFile<<"Name[en_US]="<<""<<nameApp<<endl;
    launcherFile<<"Exec="<<""<<progToExecute<<endl;
    launcherFile<<"Name="<<""<<nameApp<<endl;
    launcherFile<<"Icon="<<""<<iconApp<<endl;

    launcherFile.close();
}

int main(int argc, char* argv[]) {
    char *current_dir = get_current_dir_name();

    if(argc < 5){
        printf("!!!Error!!! the format is [FILE_NAME] [APP_NAME] [ICON] [VERSION] [PROGRAM_TO_EXECUTE]\n");
        return 1;
    }
    else{
        string fileName = argv[1];
        string nameApp  = argv[2];
        string iconApp  = argv[3];
        string version = argv[4];
        string progToExecute = argv[5];

        if(fileName != "" && nameApp != ""){
            writeLauncherFile(fileName,nameApp,iconApp,version,progToExecute);

            string origin =  (string)current_dir + "/" + fileName;
            string dest =  "/usr/share/applications/" + fileName;
            string copy_command = "sudo cp " + origin.append(".desktop") + " " +dest.append(".desktop");
            string chmod_command = "sudo chmod 644 /usr/share/applications/" + fileName.append(".desktop");
            string chown_command = "sudo chown root:root /usr/share/applications/" + fileName;
            string remove_command = "sudo rm " + origin;

            system(copy_command.c_str());
            system(chmod_command.c_str());
            system(chown_command.c_str());
            system(remove_command.c_str());
            free(current_dir);
        }
        else{
            printf("!!!Error!!! the format is [FILE_NAME] [APP_NAME] [ICON] [VERSION] [PROGRAM_TO_EXECUTE]\n");
        }

    }

    return 0;
}