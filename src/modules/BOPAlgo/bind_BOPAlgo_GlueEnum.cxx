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
#include <BOPAlgo_GlueEnum.hxx>

void bind_BOPAlgo_GlueEnum(py::module &mod){

py::enum_<BOPAlgo_GlueEnum>(mod, "BOPAlgo_GlueEnum", "The Enumeration describes an additional option for the algorithms in the Boolean Component such as General Fuse, Boolean operations, Section, Maker Volume, Splitter and Cells Builder algorithms.")
	.value("BOPAlgo_GlueOff", BOPAlgo_GlueEnum::BOPAlgo_GlueOff)
	.value("BOPAlgo_GlueShift", BOPAlgo_GlueEnum::BOPAlgo_GlueShift)
	.value("BOPAlgo_GlueFull", BOPAlgo_GlueEnum::BOPAlgo_GlueFull)
	.export_values();


}