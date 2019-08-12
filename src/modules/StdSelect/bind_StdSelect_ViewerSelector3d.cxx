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
#include <SelectMgr_ViewerSelector.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <V3d_View.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Image_PixMap.hxx>
#include <StdSelect_TypeOfSelectionImage.hxx>
#include <SelectMgr_Selection.hxx>
#include <gp_Trsf.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <StdSelect_ViewerSelector3d.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_SequenceOfStructure.hxx>

void bind_StdSelect_ViewerSelector3d(py::module &mod){

py::class_<StdSelect_ViewerSelector3d, opencascade::handle<StdSelect_ViewerSelector3d>, SelectMgr_ViewerSelector> cls_StdSelect_ViewerSelector3d(mod, "StdSelect_ViewerSelector3d", "Selector Usable by Viewers from V3d");

// Constructors
cls_StdSelect_ViewerSelector3d.def(py::init<>());

// Fields

// Methods
cls_StdSelect_ViewerSelector3d.def("SetPixelTolerance", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer)) &StdSelect_ViewerSelector3d::SetPixelTolerance, "Sets the pixel tolerance <theTolerance>.", py::arg("theTolerance"));
cls_StdSelect_ViewerSelector3d.def("PixelTolerance", (Standard_Integer (StdSelect_ViewerSelector3d::*)() const) &StdSelect_ViewerSelector3d::PixelTolerance, "Returns the pixel tolerance.");
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "Picks the sensitive entity at the pixel coordinates of the mouse <theXPix> and <theYPix>. The selector looks for touched areas and owners.", py::arg("theXPix"), py::arg("theYPix"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "Picks the sensitive entity according to the minimum and maximum pixel values <theXPMin>, <theYPMin>, <theXPMax> and <theYPMax> defining a 2D area for selection in the 3D view aView.", py::arg("theXPMin"), py::arg("theYPMin"), py::arg("theXPMax"), py::arg("theYPMax"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("Pick", (void (StdSelect_ViewerSelector3d::*)(const TColgp_Array1OfPnt2d &, const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::Pick, "pick action - input pixel values for polyline selection for selection.", py::arg("thePolyline"), py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("ToPixMap", [](StdSelect_ViewerSelector3d &self, Image_PixMap & a0, const opencascade::handle<V3d_View> & a1, const StdSelect_TypeOfSelectionImage a2) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2); });
cls_StdSelect_ViewerSelector3d.def("ToPixMap", (Standard_Boolean (StdSelect_ViewerSelector3d::*)(Image_PixMap &, const opencascade::handle<V3d_View> &, const StdSelect_TypeOfSelectionImage, const Standard_Integer)) &StdSelect_ViewerSelector3d::ToPixMap, "Dump of detection results into image. This method performs axis picking for each pixel in the image and generates a color depending on picking results and selection image type.", py::arg("theImage"), py::arg("theView"), py::arg("theType"), py::arg("thePickedIndex"));
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::DisplaySensitive, "Displays sensitives in view <theView>.", py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("ClearSensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<V3d_View> &)) &StdSelect_ViewerSelector3d::ClearSensitive, "None", py::arg("theView"));
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", [](StdSelect_ViewerSelector3d &self, const opencascade::handle<SelectMgr_Selection> & a0, const gp_Trsf & a1, const opencascade::handle<V3d_View> & a2) -> void { return self.DisplaySensitive(a0, a1, a2); });
cls_StdSelect_ViewerSelector3d.def("DisplaySensitive", (void (StdSelect_ViewerSelector3d::*)(const opencascade::handle<SelectMgr_Selection> &, const gp_Trsf &, const opencascade::handle<V3d_View> &, const Standard_Boolean)) &StdSelect_ViewerSelector3d::DisplaySensitive, "None", py::arg("theSel"), py::arg("theTrsf"), py::arg("theView"), py::arg("theToClearOthers"));
cls_StdSelect_ViewerSelector3d.def("HasDepthClipping", (Standard_Boolean (StdSelect_ViewerSelector3d::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &StdSelect_ViewerSelector3d::HasDepthClipping, "None", py::arg("theOwner"));
cls_StdSelect_ViewerSelector3d.def_static("get_type_name_", (const char * (*)()) &StdSelect_ViewerSelector3d::get_type_name, "None");
cls_StdSelect_ViewerSelector3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_ViewerSelector3d::get_type_descriptor, "None");
cls_StdSelect_ViewerSelector3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_ViewerSelector3d::*)() const) &StdSelect_ViewerSelector3d::DynamicType, "None");

// Enums

}