CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = chess
OBJECTS = mainDancho.o observer.o subject.o ChessBoard.o piece.o pawn.o rook.o bishop.o knight.o king.o queen.o emptycell.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
