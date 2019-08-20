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
#include <Quantity_ColorHasher.hxx>
#include <MeshVS_ColorHasher.hxx>

void bind_MeshVS_ColorHasher(py::module &mod){

py::class_<Quantity_ColorHasher, std::unique_ptr<Quantity_ColorHasher>> cls_MeshVS_ColorHasher(mod, "MeshVS_ColorHasher", "Hasher of Quantity_Color.", py::module_local());

// Constructors

// Fields

// Methods
cls_MeshVS_ColorHasher.def_static("HashCode_", (Standard_Integer (*)(const Quantity_Color &, const Standard_Integer)) &Quantity_ColorHasher::HashCode, "Returns hash code for the given color.", py::arg("theColor"), py::arg("theUpper"));
cls_MeshVS_ColorHasher.def_static("IsEqual_", (Standard_Boolean (*)(const Quantity_Color &, const Quantity_Color &)) &Quantity_ColorHasher::IsEqual, "Returns true if two colors are equal.", py::arg("theColor1"), py::arg("theColor2"));

// Enums

}