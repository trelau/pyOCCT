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
#include <Transfer_Binder.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TransferBRep_ShapeListBinder.hxx>

void bind_TransferBRep_ShapeListBinder(py::module &mod){

py::class_<TransferBRep_ShapeListBinder, opencascade::handle<TransferBRep_ShapeListBinder>, Transfer_Binder> cls_TransferBRep_ShapeListBinder(mod, "TransferBRep_ShapeListBinder", "This binder binds several (a list of) shapes with a starting entity, when this entity itself corresponds to a simple list of shapes. Each part is not seen as a sub-result of an independant componant, but as an item of a built-in list");

// Constructors
cls_TransferBRep_ShapeListBinder.def(py::init<>());
cls_TransferBRep_ShapeListBinder.def(py::init<const opencascade::handle<TopTools_HSequenceOfShape> &>(), py::arg("list"));

// Fields

// Methods
cls_TransferBRep_ShapeListBinder.def("IsMultiple", (Standard_Boolean (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::IsMultiple, "None");
cls_TransferBRep_ShapeListBinder.def("ResultType", (opencascade::handle<Standard_Type> (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::ResultType, "None");
cls_TransferBRep_ShapeListBinder.def("ResultTypeName", (Standard_CString (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::ResultTypeName, "None");
cls_TransferBRep_ShapeListBinder.def("AddResult", (void (TransferBRep_ShapeListBinder::*)(const TopoDS_Shape &)) &TransferBRep_ShapeListBinder::AddResult, "Adds an item to the result list", py::arg("res"));
cls_TransferBRep_ShapeListBinder.def("Result", (opencascade::handle<TopTools_HSequenceOfShape> (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::Result, "None");
cls_TransferBRep_ShapeListBinder.def("SetResult", (void (TransferBRep_ShapeListBinder::*)(const Standard_Integer, const TopoDS_Shape &)) &TransferBRep_ShapeListBinder::SetResult, "Changes an already defined sub-result", py::arg("num"), py::arg("res"));
cls_TransferBRep_ShapeListBinder.def("NbShapes", (Standard_Integer (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::NbShapes, "None");
cls_TransferBRep_ShapeListBinder.def("Shape", (const TopoDS_Shape & (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Shape, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("ShapeType", (TopAbs_ShapeEnum (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::ShapeType, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Vertex", (TopoDS_Vertex (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Vertex, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Edge", (TopoDS_Edge (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Edge, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Wire", (TopoDS_Wire (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Wire, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Face", (TopoDS_Face (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Face, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Shell", (TopoDS_Shell (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Shell, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Solid", (TopoDS_Solid (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Solid, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("CompSolid", (TopoDS_CompSolid (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::CompSolid, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def("Compound", (TopoDS_Compound (TransferBRep_ShapeListBinder::*)(const Standard_Integer) const) &TransferBRep_ShapeListBinder::Compound, "None", py::arg("num"));
cls_TransferBRep_ShapeListBinder.def_static("get_type_name_", (const char * (*)()) &TransferBRep_ShapeListBinder::get_type_name, "None");
cls_TransferBRep_ShapeListBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_ShapeListBinder::get_type_descriptor, "None");
cls_TransferBRep_ShapeListBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_ShapeListBinder::*)() const) &TransferBRep_ShapeListBinder::DynamicType, "None");

// Enums

}