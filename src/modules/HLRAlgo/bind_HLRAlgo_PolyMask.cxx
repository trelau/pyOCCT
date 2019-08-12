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
#include <HLRAlgo_PolyMask.hxx>

void bind_HLRAlgo_PolyMask(py::module &mod){

py::enum_<HLRAlgo_PolyMask>(mod, "HLRAlgo_PolyMask", "None")
	.value("HLRAlgo_PolyMask_EMskOutLin1", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin1)
	.value("HLRAlgo_PolyMask_EMskOutLin2", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin2)
	.value("HLRAlgo_PolyMask_EMskOutLin3", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskOutLin3)
	.value("HLRAlgo_PolyMask_EMskGrALin1", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin1)
	.value("HLRAlgo_PolyMask_EMskGrALin2", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin2)
	.value("HLRAlgo_PolyMask_EMskGrALin3", HLRAlgo_PolyMask::HLRAlgo_PolyMask_EMskGrALin3)
	.value("HLRAlgo_PolyMask_FMskBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskBack)
	.value("HLRAlgo_PolyMask_FMskSide", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskSide)
	.value("HLRAlgo_PolyMask_FMskHiding", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskHiding)
	.value("HLRAlgo_PolyMask_FMskFlat", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskFlat)
	.value("HLRAlgo_PolyMask_FMskOnOutL", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskOnOutL)
	.value("HLRAlgo_PolyMask_FMskOrBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskOrBack)
	.value("HLRAlgo_PolyMask_FMskFrBack", HLRAlgo_PolyMask::HLRAlgo_PolyMask_FMskFrBack)
	.export_values();


}