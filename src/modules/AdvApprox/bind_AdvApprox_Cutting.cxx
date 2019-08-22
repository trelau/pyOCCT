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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApprox_Cutting.hxx>

void bind_AdvApprox_Cutting(py::module &mod){

py::class_<AdvApprox_Cutting> cls_AdvApprox_Cutting(mod, "AdvApprox_Cutting", "to choose the way of cutting in approximation");

// Fields

// Methods
// cls_AdvApprox_Cutting.def_static("operator new_", (void * (*)(size_t)) &AdvApprox_Cutting::operator new, "None", py::arg("theSize"));
// cls_AdvApprox_Cutting.def_static("operator delete_", (void (*)(void *)) &AdvApprox_Cutting::operator delete, "None", py::arg("theAddress"));
// cls_AdvApprox_Cutting.def_static("operator new[]_", (void * (*)(size_t)) &AdvApprox_Cutting::operator new[], "None", py::arg("theSize"));
// cls_AdvApprox_Cutting.def_static("operator delete[]_", (void (*)(void *)) &AdvApprox_Cutting::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApprox_Cutting.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApprox_Cutting::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApprox_Cutting.def_static("operator delete_", (void (*)(void *, void *)) &AdvApprox_Cutting::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApprox_Cutting.def("Value", [](AdvApprox_Cutting &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "None", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

// Enums

}