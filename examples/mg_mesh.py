import time

import exchange
import graphics
from OCCT.BLSURFPlugin import BLSURFPlugin_BLSURF, BLSURFPlugin_Hypothesis
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

v = graphics.SimpleViewer()
v.display_mesh(mesh)
v.start()
