"""
https://tracker.dev.opencascade.org/view.php?id=22702
"""
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

from OCCT.BOPAlgo import BOPAlgo_Options
from OCCT.BRepAlgoAPI import BRepAlgoAPI_Common

from OCCT.Exchange import ExchangeBasic
from OCCT.Visualization.WxViewer import ViewerWx

cheese = ExchangeBasic.read_step('./models/cheese.stp')
planes = ExchangeBasic.read_step('./models/planes.stp')

v = ViewerWx()
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
