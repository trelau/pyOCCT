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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_Shape.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Prs3d_TypeOfHLR.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <gp_Pnt2d.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <TopLoc_Location.hxx>
#include <SelectMgr_Selection.hxx>
#include <Prs3d_Drawer.hxx>

void bind_AIS_Shape(py::module &mod){

py::class_<AIS_Shape, opencascade::handle<AIS_Shape>, AIS_InteractiveObject> cls_AIS_Shape(mod, "AIS_Shape", "A framework to manage presentation and selection of shapes. AIS_Shape is the interactive object which is used the most by applications. There are standard functions available which allow you to prepare selection operations on the constituent elements of shapes - vertices, edges, faces etc - in an open local context. The selection modes specific to 'Shape' type objects are referred to as Standard Activation Mode. These modes are only taken into account in open local context and only act on Interactive Objects which have redefined the virtual method AcceptShapeDecomposition so that it returns true. Several advanced functions are also available. These include functions to manage deviation angle and deviation coefficient - both HLR and non-HLR - of an inheriting shape class. These services allow you to select one type of shape interactive object for higher precision drawing. When you do this, the Prs3d_Drawer::IsOwn... functions corresponding to the above deviation angle and coefficient functions return true indicating that there is a local setting available for the specific object.");

// Constructors
cls_AIS_Shape.def(py::init<const TopoDS_Shape &>(), py::arg("shap"));

// Fields

// Methods
cls_AIS_Shape.def_static("get_type_name_", (const char * (*)()) &AIS_Shape::get_type_name, "None");
cls_AIS_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Shape::get_type_descriptor, "None");
cls_AIS_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Shape::*)() const) &AIS_Shape::DynamicType, "None");
cls_AIS_Shape.def("Signature", (Standard_Integer (AIS_Shape::*)() const) &AIS_Shape::Signature, "Returns index 0. This value refers to SHAPE from TopAbs_ShapeEnum");
cls_AIS_Shape.def("Type", (AIS_KindOfInteractive (AIS_Shape::*)() const) &AIS_Shape::Type, "Returns Object as the type of Interactive Object.");
cls_AIS_Shape.def("AcceptShapeDecomposition", (Standard_Boolean (AIS_Shape::*)() const) &AIS_Shape::AcceptShapeDecomposition, "Returns true if the Interactive Object accepts shape decomposition.");
cls_AIS_Shape.def("AcceptDisplayMode", (Standard_Boolean (AIS_Shape::*)(const Standard_Integer) const) &AIS_Shape::AcceptDisplayMode, "Return true if specified display mode is supported.", py::arg("theMode"));
cls_AIS_Shape.def("Shape", (const TopoDS_Shape & (AIS_Shape::*)() const) &AIS_Shape::Shape, "Returns this shape object.");
cls_AIS_Shape.def("SetShape", (void (AIS_Shape::*)(const TopoDS_Shape &)) &AIS_Shape::SetShape, "Constructs an instance of the shape object theShape.", py::arg("theShape"));
cls_AIS_Shape.def("Set", (void (AIS_Shape::*)(const TopoDS_Shape &)) &AIS_Shape::Set, "Alias for ::SetShape().", py::arg("theShape"));
cls_AIS_Shape.def("SetOwnDeviationCoefficient", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnDeviationCoefficient, "Sets a local value for deviation coefficient for this specific shape.");
cls_AIS_Shape.def("SetOwnHLRDeviationCoefficient", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnHLRDeviationCoefficient, "Sets a local value for HLR deviation coefficient for this specific shape.");
cls_AIS_Shape.def("SetOwnDeviationAngle", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnDeviationAngle, "Sets a local value for deviation angle for this specific shape.");
cls_AIS_Shape.def("SetOwnHLRDeviationAngle", (Standard_Boolean (AIS_Shape::*)()) &AIS_Shape::SetOwnHLRDeviationAngle, "Sets a local value for HLR deviation angle for this specific shape.");
cls_AIS_Shape.def("SetOwnDeviationCoefficient", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnDeviationCoefficient, "Sets a local value for deviation coefficient for this specific shape.", py::arg("aCoefficient"));
cls_AIS_Shape.def("SetOwnHLRDeviationCoefficient", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnHLRDeviationCoefficient, "sets myOwnHLRDeviationCoefficient field in Prs3d_Drawer & recomputes presentation", py::arg("aCoefficient"));
cls_AIS_Shape.def("SetAngleAndDeviation", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetAngleAndDeviation, "this compute a new angle and Deviation from the value anAngle and set the values stored in myDrawer with these that become local to the shape", py::arg("anAngle"));
cls_AIS_Shape.def("UserAngle", (Standard_Real (AIS_Shape::*)() const) &AIS_Shape::UserAngle, "gives back the angle initial value put by the User.");
cls_AIS_Shape.def("SetOwnDeviationAngle", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnDeviationAngle, "sets myOwnDeviationAngle field in Prs3d_Drawer & recomputes presentation", py::arg("anAngle"));
cls_AIS_Shape.def("SetHLRAngleAndDeviation", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetHLRAngleAndDeviation, "this compute a new Angle and Deviation from the value anAngle for HLR and set the values stored in myDrawer for with these that become local to the shape", py::arg("anAngle"));
cls_AIS_Shape.def("SetOwnHLRDeviationAngle", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetOwnHLRDeviationAngle, "sets myOwnHLRDeviationAngle field in Prs3d_Drawer & recomputes presentation", py::arg("anAngle"));
cls_AIS_Shape.def("OwnDeviationCoefficient", [](AIS_Shape &self, Standard_Real & aCoefficient, Standard_Real & aPreviousCoefficient){ Standard_Boolean rv = self.OwnDeviationCoefficient(aCoefficient, aPreviousCoefficient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, aCoefficient, aPreviousCoefficient); }, "Returns true and the values of the deviation coefficient aCoefficient and the previous deviation coefficient aPreviousCoefficient. If these values are not already set, false is returned.", py::arg("aCoefficient"), py::arg("aPreviousCoefficient"));
cls_AIS_Shape.def("OwnHLRDeviationCoefficient", [](AIS_Shape &self, Standard_Real & aCoefficient, Standard_Real & aPreviousCoefficient){ Standard_Boolean rv = self.OwnHLRDeviationCoefficient(aCoefficient, aPreviousCoefficient); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, aCoefficient, aPreviousCoefficient); }, "Returns true and the values of the HLR deviation coefficient aCoefficient and the previous HLR deviation coefficient aPreviousCoefficient. If these values are not already set, false is returned.", py::arg("aCoefficient"), py::arg("aPreviousCoefficient"));
cls_AIS_Shape.def("OwnDeviationAngle", [](AIS_Shape &self, Standard_Real & anAngle, Standard_Real & aPreviousAngle){ Standard_Boolean rv = self.OwnDeviationAngle(anAngle, aPreviousAngle); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, anAngle, aPreviousAngle); }, "Returns true and the values of the deviation angle anAngle and the previous deviation angle aPreviousAngle. If these values are not already set, false is returned.", py::arg("anAngle"), py::arg("aPreviousAngle"));
cls_AIS_Shape.def("OwnHLRDeviationAngle", [](AIS_Shape &self, Standard_Real & anAngle, Standard_Real & aPreviousAngle){ Standard_Boolean rv = self.OwnHLRDeviationAngle(anAngle, aPreviousAngle); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, anAngle, aPreviousAngle); }, "Returns true and the values of the HLR deviation angle anAngle and of the previous HLR deviation angle aPreviousAngle. If these values are not already set, false is returned.", py::arg("anAngle"), py::arg("aPreviousAngle"));
cls_AIS_Shape.def("SetTypeOfHLR", (void (AIS_Shape::*)(const Prs3d_TypeOfHLR)) &AIS_Shape::SetTypeOfHLR, "Sets the type of HLR algorithm used by the shape", py::arg("theTypeOfHLR"));
cls_AIS_Shape.def("TypeOfHLR", (Prs3d_TypeOfHLR (AIS_Shape::*)() const) &AIS_Shape::TypeOfHLR, "Gets the type of HLR algorithm");
cls_AIS_Shape.def("SetColor", (void (AIS_Shape::*)(const Quantity_Color &)) &AIS_Shape::SetColor, "Sets the color aColor in the reconstructed compound shape. Acts via the Drawer methods below on the appearance of: - free boundaries: Prs3d_Drawer_FreeBoundaryAspect, - isos: Prs3d_Drawer_UIsoAspect, Prs3dDrawer_VIsoAspect, - shared boundaries: Prs3d_Drawer_UnFreeBoundaryAspect, - shading: Prs3d_Drawer_ShadingAspect, - visible line color in hidden line mode: Prs3d_Drawer_SeenLineAspect - hidden line color in hidden line mode: Prs3d_Drawer_HiddenLineAspect.", py::arg("theColor"));
cls_AIS_Shape.def("UnsetColor", (void (AIS_Shape::*)()) &AIS_Shape::UnsetColor, "Removes settings for color in the reconstructed compound shape.");
cls_AIS_Shape.def("SetWidth", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetWidth, "Sets the value aValue for line width in the reconstructed compound shape. Changes line aspects for lines-only presentation modes like Wireframe and Bounding Box. Doesn't change face boundary line aspect.", py::arg("aValue"));
cls_AIS_Shape.def("UnsetWidth", (void (AIS_Shape::*)()) &AIS_Shape::UnsetWidth, "Removes the setting for line width in the reconstructed compound shape.");
cls_AIS_Shape.def("SetMaterial", (void (AIS_Shape::*)(const Graphic3d_MaterialAspect &)) &AIS_Shape::SetMaterial, "Allows you to provide settings for the material aName in the reconstructed compound shape.", py::arg("aName"));
cls_AIS_Shape.def("UnsetMaterial", (void (AIS_Shape::*)()) &AIS_Shape::UnsetMaterial, "Removes settings for material in the reconstructed compound shape.");
cls_AIS_Shape.def("SetTransparency", [](AIS_Shape &self) -> void { return self.SetTransparency(); });
cls_AIS_Shape.def("SetTransparency", (void (AIS_Shape::*)(const Standard_Real)) &AIS_Shape::SetTransparency, "Sets the value aValue for transparency in the reconstructed compound shape.", py::arg("aValue"));
cls_AIS_Shape.def("UnsetTransparency", (void (AIS_Shape::*)()) &AIS_Shape::UnsetTransparency, "Removes the setting for transparency in the reconstructed compound shape.");
cls_AIS_Shape.def("BoundingBox", (const Bnd_Box & (AIS_Shape::*)()) &AIS_Shape::BoundingBox, "Constructs a bounding box with which to reconstruct compound topological shapes for presentation.");
cls_AIS_Shape.def("Color", (void (AIS_Shape::*)(Quantity_Color &) const) &AIS_Shape::Color, "Returns the Color attributes of the shape accordingly to the current facing model;", py::arg("aColor"));
cls_AIS_Shape.def("Material", (Graphic3d_NameOfMaterial (AIS_Shape::*)() const) &AIS_Shape::Material, "Returns the NameOfMaterial attributes of the shape accordingly to the current facing model;");
cls_AIS_Shape.def("Transparency", (Standard_Real (AIS_Shape::*)() const) &AIS_Shape::Transparency, "Returns the transparency attributes of the shape accordingly to the current facing model;");
cls_AIS_Shape.def_static("SelectionType_", (TopAbs_ShapeEnum (*)(const Standard_Integer)) &AIS_Shape::SelectionType, "Return shape type for specified selection mode.", py::arg("theSelMode"));
cls_AIS_Shape.def_static("SelectionMode_", (Standard_Integer (*)(const TopAbs_ShapeEnum)) &AIS_Shape::SelectionMode, "Return selection mode for specified shape type.", py::arg("theShapeType"));
cls_AIS_Shape.def("TextureRepeatUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureRepeatUV, "Return texture repeat UV values; (1, 1) by default.");
cls_AIS_Shape.def("SetTextureRepeatUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureRepeatUV, "Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1). Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax).", py::arg("theRepeatUV"));
cls_AIS_Shape.def("TextureOriginUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureOriginUV, "Return texture origin UV position; (0, 0) by default.");
cls_AIS_Shape.def("SetTextureOriginUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureOriginUV, "Use this method to change the origin of the texture. The texel (0,0) will be mapped to the surface (myUVOrigin.X(), myUVOrigin.Y()).", py::arg("theOriginUV"));
cls_AIS_Shape.def("TextureScaleUV", (const gp_Pnt2d & (AIS_Shape::*)() const) &AIS_Shape::TextureScaleUV, "Return scale factor for UV coordinates; (1, 1) by default.");
cls_AIS_Shape.def("SetTextureScaleUV", (void (AIS_Shape::*)(const gp_Pnt2d &)) &AIS_Shape::SetTextureScaleUV, "Use this method to scale the texture (percent of the face). You can specify a scale factor for both U and V. Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat, the texture will appear twice on the face in each direction.", py::arg("theScaleUV"));
cls_AIS_Shape.def_static("computeHlrPresentation_", (void (*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &AIS_Shape::computeHlrPresentation, "Compute HLR presentation for specified shape.", py::arg("theProjector"), py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));

// Enums

}