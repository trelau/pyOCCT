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
#include <StepGeom_TrimmingPreference.hxx>

void bind_StepGeom_TrimmingPreference(py::module &mod){

py::enum_<StepGeom_TrimmingPreference>(mod, "StepGeom_TrimmingPreference", "None")
	.value("StepGeom_tpCartesian", StepGeom_TrimmingPreference::StepGeom_tpCartesian)
	.value("StepGeom_tpParameter", StepGeom_TrimmingPreference::StepGeom_tpParameter)
	.value("StepGeom_tpUnspecified", StepGeom_TrimmingPreference::StepGeom_tpUnspecified)
	.export_values();


}