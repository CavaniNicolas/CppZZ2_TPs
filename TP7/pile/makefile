SRC = $(wildcard src/*.cpp)
SRCTests = $(filter-out src/Main.cpp, $(SRC)) $(wildcard src/tests/*.cpp)

OBJ = $(addprefix build/, $(SRC:.cpp=.o))
OBJTests = $(addprefix build/, $(SRCTests:.cpp=.o))
DEP = $(addprefix build/, $(SRC:.cpp=.d))

# options de compilation et d'edition des liens
CXXFLAGS = -Wall -Wextra -MMD -g -O2
LDFLAGS = #-lSDL

.PHONY: all
all: main tests
	@echo "2 executables disponibles"

.PHONY: main
main: bin/main
	@echo "Executer avec ./bin/main"

.PHONY: tests
tests: bin/tests
	@echo "Executer avec ./bin/tests"

# edition des liens, executable main
bin/main: $(OBJ)
	@mkdir -p $(@D) #creer le dossier bin, sil nexiste pas
	$(CXX) -o $@ $^ $(LDFLAGS)

# edition des liens, executable tests
bin/tests: $(OBJTests)
	@mkdir -p $(@D) #creer le dossier bin, sil nexiste pas
	$(CXX) -o $@ $^ $(LDFLAGS)

# genere les fichiers .o (dans build) a partir des fichiers .cpp (dans src) du meme nom
# compilation
build/%.o: %.cpp
	@mkdir -p $(@D)  #creer le dossier build sil nexiste pas
	$(CXX) -c $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build core *.gch
	rm -rf bin

-include $(DEP)
