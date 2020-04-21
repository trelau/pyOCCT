"""
Copyright (c) 2016 Andrew Walker

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""

from binder import clang

__all__ = ['monkeypatch_type', 'monkeypatch_cursor', 'CymbalException']


def find_libclang_function(function_):
    return getattr(clang.cindex.conf.lib, function_)


class CymbalException(Exception):
    def __init__(self, msg):
        super(CymbalException, self).__init__(msg)


def monkeypatch_helper(classtype, name, library_function, args, result):
    if hasattr(classtype, name):
        raise CymbalException(
            'failed to add method, %s is already available' % name)
    f = find_libclang_function(library_function)
    f.argtypes = args
    f.restype = result

    def impl(*args):
        return f(*args)

    setattr(classtype, name, impl)


def monkeypatch_type(method_name, library_function, args, result):
    monkeypatch_helper(clang.cindex.Type, method_name, library_function, args,
                       result)


def monkeypatch_cursor(method_name, library_function, args, result):
    monkeypatch_helper(clang.cindex.Cursor, method_name, library_function,
                       args, result)
