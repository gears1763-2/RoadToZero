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
OBJ_TESTING_UTILS = bin/ESC_core/testing_utils.o

.PHONY: testing_utils
testing_utils: $(SRC_TESTING_UTILS)
	$(CXX) $(CXXFLAGS) -c $(SRC_TESTING_UTILS) -o $(OBJ_TESTING_UTILS)

#### ==== END Testing Utilities ==== ####



#### ==== InputsHandler ==== ####

SRC_INPUTSHANDLER = source/ESC_core/InputsHandler.cpp
OBJ_INPUTSHANDLER = bin/ESC_core/InputsHandler.o

.PHONY: InputsHandler
InputsHandler: $(SRC_INPUTSHANDLER)
	$(CXX) $(CXXFLAGS) -c $(SRC_INPUTSHANDLER) -o $(OBJ_INPUTSHANDLER)


SRC_TEST_INPUTSHANDLER = test/ESC_core/test_InputsHandler.cpp
OUT_TEST_INPUTSHANDLER = test/bin/test_InputsHandler.out

.PHONY: TEST_InputsHandler
TEST_InputsHandler: InputsHandler
	$(CXX) $(CXXFLAGS) $(SRC_TEST_INPUTSHANDLER) $(OBJ_INPUTSHANDLER) \
$(OBJ_TESTING_UTILS) -o $(OUT_TEST_INPUTSHANDLER) $(SFML)


#### ==== END InputsHandler ==== ####


## ======== END BUILD =============================================================== ##



## ======== TARGETS ================================================================= ##

.PHONY: clean
clean:
	rm -frv bin
	rm -frv gmon.*
	rm -frv object
	rm -frv profiling_results
	rm -frv test/bin


.PHONY: dirs
dirs:
	mkdir -pv bin
	mkdir -pv bin/ESC_core
	mkdir -pv object
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
	make testing_utils
	make TEST_InputsHandler
	$(OUT_TEST_INPUTSHANDLER)

## ======== END TARGETS ============================================================= ##
