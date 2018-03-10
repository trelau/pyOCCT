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

import time

from OCCT.BLSURFPlugin import BLSURFPlugin_BLSURF, BLSURFPlugin_Hypothesis
from OCCT.SMESH import SMESH_Gen, SMESH_Mesh

from OCCT.Exchange import ExchangeBasic
from OCCT.Visualization import BasicViewer

# fn = './models/lhs_wing.brep'
# fn = './models/wingbox.brep'
# fn = './models/fuselage_structure.brep'
fn = './models/wing_body.brep'

shape = ExchangeBasic.read_brep(fn)

gen = SMESH_Gen()

mesh = gen.CreateMesh(0, True)

assert isinstance(mesh, SMESH_Mesh)

mesh.ShapeToMesh(shape)

mg_hyp = BLSURFPlugin_Hypothesis(0, 0, gen, True)
mg_alg = BLSURFPlugin_BLSURF(1, 0, gen, True)
mg_hyp.SetPhySize(4)
mg_hyp.SetQuadAllowed(True)

mesh.AddHypothesis(mesh.GetShapeToMesh(), 0)
mesh.AddHypothesis(mesh.GetShapeToMesh(), 1)

print('Computing mesh...')
start = time.time()
done = gen.Compute(mesh, mesh.GetShapeToMesh())
print('done in ', time.time() - start, ' seconds.')

v = BasicViewer()
v.add(mesh)
v.start()
