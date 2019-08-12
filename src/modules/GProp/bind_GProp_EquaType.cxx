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
#include <GProp_EquaType.hxx>

void bind_GProp_EquaType(py::module &mod){

py::enum_<GProp_EquaType>(mod, "GProp_EquaType", "None")
	.value("GProp_Plane", GProp_EquaType::GProp_Plane)
	.value("GProp_Line", GProp_EquaType::GProp_Line)
	.value("GProp_Point", GProp_EquaType::GProp_Point)
	.value("GProp_Space", GProp_EquaType::GProp_Space)
	.value("GProp_None", GProp_EquaType::GProp_None)
	.export_values();


}