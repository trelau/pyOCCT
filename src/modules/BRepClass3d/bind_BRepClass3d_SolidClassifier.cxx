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
#include <BRepClass3d_SClassifier.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepClass3d_SolidExplorer.hxx>
#include <BRepClass3d_SolidClassifier.hxx>

void bind_BRepClass3d_SolidClassifier(py::module &mod){

py::class_<BRepClass3d_SolidClassifier, BRepClass3d_SClassifier> cls_BRepClass3d_SolidClassifier(mod, "BRepClass3d_SolidClassifier", "Provides an algorithm to classify a point in a solid.");

// Constructors
cls_BRepClass3d_SolidClassifier.def(py::init<>());
cls_BRepClass3d_SolidClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepClass3d_SolidClassifier.def(py::init<const TopoDS_Shape &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("P"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepClass3d_SolidClassifier.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d_SolidClassifier::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d_SolidClassifier.def_static("operator delete_", (void (*)(void *)) &BRepClass3d_SolidClassifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidClassifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d_SolidClassifier::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d_SolidClassifier.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d_SolidClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d_SolidClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d_SolidClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d_SolidClassifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d_SolidClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d_SolidClassifier.def("Load", (void (BRepClass3d_SolidClassifier::*)(const TopoDS_Shape &)) &BRepClass3d_SolidClassifier::Load, "None", py::arg("S"));
cls_BRepClass3d_SolidClassifier.def("Perform", (void (BRepClass3d_SolidClassifier::*)(const gp_Pnt &, const Standard_Real)) &BRepClass3d_SolidClassifier::Perform, "Classify the point P with the tolerance Tol on the solid S.", py::arg("P"), py::arg("Tol"));
cls_BRepClass3d_SolidClassifier.def("PerformInfinitePoint", (void (BRepClass3d_SolidClassifier::*)(const Standard_Real)) &BRepClass3d_SolidClassifier::PerformInfinitePoint, "Classify an infinite point with the tolerance Tol on the solid S. Useful for compute the orientation of a solid.", py::arg("Tol"));
cls_BRepClass3d_SolidClassifier.def("Destroy", (void (BRepClass3d_SolidClassifier::*)()) &BRepClass3d_SolidClassifier::Destroy, "None");

// Enums

}