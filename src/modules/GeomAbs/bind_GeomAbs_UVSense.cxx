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
#include <GeomAbs_UVSense.hxx>

void bind_GeomAbs_UVSense(py::module &mod){

py::enum_<GeomAbs_UVSense>(mod, "GeomAbs_UVSense", "This enumeration is used in the class RectangularTrimmedSurface to compare the orientation of the basic surface and the orientation of the trimmed surface and in the class ElementarySurface to know the direction of parametrization by comparison with the default construction mode.")
	.value("GeomAbs_SameUV", GeomAbs_UVSense::GeomAbs_SameUV)
	.value("GeomAbs_SameU", GeomAbs_UVSense::GeomAbs_SameU)
	.value("GeomAbs_SameV", GeomAbs_UVSense::GeomAbs_SameV)
	.value("GeomAbs_OppositeUV", GeomAbs_UVSense::GeomAbs_OppositeUV)
	.export_values();


}