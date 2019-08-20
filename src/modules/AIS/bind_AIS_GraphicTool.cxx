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
#include <Standard.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Drawer.hxx>
#include <AIS_TypeOfAttribute.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <AIS_GraphicTool.hxx>

void bind_AIS_GraphicTool(py::module &mod){

py::class_<AIS_GraphicTool, std::unique_ptr<AIS_GraphicTool>> cls_AIS_GraphicTool(mod, "AIS_GraphicTool", "None");

// Constructors

// Fields

// Methods
// cls_AIS_GraphicTool.def_static("operator new_", (void * (*)(size_t)) &AIS_GraphicTool::operator new, "None", py::arg("theSize"));
// cls_AIS_GraphicTool.def_static("operator delete_", (void (*)(void *)) &AIS_GraphicTool::operator delete, "None", py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator new[]_", (void * (*)(size_t)) &AIS_GraphicTool::operator new[], "None", py::arg("theSize"));
// cls_AIS_GraphicTool.def_static("operator delete[]_", (void (*)(void *)) &AIS_GraphicTool::operator delete[], "None", py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator new_", (void * (*)(size_t, void *)) &AIS_GraphicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AIS_GraphicTool.def_static("operator delete_", (void (*)(void *, void *)) &AIS_GraphicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_AIS_GraphicTool.def_static("GetLineColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute, Quantity_Color &)) &AIS_GraphicTool::GetLineColor, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("TheLineColor"));
cls_AIS_GraphicTool.def_static("GetLineWidth_", (Standard_Real (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineWidth, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineType_", (Aspect_TypeOfLine (*)(const opencascade::handle<Prs3d_Drawer> &, const AIS_TypeOfAttribute)) &AIS_GraphicTool::GetLineType, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"));
cls_AIS_GraphicTool.def_static("GetLineAtt_", [](const opencascade::handle<Prs3d_Drawer> & aDrawer, const AIS_TypeOfAttribute TheTypeOfAttributes, Quantity_NameOfColor & aCol, Standard_Real & aWidth, Aspect_TypeOfLine & aTyp){ AIS_GraphicTool::GetLineAtt(aDrawer, TheTypeOfAttributes, aCol, aWidth, aTyp); return aWidth; }, "None", py::arg("aDrawer"), py::arg("TheTypeOfAttributes"), py::arg("aCol"), py::arg("aWidth"), py::arg("aTyp"));
cls_AIS_GraphicTool.def_static("GetInteriorColor_", (Quantity_NameOfColor (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"));
cls_AIS_GraphicTool.def_static("GetInteriorColor_", (void (*)(const opencascade::handle<Prs3d_Drawer> &, Quantity_Color &)) &AIS_GraphicTool::GetInteriorColor, "None", py::arg("aDrawer"), py::arg("aColor"));
cls_AIS_GraphicTool.def_static("GetMaterial_", (Graphic3d_MaterialAspect (*)(const opencascade::handle<Prs3d_Drawer> &)) &AIS_GraphicTool::GetMaterial, "None", py::arg("aDrawer"));

// Enums

}