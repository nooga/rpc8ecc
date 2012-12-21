# rpc8ecc

... is a cc65 C compiler fitted to target redpower's rpc8e computer in Minecraft. 

## Installation

The compiler binaries for OX X 10.7 are in the `bin/` directory but You will probably need to compile the cc65 itself for your system.

1. Grab CC65 V2.13.3 for your system here: ftp://ftp.musoftware.de/pub/uz/cc65/
2. Compile the compiler with the usual `./compile && make` stuff
3. Link or copy the compiler binaries to the `bin/` folder of this project
4. Done

## Usage

To compile example `test_rb.c` use:

```
make test
```
in the project's main directory. 

You should get `test_rb.img` file that is an usable floppy image for rpc8e (both ingame or emulated).
Read the Makefiles to learn more.

For now there is no good way to use the compiler for other projects than simple C programs... as always: pull requests are welcome.

## Features

* Compiles C
* Has some sort of "hardware drivers" (check `include/`)

## Future

* Including stuff like `stdlib.h` or `string.h` into the distribution
* Finding a nice way to package this toy and make it easier to use
* Custom libraries for stuff like networking, console etc.
* Ideas? Fork & pull & have fun

## Author(s)

nooga is just the guy who put this stuff together for rpc8e. 

The CC65 compiler itself is a great work by Ullrich von Bassewitz and CC65 developers.

Also, many thanks to Jarek Pelczar and folks at #redpower.

## Questions?

You can find me (nooga) on #redpower at espernet IRC.