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
#include <gp_Pnt2d.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <BRepMesh_Classifier.hxx>

void bind_BRepMesh_Classifier(py::module &mod){

py::class_<BRepMesh_Classifier> cls_BRepMesh_Classifier(mod, "BRepMesh_Classifier", "Auxilary class contains information about correctness of discretized face and used for classification of points regarding face internals.");

// Constructors
cls_BRepMesh_Classifier.def(py::init<>());

// Fields

// Methods
// cls_BRepMesh_Classifier.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Classifier::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Classifier.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Classifier::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Classifier.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Classifier::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Classifier.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Classifier::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Classifier.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Classifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Classifier.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Classifier::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Classifier.def("Destroy", (void (BRepMesh_Classifier::*)()) &BRepMesh_Classifier::Destroy, "Method is called on destruction. Clears internal data structures.");
cls_BRepMesh_Classifier.def("Perform", (TopAbs_State (BRepMesh_Classifier::*)(const gp_Pnt2d &) const) &BRepMesh_Classifier::Perform, "Performs classification of the given point regarding to face internals.", py::arg("thePoint"));
cls_BRepMesh_Classifier.def("RegisterWire", (void (BRepMesh_Classifier::*)(const NCollection_Sequence<gp_Pnt2d> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepMesh_Classifier::RegisterWire, "Registers wire specified by sequence of points for further classification of points.", py::arg("theWire"), py::arg("theTolUV"), py::arg("theUmin"), py::arg("theUmax"), py::arg("theVmin"), py::arg("theVmax"));

// Enums

}