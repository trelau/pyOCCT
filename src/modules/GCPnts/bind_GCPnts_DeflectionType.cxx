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
#include <GCPnts_DeflectionType.hxx>

void bind_GCPnts_DeflectionType(py::module &mod){

py::enum_<GCPnts_DeflectionType>(mod, "GCPnts_DeflectionType", "None")
	.value("GCPnts_Linear", GCPnts_DeflectionType::GCPnts_Linear)
	.value("GCPnts_Circular", GCPnts_DeflectionType::GCPnts_Circular)
	.value("GCPnts_Curved", GCPnts_DeflectionType::GCPnts_Curved)
	.value("GCPnts_DefComposite", GCPnts_DeflectionType::GCPnts_DefComposite)
	.export_values();


}