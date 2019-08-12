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
#include <GProp_ValueType.hxx>

void bind_GProp_ValueType(py::module &mod){

py::enum_<GProp_ValueType>(mod, "GProp_ValueType", "Algorithmes :")
	.value("GProp_Mass", GProp_ValueType::GProp_Mass)
	.value("GProp_CenterMassX", GProp_ValueType::GProp_CenterMassX)
	.value("GProp_CenterMassY", GProp_ValueType::GProp_CenterMassY)
	.value("GProp_CenterMassZ", GProp_ValueType::GProp_CenterMassZ)
	.value("GProp_InertiaXX", GProp_ValueType::GProp_InertiaXX)
	.value("GProp_InertiaYY", GProp_ValueType::GProp_InertiaYY)
	.value("GProp_InertiaZZ", GProp_ValueType::GProp_InertiaZZ)
	.value("GProp_InertiaXY", GProp_ValueType::GProp_InertiaXY)
	.value("GProp_InertiaXZ", GProp_ValueType::GProp_InertiaXZ)
	.value("GProp_InertiaYZ", GProp_ValueType::GProp_InertiaYZ)
	.value("GProp_Unknown", GProp_ValueType::GProp_Unknown)
	.export_values();


}