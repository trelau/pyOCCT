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


def is_netgen_available():
    import OCCT
    PY_EXT = '.pyd' if sys.platform == 'win32' else '.so'
    smesh_path = os.path.join(OCCT.__path__[0], 'NETGENPlugin' + PY_EXT)
    return os.path.exists(smesh_path)


@pytest.mark.skipif(not is_netgen_available(), reason='NETGEN was not built')
def test_Box3D():
    """
    Test a tetrahedral mesh of a simple solid box
    """
    from OCCT.BRepPrimAPI import BRepPrimAPI_MakeBox
    from OCCT.NETGENPlugin import (NETGENPlugin_SimpleHypothesis_3D,
                                NETGENPlugin_NETGEN_2D3D)
    from OCCT.SMESH import SMESH_Gen

    box = BRepPrimAPI_MakeBox(10, 10, 10).Solid()

    gen = SMESH_Gen()
    mesh = gen.CreateMesh(0, True)

    hyp = NETGENPlugin_SimpleHypothesis_3D(0, 0, gen)
    hyp.SetLocalLength(1.0)

    NETGENPlugin_NETGEN_2D3D(1, 0, gen)

    mesh.ShapeToMesh(box)
    mesh.AddHypothesis(box, 0)
    mesh.AddHypothesis(box, 1)

    success = gen.Compute(mesh, box)
    assert success

    assert mesh.NbTetras() == 4767
    assert mesh.NbNodes() == 1189

