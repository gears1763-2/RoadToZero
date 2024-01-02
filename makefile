#
#   RoadToZero
#
#   [ESC] Interactive
#
#   Makefile for RoadToZero.
#
#   Linux build is made using dynamic linking, whereas the Windows build is made using
#   static linking.
#


## ======== COMPILER FLAGS ========================================================== ##

CXX = g++

CXXFLAGS = -O3 -std=c++17 -Wall -fPIC

ifeq ($(OS),Windows_NT)
    CXXFLAGS += -I../SFML-2.5.1/include -L../SFML-2.5.1/lib
endif


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



#### ==== TileImprovement ==== ####

SRC_TILEIMPROVEMENT = source/TileImprovement.cpp
OBJ_TILEIMPROVEMENT = object/TileImprovement.o

$(OBJ_TILEIMPROVEMENT): $(SRC_TILEIMPROVEMENT)
	$(CXX) $(CXXFLAGS) -c $(SRC_TILEIMPROVEMENT) -o $(OBJ_TILEIMPROVEMENT)

#### ==== END TileImprovement ==== ####



#### ==== Settlement ==== ####

SRC_SETTLEMENT = source/Settlement.cpp
OBJ_SETTLEMENT = object/Settlement.o

$(OBJ_SETTLEMENT): $(SRC_SETTLEMENT)
	$(CXX) $(CXXFLAGS) -c $(SRC_SETTLEMENT) -o $(OBJ_SETTLEMENT)

#### ==== END Settlement ==== ####



#### ==== DieselGenerator ==== ####

SRC_DIESELGENERATOR = source/DieselGenerator.cpp
OBJ_DIESELGENERATOR = object/DieselGenerator.o

$(OBJ_DIESELGENERATOR): $(SRC_DIESELGENERATOR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIESELGENERATOR) -o $(OBJ_DIESELGENERATOR)

#### ==== END DieselGenerator ==== ####



#### ==== SolarPV ==== ####

SRC_SOLARPV = source/SolarPV.cpp
OBJ_SOLARPV = object/SolarPV.o

$(OBJ_SOLARPV): $(SRC_SOLARPV)
	$(CXX) $(CXXFLAGS) -c $(SRC_SOLARPV) -o $(OBJ_SOLARPV)

#### ==== END SolarPV ==== ####



#### ==== WindTurbine ==== ####

SRC_WINDTURBINE = source/WindTurbine.cpp
OBJ_WINDTURBINE = object/WindTurbine.o

$(OBJ_WINDTURBINE): $(SRC_WINDTURBINE)
	$(CXX) $(CXXFLAGS) -c $(SRC_WINDTURBINE) -o $(OBJ_WINDTURBINE)

#### ==== END WindTurbine ==== ####



#### ==== TidalTurbine ==== ####

SRC_TIDALTURBINE = source/TidalTurbine.cpp
OBJ_TIDALTURBINE = object/TidalTurbine.o

$(OBJ_TIDALTURBINE): $(SRC_TIDALTURBINE)
	$(CXX) $(CXXFLAGS) -c $(SRC_TIDALTURBINE) -o $(OBJ_TIDALTURBINE)

#### ==== END TidalTurbine ==== ####



#### ==== WaveEnergyConverter ==== ####

SRC_WAVEENERGYCONVERTER = source/WaveEnergyConverter.cpp
OBJ_WAVEENERGYCONVERTER = object/WaveEnergyConverter.o

$(OBJ_WAVEENERGYCONVERTER): $(SRC_WAVEENERGYCONVERTER)
	$(CXX) $(CXXFLAGS) -c $(SRC_WAVEENERGYCONVERTER) -o $(OBJ_WAVEENERGYCONVERTER)

#### ==== END WaveEnergyConverter ==== ####



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



#### ==== ContextMenu ==== ####

SRC_CONTEXTMENU = source/ContextMenu.cpp
OBJ_CONTEXTMENU = object/ContextMenu.o

$(OBJ_CONTEXTMENU): $(SRC_CONTEXTMENU)
	$(CXX) $(CXXFLAGS) -c $(SRC_CONTEXTMENU) -o $(OBJ_CONTEXTMENU)

#### ==== END ContextMenu ==== ####



#### ==== Game ==== ####

SRC_GAME = source/Game.cpp
OBJ_GAME = object/Game.o

$(OBJ_GAME): $(SRC_GAME)
	$(CXX) $(CXXFLAGS) -c $(SRC_GAME) -o $(OBJ_GAME)

#### ==== END Game ==== ####



#### ==== main ==== ####

SRC_ALL = $(SRC_GAME) \
          $(SRC_CONTEXTMENU) \
          $(SRC_HEXMAP) \
          $(SRC_HEXTILE) \
          $(SRC_DIESELGENERATOR) \
          $(SRC_SOLARPV) \
          $(SRC_WINDTURBINE) \
          $(SRC_TIDALTURBINE) \
          $(SRC_WAVEENERGYCONVERTER) \
          $(SRC_SETTLEMENT) \
          $(SRC_TILEIMPROVEMENT) \
          $(SRC_ASSETSMANAGER) \
          $(SRC_MESSAGEHUB) \
          $(SRC_TESTING_UTILS)

SRC_MAIN = source/main.cpp

OBJ_ALL = $(OBJ_GAME) \
          $(OBJ_CONTEXTMENU) \
          $(OBJ_HEXMAP) \
          $(OBJ_HEXTILE) \
          $(OBJ_DIESELGENERATOR) \
          $(OBJ_SOLARPV) \
          $(OBJ_WINDTURBINE) \
          $(OBJ_TIDALTURBINE) \
          $(OBJ_WAVEENERGYCONVERTER) \
          $(OBJ_SETTLEMENT) \
          $(OBJ_TILEIMPROVEMENT) \
          $(OBJ_ASSETSMANAGER) \
          $(OBJ_MESSAGEHUB) \
          $(OBJ_TESTING_UTILS)


OUT_MAIN = RoadToZero.out

.PHONY: main_Linux
main_Linux: $(SRC_MAIN) $(OBJ_ALL)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) $(OBJ_ALL) -o $(OUT_MAIN) $(SFML)


EXE_MAIN = RoadToZero.exe

.PHONY: main_Win32
main_Win32: $(SRC_MAIN) $(SRC_ALL)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) $(SRC_ALL) -o $(EXE_MAIN) $(SFML_STATIC)

#### ==== END main ==== ####

## ======== END BUILD =============================================================== ##



## ======== TARGETS ================================================================= ##

.PHONY: all
all:
ifeq ($(OS),Windows_NT)
	make main_Win32
	./$(EXE_MAIN)
else
	make dirs
	make main_Linux
	./$(OUT_MAIN)
endif


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
     mv -fv refman.pdf ../$(DOCSNAME)_LaTeX.pdf)
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on docs/$(DOCSNAME)_html.7z docs/html
	rm -frv docs/html
	rm -frv docs/latex
	rm -frv docs/bibTmpDir
	rm -frv docs/bib2xhtml.pl
	rm -frv docs/doxygen.bst
	rm -frv docs/citelist.doc

## ======== END TARGETS ============================================================= ##
