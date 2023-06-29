#include "task.h"
#include "../paging/paging.h"
#include "../memory.h"
#include "../config.h"

struct task * current_task = 0;

struct task * task_tail = 0;

struct task * task_head = 0;



struct task * current_task()
{
    return current_task;
}


int task_init(struct task* task)
{
    memset(task, 0 , sizeof( struct task));

    task->page_directory = paging_4gb_chunk(PAGING_IS_PRESENT | PAGING_ACCESS_FROM_ALL );
    task->registers.ip = PROGRAM_VIRTUAL_ADDRESS;
    task->registers.ss = USER_DATA_SEGMENT;
    task->registers.esp = PROGRAM_VIRTUAL_STACK_ADDRESS;

    return 0;
}