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
#include <AIS_StatusOfDetection.hxx>

void bind_AIS_StatusOfDetection(py::module &mod){

py::enum_<AIS_StatusOfDetection>(mod, "AIS_StatusOfDetection", "None")
	.value("AIS_SOD_Error", AIS_StatusOfDetection::AIS_SOD_Error)
	.value("AIS_SOD_Nothing", AIS_StatusOfDetection::AIS_SOD_Nothing)
	.value("AIS_SOD_AllBad", AIS_StatusOfDetection::AIS_SOD_AllBad)
	.value("AIS_SOD_Selected", AIS_StatusOfDetection::AIS_SOD_Selected)
	.value("AIS_SOD_OnlyOneDetected", AIS_StatusOfDetection::AIS_SOD_OnlyOneDetected)
	.value("AIS_SOD_OnlyOneGood", AIS_StatusOfDetection::AIS_SOD_OnlyOneGood)
	.value("AIS_SOD_SeveralGood", AIS_StatusOfDetection::AIS_SOD_SeveralGood)
	.export_values();


}