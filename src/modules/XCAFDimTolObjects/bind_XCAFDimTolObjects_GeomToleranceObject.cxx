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
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <TCollection_HAsciiString.hxx>
#include <XCAFDimTolObjects_GeomToleranceType.hxx>
#include <XCAFDimTolObjects_GeomToleranceTypeValue.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDimTolObjects_GeomToleranceMatReqModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceZoneModif.hxx>
#include <XCAFDimTolObjects_GeomToleranceModifiersSequence.hxx>
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFDimTolObjects_ToleranceZoneAffectedPlane.hxx>
#include <gp_Pln.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDimTolObjects_GeomToleranceObject(py::module &mod){

py::class_<XCAFDimTolObjects_GeomToleranceObject, opencascade::handle<XCAFDimTolObjects_GeomToleranceObject>, Standard_Transient> cls_XCAFDimTolObjects_GeomToleranceObject(mod, "XCAFDimTolObjects_GeomToleranceObject", "Access object to store dimension and tolerance");

// Constructors
cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<>());
cls_XCAFDimTolObjects_GeomToleranceObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_GeomToleranceObject> &>(), py::arg("theObj"));

// Fields

// Methods
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetSemanticName", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_GeomToleranceObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetType", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceType)) &XCAFDimTolObjects_GeomToleranceObject::SetType, "Sets type of the object.", py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetType", (XCAFDimTolObjects_GeomToleranceType (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetType, "Returns type of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetTypeOfValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceTypeValue)) &XCAFDimTolObjects_GeomToleranceObject::SetTypeOfValue, "Sets type of tolerance value.", py::arg("theTypeOfValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetTypeOfValue", (XCAFDimTolObjects_GeomToleranceTypeValue (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetTypeOfValue, "Returns type of tolerance value.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValue", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValue, "Sets tolerance value.", py::arg("theValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValue", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetValue, "Returns tolerance value.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaterialRequirementModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceMatReqModif)) &XCAFDimTolObjects_GeomToleranceObject::SetMaterialRequirementModifier, "Sets material requirement of the tolerance.", py::arg("theMatReqModif"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaterialRequirementModifier", (XCAFDimTolObjects_GeomToleranceMatReqModif (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetMaterialRequirementModifier, "Returns material requirement of the tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceZoneModif)) &XCAFDimTolObjects_GeomToleranceObject::SetZoneModifier, "Sets tolerance zone.", py::arg("theZoneModif"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetZoneModifier", (XCAFDimTolObjects_GeomToleranceZoneModif (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetZoneModifier, "Returns tolerance zone.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetValueOfZoneModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetValueOfZoneModifier, "Sets value associated with tolerance zone.", py::arg("theValue"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetValueOfZoneModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetValueOfZoneModifier, "Returns value associated with tolerance zone.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetModifiers", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModifiersSequence &)) &XCAFDimTolObjects_GeomToleranceObject::SetModifiers, "Sets new sequence of tolerance modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("AddModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_GeomToleranceModif)) &XCAFDimTolObjects_GeomToleranceObject::AddModifier, "Adds a tolerance modifier to the sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetModifiers", (XCAFDimTolObjects_GeomToleranceModifiersSequence (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetModifiers, "Returns a sequence of modifiers of the tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetMaxValueModifier", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const Standard_Real)) &XCAFDimTolObjects_GeomToleranceObject::SetMaxValueModifier, "Sets the maximal upper tolerance value for tolerance with modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetMaxValueModifier", (Standard_Real (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetMaxValueModifier, "Returns the maximal upper tolerance.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAxis", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2)) &XCAFDimTolObjects_GeomToleranceObject::SetAxis, "None", py::arg("theAxis"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAxis", (gp_Ax2 (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAxis, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasAxis", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasAxis, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_GeomToleranceObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPoint", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPoint, "Sets reference point.", py::arg("thePnt"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPoint, "Returns reference point.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_GeomToleranceObject::SetPointTextAttach, "Sets text position.", py::arg("thePntText"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPointTextAttach, "Returns the text position.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPlane, "Returns True if the object has annotation plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPoint, "Returns True if reference point is specified.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasPointText, "Returns True if text position is specified.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetPresentation", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_GeomToleranceObject::SetPresentation, "Set graphical presentation for object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetPresentationName, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_GeomToleranceObject.def("HasAffectedPlane", (bool (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::HasAffectedPlane, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAffectedPlaneType", (XCAFDimTolObjects_ToleranceZoneAffectedPlane (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAffectedPlaneType, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlaneType", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const XCAFDimTolObjects_ToleranceZoneAffectedPlane)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlaneType, "None", py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pln &)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlane, "Sets affected plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("SetAffectedPlane", (void (XCAFDimTolObjects_GeomToleranceObject::*)(const gp_Pln &, const XCAFDimTolObjects_ToleranceZoneAffectedPlane)) &XCAFDimTolObjects_GeomToleranceObject::SetAffectedPlane, "Sets affected plane.", py::arg("thePlane"), py::arg("theType"));
cls_XCAFDimTolObjects_GeomToleranceObject.def("GetAffectedPlane", (const gp_Pln & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::GetAffectedPlane, "Returns affected plane.");
cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_name, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_GeomToleranceObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_GeomToleranceObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_GeomToleranceObject::*)() const) &XCAFDimTolObjects_GeomToleranceObject::DynamicType, "None");

// Enums

}