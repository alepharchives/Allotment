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

#include "allocator_test.h"
#include "allocator.h"

#include "string.h"

START_TEST(test_1) {
    allocator *al = create_allocator();
    
    char *test = allocate(al, 10);
    memset(test, 0, 10);
    
    test = allocate(al, 10);
    memset(test, 0, 10);
    
    free_allocator(al);
} END_TEST

TCase *allocator_test_case() {
    TCase *tc = tcase_create("allocator");
    tcase_add_test(tc, test_1);
    return tc;
}
