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
#include <XCAFDimTolObjects_DimensionGrade.hxx>

void bind_XCAFDimTolObjects_DimensionGrade(py::module &mod){

py::enum_<XCAFDimTolObjects_DimensionGrade>(mod, "XCAFDimTolObjects_DimensionGrade", "Defines value of grade")
	.value("XCAFDimTolObjects_DimensionGrade_IT01", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT01)
	.value("XCAFDimTolObjects_DimensionGrade_IT0", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT0)
	.value("XCAFDimTolObjects_DimensionGrade_IT1", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT1)
	.value("XCAFDimTolObjects_DimensionGrade_IT2", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT2)
	.value("XCAFDimTolObjects_DimensionGrade_IT3", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT3)
	.value("XCAFDimTolObjects_DimensionGrade_IT4", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT4)
	.value("XCAFDimTolObjects_DimensionGrade_IT5", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT5)
	.value("XCAFDimTolObjects_DimensionGrade_IT6", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT6)
	.value("XCAFDimTolObjects_DimensionGrade_IT7", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT7)
	.value("XCAFDimTolObjects_DimensionGrade_IT8", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT8)
	.value("XCAFDimTolObjects_DimensionGrade_IT9", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT9)
	.value("XCAFDimTolObjects_DimensionGrade_IT10", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT10)
	.value("XCAFDimTolObjects_DimensionGrade_IT11", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT11)
	.value("XCAFDimTolObjects_DimensionGrade_IT12", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT12)
	.value("XCAFDimTolObjects_DimensionGrade_IT13", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT13)
	.value("XCAFDimTolObjects_DimensionGrade_IT14", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT14)
	.value("XCAFDimTolObjects_DimensionGrade_IT15", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT15)
	.value("XCAFDimTolObjects_DimensionGrade_IT16", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT16)
	.value("XCAFDimTolObjects_DimensionGrade_IT17", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT17)
	.value("XCAFDimTolObjects_DimensionGrade_IT18", XCAFDimTolObjects_DimensionGrade::XCAFDimTolObjects_DimensionGrade_IT18)
	.export_values();


}