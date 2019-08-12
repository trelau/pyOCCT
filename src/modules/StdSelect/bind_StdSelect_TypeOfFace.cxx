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
#include <StdSelect_TypeOfFace.hxx>

void bind_StdSelect_TypeOfFace(py::module &mod){

py::enum_<StdSelect_TypeOfFace>(mod, "StdSelect_TypeOfFace", "Provides values for different types of faces. These values are used to filter faces in frameworks inheriting StdSelect_FaceFilter.")
	.value("StdSelect_AnyFace", StdSelect_TypeOfFace::StdSelect_AnyFace)
	.value("StdSelect_Plane", StdSelect_TypeOfFace::StdSelect_Plane)
	.value("StdSelect_Cylinder", StdSelect_TypeOfFace::StdSelect_Cylinder)
	.value("StdSelect_Sphere", StdSelect_TypeOfFace::StdSelect_Sphere)
	.value("StdSelect_Torus", StdSelect_TypeOfFace::StdSelect_Torus)
	.value("StdSelect_Revol", StdSelect_TypeOfFace::StdSelect_Revol)
	.value("StdSelect_Cone", StdSelect_TypeOfFace::StdSelect_Cone)
	.export_values();


}