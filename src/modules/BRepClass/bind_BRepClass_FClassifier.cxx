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
#include <BRepClass_FaceExplorer.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <BRepClass_Edge.hxx>
#include <IntRes2d_Position.hxx>
#include <BRepClass_FClass2dOfFClassifier.hxx>
#include <BRepClass_FClassifier.hxx>

void bind_BRepClass_FClassifier(py::module &mod){

py::class_<BRepClass_FClassifier> cls_BRepClass_FClassifier(mod, "BRepClass_FClassifier", "None");

// Constructors
cls_BRepClass_FClassifier.def(py::init<>());
cls_BRepClass_FClassifier.def(py::init<BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepClass_FClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FClassifier.def("Perform", (void (BRepClass_FClassifier::*)(BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real)) &BRepClass_FClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FClassifier.def("State", (TopAbs_State (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::State, "Returns the result of the classification.");
cls_BRepClass_FClassifier.def("Rejected", (Standard_Boolean (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Rejected, "Returns True when the state was computed by a rejection. The state is OUT.");
cls_BRepClass_FClassifier.def("NoWires", (Standard_Boolean (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::NoWires, "Returns True if the face contains no wire. The state is IN.");
cls_BRepClass_FClassifier.def("Edge", (const BRepClass_Edge & (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Edge, "Returns the Edge used to determine the classification. When the State is ON this is the Edge containing the point.");
cls_BRepClass_FClassifier.def("EdgeParameter", (Standard_Real (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::EdgeParameter, "Returns the parameter on Edge() used to determine the classification.");
cls_BRepClass_FClassifier.def("Position", (IntRes2d_Position (BRepClass_FClassifier::*)() const) &BRepClass_FClassifier::Position, "Returns the position of the point on the edge returned by Edge.");

// Enums

}