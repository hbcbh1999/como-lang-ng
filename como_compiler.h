/*
 * Copyright (c) 2016 Ryan McCullagh <me@ryanmccullagh.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COMO_COMPILER_H
#define COMO_COMPILER_H

#include <stddef.h>
#include <object.h>

#include "como_ast.h"
#include "como_stack.h"

#define COMO_DEFAULT_FRAME_STACKSIZE 2048U

typedef struct ComoOpCode 
{
    unsigned char op_code;
    Object       *operand;
} ComoOpCode;

typedef struct ComoFrame 
{
    size_t            cf_sp;
    size_t            cf_stack_size;
    Object           *cf_stack[(size_t)COMO_DEFAULT_FRAME_STACKSIZE];
    Object           *cf_symtab; 
    Object           *code;
    struct ComoFrame *next;
    Object           *namedparameters;
    Object           *filename;
    como_stack       *call_stack;
} ComoFrame;

void como_print_stack_trace();
void como_compile_ast(ast_node *p, const char *filename);
void como_dump_asm(ast_node *p, const char *filename);

#endif /* !COMO_COMPILER_H */
