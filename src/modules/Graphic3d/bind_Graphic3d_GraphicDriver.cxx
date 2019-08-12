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
#include <Standard_TypeDef.hxx>
#include <Graphic3d_TypeOfLimit.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_CStructure.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_CView.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Standard_Type.hxx>
#include <Aspect_GenId.hxx>

void bind_Graphic3d_GraphicDriver(py::module &mod){

py::class_<Graphic3d_GraphicDriver, opencascade::handle<Graphic3d_GraphicDriver>, Standard_Transient> cls_Graphic3d_GraphicDriver(mod, "Graphic3d_GraphicDriver", "This class allows the definition of a graphic driver for 3d interface (currently only OpenGl driver is used).");

// Fields

// Methods
cls_Graphic3d_GraphicDriver.def("InquireLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)(const Graphic3d_TypeOfLimit) const) &Graphic3d_GraphicDriver::InquireLimit, "Request limit of graphic resource of specific type.", py::arg("theType"));
cls_Graphic3d_GraphicDriver.def("InquireLightLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::InquireLightLimit, "Request maximum number of active light sources supported by driver and hardware.");
cls_Graphic3d_GraphicDriver.def("InquirePlaneLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::InquirePlaneLimit, "Request maximum number of active clipping planes supported by driver and hardware.");
cls_Graphic3d_GraphicDriver.def("InquireViewLimit", (Standard_Integer (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::InquireViewLimit, "Request maximum number of views supported by driver.");
cls_Graphic3d_GraphicDriver.def("CreateStructure", (opencascade::handle<Graphic3d_CStructure> (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &Graphic3d_GraphicDriver::CreateStructure, "Creates new empty graphic structure", py::arg("theManager"));
cls_Graphic3d_GraphicDriver.def("RemoveStructure", (void (Graphic3d_GraphicDriver::*)(opencascade::handle<Graphic3d_CStructure> &)) &Graphic3d_GraphicDriver::RemoveStructure, "Removes structure from graphic driver and releases its resources.", py::arg("theCStructure"));
cls_Graphic3d_GraphicDriver.def("CreateView", (opencascade::handle<Graphic3d_CView> (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_StructureManager> &)) &Graphic3d_GraphicDriver::CreateView, "Creates new view for this graphic driver.", py::arg("theMgr"));
cls_Graphic3d_GraphicDriver.def("RemoveView", (void (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &)) &Graphic3d_GraphicDriver::RemoveView, "Removes view from graphic driver and releases its resources.", py::arg("theView"));
cls_Graphic3d_GraphicDriver.def("EnableVBO", (void (Graphic3d_GraphicDriver::*)(const Standard_Boolean)) &Graphic3d_GraphicDriver::EnableVBO, "enables/disables usage of OpenGL vertex buffer arrays while drawing primitiev arrays", py::arg("status"));
cls_Graphic3d_GraphicDriver.def("MemoryInfo", (Standard_Boolean (Graphic3d_GraphicDriver::*)(Standard_Size &, TCollection_AsciiString &) const) &Graphic3d_GraphicDriver::MemoryInfo, "Returns information about GPU memory usage.", py::arg("theFreeBytes"), py::arg("theInfo"));
cls_Graphic3d_GraphicDriver.def("DefaultTextHeight", (Standard_ShortReal (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::DefaultTextHeight, "None");
cls_Graphic3d_GraphicDriver.def("TextSize", (void (Graphic3d_GraphicDriver::*)(const opencascade::handle<Graphic3d_CView> &, const Standard_CString, const Standard_ShortReal, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &Graphic3d_GraphicDriver::TextSize, "Computes text width.", py::arg("theView"), py::arg("theText"), py::arg("theHeight"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_Graphic3d_GraphicDriver.def("AddZLayer", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId)) &Graphic3d_GraphicDriver::AddZLayer, "Add a new top-level z layer with ID <theLayerId> for the view. Z layers allow drawing structures in higher layers in foreground of structures in lower layers. To add a structure to desired layer on display it is necessary to set the layer ID for the structure.", py::arg("theLayerId"));
cls_Graphic3d_GraphicDriver.def("RemoveZLayer", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId)) &Graphic3d_GraphicDriver::RemoveZLayer, "Removes Z layer. All structures displayed at the moment in layer will be displayed in default layer (the bottom-level z layer). By default, there are always default bottom-level layer that can't be removed. The passed theLayerId should be not less than 0 (reserved for default layers that can not be removed).", py::arg("theLayerId"));
cls_Graphic3d_GraphicDriver.def("ZLayers", (void (Graphic3d_GraphicDriver::*)(TColStd_SequenceOfInteger &) const) &Graphic3d_GraphicDriver::ZLayers, "Returns list of Z layers defined for the graphical driver.", py::arg("theLayerSeq"));
cls_Graphic3d_GraphicDriver.def("SetZLayerSettings", (void (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &Graphic3d_GraphicDriver::SetZLayerSettings, "Sets the settings for a single Z layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_Graphic3d_GraphicDriver.def("ZLayerSettings", (const Graphic3d_ZLayerSettings & (Graphic3d_GraphicDriver::*)(const Graphic3d_ZLayerId) const) &Graphic3d_GraphicDriver::ZLayerSettings, "Returns the settings of a single Z layer.", py::arg("theLayerId"));
cls_Graphic3d_GraphicDriver.def("ViewExists", (Standard_Boolean (Graphic3d_GraphicDriver::*)(const opencascade::handle<Aspect_Window> &, opencascade::handle<Graphic3d_CView> &)) &Graphic3d_GraphicDriver::ViewExists, "Returns view associated with the window if it is exists and is activated. Returns Standard_True if the view associated to the window exists.", py::arg("theWindow"), py::arg("theView"));
cls_Graphic3d_GraphicDriver.def("GetDisplayConnection", (const opencascade::handle<Aspect_DisplayConnection> & (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::GetDisplayConnection, "returns Handle to display connection");
cls_Graphic3d_GraphicDriver.def("NewIdentification", (Standard_Integer (Graphic3d_GraphicDriver::*)()) &Graphic3d_GraphicDriver::NewIdentification, "Returns a new identification number for a new structure.");
cls_Graphic3d_GraphicDriver.def("RemoveIdentification", (void (Graphic3d_GraphicDriver::*)(const Standard_Integer)) &Graphic3d_GraphicDriver::RemoveIdentification, "Frees the identifier of a structure.", py::arg("theId"));
cls_Graphic3d_GraphicDriver.def_static("get_type_name_", (const char * (*)()) &Graphic3d_GraphicDriver::get_type_name, "None");
cls_Graphic3d_GraphicDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_GraphicDriver::get_type_descriptor, "None");
cls_Graphic3d_GraphicDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_GraphicDriver::*)() const) &Graphic3d_GraphicDriver::DynamicType, "None");

// Enums

}