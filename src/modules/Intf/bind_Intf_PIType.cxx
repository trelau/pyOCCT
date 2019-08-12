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
#include <Intf_PIType.hxx>

void bind_Intf_PIType(py::module &mod){

py::enum_<Intf_PIType>(mod, "Intf_PIType", "Describes the different intersection point types for this application.")
	.value("Intf_EXTERNAL", Intf_PIType::Intf_EXTERNAL)
	.value("Intf_FACE", Intf_PIType::Intf_FACE)
	.value("Intf_EDGE", Intf_PIType::Intf_EDGE)
	.value("Intf_VERTEX", Intf_PIType::Intf_VERTEX)
	.export_values();


}