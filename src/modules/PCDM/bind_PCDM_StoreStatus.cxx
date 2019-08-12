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
#include <PCDM_StoreStatus.hxx>

void bind_PCDM_StoreStatus(py::module &mod){

py::enum_<PCDM_StoreStatus>(mod, "PCDM_StoreStatus", "None")
	.value("PCDM_SS_OK", PCDM_StoreStatus::PCDM_SS_OK)
	.value("PCDM_SS_DriverFailure", PCDM_StoreStatus::PCDM_SS_DriverFailure)
	.value("PCDM_SS_WriteFailure", PCDM_StoreStatus::PCDM_SS_WriteFailure)
	.value("PCDM_SS_Failure", PCDM_StoreStatus::PCDM_SS_Failure)
	.value("PCDM_SS_Doc_IsNull", PCDM_StoreStatus::PCDM_SS_Doc_IsNull)
	.value("PCDM_SS_No_Obj", PCDM_StoreStatus::PCDM_SS_No_Obj)
	.value("PCDM_SS_Info_Section_Error", PCDM_StoreStatus::PCDM_SS_Info_Section_Error)
	.export_values();


}