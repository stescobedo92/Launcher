# Launcher

Launcher is an application to help those GNU/Linux users to create their launchers more easily.

Surely it has happened to you many times that after installing a program you have not had access to it from the launcher and to run it you have had to use the terminal, this on many occasions is usually annoying and uncomfortable.

## Build project
```
The first step is to install the g ++ compiler

~$ sudo apt-get install g++

then we execute the command

~$ cmake CMakeLists.txt

and finally we execute make

~$ make

Another possibility is that you download the last version of launcher package in the package folder and install it using the command

~ $ sudo dpkg -i launcher_1.0.2-1_amd64.deb

executing this command will install the application in /usr/bin so that you can use it from anywhere you are.
```

## Start project

```
~$ sudo launcher FILE_NAME [--name=APP_NAME] [--icon=ICON] [--version=VERSION] [--exec=PROGRAM_TO_EXECUTE]
```

## Contributions

All contributions are welcome, so, feel free to play with the project and use it what however you want.
