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
#include <Standard_Handle.hxx>
#include <XCAFDoc_ViewTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_ViewTool(py::module &mod){

py::class_<XCAFDoc_ViewTool, opencascade::handle<XCAFDoc_ViewTool>, TDF_Attribute> cls_XCAFDoc_ViewTool(mod, "XCAFDoc_ViewTool", "Provides tools to store and retrieve Views in and from TDocStd_Document Each View contains parts XCAFDoc_View attribute with all information about camera and view window. Also each view contain information of displayed shapes and GDTs as sets of shape and GDT labels.");

// Constructors
cls_XCAFDoc_ViewTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_ViewTool.def_static("Set_", (opencascade::handle<XCAFDoc_ViewTool> (*)(const TDF_Label &)) &XCAFDoc_ViewTool::Set, "Creates (if not exist) ViewTool.", py::arg("L"));
cls_XCAFDoc_ViewTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ViewTool::GetID, "None");
cls_XCAFDoc_ViewTool.def("BaseLabel", (TDF_Label (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::BaseLabel, "Returns the label under which Views are stored");
cls_XCAFDoc_ViewTool.def("IsView", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::IsView, "Returns True if label belongs to a View table and is a View definition", py::arg("theLabel"));
cls_XCAFDoc_ViewTool.def("GetViewLabels", (void (XCAFDoc_ViewTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabels, "Returns a sequence of View labels currently stored in the View table", py::arg("theLabels"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theClippingPlanes"), py::arg("theNotes"), py::arg("theAnnotations"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theClippingPlanes"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetView", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetView, "Sets a link with GUID", py::arg("theShapes"), py::arg("theGDTs"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("SetClippingPlanes", (void (XCAFDoc_ViewTool::*)(const TDF_LabelSequence &, const TDF_Label &) const) &XCAFDoc_ViewTool::SetClippingPlanes, "Set Clipping planes to given View", py::arg("theClippingPlaneLabels"), py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("RemoveView", (void (XCAFDoc_ViewTool::*)(const TDF_Label &)) &XCAFDoc_ViewTool::RemoveView, "Remove View", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForShape", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForShape, "Returns all View labels defined for label ShapeL", py::arg("theShapeL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForGDT", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForGDT, "Returns all View labels defined for label GDTL", py::arg("theGDTL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForClippingPlane", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForClippingPlane, "Returns all View labels defined for label ClippingPlaneL", py::arg("theClippingPlaneL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForNote", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForNote, "Returns all View labels defined for label NoteL", py::arg("theNoteL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("GetViewLabelsForAnnotation", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetViewLabelsForAnnotation, "Returns all View labels defined for label AnnotationL", py::arg("theAnnotationL"), py::arg("theViews"));
cls_XCAFDoc_ViewTool.def("AddView", (TDF_Label (XCAFDoc_ViewTool::*)()) &XCAFDoc_ViewTool::AddView, "Adds a view definition to a View table and returns its label");
cls_XCAFDoc_ViewTool.def("GetRefShapeLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefShapeLabel, "Returns shape labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theShapeLabels"));
cls_XCAFDoc_ViewTool.def("GetRefGDTLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefGDTLabel, "Returns GDT labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theGDTLabels"));
cls_XCAFDoc_ViewTool.def("GetRefClippingPlaneLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefClippingPlaneLabel, "Returns ClippingPlane labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theClippingPlaneLabels"));
cls_XCAFDoc_ViewTool.def("GetRefNoteLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefNoteLabel, "Returns Notes labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theNoteLabels"));
cls_XCAFDoc_ViewTool.def("GetRefAnnotationLabel", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_ViewTool::GetRefAnnotationLabel, "Returns Annotation labels defined for label theViewL Returns False if the theViewL is not in View table", py::arg("theViewL"), py::arg("theAnnotationLabels"));
cls_XCAFDoc_ViewTool.def("IsLocked", (Standard_Boolean (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::IsLocked, "Returns true if the given View is marked as locked", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("Lock", (void (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::Lock, "Mark the given View as locked", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("Unlock", (void (XCAFDoc_ViewTool::*)(const TDF_Label &) const) &XCAFDoc_ViewTool::Unlock, "Unlock the given View", py::arg("theViewL"));
cls_XCAFDoc_ViewTool.def("ID", (const Standard_GUID & (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::ID, "None");
cls_XCAFDoc_ViewTool.def("Restore", (void (XCAFDoc_ViewTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ViewTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ViewTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::NewEmpty, "None");
cls_XCAFDoc_ViewTool.def("Paste", (void (XCAFDoc_ViewTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ViewTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ViewTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ViewTool::get_type_name, "None");
cls_XCAFDoc_ViewTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ViewTool::get_type_descriptor, "None");
cls_XCAFDoc_ViewTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ViewTool::*)() const) &XCAFDoc_ViewTool::DynamicType, "None");

// Enums

}