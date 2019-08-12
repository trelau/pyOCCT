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
#include <AIS_DisplayStatus.hxx>

void bind_AIS_DisplayStatus(py::module &mod){

py::enum_<AIS_DisplayStatus>(mod, "AIS_DisplayStatus", "To give the display status of an Interactive Object. This will be one of the following: - DS_Displayed: the Interactive Object is displayed in the main viewer; - DS_Erased: the Interactive Object is hidden in main viewer; - DS_Temporary: the Interactive Object is temporarily displayed; - DS_None: the Interactive Object is nowhere displayed.")
	.value("AIS_DS_Displayed", AIS_DisplayStatus::AIS_DS_Displayed)
	.value("AIS_DS_Erased", AIS_DisplayStatus::AIS_DS_Erased)
	.value("AIS_DS_Temporary", AIS_DisplayStatus::AIS_DS_Temporary)
	.value("AIS_DS_None", AIS_DisplayStatus::AIS_DS_None)
	.export_values();


}