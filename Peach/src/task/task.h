#ifndef TASK_H
#define TASK_H

#include <stdint.h>
#include "../paging/paging.h"

struct registers{

    uint32_t edi;
    uint32_t esi;
    uint32_t ebp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;


    uint32_t ip;
    uint32_t cs;
    uint32_t flags;
    uint32_t esp;
    uint32_t ss;
};


struct task {
//dir of task
 struct paging_4gb_chunk* page_directory;

 //registers of task 
 struct registers registers;

//next task
 struct task * next;

 //prev task 
 struct task * prev;

};


#endif