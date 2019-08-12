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
#include <Graphic3d_Group.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Structure.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Graphic3d_TextPath.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <gp_Ax2.hxx>
#include <OpenGl_Structure.hxx>
#include <OpenGl_Element.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Group.hxx>
#include <OpenGl_AspectFace.hxx>
#include <OpenGl_AspectLine.hxx>
#include <OpenGl_AspectMarker.hxx>
#include <OpenGl_AspectText.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_Group(py::module &mod){

/*
py::class_<OpenGl_Group, opencascade::handle<OpenGl_Group>, Graphic3d_Group> cls_OpenGl_Group(mod, "OpenGl_Group", "Implementation of low-level graphic group.");

// Constructors
cls_OpenGl_Group.def(py::init<const opencascade::handle<Graphic3d_Structure> &>(), py::arg("theStruct"));

// Fields

// Methods
cls_OpenGl_Group.def("Clear", (void (OpenGl_Group::*)(const Standard_Boolean)) &OpenGl_Group::Clear, "None", py::arg("theToUpdateStructureMgr"));
cls_OpenGl_Group.def("LineAspect", (opencascade::handle<Graphic3d_AspectLine3d> (OpenGl_Group::*)() const) &OpenGl_Group::LineAspect, "Return line aspect.");
cls_OpenGl_Group.def("SetGroupPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &OpenGl_Group::SetGroupPrimitivesAspect, "Update line aspect.", py::arg("theAspect"));
cls_OpenGl_Group.def("SetPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &OpenGl_Group::SetPrimitivesAspect, "Append line aspect as an element.", py::arg("theAspect"));
cls_OpenGl_Group.def("MarkerAspect", (opencascade::handle<Graphic3d_AspectMarker3d> (OpenGl_Group::*)() const) &OpenGl_Group::MarkerAspect, "Return marker aspect.");
cls_OpenGl_Group.def("SetGroupPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &OpenGl_Group::SetGroupPrimitivesAspect, "Update marker aspect.", py::arg("theAspect"));
cls_OpenGl_Group.def("SetPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &OpenGl_Group::SetPrimitivesAspect, "Append marker aspect as an element.", py::arg("theAspect"));
cls_OpenGl_Group.def("FillAreaAspect", (opencascade::handle<Graphic3d_AspectFillArea3d> (OpenGl_Group::*)() const) &OpenGl_Group::FillAreaAspect, "Return fill area aspect.");
cls_OpenGl_Group.def("SetGroupPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &OpenGl_Group::SetGroupPrimitivesAspect, "Update face aspect.", py::arg("theAspect"));
cls_OpenGl_Group.def("SetPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &OpenGl_Group::SetPrimitivesAspect, "Append face aspect as an element.", py::arg("theAspect"));
cls_OpenGl_Group.def("TextAspect", (opencascade::handle<Graphic3d_AspectText3d> (OpenGl_Group::*)() const) &OpenGl_Group::TextAspect, "Return marker aspect.");
cls_OpenGl_Group.def("SetGroupPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &OpenGl_Group::SetGroupPrimitivesAspect, "Update text aspect.", py::arg("theAspect"));
cls_OpenGl_Group.def("SetPrimitivesAspect", (void (OpenGl_Group::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &OpenGl_Group::SetPrimitivesAspect, "Append text aspect as an element.", py::arg("theAspect"));
cls_OpenGl_Group.def("AddPrimitiveArray", (void (OpenGl_Group::*)(const Graphic3d_TypeOfPrimitiveArray, const opencascade::handle<Graphic3d_IndexBuffer> &, const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_BoundBuffer> &, const Standard_Boolean)) &OpenGl_Group::AddPrimitiveArray, "Add primitive array element", py::arg("theType"), py::arg("theIndices"), py::arg("theAttribs"), py::arg("theBounds"), py::arg("theToEvalMinMax"));
cls_OpenGl_Group.def("Text", (void (OpenGl_Group::*)(const Standard_CString, const Graphic3d_Vertex &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean)) &OpenGl_Group::Text, "Add text element", py::arg("theTextUtf"), py::arg("thePoint"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHta"), py::arg("theVta"), py::arg("theToEvalMinMax"));
cls_OpenGl_Group.def("Text", [](OpenGl_Group &self, const Standard_CString a0, const gp_Ax2 & a1, const Standard_Real a2, const Standard_Real a3, const Graphic3d_TextPath a4, const Graphic3d_HorizontalTextAlignment a5, const Graphic3d_VerticalTextAlignment a6, const Standard_Boolean a7) -> void { return self.Text(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_OpenGl_Group.def("Text", (void (OpenGl_Group::*)(const Standard_CString, const gp_Ax2 &, const Standard_Real, const Standard_Real, const Graphic3d_TextPath, const Graphic3d_HorizontalTextAlignment, const Graphic3d_VerticalTextAlignment, const Standard_Boolean, const Standard_Boolean)) &OpenGl_Group::Text, "Add text element in 3D space.", py::arg("theTextUtf"), py::arg("theOrientation"), py::arg("theHeight"), py::arg("theAngle"), py::arg("theTp"), py::arg("theHTA"), py::arg("theVTA"), py::arg("theToEvalMinMax"), py::arg("theHasOwnAnchor"));
cls_OpenGl_Group.def("SetFlippingOptions", (void (OpenGl_Group::*)(const Standard_Boolean, const gp_Ax2 &)) &OpenGl_Group::SetFlippingOptions, "Add flipping element", py::arg("theIsEnabled"), py::arg("theRefPlane"));
cls_OpenGl_Group.def("SetStencilTestOptions", (void (OpenGl_Group::*)(const Standard_Boolean)) &OpenGl_Group::SetStencilTestOptions, "Add stencil test element", py::arg("theIsEnabled"));
cls_OpenGl_Group.def("GlStruct", (OpenGl_Structure * (OpenGl_Group::*)() const) &OpenGl_Group::GlStruct, "None");
cls_OpenGl_Group.def("AddElement", (void (OpenGl_Group::*)(OpenGl_Element *)) &OpenGl_Group::AddElement, "None", py::arg("theElem"));
cls_OpenGl_Group.def("Render", (void (OpenGl_Group::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Group::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Group.def("Release", (void (OpenGl_Group::*)(const opencascade::handle<OpenGl_Context> &)) &OpenGl_Group::Release, "None", py::arg("theGlCtx"));
cls_OpenGl_Group.def("FirstNode", (const OpenGl_ElementNode * (OpenGl_Group::*)() const) &OpenGl_Group::FirstNode, "Returns first OpenGL element node of the group.");
cls_OpenGl_Group.def("AspectFace", (const OpenGl_AspectFace * (OpenGl_Group::*)() const) &OpenGl_Group::AspectFace, "Returns OpenGL face aspect.");
cls_OpenGl_Group.def("IsRaytracable", (Standard_Boolean (OpenGl_Group::*)() const) &OpenGl_Group::IsRaytracable, "Is the group ray-tracable (contains ray-tracable elements)?");
cls_OpenGl_Group.def_static("get_type_name_", (const char * (*)()) &OpenGl_Group::get_type_name, "None");
cls_OpenGl_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_Group::get_type_descriptor, "None");
cls_OpenGl_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_Group::*)() const) &OpenGl_Group::DynamicType, "None");

// Enums
*/

}