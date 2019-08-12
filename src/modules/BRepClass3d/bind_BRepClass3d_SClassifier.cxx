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
#include <BRepClass3d_SolidExplorer.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <TopoDS_Face.hxx>
#include <BRepClass3d_SClassifier.hxx>

void bind_BRepClass3d_SClassifier(py::module &mod){

py::class_<BRepClass3d_SClassifier, std::unique_ptr<BRepClass3d_SClassifier, Deleter<BRepClass3d_SClassifier>>> cls_BRepClass3d_SClassifier(mod, "BRepClass3d_SClassifier", "Provides an algorithm to classify a point in a solid.");

// Constructors
cls_BRepClass3d_SClassifier.def(py::init<>());
cls_BRepClass3d_SClassifier.def(py::init<BRepClass3d_SolidExplorer &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("P"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepClass3d_SClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d_SClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d_SClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass3d_SClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d_SClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d_SClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d_SClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d_SClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d_SClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d_SClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d_SClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d_SClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d_SClassifier.def("Perform", (void (BRepClass3d_SClassifier::*)(BRepClass3d_SolidExplorer &, const gp_Pnt &, const Standard_Real)) &BRepClass3d_SClassifier::Perform, "Classify the point P with the tolerance Tol on the solid S.", py::arg("S"), py::arg("P"), py::arg("Tol"));
cls_BRepClass3d_SClassifier.def("PerformInfinitePoint", (void (BRepClass3d_SClassifier::*)(BRepClass3d_SolidExplorer &, const Standard_Real)) &BRepClass3d_SClassifier::PerformInfinitePoint, "Classify an infinite point with the tolerance Tol on the solid S.", py::arg("S"), py::arg("Tol"));
cls_BRepClass3d_SClassifier.def("Rejected", (Standard_Boolean (BRepClass3d_SClassifier::*)() const) &BRepClass3d_SClassifier::Rejected, "Returns True if the classification has been computed by rejection. The State is then OUT.");
cls_BRepClass3d_SClassifier.def("State", (TopAbs_State (BRepClass3d_SClassifier::*)() const) &BRepClass3d_SClassifier::State, "Returns the result of the classification.");
cls_BRepClass3d_SClassifier.def("IsOnAFace", (Standard_Boolean (BRepClass3d_SClassifier::*)() const) &BRepClass3d_SClassifier::IsOnAFace, "Returns True when the point is a point of a face.");
cls_BRepClass3d_SClassifier.def("Face", (TopoDS_Face (BRepClass3d_SClassifier::*)() const) &BRepClass3d_SClassifier::Face, "Returns the face used to determine the classification. When the state is ON, this is the face containing the point.");

// Enums

}