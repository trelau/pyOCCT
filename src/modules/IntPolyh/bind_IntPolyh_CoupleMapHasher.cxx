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
#include <IntPolyh_Couple.hxx>
#include <IntPolyh_CoupleMapHasher.hxx>

void bind_IntPolyh_CoupleMapHasher(py::module &mod){

py::class_<IntPolyh_CoupleMapHasher, std::unique_ptr<IntPolyh_CoupleMapHasher>> cls_IntPolyh_CoupleMapHasher(mod, "IntPolyh_CoupleMapHasher", "None");

// Constructors

// Fields

// Methods
cls_IntPolyh_CoupleMapHasher.def_static("HashCode_", (Standard_Integer (*)(const IntPolyh_Couple &, const Standard_Integer)) &IntPolyh_CoupleMapHasher::HashCode, "None", py::arg("theCouple"), py::arg("Upper"));
cls_IntPolyh_CoupleMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const IntPolyh_Couple &, const IntPolyh_Couple &)) &IntPolyh_CoupleMapHasher::IsEqual, "None", py::arg("theCouple1"), py::arg("theCouple2"));

// Enums

}