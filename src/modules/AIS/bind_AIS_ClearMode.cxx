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
#include <AIS_ClearMode.hxx>

void bind_AIS_ClearMode(py::module &mod){

py::enum_<AIS_ClearMode>(mod, "AIS_ClearMode", "Declares which entities in an opened local context are to be cleared of mode settings. Temporary graphic presentations such as those for sub-shapes, for example, are only created for the selection process. By means of these enumerations, they can be cleared from local context.")
	.value("AIS_CM_All", AIS_ClearMode::AIS_CM_All)
	.value("AIS_CM_Interactive", AIS_ClearMode::AIS_CM_Interactive)
	.value("AIS_CM_Filters", AIS_ClearMode::AIS_CM_Filters)
	.value("AIS_CM_StandardModes", AIS_ClearMode::AIS_CM_StandardModes)
	.value("AIS_CM_TemporaryShapePrs", AIS_ClearMode::AIS_CM_TemporaryShapePrs)
	.export_values();


}