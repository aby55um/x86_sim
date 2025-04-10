#include <stdint.h>

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
}

uint64_t rip;

uint64_t rflags;

int main(){
	
}