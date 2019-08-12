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
#include <BRepBuilderAPI_ShellError.hxx>

void bind_BRepBuilderAPI_ShellError(py::module &mod){

py::enum_<BRepBuilderAPI_ShellError>(mod, "BRepBuilderAPI_ShellError", "Indicates the outcome of the construction of a face, i.e. whether it is successful or not, as explained below: - BRepBuilderAPI_ShellDone No error occurred. The shell is correctly built. - BRepBuilderAPI_EmptyShell No initialization of the algorithm: only an empty constructor was used. - BRepBuilderAPI_DisconnectedShell not yet used - BRepBuilderAPI_ShellParametersOutOfRange The parameters given to limit the surface are out of its bounds.")
	.value("BRepBuilderAPI_ShellDone", BRepBuilderAPI_ShellError::BRepBuilderAPI_ShellDone)
	.value("BRepBuilderAPI_EmptyShell", BRepBuilderAPI_ShellError::BRepBuilderAPI_EmptyShell)
	.value("BRepBuilderAPI_DisconnectedShell", BRepBuilderAPI_ShellError::BRepBuilderAPI_DisconnectedShell)
	.value("BRepBuilderAPI_ShellParametersOutOfRange", BRepBuilderAPI_ShellError::BRepBuilderAPI_ShellParametersOutOfRange)
	.export_values();


}