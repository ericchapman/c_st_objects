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

#include "st_object.h"
#include <string.h>

st_object_t *st_object_new(st_malloc_t *malloc, st_object_type_t type, void *value)
{
    st_object_t *object = st_malloc_struct(malloc, sizeof(st_object_t));
    st_object_set(object, type, value);
    return object;
}

void st_object_set(st_object_t *this, st_object_type_t type, void *value)
{
    this->type = type;
    this->value = value;
}

st_object_t *st_object_new_bool(st_malloc_t *malloc, st_bool_t value)
{
    st_bool_t *temp_value = st_malloc_var(malloc, sizeof(st_bool_t));
    *temp_value = value;
    return st_object_new(malloc, ST_OBJECT_TYPE_BOOL, temp_value);
}

st_object_t *st_object_new_int(st_malloc_t *malloc, st_int_t value)
{
    st_int_t *temp_value = st_malloc_var(malloc, sizeof(st_int_t));
    *temp_value = value;
    return st_object_new(malloc, ST_OBJECT_TYPE_INT, temp_value);
}

st_object_t *st_object_new_long(st_malloc_t *malloc, st_long_t value)
{
    st_long_t *temp_value = st_malloc_var(malloc, sizeof(st_long_t));
    *temp_value = value;
    return st_object_new(malloc, ST_OBJECT_TYPE_LONG, temp_value);
}

st_object_t *st_object_new_float(st_malloc_t *malloc, st_float_t value)
{
    st_float_t *temp_value = st_malloc_var(malloc, sizeof(st_float_t));
    *temp_value = value;
    return st_object_new(malloc, ST_OBJECT_TYPE_FLOAT, temp_value);
}

st_object_t *st_object_new_string(st_malloc_t *malloc, st_string_t value)
{
    size_t length = strlen(value);
    st_string_t temp_value = st_malloc_bytes(malloc, ST_SIZE(length+1));
    strcpy(temp_value, value);
    temp_value[length] = '\0';
    return st_object_new(malloc, ST_OBJECT_TYPE_STR, temp_value);
}

st_object_t *st_object_new_array(st_malloc_t *malloc, struct st_array_s *value)
{
    return st_object_new(malloc, ST_OBJECT_TYPE_ARRAY, value);
}

st_object_t *st_object_new_dict(st_malloc_t *malloc, struct st_dict_s *value)
{
    return st_object_new(malloc, ST_OBJECT_TYPE_DICT, value);
}

st_bool_t st_object_get_bool(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_BOOL)?*((st_bool_t *)this->value):(st_bool_t)0;
}

st_int_t st_object_get_int(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_INT)?*((st_int_t *)this->value):0;
}

st_long_t st_object_get_long(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_LONG)?*((st_long_t *)this->value):0;
}

st_float_t st_object_get_float(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_FLOAT)?*((st_float_t *)this->value):0;
}

st_string_t st_object_get_string(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_STR)?((st_string_t)this->value):NULL;
}

struct st_array_s *st_object_get_array(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_ARRAY)?((struct st_array_s *)this->value):NULL;
}

struct st_dict_s *st_object_get_dict(st_object_t *this)
{
    return (this->type == ST_OBJECT_TYPE_DICT)?((struct st_dict_s *)this->value):NULL;
}

st_bool_t st_object_compare(st_object_t *object1, st_object_t *object2)
{
    if (object1 == object2)
    {
        return TRUE;
    }

    if (object1->type != object2->type)
    {
        return FALSE;
    }

    switch(object1->type) {
        case ST_OBJECT_TYPE_STR:
            return ST_BOOL(strcmp(object1->value, object2->value) == 0);
        case ST_OBJECT_TYPE_BOOL:
            return ST_BOOL(st_object_get_bool(object1) == st_object_get_bool(object2));
        case ST_OBJECT_TYPE_INT:
            return ST_BOOL(st_object_get_int(object1) == st_object_get_int(object2));
        case ST_OBJECT_TYPE_LONG:
            return ST_BOOL(st_object_get_long(object1) == st_object_get_long(object2));
        case ST_OBJECT_TYPE_FLOAT:
            return ST_BOOL(st_object_get_float(object1) == st_object_get_float(object2));
        case ST_OBJECT_TYPE_ARRAY:
        case ST_OBJECT_TYPE_DICT:
            return ST_BOOL(object1->value == object2->value);
        default:
            return FALSE;
    }
}
