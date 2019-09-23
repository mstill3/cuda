
Run this command to build for cpu:
`g++ add.cpp -o add_cpu.exe`

Run this command to build for gpu:
`nvcc add.cu -o add_gpu.exe`

Run this command to build for gpu:
`nvcc addfaster.cu -o add_faster_gpu.exe`

Test the speed difference in gpu by running:
`nvprof ./add_gpu.exe`
`nvprof ./add_faster_gpu.exe`
