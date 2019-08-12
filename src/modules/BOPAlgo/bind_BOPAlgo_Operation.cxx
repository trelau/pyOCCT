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
#include <BOPAlgo_Operation.hxx>

void bind_BOPAlgo_Operation(py::module &mod){

py::enum_<BOPAlgo_Operation>(mod, "BOPAlgo_Operation", "None")
	.value("BOPAlgo_COMMON", BOPAlgo_Operation::BOPAlgo_COMMON)
	.value("BOPAlgo_FUSE", BOPAlgo_Operation::BOPAlgo_FUSE)
	.value("BOPAlgo_CUT", BOPAlgo_Operation::BOPAlgo_CUT)
	.value("BOPAlgo_CUT21", BOPAlgo_Operation::BOPAlgo_CUT21)
	.value("BOPAlgo_SECTION", BOPAlgo_Operation::BOPAlgo_SECTION)
	.value("BOPAlgo_UNKNOWN", BOPAlgo_Operation::BOPAlgo_UNKNOWN)
	.export_values();


}