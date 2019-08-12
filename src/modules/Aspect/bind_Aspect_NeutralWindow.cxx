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
#include <Aspect_Window.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_NeutralWindow.hxx>
#include <Standard_Type.hxx>
#include <Aspect_Drawable.hxx>
#include <Aspect_FBConfig.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfResize.hxx>

void bind_Aspect_NeutralWindow(py::module &mod){

py::class_<Aspect_NeutralWindow, opencascade::handle<Aspect_NeutralWindow>, Aspect_Window> cls_Aspect_NeutralWindow(mod, "Aspect_NeutralWindow", "Defines a platform-neutral window. This class is intended to be used in context when window management (including OpenGL context creation) is performed on application side (e.g. using external framework).");

// Constructors
cls_Aspect_NeutralWindow.def(py::init<>());

// Fields

// Methods
cls_Aspect_NeutralWindow.def_static("get_type_name_", (const char * (*)()) &Aspect_NeutralWindow::get_type_name, "None");
cls_Aspect_NeutralWindow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_NeutralWindow::get_type_descriptor, "None");
cls_Aspect_NeutralWindow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DynamicType, "None");
cls_Aspect_NeutralWindow.def("NativeHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeHandle, "Return native handle of this drawable.");
cls_Aspect_NeutralWindow.def("NativeParentHandle", (Aspect_Drawable (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeParentHandle, "Return native handle of the parent drawable.");
cls_Aspect_NeutralWindow.def("NativeFBConfig", (Aspect_FBConfig (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::NativeFBConfig, "Return FBConfig.");
cls_Aspect_NeutralWindow.def("SetNativeHandle", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable)) &Aspect_NeutralWindow::SetNativeHandle, "Set native handle.", py::arg("theWindow"));
cls_Aspect_NeutralWindow.def("SetNativeHandles", (Standard_Boolean (Aspect_NeutralWindow::*)(Aspect_Drawable, Aspect_Drawable, Aspect_FBConfig)) &Aspect_NeutralWindow::SetNativeHandles, "Set native handles.", py::arg("theWindow"), py::arg("theParentWindow"), py::arg("theFbConfig"));
cls_Aspect_NeutralWindow.def("IsMapped", (Standard_Boolean (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::IsMapped, "Return true if window is not hidden.");
cls_Aspect_NeutralWindow.def("Map", (void (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Map, "Change window mapped flag to TRUE.");
cls_Aspect_NeutralWindow.def("Unmap", (void (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Unmap, "Change window mapped flag to FALSE.");
cls_Aspect_NeutralWindow.def("DoResize", (Aspect_TypeOfResize (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DoResize, "Resize window - do nothing.");
cls_Aspect_NeutralWindow.def("DoMapping", (Standard_Boolean (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::DoMapping, "Map window - do nothing.");
cls_Aspect_NeutralWindow.def("Ratio", (Standard_Real (Aspect_NeutralWindow::*)() const) &Aspect_NeutralWindow::Ratio, "Returns window ratio equal to the physical width/height dimensions.");
cls_Aspect_NeutralWindow.def("Position", [](Aspect_NeutralWindow &self, Standard_Integer & theX1, Standard_Integer & theY1, Standard_Integer & theX2, Standard_Integer & theY2){ self.Position(theX1, theY1, theX2, theY2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(theX1, theY1, theX2, theY2); }, "Return the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"));
cls_Aspect_NeutralWindow.def("SetPosition", (Standard_Boolean (Aspect_NeutralWindow::*)(Standard_Integer, Standard_Integer, Standard_Integer, Standard_Integer)) &Aspect_NeutralWindow::SetPosition, "Set the window position.", py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
cls_Aspect_NeutralWindow.def("Size", [](Aspect_NeutralWindow &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.Size(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Return the window size.", py::arg("theWidth"), py::arg("theHeight"));
cls_Aspect_NeutralWindow.def("SetSize", (Standard_Boolean (Aspect_NeutralWindow::*)(const Standard_Integer, const Standard_Integer)) &Aspect_NeutralWindow::SetSize, "Set the window size.", py::arg("theWidth"), py::arg("theHeight"));

// Enums

}