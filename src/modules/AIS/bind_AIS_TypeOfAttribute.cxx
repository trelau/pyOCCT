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
#include <AIS_TypeOfAttribute.hxx>

void bind_AIS_TypeOfAttribute(py::module &mod){

py::enum_<AIS_TypeOfAttribute>(mod, "AIS_TypeOfAttribute", "None")
	.value("AIS_TOA_Line", AIS_TypeOfAttribute::AIS_TOA_Line)
	.value("AIS_TOA_Dimension", AIS_TypeOfAttribute::AIS_TOA_Dimension)
	.value("AIS_TOA_Wire", AIS_TypeOfAttribute::AIS_TOA_Wire)
	.value("AIS_TOA_Plane", AIS_TypeOfAttribute::AIS_TOA_Plane)
	.value("AIS_TOA_Vector", AIS_TypeOfAttribute::AIS_TOA_Vector)
	.value("AIS_TOA_UIso", AIS_TypeOfAttribute::AIS_TOA_UIso)
	.value("AIS_TOA_VIso", AIS_TypeOfAttribute::AIS_TOA_VIso)
	.value("AIS_TOA_Free", AIS_TypeOfAttribute::AIS_TOA_Free)
	.value("AIS_TOA_UnFree", AIS_TypeOfAttribute::AIS_TOA_UnFree)
	.value("AIS_TOA_Section", AIS_TypeOfAttribute::AIS_TOA_Section)
	.value("AIS_TOA_Hidden", AIS_TypeOfAttribute::AIS_TOA_Hidden)
	.value("AIS_TOA_Seen", AIS_TypeOfAttribute::AIS_TOA_Seen)
	.value("AIS_TOA_FirstAxis", AIS_TypeOfAttribute::AIS_TOA_FirstAxis)
	.value("AIS_TOA_SecondAxis", AIS_TypeOfAttribute::AIS_TOA_SecondAxis)
	.value("AIS_TOA_ThirdAxis", AIS_TypeOfAttribute::AIS_TOA_ThirdAxis)
	.export_values();


}