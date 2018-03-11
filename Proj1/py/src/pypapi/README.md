# PyPAPI

[![Build Status](https://travis-ci.org/flozz/pypapi.svg?branch=master)](https://travis-ci.org/flozz/pypapi)
[![PYPI Version](https://img.shields.io/pypi/v/python_papi.svg)](https://pypi.python.org/pypi/python_papi)
[![License](https://img.shields.io/pypi/l/python_papi.svg)](https://flozz.github.io/pypapi/licenses.html)

PyPAPI is a Python binding for the [PAPI (Performance Application Programming
Interface)][libpapi] library. PyPAPI implements the whole PAPI High Level API
and partially the Low Level API.


## Documentation:

* https://flozz.github.io/pypapi/


## Hacking

### Building PyPAPI For Local Development

To work on PyPAPI, you have to build the C library inside the `pypapi` module.
This can be done with the following command:

    python pypapi/papi_build.py

### Generating Documentation

From a virtualenv:

    pip install -r requirements.txt
    python setup.py build_sphinx


[libpapi]: http://icl.cs.utk.edu/papi/index.html


## Changelog

* **5.5.1.3:** Remove .o, .lo and other generated objects from the package
* **5.5.1.2:** Partial bindings for the low level API
* **5.5.1.1:** Adds missing files to build PAPI
* **5.5.1.0:** Initial release (binding for papy 5.5.1)
