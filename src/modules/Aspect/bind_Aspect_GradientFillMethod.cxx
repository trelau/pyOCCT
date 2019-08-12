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
#include <Aspect_GradientFillMethod.hxx>

void bind_Aspect_GradientFillMethod(py::module &mod){

py::enum_<Aspect_GradientFillMethod>(mod, "Aspect_GradientFillMethod", "Defines the fill methods to write gradient background in a window.")
	.value("Aspect_GFM_NONE", Aspect_GradientFillMethod::Aspect_GFM_NONE)
	.value("Aspect_GFM_HOR", Aspect_GradientFillMethod::Aspect_GFM_HOR)
	.value("Aspect_GFM_VER", Aspect_GradientFillMethod::Aspect_GFM_VER)
	.value("Aspect_GFM_DIAG1", Aspect_GradientFillMethod::Aspect_GFM_DIAG1)
	.value("Aspect_GFM_DIAG2", Aspect_GradientFillMethod::Aspect_GFM_DIAG2)
	.value("Aspect_GFM_CORNER1", Aspect_GradientFillMethod::Aspect_GFM_CORNER1)
	.value("Aspect_GFM_CORNER2", Aspect_GradientFillMethod::Aspect_GFM_CORNER2)
	.value("Aspect_GFM_CORNER3", Aspect_GradientFillMethod::Aspect_GFM_CORNER3)
	.value("Aspect_GFM_CORNER4", Aspect_GradientFillMethod::Aspect_GFM_CORNER4)
	.export_values();


}