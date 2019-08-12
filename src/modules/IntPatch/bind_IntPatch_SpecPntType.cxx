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
#include <IntPatch_SpecPntType.hxx>

void bind_IntPatch_SpecPntType(py::module &mod){

py::enum_<IntPatch_SpecPntType>(mod, "IntPatch_SpecPntType", "This enum describe the different kinds of special (singular) points of Surface-Surface intersection algorithm. Such as pole of sphere, apex of cone, point on U- or V-seam etc.")
	.value("IntPatch_SPntNone", IntPatch_SpecPntType::IntPatch_SPntNone)
	.value("IntPatch_SPntSeamU", IntPatch_SpecPntType::IntPatch_SPntSeamU)
	.value("IntPatch_SPntSeamV", IntPatch_SpecPntType::IntPatch_SPntSeamV)
	.value("IntPatch_SPntSeamUV", IntPatch_SpecPntType::IntPatch_SPntSeamUV)
	.value("IntPatch_SPntPoleSeamU", IntPatch_SpecPntType::IntPatch_SPntPoleSeamU)
	.value("IntPatch_SPntPole", IntPatch_SpecPntType::IntPatch_SPntPole)
	.export_values();


}