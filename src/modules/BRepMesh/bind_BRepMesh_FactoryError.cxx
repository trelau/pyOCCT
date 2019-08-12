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
#include <BRepMesh_FactoryError.hxx>

void bind_BRepMesh_FactoryError(py::module &mod){

py::enum_<BRepMesh_FactoryError>(mod, "BRepMesh_FactoryError", "None")
	.value("BRepMesh_FE_NOERROR", BRepMesh_FactoryError::BRepMesh_FE_NOERROR)
	.value("BRepMesh_FE_LIBRARYNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_LIBRARYNOTFOUND)
	.value("BRepMesh_FE_FUNCTIONNOTFOUND", BRepMesh_FactoryError::BRepMesh_FE_FUNCTIONNOTFOUND)
	.value("BRepMesh_FE_CANNOTCREATEALGO", BRepMesh_FactoryError::BRepMesh_FE_CANNOTCREATEALGO)
	.export_values();


}