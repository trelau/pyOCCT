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
#include <IFSelect_PrintFail.hxx>

void bind_IFSelect_PrintFail(py::module &mod){

py::enum_<IFSelect_PrintFail>(mod, "IFSelect_PrintFail", "Indicates whether there will be information on warnings as well as on failures. The terms of this enumeration have the following semantics: - IFSelect_FailOnly gives information on failures only - IFSelect_FailAndWarn gives information on both failures and warnings. used to pilot PrintCheckList")
	.value("IFSelect_FailOnly", IFSelect_PrintFail::IFSelect_FailOnly)
	.value("IFSelect_FailAndWarn", IFSelect_PrintFail::IFSelect_FailAndWarn)
	.export_values();


}