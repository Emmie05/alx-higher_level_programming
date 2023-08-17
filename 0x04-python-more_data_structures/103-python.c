#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        printf("[*] Python list info\n");
        printf("[.] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *element = PyList_GetItem(p, i);
        const char *typeName = Py_TYPE(element)->tp_name;

        printf("Element %zd: ", i);

        if (PyBytes_Check(element)) {
            printf("bytes\n");
            printf("[.] bytes object info\n");
            printf("  size: %zd\n", PyBytes_GET_SIZE(element));

            printf("  trying string: %.*s\n", (int)(PyBytes_GET_SIZE(element) > 10 ? 10 : PyBytes_GET_SIZE(element)), PyBytes_AS_STRING(element));
            printf("  first %zd bytes: ", (PyBytes_GET_SIZE(element) > 10 ? 10 : PyBytes_GET_SIZE(element)));
            for (int j = 0; j < (PyBytes_GET_SIZE(element) > 10 ? 10 : PyBytes_GET_SIZE(element)); j++) {
                printf("%02x ", (unsigned char)PyBytes_AS_STRING(element)[j]);
            }
            printf("\n");
        } else {
            printf("%s\n", typeName);
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n");
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_GET_SIZE(p);

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", size);

    printf("  trying string: %.*s\n", (int)(size > 10 ? 10 : size), PyBytes_AS_STRING(p));
    printf("  first %zd bytes: ", (size > 10 ? 10 : size));
    for (int j = 0; j < (size > 10 ? 10 : size); j++) {
        printf("%02x ", (unsigned char)PyBytes_AS_STRING(p)[j]);
    }
    printf("\n");
}
