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
#include <AdvApprox_Cutting.hxx>
#include <Standard.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApprox_PrefCutting.hxx>

void bind_AdvApprox_PrefCutting(py::module &mod){

py::class_<AdvApprox_PrefCutting, std::unique_ptr<AdvApprox_PrefCutting, Deleter<AdvApprox_PrefCutting>>, AdvApprox_Cutting> cls_AdvApprox_PrefCutting(mod, "AdvApprox_PrefCutting", "inherits class Cutting; contains a list of preferential points (di)i if Cutting is necessary in [a,b], we cut at the di nearest from (a+b)/2.");

// Constructors
cls_AdvApprox_PrefCutting.def(py::init<const TColStd_Array1OfReal &>(), py::arg("CutPnts"));

// Fields

// Methods
// cls_AdvApprox_PrefCutting.def_static("operator new_", (void * (*)(size_t)) &AdvApprox_PrefCutting::operator new, "None", py::arg("theSize"));
// cls_AdvApprox_PrefCutting.def_static("operator delete_", (void (*)(void *)) &AdvApprox_PrefCutting::operator delete, "None", py::arg("theAddress"));
// cls_AdvApprox_PrefCutting.def_static("operator new[]_", (void * (*)(size_t)) &AdvApprox_PrefCutting::operator new[], "None", py::arg("theSize"));
// cls_AdvApprox_PrefCutting.def_static("operator delete[]_", (void (*)(void *)) &AdvApprox_PrefCutting::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApprox_PrefCutting.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApprox_PrefCutting::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApprox_PrefCutting.def_static("operator delete_", (void (*)(void *, void *)) &AdvApprox_PrefCutting::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApprox_PrefCutting.def("Value", [](AdvApprox_PrefCutting &self, const Standard_Real a, const Standard_Real b, Standard_Real & cuttingvalue){ Standard_Boolean rv = self.Value(a, b, cuttingvalue); return std::tuple<Standard_Boolean, Standard_Real &>(rv, cuttingvalue); }, "None", py::arg("a"), py::arg("b"), py::arg("cuttingvalue"));

// Enums

}