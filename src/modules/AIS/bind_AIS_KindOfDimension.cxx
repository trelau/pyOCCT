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
#include <AIS_KindOfDimension.hxx>

void bind_AIS_KindOfDimension(py::module &mod){

py::enum_<AIS_KindOfDimension>(mod, "AIS_KindOfDimension", "Declares the kinds of dimensions needed in the display of Interactive Objects.")
	.value("AIS_KOD_NONE", AIS_KindOfDimension::AIS_KOD_NONE)
	.value("AIS_KOD_LENGTH", AIS_KindOfDimension::AIS_KOD_LENGTH)
	.value("AIS_KOD_PLANEANGLE", AIS_KindOfDimension::AIS_KOD_PLANEANGLE)
	.value("AIS_KOD_SOLIDANGLE", AIS_KindOfDimension::AIS_KOD_SOLIDANGLE)
	.value("AIS_KOD_AREA", AIS_KindOfDimension::AIS_KOD_AREA)
	.value("AIS_KOD_VOLUME", AIS_KindOfDimension::AIS_KOD_VOLUME)
	.value("AIS_KOD_MASS", AIS_KindOfDimension::AIS_KOD_MASS)
	.value("AIS_KOD_TIME", AIS_KindOfDimension::AIS_KOD_TIME)
	.value("AIS_KOD_RADIUS", AIS_KindOfDimension::AIS_KOD_RADIUS)
	.value("AIS_KOD_DIAMETER", AIS_KindOfDimension::AIS_KOD_DIAMETER)
	.value("AIS_KOD_CHAMF2D", AIS_KindOfDimension::AIS_KOD_CHAMF2D)
	.value("AIS_KOD_CHAMF3D", AIS_KindOfDimension::AIS_KOD_CHAMF3D)
	.value("AIS_KOD_OFFSET", AIS_KindOfDimension::AIS_KOD_OFFSET)
	.value("AIS_KOD_ELLIPSERADIUS", AIS_KindOfDimension::AIS_KOD_ELLIPSERADIUS)
	.export_values();


}