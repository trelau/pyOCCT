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
#include <Standard_Handle.hxx>
#include <IGESDraw_Protocol.hxx>
#include <IGESDraw_ConnectPoint.hxx>
#include <IGESDraw_NetworkSubfigureDef.hxx>
#include <IGESDraw_ViewsVisible.hxx>
#include <IGESDraw_ViewsVisibleWithAttr.hxx>
#include <IGESDraw_LabelDisplay.hxx>
#include <IGESDraw_Planar.hxx>
#include <IGESDraw_SegmentedViewsVisible.hxx>
#include <IGESDraw_Drawing.hxx>
#include <IGESDraw_DrawingWithRotation.hxx>
#include <IGESDraw_View.hxx>
#include <IGESDraw_RectArraySubfigure.hxx>
#include <IGESDraw_CircArraySubfigure.hxx>
#include <IGESDraw_NetworkSubfigure.hxx>
#include <IGESDraw_PerspectiveView.hxx>
#include <IGESDraw_ToolConnectPoint.hxx>
#include <IGESDraw_ToolNetworkSubfigureDef.hxx>
#include <IGESDraw_ToolViewsVisible.hxx>
#include <IGESDraw_ToolViewsVisibleWithAttr.hxx>
#include <IGESDraw_ToolLabelDisplay.hxx>
#include <IGESDraw_ToolPlanar.hxx>
#include <IGESDraw_ToolSegmentedViewsVisible.hxx>
#include <IGESDraw_ToolDrawing.hxx>
#include <IGESDraw_ToolDrawingWithRotation.hxx>
#include <IGESDraw_ToolView.hxx>
#include <IGESDraw_ToolRectArraySubfigure.hxx>
#include <IGESDraw_ToolCircArraySubfigure.hxx>
#include <IGESDraw_ToolNetworkSubfigure.hxx>
#include <IGESDraw_ToolPerspectiveView.hxx>
#include <IGESDraw_ReadWriteModule.hxx>
#include <IGESDraw_GeneralModule.hxx>
#include <IGESDraw_SpecificModule.hxx>
#include <IGESDraw.hxx>

void bind_IGESDraw(py::module &mod){

py::class_<IGESDraw> cls_IGESDraw(mod, "IGESDraw", "This package contains the group of classes necessary for Structure Entities implied in Drawings and Structured Graphics (Sets for drawing, Drawings and Views).");

// Constructors

// Fields

// Methods
// cls_IGESDraw.def_static("operator new_", (void * (*)(size_t)) &IGESDraw::operator new, "None", py::arg("theSize"));
// cls_IGESDraw.def_static("operator delete_", (void (*)(void *)) &IGESDraw::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw.def_static("Init_", (void (*)()) &IGESDraw::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESDraw.def_static("Protocol_", (opencascade::handle<IGESDraw_Protocol> (*)()) &IGESDraw::Protocol, "Returns the Protocol for this Package");

// Enums

}