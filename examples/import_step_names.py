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
from OCCT.STEPControl import STEPControl_Reader
from OCCT.TopAbs import TopAbs_FACE
from OCCT.TopExp import TopExp_Explorer

from OCCT.Visualization.WxViewer import ViewerWx

# Read the file and get the shape
reader = STEPControl_Reader()
tr = reader.WS().TransferReader()
reader.ReadFile('./models/shape_names.step')
reader.TransferRoots()
shape = reader.OneShape()

gui = ViewerWx()

# Explore the faces of the shape (these are known to be named)
exp = TopExp_Explorer(shape, TopAbs_FACE)
while exp.More():
    rgb = None
    s = exp.Current()
    exp.Next()
    item = tr.EntityFromShapeResult(s, 1)
    name = item.Name().ToCString()
    if name:
        print('Found entity: {}'.format(name))
        rgb = (1, 0, 0)
    gui.add(s, rgb)

gui.start()
