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
#include <Geom2dAdaptor_Curve.hxx>
#include <TopAbs_Orientation.hxx>
#include <Geom2dHatch_Intersector.hxx>
#include <TopAbs_State.hxx>
#include <TopTrans_CurveTransition.hxx>
#include <Geom2dHatch_FClass2dOfClassifier.hxx>

void bind_Geom2dHatch_FClass2dOfClassifier(py::module &mod){

py::class_<Geom2dHatch_FClass2dOfClassifier, std::unique_ptr<Geom2dHatch_FClass2dOfClassifier, Deleter<Geom2dHatch_FClass2dOfClassifier>>> cls_Geom2dHatch_FClass2dOfClassifier(mod, "Geom2dHatch_FClass2dOfClassifier", "None");

// Constructors
cls_Geom2dHatch_FClass2dOfClassifier.def(py::init<>());

// Fields

// Methods
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_FClass2dOfClassifier::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_FClass2dOfClassifier::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_FClass2dOfClassifier::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_FClass2dOfClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_FClass2dOfClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_FClass2dOfClassifier.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_FClass2dOfClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_FClass2dOfClassifier.def("Reset", (void (Geom2dHatch_FClass2dOfClassifier::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real)) &Geom2dHatch_FClass2dOfClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the line segment in intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
cls_Geom2dHatch_FClass2dOfClassifier.def("Compare", (void (Geom2dHatch_FClass2dOfClassifier::*)(const Geom2dAdaptor_Curve &, const TopAbs_Orientation)) &Geom2dHatch_FClass2dOfClassifier::Compare, "Updates the classification process with the edge <E> from the boundary.", py::arg("E"), py::arg("Or"));
cls_Geom2dHatch_FClass2dOfClassifier.def("Parameter", (Standard_Real (Geom2dHatch_FClass2dOfClassifier::*)() const) &Geom2dHatch_FClass2dOfClassifier::Parameter, "Returns the current value of the parameter.");
cls_Geom2dHatch_FClass2dOfClassifier.def("Intersector", (Geom2dHatch_Intersector & (Geom2dHatch_FClass2dOfClassifier::*)()) &Geom2dHatch_FClass2dOfClassifier::Intersector, "Returns the intersecting algorithm.");
cls_Geom2dHatch_FClass2dOfClassifier.def("ClosestIntersection", (Standard_Integer (Geom2dHatch_FClass2dOfClassifier::*)() const) &Geom2dHatch_FClass2dOfClassifier::ClosestIntersection, "Returns 0 if the last compared edge had no relevant intersection. Else returns the index of this intersection in the last intersection algorithm.");
cls_Geom2dHatch_FClass2dOfClassifier.def("State", (TopAbs_State (Geom2dHatch_FClass2dOfClassifier::*)() const) &Geom2dHatch_FClass2dOfClassifier::State, "Returns the current state of the point.");
cls_Geom2dHatch_FClass2dOfClassifier.def("IsHeadOrEnd", (Standard_Boolean (Geom2dHatch_FClass2dOfClassifier::*)() const) &Geom2dHatch_FClass2dOfClassifier::IsHeadOrEnd, "Returns the Standard_True if the closest intersection point represents head or end of the edge. Returns Standard_False otherwise.");

// Enums

}