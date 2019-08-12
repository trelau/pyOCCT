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
#include <AIS_KindOfSurface.hxx>

void bind_AIS_KindOfSurface(py::module &mod){

py::enum_<AIS_KindOfSurface>(mod, "AIS_KindOfSurface", "None")
	.value("AIS_KOS_Plane", AIS_KindOfSurface::AIS_KOS_Plane)
	.value("AIS_KOS_Cylinder", AIS_KindOfSurface::AIS_KOS_Cylinder)
	.value("AIS_KOS_Cone", AIS_KindOfSurface::AIS_KOS_Cone)
	.value("AIS_KOS_Sphere", AIS_KindOfSurface::AIS_KOS_Sphere)
	.value("AIS_KOS_Torus", AIS_KindOfSurface::AIS_KOS_Torus)
	.value("AIS_KOS_Revolution", AIS_KindOfSurface::AIS_KOS_Revolution)
	.value("AIS_KOS_Extrusion", AIS_KindOfSurface::AIS_KOS_Extrusion)
	.value("AIS_KOS_OtherSurface", AIS_KindOfSurface::AIS_KOS_OtherSurface)
	.export_values();


}