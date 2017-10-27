# sdl2-TicTacToe
The simple Tic-Tac-Toe game created in C++ with SDL2.

This game was developed for **learning purposes**.
The current only supported mode is single player and the bot you'll be facing randomly chooses its AI level (easy, medium or hard) at every new game.
All board shapes were drawn using hardware accelerated primitive rendering, so no image resources were needed in the project.

## LICENSE

Tower Engineer is licensed under the [Do What The Fuck You Want License](https://github.com/davidgomes/tower-engineer/blob/master/LICENSE)

## Dependencies
You'll need SDL2 to be able to compile the program. To install it, use the following commands:

**Debian**
```
$ sudo apt-get install libsdl2-dev
```
**Arch**
```
$ sudo pacman -S sdl2
```

**Red Hat**
```
$ sudo yum install SDL2-devel
```

## Usage

From the project source folder, run:
```
$ make
$ ./tictactoe
```
