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
#include <PrsMgr_TypeOfPresentation3d.hxx>

void bind_PrsMgr_TypeOfPresentation3d(py::module &mod){

py::enum_<PrsMgr_TypeOfPresentation3d>(mod, "PrsMgr_TypeOfPresentation3d", "To declare the type of presentation as follows - AllView for display involving no recalculation for new projectors (points of view)in hidden line removal mode - ProjectorDependant for display in hidden line removal mode, where every new point of view entails recalculation of the display.")
	.value("PrsMgr_TOP_AllView", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_AllView)
	.value("PrsMgr_TOP_ProjectorDependant", PrsMgr_TypeOfPresentation3d::PrsMgr_TOP_ProjectorDependant)
	.export_values();


}