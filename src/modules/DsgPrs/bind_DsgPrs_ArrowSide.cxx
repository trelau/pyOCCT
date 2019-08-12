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
#include <DsgPrs_ArrowSide.hxx>

void bind_DsgPrs_ArrowSide(py::module &mod){

py::enum_<DsgPrs_ArrowSide>(mod, "DsgPrs_ArrowSide", "Designates how many arrows will be displayed and where they will be displayed in presenting a length.")
	.value("DsgPrs_AS_NONE", DsgPrs_ArrowSide::DsgPrs_AS_NONE)
	.value("DsgPrs_AS_FIRSTAR", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTAR)
	.value("DsgPrs_AS_LASTAR", DsgPrs_ArrowSide::DsgPrs_AS_LASTAR)
	.value("DsgPrs_AS_BOTHAR", DsgPrs_ArrowSide::DsgPrs_AS_BOTHAR)
	.value("DsgPrs_AS_FIRSTPT", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTPT)
	.value("DsgPrs_AS_LASTPT", DsgPrs_ArrowSide::DsgPrs_AS_LASTPT)
	.value("DsgPrs_AS_BOTHPT", DsgPrs_ArrowSide::DsgPrs_AS_BOTHPT)
	.value("DsgPrs_AS_FIRSTAR_LASTPT", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTAR_LASTPT)
	.value("DsgPrs_AS_FIRSTPT_LASTAR", DsgPrs_ArrowSide::DsgPrs_AS_FIRSTPT_LASTAR)
	.export_values();


}