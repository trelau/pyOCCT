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
#include <StepFEA_EnumeratedDegreeOfFreedom.hxx>

void bind_StepFEA_EnumeratedDegreeOfFreedom(py::module &mod){

py::enum_<StepFEA_EnumeratedDegreeOfFreedom>(mod, "StepFEA_EnumeratedDegreeOfFreedom", "None")
	.value("StepFEA_XTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_XTranslation)
	.value("StepFEA_YTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_YTranslation)
	.value("StepFEA_ZTranslation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_ZTranslation)
	.value("StepFEA_XRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_XRotation)
	.value("StepFEA_YRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_YRotation)
	.value("StepFEA_ZRotation", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_ZRotation)
	.value("StepFEA_Warp", StepFEA_EnumeratedDegreeOfFreedom::StepFEA_Warp)
	.export_values();


}