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

#include "allocator.h"

struct allocation {
    struct allocation *next;
};

typedef struct allocation allocation;

struct allocator {
    allocation *first, *last;
};

allocator *create_allocator() {
    allocator *al = malloc(sizeof(allocator));
    al->first = NULL;
    al->last = NULL;
    return al;
}

allocation *create_allocation(size_t sz) {
    allocation *out = malloc(sizeof(allocation) + sz);
    out->next = NULL;
    return out;
}

void *allocate(allocator *al, size_t sz) {
    allocation *n = create_allocation(sz);
    if (al->first == NULL) {
        al->first = n;
    } else {
        al->last->next = n;
    }
    al->last = n;
    return &n[1];
}

void free_allocator(allocator *al) {
    allocation *cur = al->first;
    while (cur != NULL) {
        allocation *next = cur->next;
        free(cur);
        cur = next;
    }
    free(al);
}

