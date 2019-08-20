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
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepClass_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepClass_Intersector.hxx>
#include <TopAbs_State.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <BRepClass_FacePassiveClassifier.hxx>

void bind_BRepClass_FacePassiveClassifier(py::module &mod){

py::class_<BRepClass_FacePassiveClassifier, std::unique_ptr<BRepClass_FacePassiveClassifier>> cls_BRepClass_FacePassiveClassifier(mod, "BRepClass_FacePassiveClassifier", "None");

// Constructors
cls_BRepClass_FacePassiveClassifier.def(py::init<>());

// Fields

// Methods
// cls_BRepClass_FacePassiveClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FacePassiveClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FacePassiveClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FacePassiveClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FacePassiveClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FacePassiveClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FacePassiveClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FacePassiveClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FacePassiveClassifier.def("Reset", (void (BRepClass_FacePassiveClassifier::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &BRepClass_FacePassiveClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the line segment in intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FacePassiveClassifier.def("Compare", (void (BRepClass_FacePassiveClassifier::*)(const BRepClass_Edge &, const TopAbs_Orientation)) &BRepClass_FacePassiveClassifier::Compare, "Updates the classification process with the edge <E> from the boundary.", py::arg("E"), py::arg("Or"));
cls_BRepClass_FacePassiveClassifier.def("Parameter", (Standard_Real (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::Parameter, "Returns the current value of the parameter.");
cls_BRepClass_FacePassiveClassifier.def("Intersector", (BRepClass_Intersector & (BRepClass_FacePassiveClassifier::*)()) &BRepClass_FacePassiveClassifier::Intersector, "Returns the intersecting algorithm.");
cls_BRepClass_FacePassiveClassifier.def("ClosestIntersection", (Standard_Integer (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::ClosestIntersection, "Returns 0 if the last compared edge had no relevant intersection. Else returns the index of this intersection in the last intersection algorithm.");
cls_BRepClass_FacePassiveClassifier.def("State", (TopAbs_State (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::State, "Returns the current state of the point.");
cls_BRepClass_FacePassiveClassifier.def("IsHeadOrEnd", (Standard_Boolean (BRepClass_FacePassiveClassifier::*)() const) &BRepClass_FacePassiveClassifier::IsHeadOrEnd, "Returns the Standard_True if the closest intersection point represents head or end of the edge. Returns Standard_False otherwise.");

// Enums

}