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
#include <BRepBuilderAPI_WireError.hxx>

void bind_BRepBuilderAPI_WireError(py::module &mod){

py::enum_<BRepBuilderAPI_WireError>(mod, "BRepBuilderAPI_WireError", "Indicates the outcome of wire construction, i.e. whether it is successful or not, as explained below: - BRepBuilderAPI_WireDone No error occurred. The wire is correctly built. - BRepBuilderAPI_EmptyWire No initialization of the algorithm. Only an empty constructor was used. - BRepBuilderAPI_DisconnectedWire The last edge which you attempted to add was not connected to the wire. - BRepBuilderAPI_NonManifoldWire The wire with some singularity.")
	.value("BRepBuilderAPI_WireDone", BRepBuilderAPI_WireError::BRepBuilderAPI_WireDone)
	.value("BRepBuilderAPI_EmptyWire", BRepBuilderAPI_WireError::BRepBuilderAPI_EmptyWire)
	.value("BRepBuilderAPI_DisconnectedWire", BRepBuilderAPI_WireError::BRepBuilderAPI_DisconnectedWire)
	.value("BRepBuilderAPI_NonManifoldWire", BRepBuilderAPI_WireError::BRepBuilderAPI_NonManifoldWire)
	.export_values();


}