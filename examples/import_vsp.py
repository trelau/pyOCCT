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
import random
import time

from OCCT.Boolean import FuseShapes
from OCCT.Exchange import ImportVSP
from OCCT.Visualization.WxViewer import ViewerWx

# Select version of OpenVSP used to export the model. Versions greater than
# 3.5.0 seem to decrease OpenCASCADE performance. Surface parameterization was
# changed in OpenVSP, but not entirely sure that is the root cause.
fn = './models/F-16_OpenVSP3.5.0.stp'
vsp = ImportVSP(fn)

v = ViewerWx()
for s in vsp.solids:
    r = random.randint(0, 256)
    g = random.randint(0, 256)
    b = random.randint(0, 256)
    v.display_shape(s, (r, g, b))
v.start()
v.clear()

# Attempt to fuse all the solids together. Pick one solid for the argument and
# the others will be tools (you need at least one of each). Not sure how
# selecting different arguments and tools impacts the results, if at all.
arg = vsp.solids[0]
tools = vsp.solids[1:]

fuse = FuseShapes()
fuse.set_args([arg])
fuse.set_tools(tools)
print('Fusing solids...')
start = time.time()
fuse.build()
print('Complete in ', time.time() - start, ' seconds.')

v.display_shape(fuse.shape, (0.5, 0.5, 0.5), transparency=0.5)
v.start()
