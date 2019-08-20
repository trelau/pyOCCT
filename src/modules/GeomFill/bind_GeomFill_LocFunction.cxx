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
#include <Standard_Handle.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <gp_Mat.hxx>
#include <GeomFill_LocFunction.hxx>

void bind_GeomFill_LocFunction(py::module &mod){

py::class_<GeomFill_LocFunction, std::unique_ptr<GeomFill_LocFunction>> cls_GeomFill_LocFunction(mod, "GeomFill_LocFunction", "None");

// Constructors
cls_GeomFill_LocFunction.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Law"));

// Fields

// Methods
// cls_GeomFill_LocFunction.def_static("operator new_", (void * (*)(size_t)) &GeomFill_LocFunction::operator new, "None", py::arg("theSize"));
// cls_GeomFill_LocFunction.def_static("operator delete_", (void (*)(void *)) &GeomFill_LocFunction::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_LocFunction::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_LocFunction.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_LocFunction::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_LocFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_LocFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_LocFunction.def("D0", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("D1", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("D2", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("DN", [](GeomFill_LocFunction &self, const Standard_Real Param, const Standard_Real First, const Standard_Real Last, const Standard_Integer Order, Standard_Real & Result, Standard_Integer & Ier){ self.DN(Param, First, Last, Order, Result, Ier); return std::tuple<Standard_Real &, Standard_Integer &>(Result, Ier); }, "None", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Order"), py::arg("Result"), py::arg("Ier"));

// Enums

}