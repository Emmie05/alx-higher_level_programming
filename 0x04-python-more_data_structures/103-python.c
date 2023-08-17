#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = list->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *element = PyList_GetItem(p, i);
        printf("Element %zd: ", i);

        if (PyBytes_Check(element)) {
            printf("bytes\n");
            printf("[.] bytes object info\n");
            printf("  size: %zd\n", PyBytes_Size(element));

            if (PyBytes_Size(element) > 10) {
                printf("  trying string: %.*s\n", 10, PyBytes_AsString(element));
                printf("  first 11 bytes: ");
                for (int j = 0; j < 11; j++) {
                    printf("%02x ", (unsigned char)PyBytes_AsString(element)[j]);
                }
                printf("\n");
            } else {
                printf("  trying string: %s\n", PyBytes_AsString(element));
                printf("  first %zd bytes: ", PyBytes_Size(element));
                for (int j = 0; j < PyBytes_Size(element); j++) {
                    printf("%02x ", (unsigned char)PyBytes_AsString(element)[j]);
                }
                printf("\n");
            }
        } else if (PyLong_Check(element)) {
            printf("int\n");
        } else if (PyFloat_Check(element)) {
            printf("float\n");
        } else if (PyTuple_Check(element)) {
            printf("tuple\n");
        } else if (PyList_Check(element)) {
            printf("list\n");
        } else if (PyUnicode_Check(element)) {
            printf("str\n");
        } else {
            printf("%s\n", Py_TYPE(element)->tp_name);
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n");
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);

    printf("  trying string: %.*s\n", (int)(size > 10 ? 10 : size), PyBytes_AsString(p));
    printf("  first %zd bytes: ", (size > 10 ? 10 : size));
    for (int j = 0; j < (size > 10 ? 10 : size); j++) {
        printf("%02x ", (unsigned char)PyBytes_AsString(p)[j]);
    }
    printf("\n");
}
