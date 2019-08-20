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
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepClass3d_Intersector3d.hxx>
#include <TopAbs_State.hxx>
#include <BRepClass3d_SolidPassiveClassifier.hxx>

void bind_BRepClass3d_SolidPassiveClassifier(py::module &mod){

py::class_<BRepClass3d_SolidPassiveClassifier, std::unique_ptr<BRepClass3d_SolidPassiveClassifier>> cls_BRepClass3d_SolidPassiveClassifier(mod, "BRepClass3d_SolidPassiveClassifier", "None");

// Constructors
cls_BRepClass3d_SolidPassiveClassifier.def(py::init<>());

// Fields

// Methods
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d_SolidPassiveClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass3d_SolidPassiveClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d_SolidPassiveClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d_SolidPassiveClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d_SolidPassiveClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d_SolidPassiveClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d_SolidPassiveClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d_SolidPassiveClassifier.def("Reset", (void (BRepClass3d_SolidPassiveClassifier::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &BRepClass3d_SolidPassiveClassifier::Reset, "Starts a classification process. The point to classify is the origin of the line <L>. <P> is the original length of the segment on <L> used to compute intersections. <Tol> is the tolerance attached to the intersections.", py::arg("L"), py::arg("P"), py::arg("Tol"));
cls_BRepClass3d_SolidPassiveClassifier.def("Compare", (void (BRepClass3d_SolidPassiveClassifier::*)(const TopoDS_Face &, const TopAbs_Orientation)) &BRepClass3d_SolidPassiveClassifier::Compare, "Updates the classification process with the face <F> from the boundary.", py::arg("F"), py::arg("Or"));
cls_BRepClass3d_SolidPassiveClassifier.def("Parameter", (Standard_Real (BRepClass3d_SolidPassiveClassifier::*)() const) &BRepClass3d_SolidPassiveClassifier::Parameter, "Returns the current value of the parameter.");
cls_BRepClass3d_SolidPassiveClassifier.def("HasIntersection", (Standard_Boolean (BRepClass3d_SolidPassiveClassifier::*)() const) &BRepClass3d_SolidPassiveClassifier::HasIntersection, "Returns True if an intersection is computed.");
cls_BRepClass3d_SolidPassiveClassifier.def("Intersector", (BRepClass3d_Intersector3d & (BRepClass3d_SolidPassiveClassifier::*)()) &BRepClass3d_SolidPassiveClassifier::Intersector, "Returns the intersecting algorithm.");
cls_BRepClass3d_SolidPassiveClassifier.def("State", (TopAbs_State (BRepClass3d_SolidPassiveClassifier::*)() const) &BRepClass3d_SolidPassiveClassifier::State, "Returns the current state of the point.");

// Enums

}