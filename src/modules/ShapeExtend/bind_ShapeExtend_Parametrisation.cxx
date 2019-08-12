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
#include <ShapeExtend_Parametrisation.hxx>

void bind_ShapeExtend_Parametrisation(py::module &mod){

py::enum_<ShapeExtend_Parametrisation>(mod, "ShapeExtend_Parametrisation", "Defines kind of global parametrisation on the composite surface each patch of the 1st row and column adds its range, Ui+1 = Ui + URange(i,1), etc. each patch gives range 1.: Ui = i-1, Vj = j-1 uniform parametrisation with global range [0,1]")
	.value("ShapeExtend_Natural", ShapeExtend_Parametrisation::ShapeExtend_Natural)
	.value("ShapeExtend_Uniform", ShapeExtend_Parametrisation::ShapeExtend_Uniform)
	.value("ShapeExtend_Unitary", ShapeExtend_Parametrisation::ShapeExtend_Unitary)
	.export_values();


}