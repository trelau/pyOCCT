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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Quadric.hxx>
#include <Contap_TFunction.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <Contap_ArcFunction.hxx>

void bind_Contap_ArcFunction(py::module &mod){

py::class_<Contap_ArcFunction, math_FunctionWithDerivative> cls_Contap_ArcFunction(mod, "Contap_ArcFunction", "None");

// Constructors
cls_Contap_ArcFunction.def(py::init<>());

// Fields

// Methods
// cls_Contap_ArcFunction.def_static("operator new_", (void * (*)(size_t)) &Contap_ArcFunction::operator new, "None", py::arg("theSize"));
// cls_Contap_ArcFunction.def_static("operator delete_", (void (*)(void *)) &Contap_ArcFunction::operator delete, "None", py::arg("theAddress"));
// cls_Contap_ArcFunction.def_static("operator new[]_", (void * (*)(size_t)) &Contap_ArcFunction::operator new[], "None", py::arg("theSize"));
// cls_Contap_ArcFunction.def_static("operator delete[]_", (void (*)(void *)) &Contap_ArcFunction::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_ArcFunction.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_ArcFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_ArcFunction.def_static("operator delete_", (void (*)(void *, void *)) &Contap_ArcFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_ArcFunction::Set, "None", py::arg("S"));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Dir &)) &Contap_ArcFunction::Set, "None", py::arg("Direction"));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Dir &, const Standard_Real)) &Contap_ArcFunction::Set, "None", py::arg("Direction"), py::arg("Angle"));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Pnt &)) &Contap_ArcFunction::Set, "None", py::arg("Eye"));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const gp_Pnt &, const Standard_Real)) &Contap_ArcFunction::Set, "None", py::arg("Eye"), py::arg("Angle"));
cls_Contap_ArcFunction.def("Set", (void (Contap_ArcFunction::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_ArcFunction::Set, "None", py::arg("A"));
cls_Contap_ArcFunction.def("Value", [](Contap_ArcFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_Contap_ArcFunction.def("Derivative", [](Contap_ArcFunction &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
cls_Contap_ArcFunction.def("Values", [](Contap_ArcFunction &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_Contap_ArcFunction.def("NbSamples", (Standard_Integer (Contap_ArcFunction::*)() const) &Contap_ArcFunction::NbSamples, "None");
cls_Contap_ArcFunction.def("GetStateNumber", (Standard_Integer (Contap_ArcFunction::*)()) &Contap_ArcFunction::GetStateNumber, "None");
cls_Contap_ArcFunction.def("Valpoint", (const gp_Pnt & (Contap_ArcFunction::*)(const Standard_Integer) const) &Contap_ArcFunction::Valpoint, "None", py::arg("Index"));
cls_Contap_ArcFunction.def("Quadric", (const IntSurf_Quadric & (Contap_ArcFunction::*)() const) &Contap_ArcFunction::Quadric, "None");
cls_Contap_ArcFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (Contap_ArcFunction::*)() const) &Contap_ArcFunction::Surface, "Returns mySurf field");
cls_Contap_ArcFunction.def("LastComputedPoint", (const gp_Pnt & (Contap_ArcFunction::*)() const) &Contap_ArcFunction::LastComputedPoint, "Returns the point, which has been computed while the last calling Value() method");

// Enums

}