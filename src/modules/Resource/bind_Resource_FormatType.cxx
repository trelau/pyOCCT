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
#include <Resource_FormatType.hxx>

void bind_Resource_FormatType(py::module &mod){

py::enum_<Resource_FormatType>(mod, "Resource_FormatType", "List of non ASCII format types which may be converted into the Unicode 16 bits format type. Use the functions provided by the Resource_Unicode class to convert a string from one of these non ASCII format to Unicode, and vice versa.")
	.value("Resource_SJIS", Resource_FormatType::Resource_SJIS)
	.value("Resource_EUC", Resource_FormatType::Resource_EUC)
	.value("Resource_ANSI", Resource_FormatType::Resource_ANSI)
	.value("Resource_GB", Resource_FormatType::Resource_GB)
	.export_values();


}