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
#include <XCAFDimTolObjects_DatumObject.hxx>
#include <TCollection_HAsciiString.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDimTolObjects_DatumSingleModif.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFDimTolObjects_DatumTargetType.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDimTolObjects_DatumObject(py::module &mod){

py::class_<XCAFDimTolObjects_DatumObject, opencascade::handle<XCAFDimTolObjects_DatumObject>, Standard_Transient> cls_XCAFDimTolObjects_DatumObject(mod, "XCAFDimTolObjects_DatumObject", "Access object to store datum");

// Constructors
cls_XCAFDimTolObjects_DatumObject.def(py::init<>());
cls_XCAFDimTolObjects_DatumObject.def(py::init<const opencascade::handle<XCAFDimTolObjects_DatumObject> &>(), py::arg("theObj"));

// Fields

// Methods
cls_XCAFDimTolObjects_DatumObject.def("GetSemanticName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetSemanticName, "Returns semantic name");
cls_XCAFDimTolObjects_DatumObject.def("SetSemanticName", (void (XCAFDimTolObjects_DatumObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetSemanticName, "Sets semantic name", py::arg("theName"));
cls_XCAFDimTolObjects_DatumObject.def("GetName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetName, "Returns datum name.");
cls_XCAFDimTolObjects_DatumObject.def("SetName", (void (XCAFDimTolObjects_DatumObject::*)(const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetName, "Sets datum name.", py::arg("theTag"));
cls_XCAFDimTolObjects_DatumObject.def("GetModifiers", (XCAFDimTolObjects_DatumModifiersSequence (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetModifiers, "Returns a sequence of modifiers of the datum.");
cls_XCAFDimTolObjects_DatumObject.def("SetModifiers", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifiersSequence &)) &XCAFDimTolObjects_DatumObject::SetModifiers, "Sets new sequence of datum modifiers.", py::arg("theModifiers"));
cls_XCAFDimTolObjects_DatumObject.def("GetModifierWithValue", [](XCAFDimTolObjects_DatumObject &self, XCAFDimTolObjects_DatumModifWithValue & theModifier, Standard_Real & theValue){ self.GetModifierWithValue(theModifier, theValue); return theValue; }, "Retrieves datum modifier with value.", py::arg("theModifier"), py::arg("theValue"));
cls_XCAFDimTolObjects_DatumObject.def("SetModifierWithValue", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumModifWithValue, const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetModifierWithValue, "Sets datum modifier with value.", py::arg("theModifier"), py::arg("theValue"));
cls_XCAFDimTolObjects_DatumObject.def("AddModifier", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumSingleModif)) &XCAFDimTolObjects_DatumObject::AddModifier, "Adds a modifier to the datum sequence of modifiers.", py::arg("theModifier"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTarget", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTarget, "Returns datum target shape.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &)) &XCAFDimTolObjects_DatumObject::SetDatumTarget, "Sets datum target shape.", py::arg("theShape"));
cls_XCAFDimTolObjects_DatumObject.def("GetPosition", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPosition, "Returns datum position in the related geometric tolerance object.");
cls_XCAFDimTolObjects_DatumObject.def("SetPosition", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetPosition, "Sets datum position in the related geometric tolerance object.", py::arg("thePosition"));
cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "Returns True if the datum target is specified.");
cls_XCAFDimTolObjects_DatumObject.def("IsDatumTarget", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Boolean)) &XCAFDimTolObjects_DatumObject::IsDatumTarget, "Sets or drops the datum target indicator.", py::arg("theIsDT"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetType", (XCAFDimTolObjects_DatumTargetType (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetType, "Returns datum target type");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetType", (void (XCAFDimTolObjects_DatumObject::*)(const XCAFDimTolObjects_DatumTargetType)) &XCAFDimTolObjects_DatumObject::SetDatumTargetType, "Sets datum target to point, line, rectangle, circle or area type.", py::arg("theType"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetAxis", (gp_Ax2 (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetAxis, "Returns datum target axis. The Z axis of the datum placement denotes the normal of the surface pointing away from the material.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetAxis", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetDatumTargetAxis, "Sets datum target axis.", py::arg("theAxis"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetLength", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetLength, "Returns datum target length for line and rectangle types. The length along the X axis of the datum placement.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetLength", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetLength, "Sets datum target length.", py::arg("theLength"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetWidth", (Standard_Real (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetWidth, "Returns datum target width for rectangle type. The width along the derived Y axis, with the placement itself positioned at the centre of the rectangle.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetWidth", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Real)) &XCAFDimTolObjects_DatumObject::SetDatumTargetWidth, "Sets datum target width.", py::arg("theWidth"));
cls_XCAFDimTolObjects_DatumObject.def("GetDatumTargetNumber", (Standard_Integer (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetDatumTargetNumber, "Returns datum target number.");
cls_XCAFDimTolObjects_DatumObject.def("SetDatumTargetNumber", (void (XCAFDimTolObjects_DatumObject::*)(const Standard_Integer)) &XCAFDimTolObjects_DatumObject::SetDatumTargetNumber, "Sets datum target number.", py::arg("theNumber"));
cls_XCAFDimTolObjects_DatumObject.def("SetPlane", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Ax2 &)) &XCAFDimTolObjects_DatumObject::SetPlane, "Sets annotation plane.", py::arg("thePlane"));
cls_XCAFDimTolObjects_DatumObject.def("GetPlane", (const gp_Ax2 & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPlane, "Returns annotation plane.");
cls_XCAFDimTolObjects_DatumObject.def("SetPoint", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPoint, "Sets a point on the datum target shape.", py::arg("thePnt"));
cls_XCAFDimTolObjects_DatumObject.def("GetPoint", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPoint, "Gets point on the datum shape.");
cls_XCAFDimTolObjects_DatumObject.def("SetPointTextAttach", (void (XCAFDimTolObjects_DatumObject::*)(const gp_Pnt &)) &XCAFDimTolObjects_DatumObject::SetPointTextAttach, "Sets a position of the datum text.", py::arg("thePntText"));
cls_XCAFDimTolObjects_DatumObject.def("GetPointTextAttach", (const gp_Pnt & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPointTextAttach, "Gets datum text position.");
cls_XCAFDimTolObjects_DatumObject.def("HasPlane", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPlane, "Returns True if the datum has annotation plane.");
cls_XCAFDimTolObjects_DatumObject.def("HasPoint", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPoint, "Returns True if point on the datum target is specified.");
cls_XCAFDimTolObjects_DatumObject.def("HasPointText", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::HasPointText, "Returns True if the datum text position is specified.");
cls_XCAFDimTolObjects_DatumObject.def("SetPresentation", (void (XCAFDimTolObjects_DatumObject::*)(const TopoDS_Shape &, const opencascade::handle<TCollection_HAsciiString> &)) &XCAFDimTolObjects_DatumObject::SetPresentation, "Set graphical presentation for object.", py::arg("thePresentation"), py::arg("thePresentationName"));
cls_XCAFDimTolObjects_DatumObject.def("GetPresentation", (TopoDS_Shape (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPresentation, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DatumObject.def("GetPresentationName", (opencascade::handle<TCollection_HAsciiString> (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::GetPresentationName, "Returns graphical presentation of the object.");
cls_XCAFDimTolObjects_DatumObject.def("HasDatumTargetParams", (Standard_Boolean (XCAFDimTolObjects_DatumObject::*)()) &XCAFDimTolObjects_DatumObject::HasDatumTargetParams, "Returns True if the datum has valid parameters for datum target (width, length, circle radius etc)");
cls_XCAFDimTolObjects_DatumObject.def_static("get_type_name_", (const char * (*)()) &XCAFDimTolObjects_DatumObject::get_type_name, "None");
cls_XCAFDimTolObjects_DatumObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDimTolObjects_DatumObject::get_type_descriptor, "None");
cls_XCAFDimTolObjects_DatumObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDimTolObjects_DatumObject::*)() const) &XCAFDimTolObjects_DatumObject::DynamicType, "None");

// Enums

}