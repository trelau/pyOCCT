"""
https://tracker.dev.opencascade.org/view.php?id=22702
"""

import time

import display
import exchange
from OCCT.BOPAlgo import BOPAlgo_Options
from OCCT.BRepAlgoAPI import BRepAlgoAPI_Common

cheese = exchange.read_step('./models/cheese.stp')
planes = exchange.read_step('./models/planes.stp')

v = display.Viewer()
v.add(cheese, planes)
v.start()
v.clear()

# Basic operation takes about 32 seconds
print('Starting Boolean operation...')
start = time.time()
BRepAlgoAPI_Common(cheese, planes)
print('Complete in ', time.time() - start, ' seconds.')

# Run in parallel. Should take 10 to 11 seconds on 4 cores
BOPAlgo_Options.SetParallelMode_(True)
print('Starting Boolean operation...')
start = time.time()
bop = BRepAlgoAPI_Common(cheese, planes)
print('Complete in ', time.time() - start, ' seconds.')

v.add(bop.Shape())
v.start()
