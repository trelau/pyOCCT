# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC
# Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import os
import sys
import pytest
import subprocess
import OCCT


PY_EXT = '.pyd' if sys.platform == 'win32' else '.so'
OCCT_PATH = OCCT.__path__[0]

def get_modules():
    files = sorted(os.listdir(OCCT_PATH))
    modules = [p.split(".")[0] for p in files if p.endswith(PY_EXT)]

    if sys.platform == 'win32':
        excludes = ('Cocoa', 'Xw')
    elif sys.platform == 'darwin':
        excludes = ('WNT', 'Xw')
    else:
        excludes = ('WNT', 'Cocoa')

    return [m for m in modules if m not in excludes]


def debug_module(mod):
    """
    Print debug info on why the import failed
    """
    mod_path = os.path.join(OCCT_PATH, f'{mod}{PY_EXT}')
    if sys.platform == 'win32':
        run_cmd(f'dumpbin /dependents {mod_path}')
    else:
        run_cmd(f'ldd {mod_path}')
        #out1 = run_cmd(f'nm -gD {mod_path}', verbose=False)
        #out2 = run_cmd(f'nm -gDC {mod_path}', verbose=False)
        #for a, b in zip(out1.splitlines(), out2.splitlines()):
            #print(a)
            # Print demangled output
            #if a != b:
                #print(b)
                #print("")

def run_cmd(cmd, grep=None, exclude=None, verbose=True):
    if verbose:
        print(cmd)
    output = subprocess.check_output(cmd.split()).decode()
    if verbose:
        for line in output.splitlines():
            if not grep or grep in line:
                if exclude and exclude in line:
                    continue
                print(line)
    return output


ALL_MODULES = get_modules()
@pytest.mark.parametrize('mod', ALL_MODULES)
def test_module(mod):
    try:
        __import__(f'OCCT.{mod}')
    except ImportError as e:
        print(e)
        debug_module(mod)
        if 'IVtk' in mod:
            pytest.xfail("IVtk errors are ignored")
        raise
