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
#include <BRepOffset_MakeSimpleOffset.hxx>

void bind_BRepOffsetSimple_Status(py::module &mod){

py::enum_<BRepOffsetSimple_Status>(mod, "BRepOffsetSimple_Status", "None")
	.value("BRepOffsetSimple_OK", BRepOffsetSimple_Status::BRepOffsetSimple_OK)
	.value("BRepOffsetSimple_NullInputShape", BRepOffsetSimple_Status::BRepOffsetSimple_NullInputShape)
	.value("BRepOffsetSimple_ErrorOffsetComputation", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorOffsetComputation)
	.value("BRepOffsetSimple_ErrorWallFaceComputation", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorWallFaceComputation)
	.value("BRepOffsetSimple_ErrorInvalidNbShells", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorInvalidNbShells)
	.value("BRepOffsetSimple_ErrorNonClosedShell", BRepOffsetSimple_Status::BRepOffsetSimple_ErrorNonClosedShell)
	.export_values();


}