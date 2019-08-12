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
#include <AIS_KindOfUnit.hxx>

void bind_AIS_KindOfUnit(py::module &mod){

py::enum_<AIS_KindOfUnit>(mod, "AIS_KindOfUnit", "Declares the type of Interactive Object unit.")
	.value("AIS_TOU_LENGTH", AIS_KindOfUnit::AIS_TOU_LENGTH)
	.value("AIS_TOU_SURFACE", AIS_KindOfUnit::AIS_TOU_SURFACE)
	.value("AIS_TOU_VOLUME", AIS_KindOfUnit::AIS_TOU_VOLUME)
	.value("AIS_TOU_PLANE_ANGLE", AIS_KindOfUnit::AIS_TOU_PLANE_ANGLE)
	.value("AIS_TOU_SOLID_ANGLE", AIS_KindOfUnit::AIS_TOU_SOLID_ANGLE)
	.value("AIS_TOU_MASS", AIS_KindOfUnit::AIS_TOU_MASS)
	.value("AIS_TOU_FORCE", AIS_KindOfUnit::AIS_TOU_FORCE)
	.value("AIS_TOU_TIME", AIS_KindOfUnit::AIS_TOU_TIME)
	.export_values();


}