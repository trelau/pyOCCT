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
#include <IntRes2d_Intersection.hxx>
#include <Standard.hxx>
#include <Bisector_Bisec.hxx>
#include <IntRes2d_Domain.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Bisector_BisecCC.hxx>
#include <Geom2d_Line.hxx>
#include <Bisector_Inter.hxx>

void bind_Bisector_Inter(py::module &mod){

py::class_<Bisector_Inter, std::unique_ptr<Bisector_Inter>, IntRes2d_Intersection> cls_Bisector_Inter(mod, "Bisector_Inter", "Intersection between two <Bisec> from Bisector.");

// Constructors
cls_Bisector_Inter.def(py::init<>());
cls_Bisector_Inter.def(py::init<const Bisector_Bisec &, const IntRes2d_Domain &, const Bisector_Bisec &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"), py::arg("ComunElement"));

// Fields

// Methods
// cls_Bisector_Inter.def_static("operator new_", (void * (*)(size_t)) &Bisector_Inter::operator new, "None", py::arg("theSize"));
// cls_Bisector_Inter.def_static("operator delete_", (void (*)(void *)) &Bisector_Inter::operator delete, "None", py::arg("theAddress"));
// cls_Bisector_Inter.def_static("operator new[]_", (void * (*)(size_t)) &Bisector_Inter::operator new[], "None", py::arg("theSize"));
// cls_Bisector_Inter.def_static("operator delete[]_", (void (*)(void *)) &Bisector_Inter::operator delete[], "None", py::arg("theAddress"));
// cls_Bisector_Inter.def_static("operator new_", (void * (*)(size_t, void *)) &Bisector_Inter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bisector_Inter.def_static("operator delete_", (void (*)(void *, void *)) &Bisector_Inter::operator delete, "None", py::arg(""), py::arg(""));
cls_Bisector_Inter.def("Perform", (void (Bisector_Inter::*)(const Bisector_Bisec &, const IntRes2d_Domain &, const Bisector_Bisec &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Bisector_Inter::Perform, "Intersection between 2 curves. C1 separates the element A and B. C2 separates the elements C et D. If B an C have the same geometry. <ComunElement> Has to be True. It Permits an optimiztion of the computation.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"), py::arg("ComunElement"));

// Enums

}