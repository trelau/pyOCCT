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
#include <Geom2dToIGES_Geom2dEntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dToIGES_Geom2dCurve.hxx>

void bind_Geom2dToIGES_Geom2dCurve(py::module &mod){

py::class_<Geom2dToIGES_Geom2dCurve, std::unique_ptr<Geom2dToIGES_Geom2dCurve, Deleter<Geom2dToIGES_Geom2dCurve>>, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dCurve(mod, "Geom2dToIGES_Geom2dCurve", "This class implements the transfer of the Curve Entity from Geom2d To IGES. These can be : Curve . BoundedCurve * BSplineCurve * BezierCurve * TrimmedCurve . Conic * Circle * Ellipse * Hyperbloa * Line * Parabola . OffsetCurve");

// Constructors
cls_Geom2dToIGES_Geom2dCurve.def(py::init<>());
cls_Geom2dToIGES_Geom2dCurve.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Fields

// Methods
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dCurve.def("Transfer2dCurve", (opencascade::handle<IGESData_IGESEntity> (Geom2dToIGES_Geom2dCurve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &Geom2dToIGES_Geom2dCurve::Transfer2dCurve, "Transfert an Entity from Geom2d to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));

// Enums

}