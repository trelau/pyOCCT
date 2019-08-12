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
#include <IntSurf_Quadric.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <IntPatch_ArcFunction.hxx>

void bind_IntPatch_ArcFunction(py::module &mod){

py::class_<IntPatch_ArcFunction, std::unique_ptr<IntPatch_ArcFunction, Deleter<IntPatch_ArcFunction>>, math_FunctionWithDerivative> cls_IntPatch_ArcFunction(mod, "IntPatch_ArcFunction", "None");

// Constructors
cls_IntPatch_ArcFunction.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_ArcFunction.def_static("operator new_", (void * (*)(size_t)) &IntPatch_ArcFunction::operator new, "None", py::arg("theSize"));
// cls_IntPatch_ArcFunction.def_static("operator delete_", (void (*)(void *)) &IntPatch_ArcFunction::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_ArcFunction.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_ArcFunction::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_ArcFunction.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_ArcFunction::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_ArcFunction.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_ArcFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_ArcFunction.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_ArcFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_ArcFunction.def("SetQuadric", (void (IntPatch_ArcFunction::*)(const IntSurf_Quadric &)) &IntPatch_ArcFunction::SetQuadric, "None", py::arg("Q"));
cls_IntPatch_ArcFunction.def("Set", (void (IntPatch_ArcFunction::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_ArcFunction::Set, "None", py::arg("A"));
cls_IntPatch_ArcFunction.def("Set", (void (IntPatch_ArcFunction::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_ArcFunction::Set, "None", py::arg("S"));
cls_IntPatch_ArcFunction.def("Value", [](IntPatch_ArcFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_IntPatch_ArcFunction.def("Derivative", [](IntPatch_ArcFunction &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "None", py::arg("X"), py::arg("D"));
cls_IntPatch_ArcFunction.def("Values", [](IntPatch_ArcFunction &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "None", py::arg("X"), py::arg("F"), py::arg("D"));
cls_IntPatch_ArcFunction.def("NbSamples", (Standard_Integer (IntPatch_ArcFunction::*)() const) &IntPatch_ArcFunction::NbSamples, "None");
cls_IntPatch_ArcFunction.def("GetStateNumber", (Standard_Integer (IntPatch_ArcFunction::*)()) &IntPatch_ArcFunction::GetStateNumber, "None");
cls_IntPatch_ArcFunction.def("Valpoint", (const gp_Pnt & (IntPatch_ArcFunction::*)(const Standard_Integer) const) &IntPatch_ArcFunction::Valpoint, "None", py::arg("Index"));
cls_IntPatch_ArcFunction.def("Quadric", (const IntSurf_Quadric & (IntPatch_ArcFunction::*)() const) &IntPatch_ArcFunction::Quadric, "None");
cls_IntPatch_ArcFunction.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_ArcFunction::*)() const) &IntPatch_ArcFunction::Arc, "None");
cls_IntPatch_ArcFunction.def("Surface", (const opencascade::handle<Adaptor3d_HSurface> & (IntPatch_ArcFunction::*)() const) &IntPatch_ArcFunction::Surface, "None");
cls_IntPatch_ArcFunction.def("LastComputedPoint", (const gp_Pnt & (IntPatch_ArcFunction::*)() const) &IntPatch_ArcFunction::LastComputedPoint, "Returns the point, which has been computed while the last calling Value() method");

// Enums

}