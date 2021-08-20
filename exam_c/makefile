CFLAGS=-std=c11 -pedantic -Wvla -Wall -Werror -g 

all : testVideo
	
testVideo : testVideo.o video.o image.o
	gcc $(CFLAGS) -o testVideo testVideo.o video.o image.o

testVideo.o : testVideo.c video.h
	gcc $(CFLAGS) -c testVideo.c

video.o : video.c video.h image.h
	gcc $(CFLAGS) -c video.c

image.o : image.c image.h
	gcc $(CFLAGS) -c image.c

clean :
	rm *.o
	rm testVideo
