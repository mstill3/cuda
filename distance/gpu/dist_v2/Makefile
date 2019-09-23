NVCC = /usr/local/cuda/bin/nvcc
NVCC_FLAGS = -g -G -Xcompiler -Wall

all: main.exe

# $@ means target
# $< means use first arg
# $^ means use all args(dependents)

main.exe: main.o kernel.o
	$(NVCC) $^ -o $@

main.o: main.cpp
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

kernel.o: kernel.cu
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

