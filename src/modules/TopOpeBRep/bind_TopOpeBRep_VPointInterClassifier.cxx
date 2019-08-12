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
#include <TopAbs_State.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_PointClassifier.hxx>
#include <BRepClass_FaceClassifier.hxx>
#include <TopOpeBRep_VPointInterClassifier.hxx>

void bind_TopOpeBRep_VPointInterClassifier(py::module &mod){

py::class_<TopOpeBRep_VPointInterClassifier, std::unique_ptr<TopOpeBRep_VPointInterClassifier, Deleter<TopOpeBRep_VPointInterClassifier>>> cls_TopOpeBRep_VPointInterClassifier(mod, "TopOpeBRep_VPointInterClassifier", "None");

// Constructors
cls_TopOpeBRep_VPointInterClassifier.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_VPointInterClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_VPointInterClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_VPointInterClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_VPointInterClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_VPointInterClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_VPointInterClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_VPointInterClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_VPointInterClassifier.def("VPointPosition", (TopAbs_State (TopOpeBRep_VPointInterClassifier::*)(const TopoDS_Shape &, TopOpeBRep_VPointInter &, const Standard_Integer, TopOpeBRep_PointClassifier &, const Standard_Boolean, const Standard_Real)) &TopOpeBRep_VPointInterClassifier::VPointPosition, "compute position of VPoint <VP> regarding with face <F>. <ShapeIndex> (= 1,2) indicates which (u,v) point of <VP> is used. when state is ON, set VP.EdgeON() with the edge containing <VP> and associated parameter. returns state of VP on ShapeIndex.", py::arg("F"), py::arg("VP"), py::arg("ShapeIndex"), py::arg("PC"), py::arg("AssumeINON"), py::arg("Tol"));
cls_TopOpeBRep_VPointInterClassifier.def("Edge", (const TopoDS_Shape & (TopOpeBRep_VPointInterClassifier::*)() const) &TopOpeBRep_VPointInterClassifier::Edge, "returns the edge containing the VPoint <VP> used in the last VPointPosition() call. Edge is defined if the state previously computed is ON, else Edge is a null shape.");
cls_TopOpeBRep_VPointInterClassifier.def("EdgeParameter", (Standard_Real (TopOpeBRep_VPointInterClassifier::*)() const) &TopOpeBRep_VPointInterClassifier::EdgeParameter, "returns the parameter of the VPoint <VP> on Edge()");

// Enums

}