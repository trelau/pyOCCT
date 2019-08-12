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
#include <AIS_TypeOfDist.hxx>

void bind_AIS_TypeOfDist(py::module &mod){

py::enum_<AIS_TypeOfDist>(mod, "AIS_TypeOfDist", "To declare the type of distance.")
	.value("AIS_TOD_Unknown", AIS_TypeOfDist::AIS_TOD_Unknown)
	.value("AIS_TOD_Horizontal", AIS_TypeOfDist::AIS_TOD_Horizontal)
	.value("AIS_TOD_Vertical", AIS_TypeOfDist::AIS_TOD_Vertical)
	.export_values();


}