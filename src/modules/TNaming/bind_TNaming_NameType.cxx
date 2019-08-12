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
#include <TNaming_NameType.hxx>

void bind_TNaming_NameType(py::module &mod){

py::enum_<TNaming_NameType>(mod, "TNaming_NameType", "to store naming characteristcs")
	.value("TNaming_UNKNOWN", TNaming_NameType::TNaming_UNKNOWN)
	.value("TNaming_IDENTITY", TNaming_NameType::TNaming_IDENTITY)
	.value("TNaming_MODIFUNTIL", TNaming_NameType::TNaming_MODIFUNTIL)
	.value("TNaming_GENERATION", TNaming_NameType::TNaming_GENERATION)
	.value("TNaming_INTERSECTION", TNaming_NameType::TNaming_INTERSECTION)
	.value("TNaming_UNION", TNaming_NameType::TNaming_UNION)
	.value("TNaming_SUBSTRACTION", TNaming_NameType::TNaming_SUBSTRACTION)
	.value("TNaming_CONSTSHAPE", TNaming_NameType::TNaming_CONSTSHAPE)
	.value("TNaming_FILTERBYNEIGHBOURGS", TNaming_NameType::TNaming_FILTERBYNEIGHBOURGS)
	.value("TNaming_ORIENTATION", TNaming_NameType::TNaming_ORIENTATION)
	.value("TNaming_WIREIN", TNaming_NameType::TNaming_WIREIN)
	.value("TNaming_SHELLIN", TNaming_NameType::TNaming_SHELLIN)
	.export_values();


}