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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <XCAFNoteObjects_NoteObject.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>

void bind_XCAFNoteObjects_NoteObject(py::module &mod){

py::class_<XCAFNoteObjects_NoteObject, opencascade::handle<XCAFNoteObjects_NoteObject>, Standard_Transient> cls_XCAFNoteObjects_NoteObject(mod, "XCAFNoteObjects_NoteObject", "object to store note auxiliary data");

// Constructors
cls_XCAFNoteObjects_NoteObject.def(py::init<>());
cls_XCAFNoteObjects_NoteObject.def(py::init<const opencascade::handle<XCAFNoteObjects_NoteObject> &>(), py::arg("theObj"));

// Fields

// Methods
cls_XCAFNoteObjects_NoteObject.def_static("get_type_name_", (const char * (*)()) &XCAFNoteObjects_NoteObject::get_type_name, "None");
cls_XCAFNoteObjects_NoteObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFNoteObjects_NoteObject::get_type_descriptor, "None");
cls_XCAFNoteObjects_NoteObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::DynamicType, "None");
cls_XCAFNoteObjects_NoteObject.def("HasPlane", (Standard_Boolean (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::HasPlane, "Returns True if plane is specified");
cls_XCAFNoteObjects_NoteObject.def("GetPlane", (const gp_Ax2 & (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::GetPlane, "Returns a right-handed coordinate system of the plane");
cls_XCAFNoteObjects_NoteObject.def("SetPlane", (void (XCAFNoteObjects_NoteObject::*)(const gp_Ax2 &)) &XCAFNoteObjects_NoteObject::SetPlane, "Sets a right-handed coordinate system of the plane", py::arg("thePlane"));
cls_XCAFNoteObjects_NoteObject.def("HasPoint", (Standard_Boolean (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::HasPoint, "Returns True if the attachment point on the annotated object is specified");
cls_XCAFNoteObjects_NoteObject.def("GetPoint", (const gp_Pnt & (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::GetPoint, "Returns the attachment point on the annotated object");
cls_XCAFNoteObjects_NoteObject.def("SetPoint", (void (XCAFNoteObjects_NoteObject::*)(const gp_Pnt &)) &XCAFNoteObjects_NoteObject::SetPoint, "Sets the anchor point on the annotated object", py::arg("thePnt"));
cls_XCAFNoteObjects_NoteObject.def("HasPointText", (Standard_Boolean (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::HasPointText, "Returns True if the text position is specified");
cls_XCAFNoteObjects_NoteObject.def("GetPointText", (const gp_Pnt & (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::GetPointText, "Returns the text position");
cls_XCAFNoteObjects_NoteObject.def("SetPointText", (void (XCAFNoteObjects_NoteObject::*)(const gp_Pnt &)) &XCAFNoteObjects_NoteObject::SetPointText, "Sets the text position", py::arg("thePnt"));
cls_XCAFNoteObjects_NoteObject.def("GetPresentation", (const TopoDS_Shape & (XCAFNoteObjects_NoteObject::*)() const) &XCAFNoteObjects_NoteObject::GetPresentation, "Returns a tesselated annotation if specified");
cls_XCAFNoteObjects_NoteObject.def("SetPresentation", (void (XCAFNoteObjects_NoteObject::*)(const TopoDS_Shape &)) &XCAFNoteObjects_NoteObject::SetPresentation, "Sets a tesselated annotation", py::arg("thePresentation"));
cls_XCAFNoteObjects_NoteObject.def("Reset", (void (XCAFNoteObjects_NoteObject::*)()) &XCAFNoteObjects_NoteObject::Reset, "Resets data to the state after calling the default constructor");

// Enums

}