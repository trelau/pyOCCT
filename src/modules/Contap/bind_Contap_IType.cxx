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
#include <Contap_IType.hxx>

void bind_Contap_IType(py::module &mod){

py::enum_<Contap_IType>(mod, "Contap_IType", "None")
	.value("Contap_Lin", Contap_IType::Contap_Lin)
	.value("Contap_Circle", Contap_IType::Contap_Circle)
	.value("Contap_Walking", Contap_IType::Contap_Walking)
	.value("Contap_Restriction", Contap_IType::Contap_Restriction)
	.export_values();


}