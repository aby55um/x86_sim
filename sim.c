#define SDL_MAIN_USE_CALLBACKS 1

#include <stdint.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

struct general_purpose_registers_32 {
	uint32_t eax;
	uint32_t ebx;
	uint32_t ecx;
	uint32_t edx;
	uint32_t esi;
	uint32_t edi;
	uint32_t esp;
	uint32_t ebp;
	uint32_t r8d;
	uint32_t r9d;
	uint32_t r10d;
	uint32_t r11d;
	uint32_t r12d;
	uint32_t r13d;
	uint32_t r14d;
	uint32_t r15d;
};

struct segment_registers_32 {
	uint16_t cs;
	uint16_t ds;
	uint16_t ss;
	uint16_t es;
	uint16_t fs;
	uint16_t gs;
};

uint32_t eip;
uint32_t eflags;
uint16_t control_register_32;
uint16_t status_register_32;
uint16_t tag_register_32;
// 11 bits opcode register
uint16_t opcode_register_32;

//32-bit todo:
//Eight 80-bit FPU registers (floating point registers)
//FPU Instruction Pointer Register (48 bits)
//FPU Data (Operand) Pointer Register (48 bits)
//eight 64-bit MMX registers
//eight 128-bit XMM registers
//MXCSR register (32-bits)
//eight 256-bit YMM registers
//Four 128-bit Registers - Bounds registers
//BNDCFGU register
//BNDSTATUS register

//todo: check if the general purpose fpu register list is correct
struct general_purpose_fpu_registers_32 {
	uint8_t s0[10];
	uint8_t s1[10];
	uint8_t s2[10];
	uint8_t s3[10];
	uint8_t s4[10];
	uint8_t s5[10];
	uint8_t s6[10];
	uint8_t s7[10];
};


struct general_purpose_registers_64 {
	uint64_t rax;
	uint64_t rbx;
	uint64_t rcx;
	uint64_t rdx;
	uint64_t rdi;
	uint64_t rsi;
	uint64_t rbp;
	uint64_t rsp;
	uint64_t r8;
	uint64_t r9;
	uint64_t r10;
	uint64_t r11;
	uint64_t r12;
	uint64_t r13;
	uint64_t r14;
	uint64_t r15;	
};

// check if correct
struct segment_registers_64 {
	uint16_t cs;
	uint16_t ds;
	uint16_t ss;
	uint16_t es;
	uint16_t fs;
	uint16_t gs;
};

uint64_t rip;

uint64_t rflags;

//64-bit todo:
//eight 80-bit FPU registers (floating point)
//16 bits Control Register
//16 bits Status Register
//16 bits Tag Register
//11 bits opcode register
//48 bits FPU Instruction Pointer Register
//48 bits FPU Data (Operand) Pointer Register
//eight 64 bits MMX Registers
//eight 128 bit XMM Register
//32 bit MXCSR Register
//eight 256 bit YMM Registers
//four 128-bit registers - Bound registers
//BNDCFGU Register
//BNDSTATUS Register

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

float x, y;
const char *title = "x86_64 Emulator";

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    /* Create the window */
    if (!SDL_CreateWindowAndRenderer("x86_64 Emulator", 800, 600, SDL_WINDOW_FULLSCREEN, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_KEY_DOWN && event->key.key == SDLK_ESCAPE ||
        event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	int w = 0, h = 0;
    const float scale = 2.0f; 

    x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(title)) * 0.5;
    y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) * 0.1;
    
    /* Center the title and scale it up */
    SDL_GetRenderOutputSize(renderer, &w, &h);
    SDL_SetRenderScale(renderer, scale, scale);
    
    /* Draw the title */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDebugText(renderer, x, y, title);
 
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}