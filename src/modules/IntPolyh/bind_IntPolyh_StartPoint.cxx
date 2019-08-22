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
#include <IntPolyh_Triangle.hxx>
#include <IntPolyh_StartPoint.hxx>

void bind_IntPolyh_StartPoint(py::module &mod){

py::class_<IntPolyh_StartPoint> cls_IntPolyh_StartPoint(mod, "IntPolyh_StartPoint", "None");

// Constructors
cls_IntPolyh_StartPoint.def(py::init<>());
cls_IntPolyh_StartPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("xx"), py::arg("yy"), py::arg("zz"), py::arg("uu1"), py::arg("vv1"), py::arg("uu2"), py::arg("vv2"), py::arg("T1"), py::arg("E1"), py::arg("LAM1"), py::arg("T2"), py::arg("E2"), py::arg("LAM2"), py::arg("List"));

// Fields

// Methods
// cls_IntPolyh_StartPoint.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_StartPoint::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_StartPoint.def_static("operator delete_", (void (*)(void *)) &IntPolyh_StartPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_StartPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_StartPoint::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_StartPoint.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_StartPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_StartPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_StartPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_StartPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_StartPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_StartPoint.def("X", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::X, "None");
cls_IntPolyh_StartPoint.def("Y", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::Y, "None");
cls_IntPolyh_StartPoint.def("Z", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::Z, "None");
cls_IntPolyh_StartPoint.def("U1", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::U1, "None");
cls_IntPolyh_StartPoint.def("V1", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::V1, "None");
cls_IntPolyh_StartPoint.def("U2", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::U2, "None");
cls_IntPolyh_StartPoint.def("V2", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::V2, "None");
cls_IntPolyh_StartPoint.def("T1", (Standard_Integer (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::T1, "None");
cls_IntPolyh_StartPoint.def("E1", (Standard_Integer (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::E1, "None");
cls_IntPolyh_StartPoint.def("Lambda1", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::Lambda1, "None");
cls_IntPolyh_StartPoint.def("T2", (Standard_Integer (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::T2, "None");
cls_IntPolyh_StartPoint.def("E2", (Standard_Integer (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::E2, "None");
cls_IntPolyh_StartPoint.def("Lambda2", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::Lambda2, "None");
cls_IntPolyh_StartPoint.def("GetAngle", (Standard_Real (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::GetAngle, "None");
cls_IntPolyh_StartPoint.def("ChainList", (Standard_Integer (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::ChainList, "None");
cls_IntPolyh_StartPoint.def("GetEdgePoints", [](IntPolyh_StartPoint &self, const IntPolyh_Triangle & Triangle, Standard_Integer & FirstEdgePoint, Standard_Integer & SecondEdgePoint, Standard_Integer & LastPoint){ Standard_Integer rv = self.GetEdgePoints(Triangle, FirstEdgePoint, SecondEdgePoint, LastPoint); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, FirstEdgePoint, SecondEdgePoint, LastPoint); }, "None", py::arg("Triangle"), py::arg("FirstEdgePoint"), py::arg("SecondEdgePoint"), py::arg("LastPoint"));
cls_IntPolyh_StartPoint.def("SetXYZ", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetXYZ, "None", py::arg("XX"), py::arg("YY"), py::arg("ZZ"));
cls_IntPolyh_StartPoint.def("SetUV1", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetUV1, "None", py::arg("UU1"), py::arg("VV1"));
cls_IntPolyh_StartPoint.def("SetUV2", (void (IntPolyh_StartPoint::*)(const Standard_Real, const Standard_Real)) &IntPolyh_StartPoint::SetUV2, "None", py::arg("UU2"), py::arg("VV2"));
cls_IntPolyh_StartPoint.def("SetEdge1", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetEdge1, "None", py::arg("IE1"));
cls_IntPolyh_StartPoint.def("SetLambda1", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetLambda1, "None", py::arg("LAM1"));
cls_IntPolyh_StartPoint.def("SetEdge2", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetEdge2, "None", py::arg("IE2"));
cls_IntPolyh_StartPoint.def("SetLambda2", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetLambda2, "None", py::arg("LAM2"));
cls_IntPolyh_StartPoint.def("SetCoupleValue", (void (IntPolyh_StartPoint::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_StartPoint::SetCoupleValue, "None", py::arg("IT1"), py::arg("IT2"));
cls_IntPolyh_StartPoint.def("SetAngle", (void (IntPolyh_StartPoint::*)(const Standard_Real)) &IntPolyh_StartPoint::SetAngle, "None", py::arg("ang"));
cls_IntPolyh_StartPoint.def("SetChainList", (void (IntPolyh_StartPoint::*)(const Standard_Integer)) &IntPolyh_StartPoint::SetChainList, "None", py::arg("ChList"));
cls_IntPolyh_StartPoint.def("CheckSameSP", (Standard_Integer (IntPolyh_StartPoint::*)(const IntPolyh_StartPoint &) const) &IntPolyh_StartPoint::CheckSameSP, "None", py::arg("SP"));
cls_IntPolyh_StartPoint.def("Dump", (void (IntPolyh_StartPoint::*)() const) &IntPolyh_StartPoint::Dump, "None");
cls_IntPolyh_StartPoint.def("Dump", (void (IntPolyh_StartPoint::*)(const Standard_Integer) const) &IntPolyh_StartPoint::Dump, "None", py::arg("i"));

// Enums

}