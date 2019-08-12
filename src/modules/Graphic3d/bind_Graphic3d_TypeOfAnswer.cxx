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
#include <Graphic3d_TypeOfAnswer.hxx>

void bind_Graphic3d_TypeOfAnswer(py::module &mod){

py::enum_<Graphic3d_TypeOfAnswer>(mod, "Graphic3d_TypeOfAnswer", "The answer of the method AcceptDisplay AcceptDisplay means is it possible to display the specified structure in the specified view ? TOA_YES yes TOA_NO no TOA_COMPUTE yes but we have to compute the representation")
	.value("Graphic3d_TOA_YES", Graphic3d_TypeOfAnswer::Graphic3d_TOA_YES)
	.value("Graphic3d_TOA_NO", Graphic3d_TypeOfAnswer::Graphic3d_TOA_NO)
	.value("Graphic3d_TOA_COMPUTE", Graphic3d_TypeOfAnswer::Graphic3d_TOA_COMPUTE)
	.export_values();


}