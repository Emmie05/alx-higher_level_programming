#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
    char *string;
    Py_ssize_t size, i, limit;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = ((PyVarObject *)(p))->ob_size;
    string = ((PyBytesObject *)p)->ob_sval;

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", string);

    if (size >= 10)
        limit = 10;
    else
        limit = size + 1;

    printf("  first %ld bytes:", limit);

    for (i = 0; i < limit; i++)
        if (string[i] >= 0)
            printf(" %02x", string[i]);
        else
            printf(" %02x", 256 + string[i]);

    printf("\n");
}

/**
 * print_python_list - Prints basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
    PyListObject *list;
    Py_ssize_t size, i;
    PyObject *obj;

    size = ((PyVarObject *)(p))->ob_size;
    list = (PyListObject *)p;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        obj = ((PyListObject *)p)->ob_item[i];
        printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
        if (PyBytes_Check(obj))
            print_python_bytes(obj);
    }
}
