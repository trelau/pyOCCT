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
#include <BRepBuilderAPI_FaceError.hxx>

void bind_BRepBuilderAPI_FaceError(py::module &mod){

py::enum_<BRepBuilderAPI_FaceError>(mod, "BRepBuilderAPI_FaceError", "Indicates the outcome of the construction of a face, i.e. whether it has been successful or not, as explained below: - BRepBuilderAPI_FaceDone No error occurred. The face is correctly built. - BRepBuilderAPI_NoFace No initialization of the algorithm; only an empty constructor was used. - BRepBuilderAPI_NotPlanar No surface was given and the wire was not planar. - BRepBuilderAPI_CurveProjectionFailed Not used so far. - BRepBuilderAPI_ParametersOutOfRange The parameters given to limit the surface are out of its bounds.")
	.value("BRepBuilderAPI_FaceDone", BRepBuilderAPI_FaceError::BRepBuilderAPI_FaceDone)
	.value("BRepBuilderAPI_NoFace", BRepBuilderAPI_FaceError::BRepBuilderAPI_NoFace)
	.value("BRepBuilderAPI_NotPlanar", BRepBuilderAPI_FaceError::BRepBuilderAPI_NotPlanar)
	.value("BRepBuilderAPI_CurveProjectionFailed", BRepBuilderAPI_FaceError::BRepBuilderAPI_CurveProjectionFailed)
	.value("BRepBuilderAPI_ParametersOutOfRange", BRepBuilderAPI_FaceError::BRepBuilderAPI_ParametersOutOfRange)
	.export_values();


}