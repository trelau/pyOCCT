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
#include <TDF_Label.hxx>
#include <TDF_LabelMapHasher.hxx>

void bind_TDF_LabelMapHasher(py::module &mod){

py::class_<TDF_LabelMapHasher> cls_TDF_LabelMapHasher(mod, "TDF_LabelMapHasher", "A label hasher for label maps.");

// Constructors

// Fields

// Methods
cls_TDF_LabelMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TDF_Label &, const Standard_Integer)) &TDF_LabelMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("aLab"), py::arg("Upper"));
cls_TDF_LabelMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TDF_Label &, const TDF_Label &)) &TDF_LabelMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("aLab1"), py::arg("aLab2"));

// Enums

}