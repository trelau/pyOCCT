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
#include <GeomFill_Trihedron.hxx>

void bind_GeomFill_Trihedron(py::module &mod){

py::enum_<GeomFill_Trihedron>(mod, "GeomFill_Trihedron", "None")
	.value("GeomFill_IsCorrectedFrenet", GeomFill_Trihedron::GeomFill_IsCorrectedFrenet)
	.value("GeomFill_IsFixed", GeomFill_Trihedron::GeomFill_IsFixed)
	.value("GeomFill_IsFrenet", GeomFill_Trihedron::GeomFill_IsFrenet)
	.value("GeomFill_IsConstantNormal", GeomFill_Trihedron::GeomFill_IsConstantNormal)
	.value("GeomFill_IsDarboux", GeomFill_Trihedron::GeomFill_IsDarboux)
	.value("GeomFill_IsGuideAC", GeomFill_Trihedron::GeomFill_IsGuideAC)
	.value("GeomFill_IsGuidePlan", GeomFill_Trihedron::GeomFill_IsGuidePlan)
	.value("GeomFill_IsGuideACWithContact", GeomFill_Trihedron::GeomFill_IsGuideACWithContact)
	.value("GeomFill_IsGuidePlanWithContact", GeomFill_Trihedron::GeomFill_IsGuidePlanWithContact)
	.value("GeomFill_IsDiscreteTrihedron", GeomFill_Trihedron::GeomFill_IsDiscreteTrihedron)
	.export_values();


}