#include "../include/dinamic_array.h"

DynamicArray *new_dynamic_array(int capacity)
{
    DynamicArray *dynamic_array = malloc(sizeof(DynamicArray));

    check_pointer(dynamic_array);

    dynamic_array->arr = malloc(capacity * sizeof(int));
    check_pointer(dynamic_array->arr);
    dynamic_array->size = 0;
    dynamic_array->capacity = capacity;

    return dynamic_array;
}

int da_size(DynamicArray *dynamic_array)
{
    return dynamic_array->size;
}

int da_capacity(DynamicArray *dynamic_array)
{
    return dynamic_array->capacity;
}

bool da_is_empty(DynamicArray *dynamic_array)
{
    return dynamic_array->size == 0;
}

int da_at(DynamicArray *dynamic_array, int index)
{
    if (index < 0 || index >= dynamic_array->size)
    {
        fprintf(stderr, "Error: %s\n", "Index is out of bounds");
        exit(EXIT_FAILURE);
    }

    return *(dynamic_array->arr + index);
}

void da_push(DynamicArray *dynamic_array, int value)
{
    if (da_size(dynamic_array) == dynamic_array->capacity)
    {
        fprintf(stderr, "Error: %s\n", "Dynamic Array is full");
        exit(EXIT_FAILURE);
    }

    *(dynamic_array->arr + dynamic_array->size) = value;
    dynamic_array->size++;
}

void da_insert(DynamicArray *dynamic_array, int index, int value)
{
    if (da_size(dynamic_array) == dynamic_array->capacity)
    {
        fprintf(stderr, "Error: %s\n", "Dynamic Array is full");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index >= dynamic_array->size)
    {
        fprintf(stderr, "Error: %s\n", "Index is out of bounds");
        exit(EXIT_FAILURE);
    }

    for (int i = dynamic_array->size; i >= index; i--)
    {
        *(dynamic_array->arr + i) = *(dynamic_array->arr + i - 1);
    }

    *(dynamic_array->arr + index) = value;

    dynamic_array->size++;
}

void da_prepend(DynamicArray *dynamic_array, int value)
{
    da_insert(dynamic_array, 0, value);
}

int da_pop(DynamicArray *dynamic_array)
{
    int value = *(dynamic_array->arr + (dynamic_array->size - 1));
    dynamic_array->size--;
    return value;
}

void da_delete(DynamicArray *dynamic_array, int index)
{
    if (dynamic_array->size == 0)
    {
        fprintf(stderr, "Error: %s\n", "Dynamic array is empty");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index >= dynamic_array->size)
    {
        fprintf(stderr, "Error: %s\n", "Index is out of bounds");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < dynamic_array->size; i++)
    {
        int target = *(dynamic_array->arr + (i + 1));
        *(dynamic_array->arr + i) = target;
    }

    dynamic_array->size--;
}

void da_remove(DynamicArray *dynamic_array, int value)
{
    check_pointer(dynamic_array);

    int target = da_find(dynamic_array, value);

    if (target < 0)
    {
        return;
    }

    da_delete(dynamic_array, target);
}

int da_find(DynamicArray *dynamic_array, int value)
{
    check_pointer(dynamic_array);

    int target = -1;

    for (int i = 0; i < dynamic_array->size; i++)
    {
        if (*(dynamic_array->arr + i) == value)
        {
            target = i;
            break;
        }
    }

    return target;
}

void print_dynamic_array(DynamicArray *dynamic_array)
{
    check_pointer(dynamic_array);
    printf("Size: %d\n", dynamic_array->size);
    printf("Capacity: %d\n", dynamic_array->capacity);

    printf("Items:\n");
    for (int i = 0; i < dynamic_array->size; ++i)
    {
        printf("%d: %d\n", i, *(dynamic_array->arr + i));
    }

    printf("---------\n");
}

void check_pointer(void *p)
{
    if (p == NULL)
    {
        fprintf(stderr, "Error: %s\n", "Failed to allocate of memory");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    printf("Dynamic array");
    return 0;
}
