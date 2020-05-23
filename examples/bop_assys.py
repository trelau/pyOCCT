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
from OCCT.BRepAlgoAPI import BRepAlgoAPI_Fuse
from OCCT.TopTools import TopTools_ListOfShape

from OCCT.Exchange import ExchangeBasic
from OCCT.Visualization.WxViewer import ViewerWx

fn = './models/wing_assy.brep'
wing_assy = ExchangeBasic.read_brep(fn)

fn = './models/fuse_assy.brep'
fuse_assy = ExchangeBasic.read_brep(fn)

BOPAlgo_Options.SetParallelMode_(True)
bop = BRepAlgoAPI_Fuse()
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

v = ViewerWx()
v.add(bop.Shape())
v.start()
