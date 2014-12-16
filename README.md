This repo is a demonstration of how Python's `ctypes` module is inconsistent
between Linux and Mac OS X. In particular, the module's `._as_parameter_` and
`.from_param()` mechanisms don't appear to work correctly on OS X.

To compile and test the bogus C library `mylib`, simply run `make test`.
Subsequent usage of the Python bindings depends on finding the `libmy.so`
object, so make sure to run `sudo make install && sudo ldconfig` or set
`LD_LIBRARY_PATH` correctly (or `DYLD_LIBRARY_PATH` on Mac).

To test the Python bindings, change to the *mylibpy* directory and run
`./test.py`. On Linux, the output should be identical to the  output of
`make test`. On Mac, the program will crash with a segfault. This is because
when Python calls the C library, it is passing pointers to Python objects
instead of the pointers they encapsulate.

To see a crude solution, go to the *fix* directory and type `make`. You should
then be able to go back to the *mylibpy* directory on  Mac and run `./test.py`
successfully. Type `git diff` to see what changes were made. You're essentially
required to sidestep the most useful features of `ctypes` in order to get it to
work on Mac OS X.

## Update: 16 Dec 2014

Dereferencing the value returned by C library with `c_void_p()` seems to restore
this behavior on OS X. See latest commit.