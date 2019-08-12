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
#include <MoniTool_ValueType.hxx>

void bind_MoniTool_ValueType(py::module &mod){

py::enum_<MoniTool_ValueType>(mod, "MoniTool_ValueType", "None")
	.value("MoniTool_ValueMisc", MoniTool_ValueType::MoniTool_ValueMisc)
	.value("MoniTool_ValueInteger", MoniTool_ValueType::MoniTool_ValueInteger)
	.value("MoniTool_ValueReal", MoniTool_ValueType::MoniTool_ValueReal)
	.value("MoniTool_ValueIdent", MoniTool_ValueType::MoniTool_ValueIdent)
	.value("MoniTool_ValueVoid", MoniTool_ValueType::MoniTool_ValueVoid)
	.value("MoniTool_ValueText", MoniTool_ValueType::MoniTool_ValueText)
	.value("MoniTool_ValueEnum", MoniTool_ValueType::MoniTool_ValueEnum)
	.value("MoniTool_ValueLogical", MoniTool_ValueType::MoniTool_ValueLogical)
	.value("MoniTool_ValueSub", MoniTool_ValueType::MoniTool_ValueSub)
	.value("MoniTool_ValueHexa", MoniTool_ValueType::MoniTool_ValueHexa)
	.value("MoniTool_ValueBinary", MoniTool_ValueType::MoniTool_ValueBinary)
	.export_values();


}