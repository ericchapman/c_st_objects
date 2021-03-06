/**

Copyright (c) 2016 Eric Chapman

MIT License

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef __ST_OBJECTS_ST_LINK_H__
#define __ST_OBJECTS_ST_LINK_H__

#include "st_object.h"

typedef struct st_link_s
{
    struct st_link_s *prev;
    struct st_link_s *next;
    st_object_t *object;
    st_object_t *key;
} st_link_t;

st_link_t *st_link_new(st_malloc_t *malloc, st_object_t *object, st_object_t *key);
void st_link_init(st_link_t *this, st_object_t *object, st_object_t *key);

#endif // __ST_OBJECTS_ST_LINK_H__
