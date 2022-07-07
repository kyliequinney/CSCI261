# customize your build
TARGET = A7
SRC_FILES = main.cpp
CXX = g++
CFLAGS = -Wall -g -std=c++11
INC_PATH = Z:\include # location where headers are
LIB_PATH = Z:\lib # location where archive files are
LIBS = -lsfml-window -lsfml-graphics -lsfml-system # name of archive file to load
# do not edit below here
OBJECTS = ${SRC_FILES:.cpp=.o}
DEL = ...
all: ${TARGET}
${TARGET}: ${OBJECTS}
	${CXX} -o $@ $^ -L${LIB_PATH} ${LIBS}
.cpp.o:
	${CXX} ${CFLAGS} -o $@ -c $< -I${INC_PATH}
clean:
	${DEL} ${TARGET} ${OBJECTS}