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
#include <Prs3d_TypeOfHighlight.hxx>

void bind_Prs3d_TypeOfHighlight(py::module &mod){

py::enum_<Prs3d_TypeOfHighlight>(mod, "Prs3d_TypeOfHighlight", "Type of highlighting to apply specific style.")
	.value("Prs3d_TypeOfHighlight_None", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_None)
	.value("Prs3d_TypeOfHighlight_Selected", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_Selected)
	.value("Prs3d_TypeOfHighlight_Dynamic", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_Dynamic)
	.value("Prs3d_TypeOfHighlight_LocalSelected", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_LocalSelected)
	.value("Prs3d_TypeOfHighlight_LocalDynamic", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_LocalDynamic)
	.value("Prs3d_TypeOfHighlight_SubIntensity", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_SubIntensity)
	.value("Prs3d_TypeOfHighlight_NB", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_NB)
	.export_values();


}