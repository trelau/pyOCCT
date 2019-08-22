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
#include <BRepClass_FClassifier.hxx>
#include <Standard.hxx>
#include <BRepClass_FaceExplorer.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <BRepClass_FaceClassifier.hxx>

void bind_BRepClass_FaceClassifier(py::module &mod){

py::class_<BRepClass_FaceClassifier, BRepClass_FClassifier> cls_BRepClass_FaceClassifier(mod, "BRepClass_FaceClassifier", "Provides Constructors with a Face.");

// Constructors
cls_BRepClass_FaceClassifier.def(py::init<>());
cls_BRepClass_FaceClassifier.def(py::init<BRepClass_FaceExplorer &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def(py::init<const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def(py::init<const TopoDS_Face &, const gp_Pnt &, const Standard_Real>(), py::arg("F"), py::arg("P"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepClass_FaceClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass_FaceClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass_FaceClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass_FaceClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass_FaceClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass_FaceClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass_FaceClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass_FaceClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass_FaceClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass_FaceClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass_FaceClassifier.def("Perform", (void (BRepClass_FaceClassifier::*)(const TopoDS_Face &, const gp_Pnt2d &, const Standard_Real)) &BRepClass_FaceClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));
cls_BRepClass_FaceClassifier.def("Perform", (void (BRepClass_FaceClassifier::*)(const TopoDS_Face &, const gp_Pnt &, const Standard_Real)) &BRepClass_FaceClassifier::Perform, "Classify the Point P with Tolerance <T> on the face described by <F>.", py::arg("F"), py::arg("P"), py::arg("Tol"));

// Enums

}