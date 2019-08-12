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
#include <Storage_Error.hxx>

void bind_Storage_Error(py::module &mod){

py::enum_<Storage_Error>(mod, "Storage_Error", "Error codes returned by the ErrorStatus function on a Storage_Data set of data during a storage or retrieval operation : - Storage_VSOk : no problem has been detected - Storage_VSOpenError : an error has occurred when opening the driver - Storage_VSModeError : the driver has not been opened in the correct mode - Storage_VSCloseError : an error has occurred when closing the driver - Storage_VSAlreadyOpen : the driver is already open - Storage_VSNotOpen : the driver is not open - Storage_VSSectionNotFound : a section has not been found in the driver - Storage_VSWriteError : an error occurred when writing the driver - Storage_VSFormatError : the file format is wrong - Storage_VSUnknownType : a type is not known from the schema - Storage_VSTypeMismatch : trying to read a wrong type - Storage_VSInternalError : an internal error has been detected - Storage_VSExtCharParityError : an error has occurred while reading 16 bit characte")
	.value("Storage_VSOk", Storage_Error::Storage_VSOk)
	.value("Storage_VSOpenError", Storage_Error::Storage_VSOpenError)
	.value("Storage_VSModeError", Storage_Error::Storage_VSModeError)
	.value("Storage_VSCloseError", Storage_Error::Storage_VSCloseError)
	.value("Storage_VSAlreadyOpen", Storage_Error::Storage_VSAlreadyOpen)
	.value("Storage_VSNotOpen", Storage_Error::Storage_VSNotOpen)
	.value("Storage_VSSectionNotFound", Storage_Error::Storage_VSSectionNotFound)
	.value("Storage_VSWriteError", Storage_Error::Storage_VSWriteError)
	.value("Storage_VSFormatError", Storage_Error::Storage_VSFormatError)
	.value("Storage_VSUnknownType", Storage_Error::Storage_VSUnknownType)
	.value("Storage_VSTypeMismatch", Storage_Error::Storage_VSTypeMismatch)
	.value("Storage_VSInternalError", Storage_Error::Storage_VSInternalError)
	.value("Storage_VSExtCharParityError", Storage_Error::Storage_VSExtCharParityError)
	.value("Storage_VSWrongFileDriver", Storage_Error::Storage_VSWrongFileDriver)
	.export_values();


}