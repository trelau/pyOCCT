/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <BRepPrim_Direction.hxx>

void bind_BRepPrim_Direction(py::module &mod){

py::enum_<BRepPrim_Direction>(mod, "BRepPrim_Direction", "None")
	.value("BRepPrim_XMin", BRepPrim_Direction::BRepPrim_XMin)
	.value("BRepPrim_XMax", BRepPrim_Direction::BRepPrim_XMax)
	.value("BRepPrim_YMin", BRepPrim_Direction::BRepPrim_YMin)
	.value("BRepPrim_YMax", BRepPrim_Direction::BRepPrim_YMax)
	.value("BRepPrim_ZMin", BRepPrim_Direction::BRepPrim_ZMin)
	.value("BRepPrim_ZMax", BRepPrim_Direction::BRepPrim_ZMax)
	.export_values();


}