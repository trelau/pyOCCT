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
#include <XCAFDoc_ClippingPlaneTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_ClippingPlaneTool(py::module &mod){

py::class_<XCAFDoc_ClippingPlaneTool, opencascade::handle<XCAFDoc_ClippingPlaneTool>, TDF_Attribute> cls_XCAFDoc_ClippingPlaneTool(mod, "XCAFDoc_ClippingPlaneTool", "Provide tool for management of ClippingPlane section of document. Provide tool to store, retrieve, remove and modify clipping planes. Each clipping plane consists of gp_Pln and its name.");

// Constructors
cls_XCAFDoc_ClippingPlaneTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_ClippingPlaneTool.def_static("Set_", (opencascade::handle<XCAFDoc_ClippingPlaneTool> (*)(const TDF_Label &)) &XCAFDoc_ClippingPlaneTool::Set, "Creates (if not exist) ClippingPlaneTool.", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ClippingPlaneTool::GetID, "None");
cls_XCAFDoc_ClippingPlaneTool.def("BaseLabel", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::BaseLabel, "returns the label under which ClippingPlanes are stored");
cls_XCAFDoc_ClippingPlaneTool.def("IsClippingPlane", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::IsClippingPlane, "Returns True if label belongs to a ClippingPlane table and is a ClippingPlane definition", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlane", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theLabel, gp_Pln & thePlane, TCollection_ExtendedString & theName, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetClippingPlane(theLabel, thePlane, theName, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Returns ClippingPlane defined by label lab Returns False if the label is not in ClippingPlane table or does not define a ClippingPlane", py::arg("theLabel"), py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlane", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theLabel, gp_Pln & thePlane, opencascade::handle<TCollection_HAsciiString> & theName, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetClippingPlane(theLabel, thePlane, theName, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Returns ClippingPlane defined by label lab Returns False if the label is not in ClippingPlane table or does not define a ClippingPlane", py::arg("theLabel"), py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const TCollection_ExtendedString, const Standard_Boolean) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const TCollection_ExtendedString) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("AddClippingPlane", (TDF_Label (XCAFDoc_ClippingPlaneTool::*)(const gp_Pln, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_ClippingPlaneTool::AddClippingPlane, "Adds a clipping plane definition to a ClippingPlane table and returns its label (returns existing label if the same clipping plane is already defined)", py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("RemoveClippingPlane", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::RemoveClippingPlane, "Removes clipping plane from the ClippingPlane table Return false and do nothing if clipping plane is referenced in at least one View", py::arg("theLabel"));
cls_XCAFDoc_ClippingPlaneTool.def("GetClippingPlanes", (void (XCAFDoc_ClippingPlaneTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ClippingPlaneTool::GetClippingPlanes, "Returns a sequence of clipping planes currently stored in the ClippingPlane table", py::arg("Labels"));
cls_XCAFDoc_ClippingPlaneTool.def("UpdateClippingPlane", (void (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &, const gp_Pln, const TCollection_ExtendedString) const) &XCAFDoc_ClippingPlaneTool::UpdateClippingPlane, "Sets new value of plane and name to the given clipping plane label or do nothing, if the given label is not a clipping plane label", py::arg("theLabelL"), py::arg("thePlane"), py::arg("theName"));
cls_XCAFDoc_ClippingPlaneTool.def("SetCapping", (void (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ClippingPlaneTool::SetCapping, "Set new value of capping for given clipping plane label", py::arg("theClippingPlaneL"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("GetCapping", (Standard_Boolean (XCAFDoc_ClippingPlaneTool::*)(const TDF_Label &) const) &XCAFDoc_ClippingPlaneTool::GetCapping, "Get capping value for given clipping plane label Return capping value", py::arg("theClippingPlaneL"));
cls_XCAFDoc_ClippingPlaneTool.def("GetCapping", [](XCAFDoc_ClippingPlaneTool &self, const TDF_Label & theClippingPlaneL, Standard_Boolean & theCapping){ Standard_Boolean rv = self.GetCapping(theClippingPlaneL, theCapping); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, theCapping); }, "Get capping value for given clipping plane label Return true if Label is valid abd capping is exist.", py::arg("theClippingPlaneL"), py::arg("theCapping"));
cls_XCAFDoc_ClippingPlaneTool.def("ID", (const Standard_GUID & (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::ID, "None");
cls_XCAFDoc_ClippingPlaneTool.def("Restore", (void (XCAFDoc_ClippingPlaneTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ClippingPlaneTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ClippingPlaneTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::NewEmpty, "None");
cls_XCAFDoc_ClippingPlaneTool.def("Paste", (void (XCAFDoc_ClippingPlaneTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ClippingPlaneTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ClippingPlaneTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ClippingPlaneTool::get_type_name, "None");
cls_XCAFDoc_ClippingPlaneTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ClippingPlaneTool::get_type_descriptor, "None");
cls_XCAFDoc_ClippingPlaneTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ClippingPlaneTool::*)() const) &XCAFDoc_ClippingPlaneTool::DynamicType, "None");

// Enums

}