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
#include <TopAbs_State.hxx>

void bind_TopAbs_State(py::module &mod){

py::enum_<TopAbs_State>(mod, "TopAbs_State", "Identifies the position of a vertex or a set of vertices relative to a region of a shape. The figure shown above illustrates the states of vertices found in various parts of the edge relative to the face which it intersects.")
	.value("TopAbs_IN", TopAbs_State::TopAbs_IN)
	.value("TopAbs_OUT", TopAbs_State::TopAbs_OUT)
	.value("TopAbs_ON", TopAbs_State::TopAbs_ON)
	.value("TopAbs_UNKNOWN", TopAbs_State::TopAbs_UNKNOWN)
	.export_values();


}