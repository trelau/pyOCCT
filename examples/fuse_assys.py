import time

import exchange
from OCCT.BRepAlgoAPI import BRepAlgoAPI_Fuse
from OCCT.TopTools import TopTools_ListOfShape
from display import Viewer

fn = './models/wing_assy.brep'
wing_assy = exchange.read_brep(fn)

fn = './models/fuse_assy.brep'
fuse_assy = exchange.read_brep(fn)

bop = BRepAlgoAPI_Fuse()
bop.SetRunParallel(True)
args = TopTools_ListOfShape()
args.Append(wing_assy)
bop.SetArguments(args)
tools = TopTools_ListOfShape()
tools.Append(fuse_assy)
bop.SetTools(tools)
print('Starting fuse...')
start = time.time()
bop.Build()
print('Complete in ', time.time() - start, ' seconds.')

v = Viewer()
v.add(bop.Shape())
v.start()
