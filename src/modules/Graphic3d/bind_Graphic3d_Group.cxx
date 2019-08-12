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
#include <Graphic3d_Structure.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Group.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_GroupAspect.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Graphic3d_TextPath.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Ax2.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Graphic3d_BndBox4f.hxx>

void bind_Graphic3d_Group(py::module &mod){

py::class_<Graphic3d_Group, opencascade::handle<Graphic3d_Group>, Standard_Transient> cls_Graphic3d_Group(mod, "Graphic3d_Group", "This class allows the definition of groups of primitives inside of graphic objects (presentations). A group contains the primitives and attributes for which the range is limited to this group. The primitives of a group can be globally suppressed.");

// Fields

// Methods
cls_Graphic3d_Group.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Group::get_type_name, "None");
cls_Graphic3d_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Group::get_type_descriptor, "None");
cls_Graphic3d_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Group::*)() const) &Graphic3d_Group::DynamicType, "None");
cls_Graphic3d_Group.def("Clear", [](Graphic3d_Group &self) -> void { return self.Clear(); });
cls_Graphic3d_Group.def("Clear", (void (Graphic3d_Group::*)(const Standard_Boolean)) &Graphic3d_Group::Clear, "Supress all primitives and attributes of <me>. To clear group without update in Graphic3d_StructureManager pass Standard_False as <theUpdateStructureMgr>. This used on context and viewer destruction, when the pointer to structure manager in Graphic3d_Structure could be already released (pointers are used here to avoid handle cross-reference);", py::arg("theUpdateStructureMgr"));
cls_Graphic3d_Group.def("Remove", (void (Graphic3d_Group::*)()) &Graphic3d_Group::Remove, "Supress the group <me> in the structure. Warning: No more graphic operations in <me> after this call. Modifies the current modelling transform persistence (pan, zoom or rotate) Get the current modelling transform persistence (pan, zoom or rotate)");
cls_Graphic3d_Group.def("LineAspect", (opencascade::handle<Graphic3d_AspectLine3d> (Graphic3d_Group::*)() const) &Graphic3d_Group::LineAspect, "Return line aspect.");
cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Assign line aspect to the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("FillAreaAspect", (opencascade::handle<Graphic3d_AspectFillArea3d> (Graphic3d_Group::*)() const) &Graphic3d_Group::FillAreaAspect, "Return fill area aspect.");
cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the face primitives of the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("TextAspect", (opencascade::handle<Graphic3d_AspectText3d> (Graphic3d_Group::*)() const) &Graphic3d_Group::TextAspect, "Return text aspect.");
cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the text primitives of the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("MarkerAspect", (opencascade::handle<Graphic3d_AspectMarker3d> (Graphic3d_Group::*)() const) &Graphic3d_Group::MarkerAspect, "Return marker aspect.");
cls_Graphic3d_Group.def("SetGroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Graphic3d_Group::SetGroupPrimitivesAspect, "Modifies the context for all the marker primitives of the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the line primitives created after this call in the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the face primitives created after this call in the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the text primitives created after this call in the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("SetPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Graphic3d_Group::SetPrimitivesAspect, "Modifies the current context of the group to give another aspect for all the marker primitives created after this call in the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("IsGroupPrimitivesAspectSet", (Standard_Boolean (Graphic3d_Group::*)(const Graphic3d_GroupAspect) const) &Graphic3d_Group::IsGroupPrimitivesAspectSet, "Returns TRUE if aspect is set for the group.", py::arg("theAspect"));
cls_Graphic3d_Group.def("GroupPrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &, const opencascade::handle<Graphic3d_AspectText3d> &, const opencascade::handle<Graphic3d_AspectMarker3d> &, const opencascade::handle<Graphic3d_AspectFillArea3d> &) const) &Graphic3d_Group::GroupPrimitivesAspect, "Returns the context of all the primitives of the group.", py::arg("theAspLine"), py::arg("theAspText"), py::arg("theAspMarker"), py::arg("theAspFill"));
cls_Graphic3d_Group.def("PrimitivesAspect", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &, const opencascade::handle<Graphic3d_AspectText3d> &, const opencascade::handle<Graphic3d_AspectMarker3d> &, const opencascade::handle<Graphic3d_AspectFillArea3d> &) const) &Graphic3d_Group::PrimitivesAspect, "Returns the last inserted context in the group for each kind of primitives.", py::arg("theAspLine"), py::arg("theAspText"), py::arg("theAspMarker"), py::arg("theAspFill"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const Graphic3d_Vertex & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const Graphic3d_Vertex &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). AAngle : Orientation of the text (with respect to the horizontal).", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"), py::arg("EvalMinMax"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const Graphic3d_Vertex & a1, const Standard_Real a2) -> void { return self.Text(a0, a1, a2); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const Graphic3d_Vertex &, const Standard_Real, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). The other attributes have the following default values: AAngle : PI / 2. ATp : TP_RIGHT AHta : HTA_LEFT AVta : VTA_BOTTOM", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("EvalMinMax"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const Graphic3d_Vertex & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const Graphic3d_Vertex &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). AAngle : Orientation of the text (with respect to the horizontal).", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("AAngle"), py::arg("ATp"), py::arg("AHta"), py::arg("AVta"), py::arg("EvalMinMax"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const Graphic3d_Vertex & a1, const Standard_Real a2) -> void { return self.Text(a0, a1, a2); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const Graphic3d_Vertex &, const Standard_Real, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <AText> at position <APoint>. The 3D point of attachment is projected. The text is written in the plane of projection. The attributes are given with respect to the plane of projection. AHeight : Height of text. (Relative to the Normalized Projection Coordinates (NPC) Space). The other attributes have the following default values: AAngle : PI / 2. ATp : TP_RIGHT AHta : HTA_LEFT AVta : VTA_BOTTOM", py::arg("AText"), py::arg("APoint"), py::arg("AHeight"), py::arg("EvalMinMax"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); });
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const Standard_CString a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6, const Standard_Boolean a7) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const Standard_CString, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <theText> at orientation <theOrientation> in 3D space.", py::arg("theTextUtf"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"), py::arg("theHasOwnAnchor"));
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6); });
cls_Graphic3d_Group.def("Text", [](Graphic3d_Group &self, const TCollection_ExtendedString & a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6, const Standard_Boolean a7) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_Graphic3d_Group.def("Text", (void (Graphic3d_Group::*)(const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean, const Standard_Boolean)) &Graphic3d_Group::Text, "Creates the string <theText> at orientation <theOrientation> in 3D space.", py::arg("theText"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"), py::arg("theHasOwnAnchor"));
cls_Graphic3d_Group.def("AddPrimitiveArray", [](Graphic3d_Group &self, const Graphic3d_TypeOfPrimitiveArray a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const opencascade::handle<Graphic3d_Buffer> & a2, const opencascade::handle<Graphic3d_BoundBuffer> & a3) -> void { return self.AddPrimitiveArray(a0, a1, a2, a3); });
cls_Graphic3d_Group.def("AddPrimitiveArray", (void (Graphic3d_Group::*)(const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &, const Standard_Boolean)) &Graphic3d_Group::AddPrimitiveArray, "Adds an array of primitives for display", py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"), py::arg("theToEvalMinMax"));
cls_Graphic3d_Group.def("AddPrimitiveArray", [](Graphic3d_Group &self, const opencascade::handle<Graphic3d_ArrayOfPrimitives> & a0) -> void { return self.AddPrimitiveArray(a0); });
cls_Graphic3d_Group.def("AddPrimitiveArray", (void (Graphic3d_Group::*)(const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean)) &Graphic3d_Group::AddPrimitiveArray, "Adds an array of primitives for display", py::arg("thePrim"), py::arg("theToEvalMinMax"));
cls_Graphic3d_Group.def("Marker", [](Graphic3d_Group &self, const Graphic3d_Vertex & a0) -> void { return self.Marker(a0); });
cls_Graphic3d_Group.def("Marker", (void (Graphic3d_Group::*)(const Graphic3d_Vertex &, const Standard_Boolean)) &Graphic3d_Group::Marker, "Creates a primitive array with single marker using AddPrimitiveArray().", py::arg("thePoint"), py::arg("theToEvalMinMax"));
cls_Graphic3d_Group.def("SetStencilTestOptions", (void (Graphic3d_Group::*)(const Standard_Boolean)) &Graphic3d_Group::SetStencilTestOptions, "sets the stencil test to theIsEnabled state;", py::arg("theIsEnabled"));
cls_Graphic3d_Group.def("SetFlippingOptions", (void (Graphic3d_Group::*)(const Standard_Boolean, const gp_Ax2 &)) &Graphic3d_Group::SetFlippingOptions, "sets the flipping to theIsEnabled state.", py::arg("theIsEnabled"), py::arg("theRefPlane"));
cls_Graphic3d_Group.def("ContainsFacet", (bool (Graphic3d_Group::*)() const) &Graphic3d_Group::ContainsFacet, "Returns true if the group contains Polygons, Triangles or Quadrangles.");
cls_Graphic3d_Group.def("IsDeleted", (Standard_Boolean (Graphic3d_Group::*)() const) &Graphic3d_Group::IsDeleted, "Returns Standard_True if the group <me> is deleted. <me> is deleted after the call Remove (me) or the associated structure is deleted.");
cls_Graphic3d_Group.def("IsEmpty", (Standard_Boolean (Graphic3d_Group::*)() const) &Graphic3d_Group::IsEmpty, "Returns Standard_True if the group <me> is empty.");
cls_Graphic3d_Group.def("MinMaxValues", [](Graphic3d_Group &self, Standard_Real & theXMin, Standard_Real & theYMin, Standard_Real & theZMin, Standard_Real & theXMax, Standard_Real & theYMax, Standard_Real & theZMax){ self.MinMaxValues(theXMin, theYMin, theZMin, theXMax, theYMax, theZMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theXMin, theYMin, theZMin, theXMax, theYMax, theZMax); }, "Returns the coordinates of the boundary box of the group.", py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));
cls_Graphic3d_Group.def("SetMinMaxValues", (void (Graphic3d_Group::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Group::SetMinMaxValues, "Sets the coordinates of the boundary box of the group.", py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));
cls_Graphic3d_Group.def("BoundingBox", (const Graphic3d_BndBox4f & (Graphic3d_Group::*)() const) &Graphic3d_Group::BoundingBox, "Returns boundary box of the group <me> without transformation applied,");
cls_Graphic3d_Group.def("ChangeBoundingBox", (Graphic3d_BndBox4f & (Graphic3d_Group::*)()) &Graphic3d_Group::ChangeBoundingBox, "Returns non-const boundary box of the group <me> without transformation applied,");
cls_Graphic3d_Group.def("Structure", (opencascade::handle<Graphic3d_Structure> (Graphic3d_Group::*)() const) &Graphic3d_Group::Structure, "Returns the structure containing the group <me>.");
cls_Graphic3d_Group.def("SetClosed", (void (Graphic3d_Group::*)(const bool)) &Graphic3d_Group::SetClosed, "Changes property shown that primitive arrays within this group form closed volume (do no contain open shells).", py::arg("theIsClosed"));
cls_Graphic3d_Group.def("IsClosed", (bool (Graphic3d_Group::*)() const) &Graphic3d_Group::IsClosed, "Return true if primitive arrays within this graphic group form closed volume (do no contain open shells).");

// Enums

}