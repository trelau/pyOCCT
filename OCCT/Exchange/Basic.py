# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018 Laughlin Research, LLC
# Copyright (C) 2019-2020 Trevor Laughlin and pyOCCT contributors
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
from OCCT.IGESControl import IGESControl_Reader, IGESControl_Writer
from OCCT.STEPControl import (STEPControl_Reader, STEPControl_Writer,
                              STEPControl_AsIs)
from OCCT.TopoDS import TopoDS_Shape

__all__ = ['ExchangeBasic']


class ExchangeBasic(object):
    """
    Static methods for simple data exchange.
    """

    @staticmethod
    def read_brep(fn):
        """
        Read a BREP file and return as a single shape.

        :param str fn: Filename.

        :return: The shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        shape = TopoDS_Shape()
        builder = BRep_Builder()
        BRepTools.Read_(shape, fn, builder)
        return shape

    @staticmethod
    def write_brep(shape, fn):
        """
        Write a BREP file using the shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape to export.
        :param str fn: Filename.

        :return: ``True`` if successful, ``False`` otherwise.
        :rtype: bool
        """
        return BRepTools.Write_(shape, fn)

    @staticmethod
    def read_iges(fn):
        """
        Read an IGES file and return as a single shape.

        :param str fn: Filename.

        :return: The shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        reader = IGESControl_Reader()
        reader.ReadFile(fn)
        reader.TransferRoots()
        return reader.OneShape()

    @staticmethod
    def write_iges(shape, fn):
        """
        Write an IGES file using the shape.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape to export.
        :param str fn: Filename.

        :return: ``True`` if successful, ``False`` otherwise.
        :rtype: bool
        """
        writer = IGESControl_Writer()
        writer.AddShape(shape)
        return writer.Write(fn)

    @staticmethod
    def read_step(fn):
        """
        Read a STEP file and return as a single shape.

        :param str fn: Filename.

        :return: The shape.
        :rtype: OCCT.TopoDS.TopoDS_Shape
        """
        reader = STEPControl_Reader()
        reader.ReadFile(fn)
        reader.TransferRoots()
        return reader.OneShape()

    @staticmethod
    def write_step(shape, fn):
        """
        Write a STEP file using the shape using AP203 schema.

        :param OCCT.TopoDS.TopoDS_Shape shape: The shape to export.
        :param str fn: Filename.

        :return: Write status.
        :rtype: OCCT.IFSelect.IFSelect_ReturnStatus
        """
        writer = STEPControl_Writer()
        writer.Transfer(shape, STEPControl_AsIs)
        return writer.Write(fn)
