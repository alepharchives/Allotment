/*  
    Copyright (C) 2011 Allotment authors,
    
    This file is part of Allotment.
    
    Allotment is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Allotment is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdlib.h>

struct allocator;
typedef struct allocator allocator;

allocator *create_allocator();
void *allocate(allocator *, size_t);
void free_allocator(allocator *);

#endif
