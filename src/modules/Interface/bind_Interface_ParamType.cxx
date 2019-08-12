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
#include <Interface_ParamType.hxx>

void bind_Interface_ParamType(py::module &mod){

py::enum_<Interface_ParamType>(mod, "Interface_ParamType", "None")
	.value("Interface_ParamMisc", Interface_ParamType::Interface_ParamMisc)
	.value("Interface_ParamInteger", Interface_ParamType::Interface_ParamInteger)
	.value("Interface_ParamReal", Interface_ParamType::Interface_ParamReal)
	.value("Interface_ParamIdent", Interface_ParamType::Interface_ParamIdent)
	.value("Interface_ParamVoid", Interface_ParamType::Interface_ParamVoid)
	.value("Interface_ParamText", Interface_ParamType::Interface_ParamText)
	.value("Interface_ParamEnum", Interface_ParamType::Interface_ParamEnum)
	.value("Interface_ParamLogical", Interface_ParamType::Interface_ParamLogical)
	.value("Interface_ParamSub", Interface_ParamType::Interface_ParamSub)
	.value("Interface_ParamHexa", Interface_ParamType::Interface_ParamHexa)
	.value("Interface_ParamBinary", Interface_ParamType::Interface_ParamBinary)
	.export_values();


}