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
#include <NCollection_Vec4.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <gp_Pln.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Aspect_HatchStyle.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_ClipPlane(py::module &mod){

py::class_<Graphic3d_ClipPlane, opencascade::handle<Graphic3d_ClipPlane>, Standard_Transient> cls_Graphic3d_ClipPlane(mod, "Graphic3d_ClipPlane", "Container for properties describing graphic driver clipping planes. It is up to application to create instances of this class and specify its properties. The instances are passed into graphic driver or other facilities that implement clipping features (e.g. selection). Depending on usage context the class can be used to specify: - Global clipping applied over the whole scene. - Object-level clipping applied for each particular object. The plane equation is specified in 'world' coordinate system. Please note that the set of planes can define convex clipping volume. Be aware that number of clip planes supported by OpenGl is implementation dependent: at least 6 planes are available. Thus, take into account number of clipping planes passed for rendering: the object planes plus the view defined ones.");

// Constructors
cls_Graphic3d_ClipPlane.def(py::init<>());
cls_Graphic3d_ClipPlane.def(py::init<const Graphic3d_ClipPlane &>(), py::arg("theOther"));
cls_Graphic3d_ClipPlane.def(py::init<const Graphic3d_ClipPlane::Equation &>(), py::arg("theEquation"));
cls_Graphic3d_ClipPlane.def(py::init<const gp_Pln &>(), py::arg("thePlane"));

// Fields

// Methods
cls_Graphic3d_ClipPlane.def("SetEquation", (void (Graphic3d_ClipPlane::*)(const gp_Pln &)) &Graphic3d_ClipPlane::SetEquation, "Set plane equation by its geometrical definition. The equation is specified in 'world' coordinate system.", py::arg("thePlane"));
cls_Graphic3d_ClipPlane.def("SetEquation", (void (Graphic3d_ClipPlane::*)(const Graphic3d_ClipPlane::Equation &)) &Graphic3d_ClipPlane::SetEquation, "Set 4-component equation vector for clipping plane. The equation is specified in 'world' coordinate system.", py::arg("theEquation"));
cls_Graphic3d_ClipPlane.def("GetEquation", (const Graphic3d_ClipPlane::Equation & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::GetEquation, "Get 4-component equation vector for clipping plane.");
cls_Graphic3d_ClipPlane.def("IsOn", (Standard_Boolean (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::IsOn, "Check that the clipping plane is turned on.");
cls_Graphic3d_ClipPlane.def("SetOn", (void (Graphic3d_ClipPlane::*)(const Standard_Boolean)) &Graphic3d_ClipPlane::SetOn, "Change state of the clipping plane.", py::arg("theIsOn"));
cls_Graphic3d_ClipPlane.def("SetCapping", (void (Graphic3d_ClipPlane::*)(const Standard_Boolean)) &Graphic3d_ClipPlane::SetCapping, "Change state of capping surface rendering.", py::arg("theIsOn"));
cls_Graphic3d_ClipPlane.def("IsCapping", (Standard_Boolean (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::IsCapping, "Check state of capping surface rendering.");
cls_Graphic3d_ClipPlane.def("ToPlane", (const gp_Pln & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::ToPlane, "Get geometrical definition.");
cls_Graphic3d_ClipPlane.def("Clone", (opencascade::handle<Graphic3d_ClipPlane> (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::Clone, "Clone plane. Virtual method to simplify copying procedure if plane class is redefined at application level to add specific fields to it e.g. id, name, etc.");
cls_Graphic3d_ClipPlane.def("SetCappingMaterial", (void (Graphic3d_ClipPlane::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_ClipPlane::SetCappingMaterial, "Set material for rendering capping surface.", py::arg("theMat"));
cls_Graphic3d_ClipPlane.def("CappingMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::CappingMaterial, "Returns capping material.");
cls_Graphic3d_ClipPlane.def("SetCappingTexture", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_ClipPlane::SetCappingTexture, "Set texture to be applied on capping surface.", py::arg("theTexture"));
cls_Graphic3d_ClipPlane.def("CappingTexture", (opencascade::handle<Graphic3d_TextureMap> (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::CappingTexture, "Returns capping texture map.");
cls_Graphic3d_ClipPlane.def("SetCappingHatch", (void (Graphic3d_ClipPlane::*)(const Aspect_HatchStyle)) &Graphic3d_ClipPlane::SetCappingHatch, "Set hatch style (stipple) and turn hatching on.", py::arg("theStyle"));
cls_Graphic3d_ClipPlane.def("CappingHatch", (Aspect_HatchStyle (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::CappingHatch, "Returns hatching style.");
cls_Graphic3d_ClipPlane.def("SetCappingCustomHatch", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &Graphic3d_ClipPlane::SetCappingCustomHatch, "Set custom hatch style (stipple) and turn hatching on.", py::arg("theStyle"));
cls_Graphic3d_ClipPlane.def("CappingCustomHatch", (const opencascade::handle<Graphic3d_HatchStyle> & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::CappingCustomHatch, "Returns hatching style.");
cls_Graphic3d_ClipPlane.def("SetCappingHatchOn", (void (Graphic3d_ClipPlane::*)()) &Graphic3d_ClipPlane::SetCappingHatchOn, "Turn on hatching.");
cls_Graphic3d_ClipPlane.def("SetCappingHatchOff", (void (Graphic3d_ClipPlane::*)()) &Graphic3d_ClipPlane::SetCappingHatchOff, "Turn off hatching.");
cls_Graphic3d_ClipPlane.def("IsHatchOn", (Standard_Boolean (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::IsHatchOn, "Returns True if hatching mask is turned on.");
cls_Graphic3d_ClipPlane.def("GetId", (const TCollection_AsciiString & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::GetId, "This ID is used for managing associated resources in graphical driver. The clip plane can be assigned within a range of IO which can be displayed in separate OpenGl contexts. For each of the context an associated OpenGl resource for graphical aspects should be created and kept. The resources are stored in graphical driver for each of individual groups of shared context under the clip plane identifier.");
cls_Graphic3d_ClipPlane.def("CappingAspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::CappingAspect, "Return capping aspect.");
cls_Graphic3d_ClipPlane.def("SetCappingAspect", (void (Graphic3d_ClipPlane::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Graphic3d_ClipPlane::SetCappingAspect, "Assign capping aspect.", py::arg("theAspect"));
cls_Graphic3d_ClipPlane.def("ToUseObjectMaterial", (bool (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::ToUseObjectMaterial, "Flag indicating whether material for capping plane should be taken from object. Default value: FALSE (use dedicated capping plane material).");
cls_Graphic3d_ClipPlane.def("SetUseObjectMaterial", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectMaterial, "Set flag for controlling the source of capping plane material.", py::arg("theToUse"));
cls_Graphic3d_ClipPlane.def("ToUseObjectTexture", (bool (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::ToUseObjectTexture, "Flag indicating whether texture for capping plane should be taken from object. Default value: FALSE.");
cls_Graphic3d_ClipPlane.def("SetUseObjectTexture", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectTexture, "Set flag for controlling the source of capping plane texture.", py::arg("theToUse"));
cls_Graphic3d_ClipPlane.def("ToUseObjectShader", (bool (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::ToUseObjectShader, "Flag indicating whether shader program for capping plane should be taken from object. Default value: FALSE.");
cls_Graphic3d_ClipPlane.def("SetUseObjectShader", (void (Graphic3d_ClipPlane::*)(bool)) &Graphic3d_ClipPlane::SetUseObjectShader, "Set flag for controlling the source of capping plane shader program.", py::arg("theToUse"));
cls_Graphic3d_ClipPlane.def("ToUseObjectProperties", (bool (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::ToUseObjectProperties, "Return true if some fill area aspect properties should be taken from object.");
cls_Graphic3d_ClipPlane.def("MCountEquation", (unsigned int (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::MCountEquation, "Returns modification counter for equation.");
cls_Graphic3d_ClipPlane.def("MCountAspect", (unsigned int (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::MCountAspect, "Returns modification counter for aspect.");
cls_Graphic3d_ClipPlane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ClipPlane::get_type_name, "None");
cls_Graphic3d_ClipPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ClipPlane::get_type_descriptor, "None");
cls_Graphic3d_ClipPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ClipPlane::*)() const) &Graphic3d_ClipPlane::DynamicType, "None");

// Enums

}