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

import display
import exchange
from OCCT.NETGENPlugin import (NETGENPlugin_Hypothesis_2D,
                               NETGENPlugin_NETGEN_2D)
from OCCT.SMESH import SMESH_Gen, SMESH_Mesh

# fn = './models/lhs_wing.brep'
# fn = './models/wingbox.brep'
# fn = './models/fuselage_structure.brep'
fn = './models/wing_body.brep'

shape = exchange.read_brep(fn)

gen = SMESH_Gen()

mesh = gen.CreateMesh(0, True)

assert isinstance(mesh, SMESH_Mesh)

mesh.ShapeToMesh(shape)

hyp2d = NETGENPlugin_Hypothesis_2D(0, 0, gen)
hyp2d.SetQuadAllowed(True)
hyp2d.SetMaxSize(4)
hyp2d.SetMinSize(4)
hyp2d.SetSurfaceCurvature(False)

alg2d = NETGENPlugin_NETGEN_2D(1, 0, gen)

mesh.AddHypothesis(mesh.GetShapeToMesh(), 0)
mesh.AddHypothesis(mesh.GetShapeToMesh(), 1)

print('Computing mesh...')
done = gen.Compute(mesh, mesh.GetShapeToMesh())
assert bool
print('done.')

v = display.Viewer()
v.add(mesh)
v.start()
