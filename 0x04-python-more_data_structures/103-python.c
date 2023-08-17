#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes = (PyBytesObject *)p;
    Py_ssize_t size = PyBytes_GET_SIZE(p);
    Py_ssize_t i;
    unsigned char *data = (unsigned char *)(bytes->ob_sval);

    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));

    printf("  first 10 bytes:");
    for (i = 0; i < size && i < 10; i++)
        printf(" %02x", data[i]);
    printf("\n");
}

/**
 * print_python_list - Prints basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t i;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        PyObject *item = list->ob_item[i];
        const char *typeName = Py_TYPE(item)->tp_name;

        printf("Element %ld: %s\n", i, typeName);

        if (PyBytes_Check(item))
            print_python_bytes(item);
    }
}

int main(void)
{
    return (0);
}

