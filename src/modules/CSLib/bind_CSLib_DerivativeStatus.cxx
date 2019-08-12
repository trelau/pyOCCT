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
#include <CSLib_DerivativeStatus.hxx>

void bind_CSLib_DerivativeStatus(py::module &mod){

py::enum_<CSLib_DerivativeStatus>(mod, "CSLib_DerivativeStatus", "D1uIsNull : ||D1U|| <= Resolution")
	.value("CSLib_Done", CSLib_DerivativeStatus::CSLib_Done)
	.value("CSLib_D1uIsNull", CSLib_DerivativeStatus::CSLib_D1uIsNull)
	.value("CSLib_D1vIsNull", CSLib_DerivativeStatus::CSLib_D1vIsNull)
	.value("CSLib_D1IsNull", CSLib_DerivativeStatus::CSLib_D1IsNull)
	.value("CSLib_D1uD1vRatioIsNull", CSLib_DerivativeStatus::CSLib_D1uD1vRatioIsNull)
	.value("CSLib_D1vD1uRatioIsNull", CSLib_DerivativeStatus::CSLib_D1vD1uRatioIsNull)
	.value("CSLib_D1uIsParallelD1v", CSLib_DerivativeStatus::CSLib_D1uIsParallelD1v)
	.export_values();


}