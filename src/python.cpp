#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "logger.cpp"

static PyObject *
pictlogger_log(PyObject *self, PyObject *args)
{
    char *text;

    if (!PyArg_ParseTuple(args, "s", &text))
        return NULL;
    logt(text);
    return PyLong_FromLong(0);
}

static PyObject *
pictlogger_close(PyObject *self, PyObject *args)
{
    int code = 0;

    PyArg_ParseTuple(args, "i", &code);

    closec(code);
    
    return PyLong_FromLong(0);
}

static PyMethodDef PictLoggerMethods[] = {
    {"log",  pictlogger_log, METH_VARARGS,
     "Log text"},
    {"close",  pictlogger_close, METH_VARARGS,
     "Log text"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef pictlogger = {
    PyModuleDef_HEAD_INIT,
    "pictlogger",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    PictLoggerMethods
};

PyMODINIT_FUNC
PyInit_pictlogger(void)
{
    start();
    logt("PictLogger imported to python");
    return PyModule_Create(&pictlogger);
}