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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_ShapeMapTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_RelocationTable.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_ShapeMapTool(py::module &mod){

py::class_<XCAFDoc_ShapeMapTool, opencascade::handle<XCAFDoc_ShapeMapTool>, TDF_Attribute> cls_XCAFDoc_ShapeMapTool(mod, "XCAFDoc_ShapeMapTool", "attribute containing map of sub shapes");

// Constructors
cls_XCAFDoc_ShapeMapTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_ShapeMapTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ShapeMapTool::GetID, "None");
cls_XCAFDoc_ShapeMapTool.def_static("Set_", (opencascade::handle<XCAFDoc_ShapeMapTool> (*)(const TDF_Label &)) &XCAFDoc_ShapeMapTool::Set, "Create (if not exist) ShapeTool from XCAFDoc on <L>.", py::arg("L"));
cls_XCAFDoc_ShapeMapTool.def("IsSubShape", (Standard_Boolean (XCAFDoc_ShapeMapTool::*)(const TopoDS_Shape &) const) &XCAFDoc_ShapeMapTool::IsSubShape, "Checks whether shape is subshape of shape stored on label shapeL", py::arg("sub"));
cls_XCAFDoc_ShapeMapTool.def("SetShape", (void (XCAFDoc_ShapeMapTool::*)(const TopoDS_Shape &)) &XCAFDoc_ShapeMapTool::SetShape, "Sets representation (TopoDS_Shape) for top-level shape", py::arg("S"));
cls_XCAFDoc_ShapeMapTool.def("ID", (const Standard_GUID & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::ID, "None");
cls_XCAFDoc_ShapeMapTool.def("Restore", (void (XCAFDoc_ShapeMapTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ShapeMapTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ShapeMapTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::NewEmpty, "None");
cls_XCAFDoc_ShapeMapTool.def("Paste", (void (XCAFDoc_ShapeMapTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ShapeMapTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ShapeMapTool.def("GetMap", (const TopTools_IndexedMapOfShape & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::GetMap, "None");
cls_XCAFDoc_ShapeMapTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ShapeMapTool::get_type_name, "None");
cls_XCAFDoc_ShapeMapTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ShapeMapTool::get_type_descriptor, "None");
cls_XCAFDoc_ShapeMapTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ShapeMapTool::*)() const) &XCAFDoc_ShapeMapTool::DynamicType, "None");

// Enums

}