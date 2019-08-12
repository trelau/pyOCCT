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
#include <Vrml_VertexOrdering.hxx>

void bind_Vrml_VertexOrdering(py::module &mod){

py::enum_<Vrml_VertexOrdering>(mod, "Vrml_VertexOrdering", "None")
	.value("Vrml_UNKNOWN_ORDERING", Vrml_VertexOrdering::Vrml_UNKNOWN_ORDERING)
	.value("Vrml_CLOCKWISE", Vrml_VertexOrdering::Vrml_CLOCKWISE)
	.value("Vrml_COUNTERCLOCKWISE", Vrml_VertexOrdering::Vrml_COUNTERCLOCKWISE)
	.export_values();


}