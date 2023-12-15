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

.PHONY: testing_utils
testing_utils: $(SRC_TESTING_UTILS)
	$(CXX) $(CXXFLAGS) -c $(SRC_TESTING_UTILS) -o $(OBJ_TESTING_UTILS)

#### ==== END Testing Utilities ==== ####



#### ==== InputsHandler ==== ####

SRC_INPUTSHANDLER = source/ESC_core/InputsHandler.cpp
OBJ_INPUTSHANDLER = object/ESC_core/InputsHandler.o

.PHONY: InputsHandler
InputsHandler: $(SRC_INPUTSHANDLER)
	$(CXX) $(CXXFLAGS) -c $(SRC_INPUTSHANDLER) -o $(OBJ_INPUTSHANDLER)


SRC_TEST_INPUTSHANDLER = test/ESC_core/test_InputsHandler.cpp
OUT_TEST_INPUTSHANDLER = test/bin/test_InputsHandler.out

.PHONY: TEST_InputsHandler
TEST_InputsHandler: InputsHandler testing_utils
	$(CXX) $(CXXFLAGS) $(SRC_TEST_INPUTSHANDLER) $(OBJ_INPUTSHANDLER) \
$(OBJ_TESTING_UTILS) -o $(OUT_TEST_INPUTSHANDLER) $(SFML)

#### ==== END InputsHandler ==== ####



#### ==== AssetsManager ==== ####

SRC_ASSETSMANAGER = source/ESC_core/AssetsManager.cpp
OBJ_ASSETSMANAGER = object/ESC_core/AssetsManager.o

.PHONY: AssetsManager
AssetsManager: $(SRC_ASSETSMANAGER)
	$(CXX) $(CXXFLAGS) -c $(SRC_ASSETSMANAGER) -o $(OBJ_ASSETSMANAGER)


SRC_TEST_ASSETSMANAGER = test/ESC_core/test_AssetsManager.cpp
OUT_TEST_ASSETSMANAGER = test/bin/test_AssetsManager.out

.PHONY: TEST_AssetsManager
TEST_AssetsManager: AssetsManager InputsHandler testing_utils
	$(CXX) $(CXXFLAGS) $(SRC_TEST_ASSETSMANAGER) $(OBJ_ASSETSMANAGER) \
$(OBJ_INPUTSHANDLER) $(OBJ_TESTING_UTILS) -o $(OUT_TEST_ASSETSMANAGER) $(SFML)

#### ==== END AssetsManager ==== ####



#### ==== HexMap ==== ####

SRC_HEXTILE = source/HexMap/HexTile.cpp
OBJ_HEXTILE = object/HexMap/HexTile.o

.PHONY: HexTile
HexTile: $(SRC_HEXTILE)
	$(CXX) $(CXXFLAGS) -c $(SRC_HEXTILE) -o $(OBJ_HEXTILE)


SRC_HEXMAP = source/HexMap/HexMap.cpp
OBJ_HEXMAP = object/HexMap/HexMap.o

.PHONY: HexMap
HexMap: $(SRC_HEXMAP)
	$(CXX) $(CXXFLAGS) -c $(SRC_HEXMAP) -o $(OBJ_HEXMAP)


SRC_TEST_HEXMAP = test/HexMap/test_HexMap.cpp
OUT_TEST_HEXMAP = test/bin/test_HexMap.out

.PHONY: TEST_HexMap
TEST_HexMap: HexMap HexTile AssetsManager InputsHandler testing_utils
	$(CXX) $(CXXFLAGS) $(SRC_TEST_HEXMAP) $(OBJ_HEXMAP) $(OBJ_HEXTILE) \
$(OBJ_ASSETSMANAGER) $(OBJ_INPUTSHANDLER) $(OBJ_TESTING_UTILS) -o $(OUT_TEST_HEXMAP) \
$(SFML)

#### ==== END HexMap ==== ####

## ======== END BUILD =============================================================== ##



## ======== TARGETS ================================================================= ##

.PHONY: clean
clean:
	rm -frv bin
	rm -frv gmon.*
	rm -frv object
	rm -frv profiling_results
	rm -frv test/bin
	make docs
	make compress


.PHONY: compress
compress:
	rm -frv assets.7z
	7z a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on assets.7z assets


.PHONY: dirs
dirs:
	mkdir -pv bin
	mkdir -pv object
	mkdir -pv object/ESC_core
	mkdir -pv object/HexMap
	mkdir -pv test/bin


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


.PHONY: test_InputsHandler
test_InputsHandler:
	make dirs
	make TEST_InputsHandler
	$(OUT_TEST_INPUTSHANDLER)


.PHONY: test_AssetsManager
test_AssetsManager:
	make dirs
	make TEST_AssetsManager
	$(OUT_TEST_ASSETSMANAGER)


.PHONY: test_HexMap
test_HexMap:
	make dirs
	make TEST_HexMap
	$(OUT_TEST_HEXMAP)

## ======== END TARGETS ============================================================= ##
