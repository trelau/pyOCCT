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
#include <GeomAbs_SurfaceType.hxx>

void bind_GeomAbs_SurfaceType(py::module &mod){

py::enum_<GeomAbs_SurfaceType>(mod, "GeomAbs_SurfaceType", "None")
	.value("GeomAbs_Plane", GeomAbs_SurfaceType::GeomAbs_Plane)
	.value("GeomAbs_Cylinder", GeomAbs_SurfaceType::GeomAbs_Cylinder)
	.value("GeomAbs_Cone", GeomAbs_SurfaceType::GeomAbs_Cone)
	.value("GeomAbs_Sphere", GeomAbs_SurfaceType::GeomAbs_Sphere)
	.value("GeomAbs_Torus", GeomAbs_SurfaceType::GeomAbs_Torus)
	.value("GeomAbs_BezierSurface", GeomAbs_SurfaceType::GeomAbs_BezierSurface)
	.value("GeomAbs_BSplineSurface", GeomAbs_SurfaceType::GeomAbs_BSplineSurface)
	.value("GeomAbs_SurfaceOfRevolution", GeomAbs_SurfaceType::GeomAbs_SurfaceOfRevolution)
	.value("GeomAbs_SurfaceOfExtrusion", GeomAbs_SurfaceType::GeomAbs_SurfaceOfExtrusion)
	.value("GeomAbs_OffsetSurface", GeomAbs_SurfaceType::GeomAbs_OffsetSurface)
	.value("GeomAbs_OtherSurface", GeomAbs_SurfaceType::GeomAbs_OtherSurface)
	.export_values();


}