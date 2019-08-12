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
#include <math_Status.hxx>

void bind_math_Status(py::module &mod){

py::enum_<math_Status>(mod, "math_Status", "None")
	.value("math_OK", math_Status::math_OK)
	.value("math_TooManyIterations", math_Status::math_TooManyIterations)
	.value("math_FunctionError", math_Status::math_FunctionError)
	.value("math_DirectionSearchError", math_Status::math_DirectionSearchError)
	.value("math_NotBracketed", math_Status::math_NotBracketed)
	.export_values();


}