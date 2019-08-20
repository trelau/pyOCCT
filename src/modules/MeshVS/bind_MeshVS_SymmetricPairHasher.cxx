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
#include <MeshVS_SymmetricPairHasher.hxx>

void bind_MeshVS_SymmetricPairHasher(py::module &mod){

py::class_<MeshVS_SymmetricPairHasher, std::unique_ptr<MeshVS_SymmetricPairHasher>> cls_MeshVS_SymmetricPairHasher(mod, "MeshVS_SymmetricPairHasher", "Provides symmetric hash methods pair of integers.");

// Constructors

// Fields

// Methods
cls_MeshVS_SymmetricPairHasher.def_static("HashCode_", (Standard_Integer (*)(const MeshVS_NodePair &, const Standard_Integer)) &MeshVS_SymmetricPairHasher::HashCode, "None", py::arg("thePair"), py::arg("theMaxCode"));
cls_MeshVS_SymmetricPairHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MeshVS_NodePair &, const MeshVS_NodePair &)) &MeshVS_SymmetricPairHasher::IsEqual, "None", py::arg("thePair1"), py::arg("thePair2"));

// Enums

}