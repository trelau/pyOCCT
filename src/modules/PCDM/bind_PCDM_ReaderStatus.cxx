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
#include <PCDM_ReaderStatus.hxx>

void bind_PCDM_ReaderStatus(py::module &mod){

py::enum_<PCDM_ReaderStatus>(mod, "PCDM_ReaderStatus", "None")
	.value("PCDM_RS_OK", PCDM_ReaderStatus::PCDM_RS_OK)
	.value("PCDM_RS_NoDriver", PCDM_ReaderStatus::PCDM_RS_NoDriver)
	.value("PCDM_RS_UnknownFileDriver", PCDM_ReaderStatus::PCDM_RS_UnknownFileDriver)
	.value("PCDM_RS_OpenError", PCDM_ReaderStatus::PCDM_RS_OpenError)
	.value("PCDM_RS_NoVersion", PCDM_ReaderStatus::PCDM_RS_NoVersion)
	.value("PCDM_RS_NoSchema", PCDM_ReaderStatus::PCDM_RS_NoSchema)
	.value("PCDM_RS_NoDocument", PCDM_ReaderStatus::PCDM_RS_NoDocument)
	.value("PCDM_RS_ExtensionFailure", PCDM_ReaderStatus::PCDM_RS_ExtensionFailure)
	.value("PCDM_RS_WrongStreamMode", PCDM_ReaderStatus::PCDM_RS_WrongStreamMode)
	.value("PCDM_RS_FormatFailure", PCDM_ReaderStatus::PCDM_RS_FormatFailure)
	.value("PCDM_RS_TypeFailure", PCDM_ReaderStatus::PCDM_RS_TypeFailure)
	.value("PCDM_RS_TypeNotFoundInSchema", PCDM_ReaderStatus::PCDM_RS_TypeNotFoundInSchema)
	.value("PCDM_RS_UnrecognizedFileFormat", PCDM_ReaderStatus::PCDM_RS_UnrecognizedFileFormat)
	.value("PCDM_RS_MakeFailure", PCDM_ReaderStatus::PCDM_RS_MakeFailure)
	.value("PCDM_RS_PermissionDenied", PCDM_ReaderStatus::PCDM_RS_PermissionDenied)
	.value("PCDM_RS_DriverFailure", PCDM_ReaderStatus::PCDM_RS_DriverFailure)
	.value("PCDM_RS_AlreadyRetrievedAndModified", PCDM_ReaderStatus::PCDM_RS_AlreadyRetrievedAndModified)
	.value("PCDM_RS_AlreadyRetrieved", PCDM_ReaderStatus::PCDM_RS_AlreadyRetrieved)
	.value("PCDM_RS_UnknownDocument", PCDM_ReaderStatus::PCDM_RS_UnknownDocument)
	.value("PCDM_RS_WrongResource", PCDM_ReaderStatus::PCDM_RS_WrongResource)
	.value("PCDM_RS_ReaderException", PCDM_ReaderStatus::PCDM_RS_ReaderException)
	.value("PCDM_RS_NoModel", PCDM_ReaderStatus::PCDM_RS_NoModel)
	.export_values();


}