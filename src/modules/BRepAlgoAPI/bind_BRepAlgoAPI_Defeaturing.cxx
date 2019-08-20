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
#include <BRepAlgoAPI_Algo.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_History.hxx>
#include <BOPAlgo_RemoveFeatures.hxx>
#include <BRepAlgoAPI_Defeaturing.hxx>

void bind_BRepAlgoAPI_Defeaturing(py::module &mod){

py::class_<BRepAlgoAPI_Defeaturing, std::unique_ptr<BRepAlgoAPI_Defeaturing>, BRepAlgoAPI_Algo> cls_BRepAlgoAPI_Defeaturing(mod, "BRepAlgoAPI_Defeaturing", "The BRepAlgoAPI_Defeaturing algorithm is the API algorithm intended for removal of the unwanted parts from the shape. The unwanted parts (or features) can be holes, protrusions, gaps, chamfers, fillets etc. The shape itself is not modified, the new shape is built as the result.");

// Constructors
cls_BRepAlgoAPI_Defeaturing.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Defeaturing::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Defeaturing::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Defeaturing::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Defeaturing::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Defeaturing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Defeaturing.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Defeaturing::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Defeaturing.def("SetShape", (void (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::SetShape, "Sets the shape for processing.", py::arg("theShape"));
cls_BRepAlgoAPI_Defeaturing.def("InputShape", (const TopoDS_Shape & (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::InputShape, "Returns the input shape");
cls_BRepAlgoAPI_Defeaturing.def("AddFaceToRemove", (void (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::AddFaceToRemove, "Adds the features to remove from the input shape.", py::arg("theFace"));
cls_BRepAlgoAPI_Defeaturing.def("AddFacesToRemove", (void (BRepAlgoAPI_Defeaturing::*)(const TopTools_ListOfShape &)) &BRepAlgoAPI_Defeaturing::AddFacesToRemove, "Adds the faces to remove from the input shape.", py::arg("theFaces"));
cls_BRepAlgoAPI_Defeaturing.def("FacesToRemove", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::FacesToRemove, "Returns the list of faces which have been requested for removal from the input shape.");
cls_BRepAlgoAPI_Defeaturing.def("Build", (void (BRepAlgoAPI_Defeaturing::*)()) &BRepAlgoAPI_Defeaturing::Build, "Performs the operation");
cls_BRepAlgoAPI_Defeaturing.def("TrackHistory", (void (BRepAlgoAPI_Defeaturing::*)(const Standard_Boolean)) &BRepAlgoAPI_Defeaturing::TrackHistory, "Defines whether to track the modification of the shapes or not.", py::arg("theFlag"));
cls_BRepAlgoAPI_Defeaturing.def("HasHistory", (Standard_Boolean (BRepAlgoAPI_Defeaturing::*)() const) &BRepAlgoAPI_Defeaturing::HasHistory, "Returns whether the history was requested or not.");
cls_BRepAlgoAPI_Defeaturing.def("Modified", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::Modified, "Returns the list of shapes modified from the shape <theS> during the operation.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("Generated", (const TopTools_ListOfShape & (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::Generated, "Returns the list of shapes generated from the shape <theS> during the operation.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("IsDeleted", (Standard_Boolean (BRepAlgoAPI_Defeaturing::*)(const TopoDS_Shape &)) &BRepAlgoAPI_Defeaturing::IsDeleted, "Returns true if the shape <theS> has been deleted during the operation. It means that the shape has no any trace in the result. Otherwise it returns false.", py::arg("theS"));
cls_BRepAlgoAPI_Defeaturing.def("GetHistory", (opencascade::handle<BRepTools_History> (BRepAlgoAPI_Defeaturing::*)()) &BRepAlgoAPI_Defeaturing::GetHistory, "Returns the History of shapes modifications");

// Enums

}