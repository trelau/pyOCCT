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
import subprocess
import sys

import OCCT

path = OCCT.__path__[0]

# Find names of all modules. Set appropriate extension for platform.
libs = [lib for lib in os.listdir(path) if lib.endswith('.pyd')]

# Try and import the modules and catch any error output.
fout = open('import_errors.txt', 'w')
for lib in libs:
    name = lib.split('.')[0]

    proc = subprocess.Popen(sys.executable, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, stdin=subprocess.PIPE)

    print('Trying to import {}'.format(name))
    cmd = 'import OCCT.{}\n'.format(name).encode()
    _, err = proc.communicate(cmd)
    proc.kill()
    if err:
        print(err)
        fout.write('Failed to import {}\n'.format(name))
        txt = err.decode()
        fout.write(txt)
        fout.write('\n')
fout.close()
