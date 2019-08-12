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
#include <AIS_KindOfRelation.hxx>

void bind_AIS_KindOfRelation(py::module &mod){

py::enum_<AIS_KindOfRelation>(mod, "AIS_KindOfRelation", "None")
	.value("AIS_KOR_NONE", AIS_KindOfRelation::AIS_KOR_NONE)
	.value("AIS_KOR_CONCENTRIC", AIS_KindOfRelation::AIS_KOR_CONCENTRIC)
	.value("AIS_KOR_EQUALDISTANCE", AIS_KindOfRelation::AIS_KOR_EQUALDISTANCE)
	.value("AIS_KOR_EQUALRADIUS", AIS_KindOfRelation::AIS_KOR_EQUALRADIUS)
	.value("AIS_KOR_FIX", AIS_KindOfRelation::AIS_KOR_FIX)
	.value("AIS_KOR_IDENTIC", AIS_KindOfRelation::AIS_KOR_IDENTIC)
	.value("AIS_KOR_OFFSET", AIS_KindOfRelation::AIS_KOR_OFFSET)
	.value("AIS_KOR_PARALLEL", AIS_KindOfRelation::AIS_KOR_PARALLEL)
	.value("AIS_KOR_PERPENDICULAR", AIS_KindOfRelation::AIS_KOR_PERPENDICULAR)
	.value("AIS_KOR_TANGENT", AIS_KindOfRelation::AIS_KOR_TANGENT)
	.value("AIS_KOR_SYMMETRIC", AIS_KindOfRelation::AIS_KOR_SYMMETRIC)
	.export_values();


}