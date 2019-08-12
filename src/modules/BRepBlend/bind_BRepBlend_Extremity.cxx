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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <gp_Vec.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_PointOnRst.hxx>
#include <BRepBlend_SequenceOfPointOnRst.hxx>
#include <BRepBlend_Extremity.hxx>

void bind_BRepBlend_Extremity(py::module &mod){

py::class_<BRepBlend_Extremity, std::unique_ptr<BRepBlend_Extremity, Deleter<BRepBlend_Extremity>>> cls_BRepBlend_Extremity(mod, "BRepBlend_Extremity", "None");

// Constructors
cls_BRepBlend_Extremity.def(py::init<>());
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"), py::arg("Vtx"));
cls_BRepBlend_Extremity.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("W"), py::arg("Param"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepBlend_Extremity.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_Extremity::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Extremity.def_static("operator delete_", (void (*)(void *)) &BRepBlend_Extremity::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_Extremity::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Extremity.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_Extremity::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_Extremity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Extremity.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_Extremity::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on a surface.", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Adaptor3d_HVertex> &)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on a surface.This extremity matches the vertex <Vtx>.", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Param"), py::arg("Tol"), py::arg("Vtx"));
cls_BRepBlend_Extremity.def("SetValue", (void (BRepBlend_Extremity::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepBlend_Extremity::SetValue, "Set the values for an extremity on curve.", py::arg("P"), py::arg("W"), py::arg("Param"), py::arg("Tol"));
cls_BRepBlend_Extremity.def("Value", (const gp_Pnt & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Value, "This method returns the value of the point in 3d space.");
cls_BRepBlend_Extremity.def("SetTangent", (void (BRepBlend_Extremity::*)(const gp_Vec &)) &BRepBlend_Extremity::SetTangent, "Set the tangent vector for an extremity on a surface.", py::arg("Tangent"));
cls_BRepBlend_Extremity.def("HasTangent", (Standard_Boolean (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::HasTangent, "Returns TRUE if the Tangent is stored.");
cls_BRepBlend_Extremity.def("Tangent", (const gp_Vec & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Tangent, "This method returns the value of tangent in 3d space.");
cls_BRepBlend_Extremity.def("Tolerance", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Tolerance, "This method returns the fuzziness on the point in 3d space.");
cls_BRepBlend_Extremity.def("SetVertex", (void (BRepBlend_Extremity::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepBlend_Extremity::SetVertex, "Set the values for an extremity on a curve.", py::arg("V"));
cls_BRepBlend_Extremity.def("AddArc", (void (BRepBlend_Extremity::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &BRepBlend_Extremity::AddArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_BRepBlend_Extremity.def("Parameters", [](BRepBlend_Extremity &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "This method returns the parameters of the point on the concerned surface.", py::arg("U"), py::arg("V"));
cls_BRepBlend_Extremity.def("IsVertex", (Standard_Boolean (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::IsVertex, "Returns Standard_True when the point coincide with an existing vertex.");
cls_BRepBlend_Extremity.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Vertex, "Returns the vertex when IsVertex returns Standard_True.");
cls_BRepBlend_Extremity.def("NbPointOnRst", (Standard_Integer (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::NbPointOnRst, "Returns the number of arc containing the extremity. If the method returns 0, the point is inside the surface. Otherwise, the extremity lies on at least 1 arc, and all the information (arc, parameter, transitions) are given by the point on restriction (PointOnRst) returned by the next method.");
cls_BRepBlend_Extremity.def("PointOnRst", (const BRepBlend_PointOnRst & (BRepBlend_Extremity::*)(const Standard_Integer) const) &BRepBlend_Extremity::PointOnRst, "None", py::arg("Index"));
cls_BRepBlend_Extremity.def("Parameter", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::Parameter, "None");
cls_BRepBlend_Extremity.def("ParameterOnGuide", (Standard_Real (BRepBlend_Extremity::*)() const) &BRepBlend_Extremity::ParameterOnGuide, "None");

// Enums

}