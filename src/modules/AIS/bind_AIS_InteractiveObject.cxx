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
#include <SelectMgr_SelectableObject.hxx>
#include <AIS_InteractiveContext.hxx>
#include <Standard_Handle.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_Type.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Quantity_Color.hxx>
#include <Standard_Transient.hxx>
#include <Prs3d_Drawer.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>

void bind_AIS_InteractiveObject(py::module &mod){

py::class_<AIS_InteractiveObject, opencascade::handle<AIS_InteractiveObject>, SelectMgr_SelectableObject> cls_AIS_InteractiveObject(mod, "AIS_InteractiveObject", "Defines a class of objects with display and selection services. Entities which are visualized and selected are Interactive Objects. You can make use of classes of standard Interactive Objects for which all necessary methods have already been programmed, or you can implement your own classes of Interactive Objects. Specific attributes of entities such as arrow aspect for dimensions must be loaded in a Drawer. This Drawer is then applied to the Interactive Object in view. There are four types of Interactive Object in AIS: the construction element or Datum, the Relation, which includes both dimensions and constraints, the Object, and finally, when the object is of an unknown type, the None type. Inside these categories, a signature, or index, provides the possibility of additional characterization. By default, the Interactive Object has a None type and a signature of 0. If you want to give a particular type and signature to your interactive object, you must redefine the methods, Signature and Type. Warning In the case of attribute methods, methods for standard attributes are virtual. They must be redefined by the inheriting classes. Setcolor for a point and Setcolor for a plane, for example, do not affect the same attributes in the Drawer.");

// Fields

// Methods
cls_AIS_InteractiveObject.def_static("get_type_name_", (const char * (*)()) &AIS_InteractiveObject::get_type_name, "None");
cls_AIS_InteractiveObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_InteractiveObject::get_type_descriptor, "None");
cls_AIS_InteractiveObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::DynamicType, "None");
cls_AIS_InteractiveObject.def("Type", (AIS_KindOfInteractive (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Type, "Returns the kind of Interactive Object: - None - Datum - Relation - Object By default, the interactive object has a None type. Because specific shapes entail different behavior according to their sub-shapes, you may need to create a Local Context. This will allow you to specify the additional characteristics which you need to handle these shapes.");
cls_AIS_InteractiveObject.def("Signature", (Standard_Integer (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Signature, "Specifies additional characteristics of Interactive Objects. A signature is, in fact, an index with integer values assigned different properties. This method is frequently used in conjuction with Type to give a particular type and signature to an Interactive Object. By default, the Interactive Object has a None type and a signature of 0. Among the datums, this signature is attributed to the shape The remaining datums have the following default signatures: - Point signature 1 - Axis signature 2 - Trihedron signature 3 - PlaneTrihedron signature 4 - Line signature 5 - Circle signature 6 - Plane signature 7.");
cls_AIS_InteractiveObject.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::AcceptShapeDecomposition, "Informs the graphic context that the interactive Object may be decomposed into sub-shapes for dynamic selection. The most used Interactive Object is AIS_Shape. Activation methods for standard selection modes are proposed in the Interactive Context. These include selection by vertex or by edges. For datums with the same behavior as AIS_Shape, such as vetices and edges, we must redefine the virtual method so that AcceptShapeDecomposition returns false. Rule for selection : Mode 0 : Selection of the interactive Object itself Mode 1 : Selection of vertices Mode 2 : Selection Of Edges Mode 3 : Selection Of Wires Mode 4 : Selection Of Faces ...");
cls_AIS_InteractiveObject.def("SetCurrentFacingModel", [](AIS_InteractiveObject &self) -> void { return self.SetCurrentFacingModel(); });
cls_AIS_InteractiveObject.def("SetCurrentFacingModel", (void (AIS_InteractiveObject::*)(const Aspect_TypeOfFacingModel)) &AIS_InteractiveObject::SetCurrentFacingModel, "change the current facing model apply on polygons for SetColor(), SetTransparency(), SetMaterial() methods default facing model is Aspect_TOFM_TWO_SIDE. This mean that attributes is applying both on the front and back face.", py::arg("aModel"));
cls_AIS_InteractiveObject.def("CurrentFacingModel", (Aspect_TypeOfFacingModel (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::CurrentFacingModel, "Returns the current facing model which is in effect.");
cls_AIS_InteractiveObject.def("SetColor", (void (AIS_InteractiveObject::*)(const Quantity_Color &)) &AIS_InteractiveObject::SetColor, "Only the interactive object knowns which Drawer attribute is affected by the color, if any (ex: for a wire,it's the wireaspect field of the drawer, but for a vertex, only the point aspect field is affected by the color). WARNING : Do not forget to set the corresponding fields here (hasOwnColor and myDrawer->SetColor())", py::arg("theColor"));
cls_AIS_InteractiveObject.def("UnsetColor", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetColor, "Removes color settings. Only the Interactive Object knows which Drawer attribute is affected by the color setting. For a wire, for example, wire aspect is the attribute affected. For a vertex, however, only point aspect is affected by the color setting.");
cls_AIS_InteractiveObject.def("SetWidth", (void (AIS_InteractiveObject::*)(const Standard_Real)) &AIS_InteractiveObject::SetWidth, "Allows you to provide the setting aValue for width. Only the Interactive Object knows which Drawer attribute is affected by the width setting.", py::arg("aValue"));
cls_AIS_InteractiveObject.def("UnsetWidth", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetWidth, "None");
cls_AIS_InteractiveObject.def("AcceptDisplayMode", (Standard_Boolean (AIS_InteractiveObject::*)(const Standard_Integer) const) &AIS_InteractiveObject::AcceptDisplayMode, "Returns true if the class of objects accepts the display mode aMode. The interactive context can have a default mode of representation for the set of Interactive Objects. This mode may not be accepted by a given class of objects. Consequently, this virtual method allowing us to get information about the class in question must be implemented.", py::arg("aMode"));
cls_AIS_InteractiveObject.def("DefaultDisplayMode", (Standard_Integer (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::DefaultDisplayMode, "Returns the default display mode. This method is to be implemented when the main mode is not mode 0.");
cls_AIS_InteractiveObject.def("Redisplay", [](AIS_InteractiveObject &self) -> void { return self.Redisplay(); });
cls_AIS_InteractiveObject.def("Redisplay", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::Redisplay, "Updates the active presentation; if <AllModes> = Standard_True all the presentations inside are recomputed. IMPORTANT: It is preferable to call Redisplay method of corresponding AIS_InteractiveContext instance for cases when it is accessible. This method just redirects call to myCTXPtr, so this class field must be up to date for proper result.", py::arg("AllModes"));
cls_AIS_InteractiveObject.def("SetInfiniteState", [](AIS_InteractiveObject &self) -> void { return self.SetInfiniteState(); });
cls_AIS_InteractiveObject.def("SetInfiniteState", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::SetInfiniteState, "Sets the infinite state flag aFlage. if <aFlag> = True , the interactiveObject is considered as infinite, i.e. its graphic presentations are not taken in account for View FitAll...", py::arg("aFlag"));
cls_AIS_InteractiveObject.def("IsInfinite", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::IsInfinite, "Returns true if the interactive object is infinite. In this case, its graphic presentations are not taken into account in the fit-all view.");
cls_AIS_InteractiveObject.def("HasInteractiveContext", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasInteractiveContext, "Indicates whether the Interactive Object has a pointer to an interactive context.");
cls_AIS_InteractiveObject.def("GetContext", (opencascade::handle<AIS_InteractiveContext> (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::GetContext, "Returns the context pointer to the interactive context.");
cls_AIS_InteractiveObject.def("SetContext", (void (AIS_InteractiveObject::*)(const opencascade::handle<AIS_InteractiveContext> &)) &AIS_InteractiveObject::SetContext, "Sets the interactive context aCtx and provides a link to the default drawing tool or 'Drawer' if there is none.", py::arg("aCtx"));
cls_AIS_InteractiveObject.def("HasOwner", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasOwner, "Returns true if the object has an owner attributed to it. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient.");
cls_AIS_InteractiveObject.def("GetOwner", (const opencascade::handle<Standard_Transient> & (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::GetOwner, "Returns the owner of the Interactive Object. The owner can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of, and takes the form of a transient. There are two types of owners: - Direct owners, decomposition shapes such as edges, wires, and faces. - Users, presentable objects connecting to sensitive primitives, or a shape which has been decomposed.");
cls_AIS_InteractiveObject.def("SetOwner", (void (AIS_InteractiveObject::*)(const opencascade::handle<Standard_Transient> &)) &AIS_InteractiveObject::SetOwner, "Allows you to attribute the owner theApplicativeEntity to an Interactive Object. This can be a shape for a set of sub-shapes or a sub-shape for sub-shapes which it is composed of. The owner takes the form of a transient.", py::arg("theApplicativeEntity"));
cls_AIS_InteractiveObject.def("ClearOwner", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::ClearOwner, "Each Interactive Object has methods which allow us to attribute an Owner to it in the form of a Transient. This method removes the owner from the graphic entity.");
cls_AIS_InteractiveObject.def("HasDisplayMode", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasDisplayMode, "Returns true if the Interactive Object has a display mode setting. Otherwise, it is displayed in Neutral Point.");
cls_AIS_InteractiveObject.def("SetDisplayMode", (void (AIS_InteractiveObject::*)(const Standard_Integer)) &AIS_InteractiveObject::SetDisplayMode, "Sets the display mode aMode for the interactive object. An object can have its own temporary display mode, which is different from that proposed by the interactive context. The range of possibilities currently proposed is the following: - AIS_WireFrame - AIS_Shaded This range can, however, be extended through the creation of new display modes.", py::arg("aMode"));
cls_AIS_InteractiveObject.def("UnsetDisplayMode", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetDisplayMode, "Removes display mode settings from the interactive object.");
cls_AIS_InteractiveObject.def("DisplayMode", (Standard_Integer (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::DisplayMode, "Returns the display mode setting of the Interactive Object. The range of possibilities is the following: - AIS_WireFrame - AIS_Shaded This range can, however, be extended through the creation of new display modes.");
cls_AIS_InteractiveObject.def("HasHilightMode", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasHilightMode, "Returns true if the Interactive Object is in highlight mode.");
cls_AIS_InteractiveObject.def("HilightMode", (Standard_Integer (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HilightMode, "Returns highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.");
cls_AIS_InteractiveObject.def("SetHilightMode", (void (AIS_InteractiveObject::*)(const Standard_Integer)) &AIS_InteractiveObject::SetHilightMode, "Sets highlight display mode. This is obsolete method for backward compatibility - use ::HilightAttributes() and ::DynamicHilightAttributes() instead.", py::arg("theMode"));
cls_AIS_InteractiveObject.def("UnsetHilightMode", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetHilightMode, "Unsets highlight display mode.");
cls_AIS_InteractiveObject.def("HasColor", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasColor, "Returns true if the Interactive Object has color.");
cls_AIS_InteractiveObject.def("Color", (void (AIS_InteractiveObject::*)(Quantity_Color &) const) &AIS_InteractiveObject::Color, "Returns the color setting of the Interactive Object.", py::arg("theColor"));
cls_AIS_InteractiveObject.def("HasWidth", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasWidth, "Returns true if the Interactive Object has width.");
cls_AIS_InteractiveObject.def("Width", (Standard_Real (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Width, "Returns the width setting of the Interactive Object.");
cls_AIS_InteractiveObject.def("HasMaterial", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasMaterial, "Returns true if the Interactive Object has a setting for material.");
cls_AIS_InteractiveObject.def("Material", (Graphic3d_NameOfMaterial (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Material, "Returns the current material setting. This will be on of the following materials: - Brass - Bronze - Gold - Pewter - Silver - Stone.");
cls_AIS_InteractiveObject.def("SetMaterial", (void (AIS_InteractiveObject::*)(const Graphic3d_MaterialAspect &)) &AIS_InteractiveObject::SetMaterial, "Sets the material aMat defining this display attribute for the interactive object. Material aspect determines shading aspect, color and transparency of visible entities.", py::arg("aName"));
cls_AIS_InteractiveObject.def("UnsetMaterial", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetMaterial, "Removes the setting for material.");
cls_AIS_InteractiveObject.def("SetTransparency", [](AIS_InteractiveObject &self) -> void { return self.SetTransparency(); });
cls_AIS_InteractiveObject.def("SetTransparency", (void (AIS_InteractiveObject::*)(const Standard_Real)) &AIS_InteractiveObject::SetTransparency, "Attributes a setting aValue for transparency. The transparency value should be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent. Warning At a value of 1.0, there may be nothing visible.", py::arg("aValue"));
cls_AIS_InteractiveObject.def("IsTransparent", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::IsTransparent, "Returns true if there is a transparency setting.");
cls_AIS_InteractiveObject.def("Transparency", (Standard_Real (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Transparency, "Returns the transparency setting. This will be between 0.0 and 1.0. At 0.0 an object will be totally opaque, and at 1.0, fully transparent.");
cls_AIS_InteractiveObject.def("UnsetTransparency", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetTransparency, "Removes the transparency setting. The object is opaque by default.");
cls_AIS_InteractiveObject.def("UnsetAttributes", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::UnsetAttributes, "Clears settings provided by the drawing tool aDrawer.");
cls_AIS_InteractiveObject.def("HasPresentation", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasPresentation, "Returns TRUE when this object has a presentation in the current DisplayMode()");
cls_AIS_InteractiveObject.def("Presentation", (opencascade::handle<Prs3d_Presentation> (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::Presentation, "Returns the current presentation of this object according to the current DisplayMode()");
cls_AIS_InteractiveObject.def("SetAspect", (void (AIS_InteractiveObject::*)(const opencascade::handle<Prs3d_BasicAspect> &)) &AIS_InteractiveObject::SetAspect, "Sets the graphic basic aspect to the current presentation.", py::arg("anAspect"));
cls_AIS_InteractiveObject.def("SetPolygonOffsets", [](AIS_InteractiveObject &self, const Standard_Integer a0) -> void { return self.SetPolygonOffsets(a0); });
cls_AIS_InteractiveObject.def("SetPolygonOffsets", [](AIS_InteractiveObject &self, const Standard_Integer a0, const Standard_ShortReal a1) -> void { return self.SetPolygonOffsets(a0, a1); });
cls_AIS_InteractiveObject.def("SetPolygonOffsets", (void (AIS_InteractiveObject::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal)) &AIS_InteractiveObject::SetPolygonOffsets, "Sets up polygon offsets for this object. It modifies all existing presentations of <anObj> (if any), so it is reasonable to call this method after <anObj> has been displayed. Otherwise, Compute() method should pass Graphic3d_AspectFillArea3d aspect from <myDrawer> to Graphic3d_Group to make polygon offsets work.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
cls_AIS_InteractiveObject.def("HasPolygonOffsets", (Standard_Boolean (AIS_InteractiveObject::*)() const) &AIS_InteractiveObject::HasPolygonOffsets, "Returns Standard_True if <myDrawer> has non-null shading aspect");
cls_AIS_InteractiveObject.def("PolygonOffsets", [](AIS_InteractiveObject &self, Standard_Integer & aMode, Standard_ShortReal & aFactor, Standard_ShortReal & aUnits){ self.PolygonOffsets(aMode, aFactor, aUnits); return aMode; }, "Retrieves current polygon offsets settings from <myDrawer>.", py::arg("aMode"), py::arg("aFactor"), py::arg("aUnits"));
cls_AIS_InteractiveObject.def("BoundingBox", (void (AIS_InteractiveObject::*)(Bnd_Box &)) &AIS_InteractiveObject::BoundingBox, "Returns bounding box of object correspondingly to its current display mode.", py::arg("theBndBox"));
cls_AIS_InteractiveObject.def("SetIsoOnTriangulation", (void (AIS_InteractiveObject::*)(const Standard_Boolean)) &AIS_InteractiveObject::SetIsoOnTriangulation, "Enables or disables on-triangulation build of isolines according to the flag given.", py::arg("theIsEnabled"));
cls_AIS_InteractiveObject.def("SynchronizeAspects", (void (AIS_InteractiveObject::*)()) &AIS_InteractiveObject::SynchronizeAspects, "Synchronize presentation aspects after their modification.");

// Enums

}