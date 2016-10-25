CC = g++

# For program run
CC_OPTION = -fomit-frame-pointer -W -Wall -Winline -DNDBUG -O3

# For debug
# CC_OPTION = -g -fomit-frame-pointer -W -Wall -Winline

ALL_OPS = Timing Boolean LinearSuffixSort MakeTest Clear

ALL:$(ALL_OPS)

Boolean:
	$(CC) -c BooleanString.C $(CC_OPTION)

Timing:
	$(CC) -c Timing.C $(CC_OPTION)

LinearSuffixSort:LinearSuffixSort.cc
	$(CC) -c LinearSuffixSort.cc $(CC_OPTION)

MakeTest:test.C
	$(CC) -o test.exe test.C LinearSuffixSort.o BooleanString.o Timing.o $(CC_OPTION)

Clear:
	rm *.o

test:test.exe
	./test.exe test.dat




