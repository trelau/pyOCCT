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
#include <Intrv_Position.hxx>

void bind_Intrv_Position(py::module &mod){

py::enum_<Intrv_Position>(mod, "Intrv_Position", "None")
	.value("Intrv_Before", Intrv_Position::Intrv_Before)
	.value("Intrv_JustBefore", Intrv_Position::Intrv_JustBefore)
	.value("Intrv_OverlappingAtStart", Intrv_Position::Intrv_OverlappingAtStart)
	.value("Intrv_JustEnclosingAtEnd", Intrv_Position::Intrv_JustEnclosingAtEnd)
	.value("Intrv_Enclosing", Intrv_Position::Intrv_Enclosing)
	.value("Intrv_JustOverlappingAtStart", Intrv_Position::Intrv_JustOverlappingAtStart)
	.value("Intrv_Similar", Intrv_Position::Intrv_Similar)
	.value("Intrv_JustEnclosingAtStart", Intrv_Position::Intrv_JustEnclosingAtStart)
	.value("Intrv_Inside", Intrv_Position::Intrv_Inside)
	.value("Intrv_JustOverlappingAtEnd", Intrv_Position::Intrv_JustOverlappingAtEnd)
	.value("Intrv_OverlappingAtEnd", Intrv_Position::Intrv_OverlappingAtEnd)
	.value("Intrv_JustAfter", Intrv_Position::Intrv_JustAfter)
	.value("Intrv_After", Intrv_Position::Intrv_After)
	.export_values();


}