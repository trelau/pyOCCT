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
#include <AIS_KindOfDimension.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pln.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <AIS_DisplaySpecialSymbol.hxx>
#include <TCollection_AsciiString.hxx>
#include <AIS_Dimension.hxx>
#include <Standard_Type.hxx>
#include <Prs3d_Presentation.hxx>
#include <gp_Dir.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Circ.hxx>
#include <Prs3d_DimensionTextHorizontalPosition.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Edge.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Handle.hxx>
#include <gp.hxx>

void bind_AIS_Dimension(py::module &mod){

py::class_<AIS_Dimension, opencascade::handle<AIS_Dimension>, AIS_InteractiveObject> cls_AIS_Dimension(mod, "AIS_Dimension", "AIS_Dimension is a base class for 2D presentations of linear (length, diameter, radius) and angular dimensions.");

// Constructors
cls_AIS_Dimension.def(py::init<const AIS_KindOfDimension>(), py::arg("theType"));

// Fields

// Methods
cls_AIS_Dimension.def("GetValue", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::GetValue, "Gets dimension measurement value. If the value to display is not specified by user, then the dimension object is responsible to compute it on its own in model space coordinates.");
cls_AIS_Dimension.def("SetComputedValue", (void (AIS_Dimension::*)()) &AIS_Dimension::SetComputedValue, "Sets computed dimension value. Resets custom value mode if it was set.");
cls_AIS_Dimension.def("SetCustomValue", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetCustomValue, "Sets user-defined dimension value. The user-defined dimension value is specified in model space, and affect by unit conversion during the display.", py::arg("theValue"));
cls_AIS_Dimension.def("SetCustomValue", (void (AIS_Dimension::*)(const TCollection_ExtendedString &)) &AIS_Dimension::SetCustomValue, "Sets user-defined dimension value. Unit conversion during the display is not applyed.", py::arg("theValue"));
cls_AIS_Dimension.def("GetCustomValue", (const TCollection_ExtendedString & (AIS_Dimension::*)() const) &AIS_Dimension::GetCustomValue, "Gets user-defined dimension value.");
cls_AIS_Dimension.def("GetPlane", (const gp_Pln & (AIS_Dimension::*)() const) &AIS_Dimension::GetPlane, "Get the dimension plane in which the 2D dimension presentation is computed. By default, if plane is not defined by user, it is computed automatically after dimension geometry is computed. If computed dimension geometry (points) can't be placed on the user-defined plane, dimension geometry was set as invalid (validity flag is set to false) and dimension presentation will not be computed. If user-defined plane allow geometry placement on it, it will be used for computing of the dimension presentation.");
cls_AIS_Dimension.def("GetGeometryType", (Standard_Integer (AIS_Dimension::*)() const) &AIS_Dimension::GetGeometryType, "Geometry type defines type of shapes on which the dimension is to be built.");
cls_AIS_Dimension.def("SetCustomPlane", (void (AIS_Dimension::*)(const gp_Pln &)) &AIS_Dimension::SetCustomPlane, "Sets user-defined plane where the 2D dimension presentation will be placed. Checks validity of this plane if geometry has been set already. Validity of the plane is checked according to the geometry set and has different criteria for different kinds of dimensions.", py::arg("thePlane"));
cls_AIS_Dimension.def("UnsetCustomPlane", (void (AIS_Dimension::*)()) &AIS_Dimension::UnsetCustomPlane, "Unsets user-defined plane. Therefore the plane for dimension will be computed automatically.");
cls_AIS_Dimension.def("IsTextPositionCustom", (Standard_Boolean (AIS_Dimension::*)() const) &AIS_Dimension::IsTextPositionCustom, "Returns TRUE if text position is set by user with method SetTextPosition().");
cls_AIS_Dimension.def("SetTextPosition", (void (AIS_Dimension::*)(const gp_Pnt &)) &AIS_Dimension::SetTextPosition, "Fixes the absolute text position and adjusts flyout, plane and text alignment according to it. Updates presentation if the text position is valid. ATTENTION! It does not change vertical text alignment.", py::arg(""));
cls_AIS_Dimension.def("GetTextPosition", (const gp_Pnt (AIS_Dimension::*)() const) &AIS_Dimension::GetTextPosition, "Computes absolute text position from dimension parameters (flyout, plane and text alignment).");
cls_AIS_Dimension.def("DimensionAspect", (opencascade::handle<Prs3d_DimensionAspect> (AIS_Dimension::*)() const) &AIS_Dimension::DimensionAspect, "Gets the dimension aspect from AIS object drawer. Dimension aspect contains aspects of line, text and arrows for dimension presentation.");
cls_AIS_Dimension.def("SetDimensionAspect", (void (AIS_Dimension::*)(const opencascade::handle<Prs3d_DimensionAspect> &)) &AIS_Dimension::SetDimensionAspect, "Sets new dimension aspect for the interactive object drawer. The dimension aspect provides dynamic properties which are generally used during computation of dimension presentations.", py::arg("theDimensionAspect"));
cls_AIS_Dimension.def("KindOfDimension", (AIS_KindOfDimension (AIS_Dimension::*)() const) &AIS_Dimension::KindOfDimension, "Returns the kind of dimension.");
cls_AIS_Dimension.def("Type", (AIS_KindOfInteractive (AIS_Dimension::*)() const) &AIS_Dimension::Type, "Returns the kind of interactive.");
cls_AIS_Dimension.def("AcceptDisplayMode", (Standard_Boolean (AIS_Dimension::*)(const Standard_Integer) const) &AIS_Dimension::AcceptDisplayMode, "Returns true if the class of objects accepts the display mode theMode. The interactive context can have a default mode of representation for the set of Interactive Objects. This mode may not be accepted by object.", py::arg("theMode"));
cls_AIS_Dimension.def("DisplaySpecialSymbol", (AIS_DisplaySpecialSymbol (AIS_Dimension::*)() const) &AIS_Dimension::DisplaySpecialSymbol, "Returns dimension special symbol display options.");
cls_AIS_Dimension.def("SetDisplaySpecialSymbol", (void (AIS_Dimension::*)(const AIS_DisplaySpecialSymbol)) &AIS_Dimension::SetDisplaySpecialSymbol, "Specifies whether to display special symbol or not.", py::arg("theDisplaySpecSymbol"));
cls_AIS_Dimension.def("SpecialSymbol", (Standard_ExtCharacter (AIS_Dimension::*)() const) &AIS_Dimension::SpecialSymbol, "Returns special symbol.");
cls_AIS_Dimension.def("SetSpecialSymbol", (void (AIS_Dimension::*)(const Standard_ExtCharacter)) &AIS_Dimension::SetSpecialSymbol, "Specifies special symbol.", py::arg("theSpecialSymbol"));
cls_AIS_Dimension.def("GetDisplayUnits", (const TCollection_AsciiString & (AIS_Dimension::*)() const) &AIS_Dimension::GetDisplayUnits, "None");
cls_AIS_Dimension.def("GetModelUnits", (const TCollection_AsciiString & (AIS_Dimension::*)() const) &AIS_Dimension::GetModelUnits, "None");
cls_AIS_Dimension.def("SetDisplayUnits", (void (AIS_Dimension::*)(const TCollection_AsciiString &)) &AIS_Dimension::SetDisplayUnits, "None", py::arg(""));
cls_AIS_Dimension.def("SetModelUnits", (void (AIS_Dimension::*)(const TCollection_AsciiString &)) &AIS_Dimension::SetModelUnits, "None", py::arg(""));
cls_AIS_Dimension.def("UnsetFixedTextPosition", (void (AIS_Dimension::*)()) &AIS_Dimension::UnsetFixedTextPosition, "Unsets user defined text positioning and enables text positioning by other parameters: text alignment, extension size, flyout and custom plane.");
cls_AIS_Dimension.def("SelToleranceForText2d", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::SelToleranceForText2d, "Returns selection tolerance for text2d: For 2d text selection detection sensitive point with tolerance is used Important! Only for 2d text.");
cls_AIS_Dimension.def("SetSelToleranceForText2d", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetSelToleranceForText2d, "Sets selection tolerance for text2d: For 2d text selection detection sensitive point with tolerance is used to change this tolerance use this method Important! Only for 2d text.", py::arg("theTol"));
cls_AIS_Dimension.def("GetFlyout", (Standard_Real (AIS_Dimension::*)() const) &AIS_Dimension::GetFlyout, "Returns flyout value for dimension.");
cls_AIS_Dimension.def("SetFlyout", (void (AIS_Dimension::*)(const Standard_Real)) &AIS_Dimension::SetFlyout, "Sets flyout value for dimension.", py::arg("theFlyout"));
cls_AIS_Dimension.def("IsValid", (Standard_Boolean (AIS_Dimension::*)() const) &AIS_Dimension::IsValid, "Check that the input geometry for dimension is valid and the presentation can be successfully computed.");
cls_AIS_Dimension.def_static("get_type_name_", (const char * (*)()) &AIS_Dimension::get_type_name, "None");
cls_AIS_Dimension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Dimension::get_type_descriptor, "None");
cls_AIS_Dimension.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Dimension::*)() const) &AIS_Dimension::DynamicType, "None");

// Enums
py::enum_<AIS_Dimension::ComputeMode>(cls_AIS_Dimension, "ComputeMode", "Specifies supported presentation compute modes. Used to compute only parts of presentation for advanced highlighting.")
	.value("ComputeMode_All", AIS_Dimension::ComputeMode::ComputeMode_All)
	.value("ComputeMode_Line", AIS_Dimension::ComputeMode::ComputeMode_Line)
	.value("ComputeMode_Text", AIS_Dimension::ComputeMode::ComputeMode_Text)
	.export_values();

}