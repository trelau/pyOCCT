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
#include <Interface_CheckStatus.hxx>

void bind_Interface_CheckStatus(py::module &mod){

py::enum_<Interface_CheckStatus>(mod, "Interface_CheckStatus", "Classifies checks OK : check is empty Warning : Warning, no Fail Fail : Fail Others to query : Any : any status Message : Warning/Fail NoFail : Warning/OK")
	.value("Interface_CheckOK", Interface_CheckStatus::Interface_CheckOK)
	.value("Interface_CheckWarning", Interface_CheckStatus::Interface_CheckWarning)
	.value("Interface_CheckFail", Interface_CheckStatus::Interface_CheckFail)
	.value("Interface_CheckAny", Interface_CheckStatus::Interface_CheckAny)
	.value("Interface_CheckMessage", Interface_CheckStatus::Interface_CheckMessage)
	.value("Interface_CheckNoFail", Interface_CheckStatus::Interface_CheckNoFail)
	.export_values();


}