
NVCC = /usr/local/cuda/bin/nvcc
NVCC_FLAGS = -g -G -Xcompiler -Wall
GLUT_FLAGS = -lGL -lGLU -lGLEW -lglut


all: main.exe


main.exe: main.o kernel.o
	$(NVCC) $^ -o $@ $(GLUT_FLAGS)

main.o: main.cpp kernel.h interactions.h
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

kernel.o: kernel.cu kernel.h
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@


clean:
	rm -f *.o *.exe
