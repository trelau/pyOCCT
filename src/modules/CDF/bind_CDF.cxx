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
#include <Standard_TypeDef.hxx>
#include <CDF.hxx>

void bind_CDF(py::module &mod){

py::class_<CDF> cls_CDF(mod, "CDF", "None");

// Constructors

// Fields

// Methods
cls_CDF.def_static("GetLicense_", (void (*)(const Standard_Integer)) &CDF::GetLicense, "None", py::arg("anApplicationIdentifier"));
cls_CDF.def_static("IsAvailable_", (Standard_Boolean (*)(const Standard_Integer)) &CDF::IsAvailable, "None", py::arg("anApplicationIdentifier"));

// Enums

}