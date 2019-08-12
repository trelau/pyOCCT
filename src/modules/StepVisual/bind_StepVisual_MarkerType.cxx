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
#include <StepVisual_MarkerType.hxx>

void bind_StepVisual_MarkerType(py::module &mod){

py::enum_<StepVisual_MarkerType>(mod, "StepVisual_MarkerType", "None")
	.value("StepVisual_mtDot", StepVisual_MarkerType::StepVisual_mtDot)
	.value("StepVisual_mtX", StepVisual_MarkerType::StepVisual_mtX)
	.value("StepVisual_mtPlus", StepVisual_MarkerType::StepVisual_mtPlus)
	.value("StepVisual_mtAsterisk", StepVisual_MarkerType::StepVisual_mtAsterisk)
	.value("StepVisual_mtRing", StepVisual_MarkerType::StepVisual_mtRing)
	.value("StepVisual_mtSquare", StepVisual_MarkerType::StepVisual_mtSquare)
	.value("StepVisual_mtTriangle", StepVisual_MarkerType::StepVisual_mtTriangle)
	.export_values();


}