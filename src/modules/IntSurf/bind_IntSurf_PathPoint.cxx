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
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <IntSurf_PathPoint.hxx>

void bind_IntSurf_PathPoint(py::module &mod){

py::class_<IntSurf_PathPoint, std::unique_ptr<IntSurf_PathPoint>> cls_IntSurf_PathPoint(mod, "IntSurf_PathPoint", "None");

// Constructors
cls_IntSurf_PathPoint.def(py::init<>());
cls_IntSurf_PathPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("U"), py::arg("V"));

// Fields

// Methods
// cls_IntSurf_PathPoint.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PathPoint::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PathPoint.def_static("operator delete_", (void (*)(void *)) &IntSurf_PathPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PathPoint::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PathPoint.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PathPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PathPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PathPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PathPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PathPoint.def("SetValue", (void (IntSurf_PathPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("AddUV", (void (IntSurf_PathPoint::*)(const Standard_Real, const Standard_Real)) &IntSurf_PathPoint::AddUV, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("SetDirections", (void (IntSurf_PathPoint::*)(const gp_Vec &, const gp_Dir2d &)) &IntSurf_PathPoint::SetDirections, "None", py::arg("V"), py::arg("D"));
cls_IntSurf_PathPoint.def("SetTangency", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetTangency, "None", py::arg("Tang"));
cls_IntSurf_PathPoint.def("SetPassing", (void (IntSurf_PathPoint::*)(const Standard_Boolean)) &IntSurf_PathPoint::SetPassing, "None", py::arg("Pass"));
cls_IntSurf_PathPoint.def("Value", (const gp_Pnt & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Value, "None");
cls_IntSurf_PathPoint.def("Value2d", [](IntSurf_PathPoint &self, Standard_Real & U, Standard_Real & V){ self.Value2d(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_IntSurf_PathPoint.def("IsPassingPnt", (Standard_Boolean (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::IsPassingPnt, "None");
cls_IntSurf_PathPoint.def("IsTangent", (Standard_Boolean (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::IsTangent, "None");
cls_IntSurf_PathPoint.def("Direction3d", (const gp_Vec & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Direction3d, "None");
cls_IntSurf_PathPoint.def("Direction2d", (const gp_Dir2d & (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Direction2d, "None");
cls_IntSurf_PathPoint.def("Multiplicity", (Standard_Integer (IntSurf_PathPoint::*)() const) &IntSurf_PathPoint::Multiplicity, "None");
cls_IntSurf_PathPoint.def("Parameters", [](IntSurf_PathPoint &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));

// Enums

}