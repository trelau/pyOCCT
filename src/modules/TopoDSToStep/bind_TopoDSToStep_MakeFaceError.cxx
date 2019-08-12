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
#include <TopoDSToStep_MakeFaceError.hxx>

void bind_TopoDSToStep_MakeFaceError(py::module &mod){

py::enum_<TopoDSToStep_MakeFaceError>(mod, "TopoDSToStep_MakeFaceError", "None")
	.value("TopoDSToStep_FaceDone", TopoDSToStep_MakeFaceError::TopoDSToStep_FaceDone)
	.value("TopoDSToStep_InfiniteFace", TopoDSToStep_MakeFaceError::TopoDSToStep_InfiniteFace)
	.value("TopoDSToStep_NonManifoldFace", TopoDSToStep_MakeFaceError::TopoDSToStep_NonManifoldFace)
	.value("TopoDSToStep_NoWireMapped", TopoDSToStep_MakeFaceError::TopoDSToStep_NoWireMapped)
	.value("TopoDSToStep_FaceOther", TopoDSToStep_MakeFaceError::TopoDSToStep_FaceOther)
	.export_values();


}