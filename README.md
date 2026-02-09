# Asylum Windows

<i>Young Sigmund has a few problems. To help him resolve his mental instability you must enter the surreal world of his inner mind and shut down the malfunctioning brain cells which are causing him these problems.</i> — Instructions file from original game

SDL Asylum is a C port of the computer game Asylum, which was written by Andy Southgate in 1994 for the Acorn Archimedes and is now public domain. This fork targets Windows only and runs on SDL2 with optional OpenGL rendering.

This fork contains the SDL2 port and Windows-specific build/run improvements.

## Maintainer and upstream

- Maintainer: itinfra7
- Upstream forked from: https://github.com/M-HT/asylum

## Build and run (Windows)

Use MSYS2 MinGW64:

- Build: make HOST=mingw
- Run: place asylum.exe next to the required SDL2 DLLs and the data/ and hiscores/ directories
- A ready-to-run layout is typically placed in dist/

## Windows-specific differences

- Save/config files are stored in a local save/ directory alongside asylum.exe
	(created automatically if missing).
- Key binding prompts use "Press Key to Jump" for the up action, and the order
	is Left, Right, Down, Fire, Jump.
- Key binding input is debounced to avoid repeated captures on fast machines.

## Instructions

<i>Well, you don't really need any instructions to play the game. Just remember, the object is to find things that look like brain cells and shut them down! Good luck!</i> — Instructions file from original game

The game revolves around shooting anything which moves, collecting anything which doesn't move, and, most importantly, finding your way to each of the eight pulsating neurons scattered through the immense map. Use ‘Z’, ‘X’, ‘;’ and ‘.’ to move and ‘Enter’ to fire, or remap the keys to something you like better.

The one game feature which does merit explicit instruction is teleporting. In the first level (“Ego”) the teleporters look like candelabra. To use a teleporter, stand in its centre and press “down” (that's ‘.’ with the default key settings).


## Credits

SDL Asylum wouldn't have happened at all without Andy Southgate, who wrote the original game and later generously made it public domain. Nor without Jeffrey Lee and John Hoare, who got hold of Andy's original assembly source and hosted it on their marvellous Asylum tribute site at acornarcade.com.

SDL Asylum wouldn't be as good without the ports, packages and patches provided by: Dmitry Marakasov, Ian Chapman, James Woodcock, Peter De Wachter.


## Licensing

SDL Asylum is distributed under GPL version 3.  The original game music and graphics are © Andy Southgate 1993, and have been placed in the public domain by Andy Southgate.


## Original Web site

http://sdl-asylum.sourceforge.net/
