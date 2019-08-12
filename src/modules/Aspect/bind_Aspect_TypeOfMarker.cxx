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
#include <Aspect_TypeOfMarker.hxx>

void bind_Aspect_TypeOfMarker(py::module &mod){

py::enum_<Aspect_TypeOfMarker>(mod, "Aspect_TypeOfMarker", "Definition of types of markers")
	.value("Aspect_TOM_EMPTY", Aspect_TypeOfMarker::Aspect_TOM_EMPTY)
	.value("Aspect_TOM_POINT", Aspect_TypeOfMarker::Aspect_TOM_POINT)
	.value("Aspect_TOM_PLUS", Aspect_TypeOfMarker::Aspect_TOM_PLUS)
	.value("Aspect_TOM_STAR", Aspect_TypeOfMarker::Aspect_TOM_STAR)
	.value("Aspect_TOM_X", Aspect_TypeOfMarker::Aspect_TOM_X)
	.value("Aspect_TOM_O", Aspect_TypeOfMarker::Aspect_TOM_O)
	.value("Aspect_TOM_O_POINT", Aspect_TypeOfMarker::Aspect_TOM_O_POINT)
	.value("Aspect_TOM_O_PLUS", Aspect_TypeOfMarker::Aspect_TOM_O_PLUS)
	.value("Aspect_TOM_O_STAR", Aspect_TypeOfMarker::Aspect_TOM_O_STAR)
	.value("Aspect_TOM_O_X", Aspect_TypeOfMarker::Aspect_TOM_O_X)
	.value("Aspect_TOM_RING1", Aspect_TypeOfMarker::Aspect_TOM_RING1)
	.value("Aspect_TOM_RING2", Aspect_TypeOfMarker::Aspect_TOM_RING2)
	.value("Aspect_TOM_RING3", Aspect_TypeOfMarker::Aspect_TOM_RING3)
	.value("Aspect_TOM_BALL", Aspect_TypeOfMarker::Aspect_TOM_BALL)
	.value("Aspect_TOM_USERDEFINED", Aspect_TypeOfMarker::Aspect_TOM_USERDEFINED)
	.export_values();


}