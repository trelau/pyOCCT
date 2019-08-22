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
#include <Standard_TypeDef.hxx>
#include <NCollection_UtfString.hxx>

void bind_NCollection_UtfStringTool(py::module &mod){

py::class_<NCollection_UtfStringTool> cls_NCollection_UtfStringTool(mod, "NCollection_UtfStringTool", "Auxiliary convertion tool.");

// Constructors
cls_NCollection_UtfStringTool.def(py::init<>());

// Fields

// Methods
cls_NCollection_UtfStringTool.def("FromLocale", (wchar_t * (NCollection_UtfStringTool::*)(const char *)) &NCollection_UtfStringTool::FromLocale, "Convert the string from current locale into UNICODE (wide characters) using system APIs. Returned pointer will be released by this tool.", py::arg("theString"));
cls_NCollection_UtfStringTool.def_static("ToLocale_", (bool (*)(const wchar_t *, char *, const Standard_Integer)) &NCollection_UtfStringTool::ToLocale, "Convert the UNICODE (wide characters) string into locale using system APIs.", py::arg("theWideString"), py::arg("theBuffer"), py::arg("theSizeBytes"));

// Enums

}