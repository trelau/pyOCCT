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
#include <ChFiDS_State.hxx>

void bind_ChFiDS_State(py::module &mod){

py::enum_<ChFiDS_State>(mod, "ChFiDS_State", "This enum describe the different kinds of extremities of a fillet. OnSame, Ondiff and AllSame are particular cases of BreakPoint for a corner with 3 edges and three faces : - AllSame means that the three concavities are on the same side of the Shape, - OnDiff means that the edge of the fillet has a concave side different than the two other edges, - OnSame means that the edge of the fillet has a concave side different than one of the two other edges and identical to the third edge.")
	.value("ChFiDS_OnSame", ChFiDS_State::ChFiDS_OnSame)
	.value("ChFiDS_OnDiff", ChFiDS_State::ChFiDS_OnDiff)
	.value("ChFiDS_AllSame", ChFiDS_State::ChFiDS_AllSame)
	.value("ChFiDS_BreakPoint", ChFiDS_State::ChFiDS_BreakPoint)
	.value("ChFiDS_FreeBoundary", ChFiDS_State::ChFiDS_FreeBoundary)
	.value("ChFiDS_Closed", ChFiDS_State::ChFiDS_Closed)
	.value("ChFiDS_Tangent", ChFiDS_State::ChFiDS_Tangent)
	.export_values();


}