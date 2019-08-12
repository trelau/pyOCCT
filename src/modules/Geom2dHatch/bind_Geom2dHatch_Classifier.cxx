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
#include <Geom2dHatch_Elements.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <IntRes2d_Position.hxx>
#include <Geom2dHatch_FClass2dOfClassifier.hxx>
#include <Geom2dHatch_Classifier.hxx>

void bind_Geom2dHatch_Classifier(py::module &mod){

py::class_<Geom2dHatch_Classifier, std::unique_ptr<Geom2dHatch_Classifier, Deleter<Geom2dHatch_Classifier>>> cls_Geom2dHatch_Classifier(mod, "Geom2dHatch_Classifier", "None");

// Constructors
cls_Geom2dHatch_Classifier.def(py::init<>());
cls_Geom2dHatch_Classifier.def(py::init<Geom2dHatch_Elements &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));

// Fields

// Methods
// cls_Geom2dHatch_Classifier.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Classifier::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Classifier.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Classifier::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Classifier.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Classifier::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Classifier.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Classifier::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Classifier.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Classifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Classifier.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Classifier::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Classifier.def("Perform", (void (Geom2dHatch_Classifier::*)(Geom2dHatch_Elements &, const gp_Pnt2d &, const Standard_Real)) &Geom2dHatch_Classifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_Geom2dHatch_Classifier.def("State", (TopAbs_State (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::State, "Returns the result of the classification.");
cls_Geom2dHatch_Classifier.def("Rejected", (Standard_Boolean (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::Rejected, "Returns True when the state was computed by a rejection. The state is OUT.");
cls_Geom2dHatch_Classifier.def("NoWires", (Standard_Boolean (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::NoWires, "Returns True if the face contains no wire. The state is IN.");
cls_Geom2dHatch_Classifier.def("Edge", (const Geom2dAdaptor_Curve & (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::Edge, "Returns the Edge used to determine the classification. When the State is ON this is the Edge containing the point.");
cls_Geom2dHatch_Classifier.def("EdgeParameter", (Standard_Real (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::EdgeParameter, "Returns the parameter on Edge() used to determine the classification.");
cls_Geom2dHatch_Classifier.def("Position", (IntRes2d_Position (Geom2dHatch_Classifier::*)() const) &Geom2dHatch_Classifier::Position, "Returns the position of the point on the edge returned by Edge.");

// Enums

}