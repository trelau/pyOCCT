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

from OCCT.BRep import BRep_Builder
from OCCT.BRepTools import BRepTools
from OCCT.STEPControl import STEPControl_Reader
from OCCT.TopoDS import TopoDS_Shape


def write_brep(shape, fn):
    """
    Write a BREP file using the shape.
    """
    BRepTools.Write_(shape, fn)


def read_brep(fn):
    """
    Read a BREP file and return the shape.
    """
    shape = TopoDS_Shape()
    builder = BRep_Builder()
    BRepTools.Read_(shape, fn, builder)
    return shape


def read_step(fn):
    """
    Read a STEP file and return the shape.
    """
    reader = STEPControl_Reader()
    reader.ReadFile(fn)
    reader.TransferRoots()
    return reader.OneShape()
