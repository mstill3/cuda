NVCC = /usr/local/cuda/bin/nvcc
NVCC_FLAGS = -g -G -Xcompiler -Wall

all: main.exe

main.exe: kernel.cu
	$(NVCC) $(NVCC_FLAGS) $< -o $@

