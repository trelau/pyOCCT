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
#include <CSLib_NormalStatus.hxx>

void bind_CSLib_NormalStatus(py::module &mod){

py::enum_<CSLib_NormalStatus>(mod, "CSLib_NormalStatus", "if N is the normal")
	.value("CSLib_Singular", CSLib_NormalStatus::CSLib_Singular)
	.value("CSLib_Defined", CSLib_NormalStatus::CSLib_Defined)
	.value("CSLib_InfinityOfSolutions", CSLib_NormalStatus::CSLib_InfinityOfSolutions)
	.value("CSLib_D1NuIsNull", CSLib_NormalStatus::CSLib_D1NuIsNull)
	.value("CSLib_D1NvIsNull", CSLib_NormalStatus::CSLib_D1NvIsNull)
	.value("CSLib_D1NIsNull", CSLib_NormalStatus::CSLib_D1NIsNull)
	.value("CSLib_D1NuNvRatioIsNull", CSLib_NormalStatus::CSLib_D1NuNvRatioIsNull)
	.value("CSLib_D1NvNuRatioIsNull", CSLib_NormalStatus::CSLib_D1NvNuRatioIsNull)
	.value("CSLib_D1NuIsParallelD1Nv", CSLib_NormalStatus::CSLib_D1NuIsParallelD1Nv)
	.export_values();


}