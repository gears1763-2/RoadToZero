# Road to Zero - The Microgrid Management Game

    (C) 2023 - [ESC] Interactive
    
    Anthony Truelove MASc, P.Eng.
    github:  gears1763-2


This is a 3X (i.e. eXplore, eXpand, eXploit) game that aims to teach players about
integrating renewable energy production and storage assets into an isolated microgrid
(in this case, a remote island settlement), and then managing their operations over
the long term. The goal is to grow your settlement while also achieving and maintaining
zero emissions energy dispatch. That said, the only way to win is to grow your settlement
to a population of at least 1,000 **and** achieve at least 12 *consecutive* months of
zero emissions. But take care! If you fail to meet energy demand at any time **or** you
run out of credits **or** you generate too many emissions, you immediately lose. Good
luck!

--------


## Licensing

  * This software and the associated documentation files are released under a 3-Clause BSD License (a.k.a. "New BSD License" or "Modified BSD License"). See the enclosed `LICENSE.md` for terms and conditions.
  
  * The assets (i.e., textures, sounds, music, etc.) associated with this software are governed by their own individual licenses. See the `0_*_refs_licenses.md` files in `assets/...` for details.

--------


## Contents

[...]

--------


## Key Features

  * [...]
  
  * [...]
  
  * [...]

--------


## Setup

### Windows

Road to Zero was developed using SFML 2.5.1., so be sure to be using at least this
version. For this version of SFML, you can download the complete library from
<https://www.sfml-dev.org/download/sfml/2.5.1/>. Be sure to amend the provided makefile
as necessary so that the include (`-I`) and library (`-L`) options point to the
`SFML-2.5.1\include` and `SFML-2.5.1\lib` sub-directories of wherever you unzipped 
SFML.

Since the provided makefile is set up to do static linking in the case of building on
Windows, you need to ensure that you're using a compatible C++ compiler. For this part,
the mingw32 compiler `g++` was used (and is available at
<https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip>). Note
that version 7.3.0 of mingw32 is specifically needed in order for static linking of 
SFML 2.5.1. libs to work! Of course, once you've unzipped mingw32, be sure to add
`..\mingw32\bin` to the system path.

Finally, you will need to install `make` in order to use the provided makefile. For
this part, Make for Windows was used (and is available at 
<https://gnuwin32.sourceforge.net/packages/make.htm>; specifically, the download from 
<https://gnuwin32.sourceforge.net/downlinks/make.php> was used). Of course, once you've
unzipped Make for Windows, be sure to add `..\GnuWin32\bin` to the system path.

Having done all that, it should suffice to

    make all

from the command prompt (`cmd`).


### Linux (Debian/Ubuntu)

Road to Zero was developed on Linux, so building it yourself should be pretty
straightforward. Fist, if you don't already have the development package installed, you
can do so by way of

    sudo apt-get install build-essential

Then, SFML can be installed by way of

    sudo apt-get install libsfml-dev

Finally, it should suffice to

    make all

--------


## Documentation

Documentation for this project is auto-generated using Doxygen
(see <https://www.doxygen.nl/>). HTML documentation can be found in
`docs/RoadToZero_html.7z`, and LaTeX documentation can be found in
`docs/RoadToZero_LaTeX.pdf`. All references are listed in `docs/refs.bib`.

If you do make changes to the code, you can easily generate updated documentation by way
of

    make docs

assuming you are set up to do so (i.e., `doxygen` installed, etc.).

--------

## SFML Version

Road to Zero was developed using SFML 2.5.1. See <https://www.sfml-dev.org/>.

--------


## Testing

The provided makefile and all source code was successfully tested on the following OS
and architectures:

    Operating System: Linux Mint 21.2
              Kernel: Linux 6.6.6-76060606-generic
        Architecture: x86-64

    Operating System: Windows 11 Pro
             Version: Build 22621.ni_release.220506-1250
        Architecture: 64-bit OS, x64-based processor


The following compilers were used in testing:

    g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
    g++ (i686-posix-dwarf-rev0, Built by MinGW-Wg4 project) 7.3.0


