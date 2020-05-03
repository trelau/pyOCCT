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
import os
import sys
import pytest


ALL_MODULES = [
    'BaseTraceCollector',
    'BasicsGenericDestructor',
    'Driver',
    'DriverDAT',
    'DriverGMF',
    'DriverSTL',
    'DriverUNV',
    'LocalTraceBufferPool',
    'NETGENPlugin',
    'SMDS',
    'SMDSAbs',
    'SMESH',
    'SMESHDS',
    'StdMeshers',
    'Utils',
]


def is_smesh_built():
    import OCCT
    PY_EXT = '.pyd' if sys.platform == 'win32' else '.so'
    smesh_path = os.path.join(OCCT.__path__[0], 'SMESH' + PY_EXT)
    return os.path.exists(smesh_path)


@pytest.mark.skipif(not is_smesh_built(), reason="SMESH was not built")
@pytest.mark.parametrize('mod', ALL_MODULES)
def test_module(mod):
    try:
        __import__(f'OCCT.{mod}')
    except ImportError as e:
        print(e)
        raise
