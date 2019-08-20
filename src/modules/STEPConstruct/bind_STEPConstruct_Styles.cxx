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
#include <STEPConstruct_Tool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <TopoDS_Shape.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#include <StepShape_ContextDependentShapeRepresentation.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <StepVisual_Colour.hxx>
#include <Quantity_Color.hxx>
#include <STEPConstruct_DataMapOfAsciiStringTransient.hxx>
#include <STEPConstruct_DataMapOfPointTransient.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <STEPConstruct_Styles.hxx>

void bind_STEPConstruct_Styles(py::module &mod){

py::class_<STEPConstruct_Styles, std::unique_ptr<STEPConstruct_Styles>, STEPConstruct_Tool> cls_STEPConstruct_Styles(mod, "STEPConstruct_Styles", "Provides a mechanism for reading and writing shape styles (such as color) to and from the STEP file This tool maintains a list of styles, either taking them from STEP model (reading), or filling it by calls to AddStyle or directly (writing). Some methods deal with general structures of styles and presentations in STEP, but there are methods which deal with particular implementation of colors (as described in RP)");

// Constructors
cls_STEPConstruct_Styles.def(py::init<>());
cls_STEPConstruct_Styles.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));

// Fields

// Methods
// cls_STEPConstruct_Styles.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_Styles::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_Styles.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_Styles::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_Styles::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_Styles.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_Styles::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_Styles::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_Styles.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_Styles::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_Styles.def("Init", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<XSControl_WorkSession> &)) &STEPConstruct_Styles::Init, "Initializes tool; returns True if succeeded", py::arg("WS"));
cls_STEPConstruct_Styles.def("NbStyles", (Standard_Integer (STEPConstruct_Styles::*)() const) &STEPConstruct_Styles::NbStyles, "Returns number of defined styles");
cls_STEPConstruct_Styles.def("Style", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const Standard_Integer) const) &STEPConstruct_Styles::Style, "Returns style with given index", py::arg("i"));
cls_STEPConstruct_Styles.def("ClearStyles", (void (STEPConstruct_Styles::*)()) &STEPConstruct_Styles::ClearStyles, "Clears all defined styles and PSA sequence");
cls_STEPConstruct_Styles.def("AddStyle", (void (STEPConstruct_Styles::*)(const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Adds a style to a sequence", py::arg("style"));
cls_STEPConstruct_Styles.def("AddStyle", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &, const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Create a style linking giving PSA to the item, and add it to the sequence of stored styles. If Override is not Null, then the resulting style will be of the subtype OverridingStyledItem.", py::arg("item"), py::arg("PSA"), py::arg("Override"));
cls_STEPConstruct_Styles.def("AddStyle", (opencascade::handle<StepVisual_StyledItem> (STEPConstruct_Styles::*)(const TopoDS_Shape &, const opencascade::handle<StepVisual_PresentationStyleAssignment> &, const opencascade::handle<StepVisual_StyledItem> &)) &STEPConstruct_Styles::AddStyle, "Create a style linking giving PSA to the Shape, and add it to the sequence of stored styles. If Override is not Null, then the resulting style will be of the subtype OverridingStyledItem. The Sape is used to find corresponding STEP entity by call to STEPConstruct::FindEntity(), then previous method is called.", py::arg("Shape"), py::arg("PSA"), py::arg("Override"));
cls_STEPConstruct_Styles.def("CreateMDGPR", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationContext> &, opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation> &)) &STEPConstruct_Styles::CreateMDGPR, "Create MDGPR, fill it with all the styles previously defined, and add it to the model", py::arg("Context"), py::arg("MDGPR"));
cls_STEPConstruct_Styles.def("CreateNAUOSRD", (Standard_Boolean (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationContext> &, const opencascade::handle<StepShape_ContextDependentShapeRepresentation> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &STEPConstruct_Styles::CreateNAUOSRD, "Create MDGPR, fill it with all the styles previously defined, and add it to the model IMPORTANT: <initPDS> must be null when use for NAUO colors <initPDS> initialised only for SHUO case.", py::arg("Context"), py::arg("CDSR"), py::arg("initPDS"));
cls_STEPConstruct_Styles.def("FindContext", (opencascade::handle<StepRepr_RepresentationContext> (STEPConstruct_Styles::*)(const TopoDS_Shape &) const) &STEPConstruct_Styles::FindContext, "Searches the STEP model for the RepresentationContext in which given shape is defined. This context (if found) can be used then in call to CreateMDGPR()", py::arg("Shape"));
cls_STEPConstruct_Styles.def("LoadStyles", (Standard_Boolean (STEPConstruct_Styles::*)()) &STEPConstruct_Styles::LoadStyles, "Searches the STEP model for the MDGPR or DM entities (which bring styles) and fills sequence of styles");
cls_STEPConstruct_Styles.def("LoadInvisStyles", (Standard_Boolean (STEPConstruct_Styles::*)(opencascade::handle<TColStd_HSequenceOfTransient> &) const) &STEPConstruct_Styles::LoadInvisStyles, "Searches the STEP model for the INISIBILITY enteties (which bring styles) and fills out sequence of styles", py::arg("InvSyles"));
cls_STEPConstruct_Styles.def("MakeColorPSA", [](STEPConstruct_Styles &self, const opencascade::handle<StepRepr_RepresentationItem> & a0, const opencascade::handle<StepVisual_Colour> & a1, const opencascade::handle<StepVisual_Colour> & a2) -> opencascade::handle<StepVisual_PresentationStyleAssignment> { return self.MakeColorPSA(a0, a1, a2); });
cls_STEPConstruct_Styles.def("MakeColorPSA", (opencascade::handle<StepVisual_PresentationStyleAssignment> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_Colour> &, const opencascade::handle<StepVisual_Colour> &, const Standard_Boolean) const) &STEPConstruct_Styles::MakeColorPSA, "Create a PresentationStyleAssignment entity which defines two colors (for filling surfaces and curves) if isForNAUO true then returns PresentationStyleByContext", py::arg("item"), py::arg("SurfCol"), py::arg("CurveCol"), py::arg("isForNAUO"));
cls_STEPConstruct_Styles.def("GetColorPSA", (opencascade::handle<StepVisual_PresentationStyleAssignment> (STEPConstruct_Styles::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepVisual_Colour> &)) &STEPConstruct_Styles::GetColorPSA, "Returns a PresentationStyleAssignment entity which defines surface and curve colors as Col. This PSA is either created or taken from internal map where all PSAs created by this method are remembered.", py::arg("item"), py::arg("Col"));
cls_STEPConstruct_Styles.def("GetColors", [](STEPConstruct_Styles &self, const opencascade::handle<StepVisual_StyledItem> & style, opencascade::handle<StepVisual_Colour> & SurfCol, opencascade::handle<StepVisual_Colour> & BoundCol, opencascade::handle<StepVisual_Colour> & CurveCol, Standard_Boolean & IsComponent){ Standard_Boolean rv = self.GetColors(style, SurfCol, BoundCol, CurveCol, IsComponent); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, IsComponent); }, "Extract color definitions from the style entity For each type of color supported, result can be either NULL if it is not defined by that style, or last definition (if they are 1 or more)", py::arg("style"), py::arg("SurfCol"), py::arg("BoundCol"), py::arg("CurveCol"), py::arg("IsComponent"));
cls_STEPConstruct_Styles.def_static("EncodeColor_", (opencascade::handle<StepVisual_Colour> (*)(const Quantity_Color &)) &STEPConstruct_Styles::EncodeColor, "Create STEP color entity by given Quantity_Color The analysis is performed for whether the color corresponds to one of standard colors predefined in STEP. In that case, PredefinedColour entity is created instead of RGBColour", py::arg("Col"));
cls_STEPConstruct_Styles.def_static("EncodeColor_", (opencascade::handle<StepVisual_Colour> (*)(const Quantity_Color &, STEPConstruct_DataMapOfAsciiStringTransient &, STEPConstruct_DataMapOfPointTransient &)) &STEPConstruct_Styles::EncodeColor, "Create STEP color entity by given Quantity_Color The analysis is performed for whether the color corresponds to one of standard colors predefined in STEP. In that case, PredefinedColour entity is created instead of RGBColour", py::arg("Col"), py::arg("DPDCs"), py::arg("ColRGBs"));
cls_STEPConstruct_Styles.def_static("DecodeColor_", (Standard_Boolean (*)(const opencascade::handle<StepVisual_Colour> &, Quantity_Color &)) &STEPConstruct_Styles::DecodeColor, "Decodes STEP color and fills the Quantity_Color. Returns True if OK or False if color is not recognized", py::arg("Colour"), py::arg("Col"));

// Enums

}