# g++ with support C++14 (tested on g++6.3)
CC = g++ 
CFLAGS = -c -std=c++14

INCLUDEPATH = -I/usr/local/include/opencv4/

LIBS = -lstdc++fs -lopencv_core -lopencv_imgproc -lopencv_imgcodecs 

all: EditImage

EditImage: main.o image.o
	$(CC) main.o image.o $(LIBS) -o EditImage

main.o: main.cpp
	$(CC) $(INCLUDEPATH) $(CFLAGS) main.cpp

image.o: image.cpp
	$(CC) $(INCLUDEPATH) $(CFLAGS) image.cpp

clean:
	rm -rf *.o EditImage

