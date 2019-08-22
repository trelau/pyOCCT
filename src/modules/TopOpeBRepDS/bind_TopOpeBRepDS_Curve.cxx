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
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopoDS_Shape.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_Curve.hxx>

void bind_TopOpeBRepDS_Curve(py::module &mod){

py::class_<TopOpeBRepDS_Curve> cls_TopOpeBRepDS_Curve(mod, "TopOpeBRepDS_Curve", "A Geom curve and a tolerance.");

// Constructors
cls_TopOpeBRepDS_Curve.def(py::init<>());
cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("P"), py::arg("T"));
cls_TopOpeBRepDS_Curve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean>(), py::arg("P"), py::arg("T"), py::arg("IsWalk"));

// Fields

// Methods
// cls_TopOpeBRepDS_Curve.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_Curve::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_Curve::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_Curve::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_Curve.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_Curve.def("DefineCurve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Boolean)) &TopOpeBRepDS_Curve::DefineCurve, "None", py::arg("P"), py::arg("T"), py::arg("IsWalk"));
cls_TopOpeBRepDS_Curve.def("Tolerance", (void (TopOpeBRepDS_Curve::*)(const Standard_Real)) &TopOpeBRepDS_Curve::Tolerance, "Update the tolerance", py::arg("tol"));
cls_TopOpeBRepDS_Curve.def("SetSCI", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_Curve::SetSCI, "define the interferences face/curve.", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_Curve.def("GetSCI1", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::GetSCI1, "None");
cls_TopOpeBRepDS_Curve.def("GetSCI2", (const opencascade::handle<TopOpeBRepDS_Interference> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::GetSCI2, "None");
cls_TopOpeBRepDS_Curve.def("GetSCI", (void (TopOpeBRepDS_Curve::*)(opencascade::handle<TopOpeBRepDS_Interference> &, opencascade::handle<TopOpeBRepDS_Interference> &) const) &TopOpeBRepDS_Curve::GetSCI, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRepDS_Curve.def("SetShapes", (void (TopOpeBRepDS_Curve::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_Curve::SetShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_Curve.def("GetShapes", (void (TopOpeBRepDS_Curve::*)(TopoDS_Shape &, TopoDS_Shape &) const) &TopOpeBRepDS_Curve::GetShapes, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_Curve.def("Shape1", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Shape1, "None");
cls_TopOpeBRepDS_Curve.def("ChangeShape1", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape1, "None");
cls_TopOpeBRepDS_Curve.def("Shape2", (const TopoDS_Shape & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Shape2, "None");
cls_TopOpeBRepDS_Curve.def("ChangeShape2", (TopoDS_Shape & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeShape2, "None");
cls_TopOpeBRepDS_Curve.def("Curve", (const opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve, "None");
cls_TopOpeBRepDS_Curve.def("SetRange", (void (TopOpeBRepDS_Curve::*)(const Standard_Real, const Standard_Real)) &TopOpeBRepDS_Curve::SetRange, "None", py::arg("First"), py::arg("Last"));
cls_TopOpeBRepDS_Curve.def("Range", [](TopOpeBRepDS_Curve &self, Standard_Real & First, Standard_Real & Last){ Standard_Boolean rv = self.Range(First, Last); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_TopOpeBRepDS_Curve.def("Tolerance", (Standard_Real (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Tolerance, "None");
cls_TopOpeBRepDS_Curve.def("ChangeCurve", (opencascade::handle<Geom_Curve> & (TopOpeBRepDS_Curve::*)()) &TopOpeBRepDS_Curve::ChangeCurve, "None");
cls_TopOpeBRepDS_Curve.def("Curve", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &TopOpeBRepDS_Curve::Curve, "None", py::arg("C3D"), py::arg("Tol"));
cls_TopOpeBRepDS_Curve.def("Curve1", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve1, "None");
cls_TopOpeBRepDS_Curve.def("Curve1", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve1, "None", py::arg("PC1"));
cls_TopOpeBRepDS_Curve.def("Curve2", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Curve2, "None");
cls_TopOpeBRepDS_Curve.def("Curve2", (void (TopOpeBRepDS_Curve::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_Curve::Curve2, "None", py::arg("PC2"));
cls_TopOpeBRepDS_Curve.def("IsWalk", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::IsWalk, "None");
cls_TopOpeBRepDS_Curve.def("ChangeIsWalk", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeIsWalk, "None", py::arg("B"));
cls_TopOpeBRepDS_Curve.def("Keep", (Standard_Boolean (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Keep, "None");
cls_TopOpeBRepDS_Curve.def("ChangeKeep", (void (TopOpeBRepDS_Curve::*)(const Standard_Boolean)) &TopOpeBRepDS_Curve::ChangeKeep, "None", py::arg("B"));
cls_TopOpeBRepDS_Curve.def("Mother", (Standard_Integer (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::Mother, "None");
cls_TopOpeBRepDS_Curve.def("ChangeMother", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeMother, "None", py::arg("I"));
cls_TopOpeBRepDS_Curve.def("DSIndex", (Standard_Integer (TopOpeBRepDS_Curve::*)() const) &TopOpeBRepDS_Curve::DSIndex, "None");
cls_TopOpeBRepDS_Curve.def("ChangeDSIndex", (void (TopOpeBRepDS_Curve::*)(const Standard_Integer)) &TopOpeBRepDS_Curve::ChangeDSIndex, "None", py::arg("I"));

// Enums

}