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
#include <BOPAlgo_Options.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_History.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <BOPAlgo_RemoveFeatures.hxx>

void bind_BOPAlgo_RemoveFeatures(py::module &mod){

py::class_<BOPAlgo_RemoveFeatures, std::unique_ptr<BOPAlgo_RemoveFeatures>, BOPAlgo_Options> cls_BOPAlgo_RemoveFeatures(mod, "BOPAlgo_RemoveFeatures", "The RemoveFeatures algorithm is intended for reconstruction of the shape by removal of the unwanted parts from it. These parts can be holes, protrusions, spikes, fillets etc. The shape itself is not modified, the new shape is built in the result.");

// Constructors
cls_BOPAlgo_RemoveFeatures.def(py::init<>());

// Fields

// Methods
// cls_BOPAlgo_RemoveFeatures.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_RemoveFeatures::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_RemoveFeatures::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_RemoveFeatures::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_RemoveFeatures::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_RemoveFeatures::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_RemoveFeatures.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_RemoveFeatures::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_RemoveFeatures.def("SetShape", (void (BOPAlgo_RemoveFeatures::*)(const TopoDS_Shape &)) &BOPAlgo_RemoveFeatures::SetShape, "Sets the shape for processing.", py::arg("theShape"));
cls_BOPAlgo_RemoveFeatures.def("InputShape", (const TopoDS_Shape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::InputShape, "Returns the input shape");
cls_BOPAlgo_RemoveFeatures.def("AddFaceToRemove", (void (BOPAlgo_RemoveFeatures::*)(const TopoDS_Shape &)) &BOPAlgo_RemoveFeatures::AddFaceToRemove, "Adds the face to remove from the input shape.", py::arg("theFace"));
cls_BOPAlgo_RemoveFeatures.def("AddFacesToRemove", (void (BOPAlgo_RemoveFeatures::*)(const TopTools_ListOfShape &)) &BOPAlgo_RemoveFeatures::AddFacesToRemove, "Adds the faces to remove from the input shape.", py::arg("theFaces"));
cls_BOPAlgo_RemoveFeatures.def("FacesToRemove", (const TopTools_ListOfShape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::FacesToRemove, "Returns the list of faces which have been requested for removal from the input shape.");
cls_BOPAlgo_RemoveFeatures.def("Perform", (void (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::Perform, "Performs the operation");
cls_BOPAlgo_RemoveFeatures.def("Clear", (void (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::Clear, "Clears the contents of the algorithm from previous run, allowing reusing it for following removals.");
cls_BOPAlgo_RemoveFeatures.def("TrackHistory", (void (BOPAlgo_RemoveFeatures::*)(const Standard_Boolean)) &BOPAlgo_RemoveFeatures::TrackHistory, "Defines whether to track the modification of the shapes or not", py::arg("theFlag"));
cls_BOPAlgo_RemoveFeatures.def("History", (opencascade::handle<BRepTools_History> (BOPAlgo_RemoveFeatures::*)()) &BOPAlgo_RemoveFeatures::History, "Gets the History object");
cls_BOPAlgo_RemoveFeatures.def("Shape", (const TopoDS_Shape & (BOPAlgo_RemoveFeatures::*)() const) &BOPAlgo_RemoveFeatures::Shape, "Returns the resulting shape");

// Enums

}