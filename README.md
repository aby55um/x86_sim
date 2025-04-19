X86_64 emulator

Compilation from source:

Download and build SDL3 (https://github.com/libsdl-org/SDL/tree/main)

git clone https://github.com/aby55um/x86_sim.git

cd x86_sim

gcc sim.c -L/path/to/SDL3/build/ -lSDL3

./a.out
