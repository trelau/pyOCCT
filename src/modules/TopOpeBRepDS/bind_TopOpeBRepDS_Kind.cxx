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
#include <TopOpeBRepDS_Kind.hxx>

void bind_TopOpeBRepDS_Kind(py::module &mod){

py::enum_<TopOpeBRepDS_Kind>(mod, "TopOpeBRepDS_Kind", "different types of objects in DataStructure")
	.value("TopOpeBRepDS_POINT", TopOpeBRepDS_Kind::TopOpeBRepDS_POINT)
	.value("TopOpeBRepDS_CURVE", TopOpeBRepDS_Kind::TopOpeBRepDS_CURVE)
	.value("TopOpeBRepDS_SURFACE", TopOpeBRepDS_Kind::TopOpeBRepDS_SURFACE)
	.value("TopOpeBRepDS_VERTEX", TopOpeBRepDS_Kind::TopOpeBRepDS_VERTEX)
	.value("TopOpeBRepDS_EDGE", TopOpeBRepDS_Kind::TopOpeBRepDS_EDGE)
	.value("TopOpeBRepDS_WIRE", TopOpeBRepDS_Kind::TopOpeBRepDS_WIRE)
	.value("TopOpeBRepDS_FACE", TopOpeBRepDS_Kind::TopOpeBRepDS_FACE)
	.value("TopOpeBRepDS_SHELL", TopOpeBRepDS_Kind::TopOpeBRepDS_SHELL)
	.value("TopOpeBRepDS_SOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_SOLID)
	.value("TopOpeBRepDS_COMPSOLID", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPSOLID)
	.value("TopOpeBRepDS_COMPOUND", TopOpeBRepDS_Kind::TopOpeBRepDS_COMPOUND)
	.value("TopOpeBRepDS_UNKNOWN", TopOpeBRepDS_Kind::TopOpeBRepDS_UNKNOWN)
	.export_values();


}