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
#include <VrmlData_ErrorStatus.hxx>

void bind_VrmlData_ErrorStatus(py::module &mod){

py::enum_<VrmlData_ErrorStatus>(mod, "VrmlData_ErrorStatus", "Status of read/write or other operation.")
	.value("VrmlData_StatusOK", VrmlData_ErrorStatus::VrmlData_StatusOK)
	.value("VrmlData_EmptyData", VrmlData_ErrorStatus::VrmlData_EmptyData)
	.value("VrmlData_UnrecoverableError", VrmlData_ErrorStatus::VrmlData_UnrecoverableError)
	.value("VrmlData_GeneralError", VrmlData_ErrorStatus::VrmlData_GeneralError)
	.value("VrmlData_EndOfFile", VrmlData_ErrorStatus::VrmlData_EndOfFile)
	.value("VrmlData_NotVrmlFile", VrmlData_ErrorStatus::VrmlData_NotVrmlFile)
	.value("VrmlData_CannotOpenFile", VrmlData_ErrorStatus::VrmlData_CannotOpenFile)
	.value("VrmlData_VrmlFormatError", VrmlData_ErrorStatus::VrmlData_VrmlFormatError)
	.value("VrmlData_NumericInputError", VrmlData_ErrorStatus::VrmlData_NumericInputError)
	.value("VrmlData_IrrelevantNumber", VrmlData_ErrorStatus::VrmlData_IrrelevantNumber)
	.value("VrmlData_BooleanInputError", VrmlData_ErrorStatus::VrmlData_BooleanInputError)
	.value("VrmlData_StringInputError", VrmlData_ErrorStatus::VrmlData_StringInputError)
	.value("VrmlData_NodeNameUnknown", VrmlData_ErrorStatus::VrmlData_NodeNameUnknown)
	.value("VrmlData_NonPositiveSize", VrmlData_ErrorStatus::VrmlData_NonPositiveSize)
	.value("VrmlData_ReadUnknownNode", VrmlData_ErrorStatus::VrmlData_ReadUnknownNode)
	.value("VrmlData_NonSupportedFeature", VrmlData_ErrorStatus::VrmlData_NonSupportedFeature)
	.value("VrmlData_OutputStreamUndefined", VrmlData_ErrorStatus::VrmlData_OutputStreamUndefined)
	.value("VrmlData_NotImplemented", VrmlData_ErrorStatus::VrmlData_NotImplemented)
	.export_values();


}