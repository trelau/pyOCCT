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
#include <Graphic3d_GraphicDriver.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <Standard_Type.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfLimit.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_CView.hxx>
#include <OpenGl_Window.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <OpenGl_Caps.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_Context.hxx>
#include <NCollection_Map.hxx>
#include <OpenGl_View.hxx>
#include <NCollection_DataMap.hxx>
#include <OpenGl_Structure.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <OpenGl_MapOfZLayerSettings.hxx>

void bind_OpenGl_GraphicDriver(py::module &mod){

py::class_<OpenGl_GraphicDriver, opencascade::handle<OpenGl_GraphicDriver>, Graphic3d_GraphicDriver> cls_OpenGl_GraphicDriver(mod, "OpenGl_GraphicDriver", "This class defines an OpenGl graphic driver");

// Constructors
cls_OpenGl_GraphicDriver.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &>(), py::arg("theDisp"));
cls_OpenGl_GraphicDriver.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Standard_Boolean>(), py::arg("theDisp"), py::arg("theToInitialize"));

// Fields

// Methods
cls_OpenGl_GraphicDriver.def_static("get_type_name_", (const char * (*)()) &OpenGl_GraphicDriver::get_type_name, "None");
cls_OpenGl_GraphicDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_GraphicDriver::get_type_descriptor, "None");
cls_OpenGl_GraphicDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::DynamicType, "None");
cls_OpenGl_GraphicDriver.def("ReleaseContext", (void (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::ReleaseContext, "Release default context.");
cls_OpenGl_GraphicDriver.def("InitContext", (Standard_Boolean (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::InitContext, "Perform initialization of default OpenGL context.");
cls_OpenGl_GraphicDriver.def("InquireLimit", (Standard_Integer (OpenGl_GraphicDriver::*)(const Graphic3d_TypeOfLimit) const) &OpenGl_GraphicDriver::InquireLimit, "Request limit of graphic resource of specific type.", py::arg("theType"));
cls_OpenGl_GraphicDriver.def("CreateStructure", (opencascade::handle<Graphic3d_CStructure> (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &OpenGl_GraphicDriver::CreateStructure, "None", py::arg("theManager"));
cls_OpenGl_GraphicDriver.def("RemoveStructure", (void (OpenGl_GraphicDriver::*)(opencascade::handle<Graphic3d_CStructure> &)) &OpenGl_GraphicDriver::RemoveStructure, "None", py::arg("theCStructure"));
cls_OpenGl_GraphicDriver.def("CreateView", (opencascade::handle<Graphic3d_CView> (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &OpenGl_GraphicDriver::CreateView, "None", py::arg("theMgr"));
cls_OpenGl_GraphicDriver.def("RemoveView", (void (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &)) &OpenGl_GraphicDriver::RemoveView, "None", py::arg("theView"));
cls_OpenGl_GraphicDriver.def("CreateRenderWindow", (opencascade::handle<OpenGl_Window> (OpenGl_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &OpenGl_GraphicDriver::CreateRenderWindow, "None", py::arg("theWindow"), py::arg("theContext"));
cls_OpenGl_GraphicDriver.def("TextSize", (void (OpenGl_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &, const Standard_CString, const Standard_ShortReal, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &OpenGl_GraphicDriver::TextSize, "None", py::arg("theView"), py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_OpenGl_GraphicDriver.def("DefaultTextHeight", (Standard_ShortReal (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::DefaultTextHeight, "None");
cls_OpenGl_GraphicDriver.def("ViewExists", (Standard_Boolean (OpenGl_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, opencascade::handle<Graphic3d_CView> &)) &OpenGl_GraphicDriver::ViewExists, "None", py::arg("theWindow"), py::arg("theView"));
cls_OpenGl_GraphicDriver.def("AddZLayer", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::AddZLayer, "Adds a new top-level z layer with ID theLayerId for all views. Z layers allow drawing structures in higher layers in foreground of structures in lower layers. To add a structure to desired layer on display it is necessary to set the layer index for the structure. The passed theLayerId should be not less than 0 (reserved for default layers).", py::arg("theLayerId"));
cls_OpenGl_GraphicDriver.def("RemoveZLayer", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::RemoveZLayer, "Removes Z layer. All structures displayed at the moment in layer will be displayed in default layer (the bottom-level z layer). By default, there are always default bottom-level layer that can't be removed. The passed theLayerId should be not less than 0 (reserved for default layers that can not be removed).", py::arg("theLayerId"));
cls_OpenGl_GraphicDriver.def("ZLayers", (void (OpenGl_GraphicDriver::*)(TColStd_SequenceOfInteger &) const) &OpenGl_GraphicDriver::ZLayers, "Returns list of Z layers defined for the graphical driver.", py::arg("theLayerSeq"));
cls_OpenGl_GraphicDriver.def("SetZLayerSettings", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &OpenGl_GraphicDriver::SetZLayerSettings, "Sets the settings for a single Z layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_OpenGl_GraphicDriver.def("ZLayerSettings", (const Graphic3d_ZLayerSettings & (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId) const) &OpenGl_GraphicDriver::ZLayerSettings, "Returns the settings of a single Z layer.", py::arg("theLayerId"));
cls_OpenGl_GraphicDriver.def("Options", (const OpenGl_Caps & (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::Options, "Returns the visualization options");
cls_OpenGl_GraphicDriver.def("ChangeOptions", (OpenGl_Caps & (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::ChangeOptions, "Returns the visualization options");
cls_OpenGl_GraphicDriver.def("SetBuffersNoSwap", (void (OpenGl_GraphicDriver::*)(const Standard_Boolean)) &OpenGl_GraphicDriver::SetBuffersNoSwap, "Specify swap buffer behavior.", py::arg("theIsNoSwap"));
cls_OpenGl_GraphicDriver.def("EnableVBO", (void (OpenGl_GraphicDriver::*)(const Standard_Boolean)) &OpenGl_GraphicDriver::EnableVBO, "VBO usage can be forbidden by this method even if it is supported by GL driver. Notice that disabling of VBO will cause rendering performance degradation. Warning! This method should be called only before any primitives are displayed in GL scene!", py::arg("theToTurnOn"));
cls_OpenGl_GraphicDriver.def("MemoryInfo", (Standard_Boolean (OpenGl_GraphicDriver::*)(Standard_Size &, TCollection_AsciiString &) const) &OpenGl_GraphicDriver::MemoryInfo, "Returns information about GPU memory usage. Please read OpenGl_Context::MemoryInfo() for more description.", py::arg("theFreeBytes"), py::arg("theInfo"));
cls_OpenGl_GraphicDriver.def("GetSharedContext", (const opencascade::handle<OpenGl_Context> & (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::GetSharedContext, "Method to retrieve valid GL context. Could return NULL-handle if no window created by this driver.");
cls_OpenGl_GraphicDriver.def("addZLayerIndex", (void (OpenGl_GraphicDriver::*)(const Graphic3d_ZLayerId)) &OpenGl_GraphicDriver::addZLayerIndex, "Insert index layer at proper position.", py::arg("theLayerId"));
cls_OpenGl_GraphicDriver.def("setDeviceLost", (void (OpenGl_GraphicDriver::*)()) &OpenGl_GraphicDriver::setDeviceLost, "Set device lost flag for redrawn views.");
cls_OpenGl_GraphicDriver.def("GetStateCounter", (OpenGl_StateCounter * (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::GetStateCounter, "State counter for OpenGl structures.");
cls_OpenGl_GraphicDriver.def("GetNextPrimitiveArrayUID", (Standard_Size (OpenGl_GraphicDriver::*)() const) &OpenGl_GraphicDriver::GetNextPrimitiveArrayUID, "Returns unique ID for primitive arrays.");

// Enums

}