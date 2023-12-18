#
#   RoadToZero
#
#   [ESC] Interactive
#
#   Makefile for RoadToZero.
#
#   Remember, Linux only supports the DYNAMIC build option; the STATIC build option is
#   for Windows.
#


## ======== COMPILER FLAGS ========================================================== ##

CXX = g++ -O3 -std=c++17


#CXXFLAGS =  -Wall -g -p -fPIC
CXXFLAGS = -Wall -fPIC


SFML = -lsfml-graphics\
       -lsfml-audio\
       -lsfml-network\
       -lsfml-window\
       -lsfml-system\
       -lpthread


STATIC = -static -static-libgcc -static-libstdc++


SFML_STATIC = -DSFML_STATIC\
              -lsfml-main\
              -lsfml-graphics-s\
              -lsfml-audio-s\
              -lsfml-network-s\
              -lsfml-window-s\
              -lsfml-system-s\
              -lopengl32\
              -lopenal32\
              -lfreetype\
              -lwinmm\
              -lgdi32\
              -lFLAC\
              -lvorbisenc\
              -lvorbisfile\
              -lvorbis\
              -logg\
              -lws2_32\
              -ljpeg\
              -lpthread\
              $(STATIC)

## ======== END COMPILER FLAGS ====================================================== ##



## ======== BUILD =================================================================== ##

#### ==== Testing Utilities ==== ####

SRC_TESTING_UTILS = source/ESC_core/testing_utils.cpp
OBJ_TESTING_UTILS = object/ESC_core/testing_utils.o

$(OBJ_TESTING_UTILS): $(SRC_TESTING_UTILS)
	$(CXX) $(CXXFLAGS) -c $(SRC_TESTING_UTILS) -o $(OBJ_TESTING_UTILS)

#### ==== END Testing Utilities ==== ####



#### ==== AssetsManager ==== ####

SRC_ASSETSMANAGER = source/ESC_core/AssetsManager.cpp
OBJ_ASSETSMANAGER = object/ESC_core/AssetsManager.o

$(OBJ_ASSETSMANAGER): $(SRC_ASSETSMANAGER)
	$(CXX) $(CXXFLAGS) -c $(SRC_ASSETSMANAGER) -o $(OBJ_ASSETSMANAGER)

#### ==== END AssetsManager ==== ####



#### ==== MessageHub ==== ####

SRC_MESSAGEHUB = source/ESC_core/MessageHub.cpp
OBJ_MESSAGEHUB = object/ESC_core/MessageHub.o

$(OBJ_MESSAGEHUB): $(SRC_MESSAGEHUB)
	$(CXX) $(CXXFLAGS) -c $(SRC_MESSAGEHUB) -o $(OBJ_MESSAGEHUB)

#### ==== END MessageHub ==== ####



#### ==== HexTile ==== ####

SRC_HEXTILE = source/HexTile.cpp
OBJ_HEXTILE = object/HexTile.o

$(OBJ_HEXTILE): $(SRC_HEXTILE)
	$(CXX) $(CXXFLAGS) -c $(SRC_HEXTILE) -o $(OBJ_HEXTILE)

#### ==== END HexTile ==== ####



#### ==== HexMap ==== ####

SRC_HEXMAP = source/HexMap.cpp
OBJ_HEXMAP = object/HexMap.o

$(OBJ_HEXMAP): $(SRC_HEXMAP)
	$(CXX) $(CXXFLAGS) -c $(SRC_HEXMAP) -o $(OBJ_HEXMAP)

#### ==== END HexMap ==== ####



#...



#### ==== Game ==== ####

SRC_GAME = source/Game.cpp
OBJ_GAME = object/Game.o

$(OBJ_GAME): $(SRC_GAME)
	$(CXX) $(CXXFLAGS) -c $(SRC_GAME) -o $(OBJ_GAME)

#### ==== END Game ==== ####



#### ==== main ==== ####

OBJ_ALL = $(OBJ_GAME) \
          $(OBJ_HEXMAP) \
          $(OBJ_HEXTILE) \
          $(OBJ_ASSETSMANAGER) \
          $(OBJ_MESSAGEHUB) \
          $(OBJ_TESTING_UTILS)


SRC_MAIN = source/main.cpp
OUT_MAIN = RoadToZero.out

.PHONY: main
main: $(SRC_MAIN) $(OBJ_ALL)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) $(OBJ_ALL) -o $(OUT_MAIN) $(SFML)

#### ==== END main ==== ####

## ======== END BUILD =============================================================== ##



## ======== TARGETS ================================================================= ##

.PHONY: all
all:
	make dirs
	make main
	./$(OUT_MAIN)


.PHONY: clean
clean:
	rm -frv gmon.*
	rm -frv object
	rm -frv profiling_results
	rm -frv $(OUT_MAIN)


.PHONY: compress
compress:
	rm -frv assets.7z
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on assets.7z assets


.PHONY: dirs
dirs:
	mkdir -pv object
	mkdir -pv object/ESC_core


DOCSNAME = RoadToZero

.PHONY: docs
docs:
	rm -fv docs/$(DOCSNAME).7z
	rm -fv docs/$(DOCSNAME).pdf
	doxygen docs/config.doxygen
	(cd docs/latex && \
     make pdf && \
     mv -fv refman.pdf ../$(DOCSNAME).pdf)
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on docs/$(DOCSNAME).7z docs/html
	rm -frv docs/html
	rm -frv docs/latex
	rm -frv docs/bibTmpDir
	rm -frv docs/bib2xhtml.pl
	rm -frv docs/doxygen.bst
	rm -frv docs/citelist.doc

## ======== END TARGETS ============================================================= ##
