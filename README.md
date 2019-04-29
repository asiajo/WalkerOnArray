# WalkerOnArray

small two people cooperation project.
Snake game.

## Compilation

Game uses ncurses library.
To install it on Linux: [tutNcurs][df1]
Game uses SFML library. 
To install it on Linux: [tutSfml][df2]

Under Linux:
From build folder run the terminal and type:

	cmake ..

	make

	./WalkerOnArray

The game will start!

## TODO:

- [ ] create UML diagram with game structure
- [x] create board class
- [x] create snake class
- [x] create controller class
- [x] create displayer class
	- [x] Terminal
	- [x] GUI
- [ ] create unit tests


[df1]: <https://www.cyberciti.biz/faq/linux-install-ncurses-library-headers-on-debian-ubuntu-centos-fedora/>
[df2]: <https://www.sfml-dev.org/tutorials/2.5/start-linux.php>