.PHONY: all build run clean git 

CXX := g++
CXXFLAGS := -I src/board -I src/pieces -I src/utils -g
LIBS := -lmingw32

all: build run clean

git:
	git add *
	git commit
	git push

run:
	./main

build: main

main: obj/pawn.o obj/rook.o obj/knight.o obj/bishop.o obj/king.o obj/queen.o obj/board.o obj/main.o
	@$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

obj/main.o: main.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/board.o: src/board/board.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/pawn.o: src/pieces/pawn.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/rook.o: src/pieces/rook.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/knight.o: src/pieces/knight.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/bishop.o: src/pieces/bishop.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/king.o: src/pieces/king.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/queen.o: src/pieces/queen.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<



clean:
	@del \Q obj\*.o
	@del \Q *.exe