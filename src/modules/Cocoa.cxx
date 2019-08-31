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
#include <Cocoa_LocalPool.hxx>
#include <Aspect_Window.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Aspect_Drawable.hxx>
#include <Aspect_FBConfig.hxx>
#include <Standard_Handle.hxx>
#include <Cocoa_Window.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(Cocoa, mod) {

py::module::import("OCCT.Aspect");
py::module::import("OCCT.Standard");

// CLASS: COCOA_LOCALPOOL
/*
py::class_<Cocoa_LocalPool> cls_Cocoa_LocalPool(mod, "Cocoa_LocalPool", "Auxiliary class to create local pool.");

// Constructors
cls_Cocoa_LocalPool.def(py::init<>());
*/

// CLASS: COCOA_WINDOW
py::class_<Cocoa_Window, opencascade::handle<Cocoa_Window>, Aspect_Window> cls_Cocoa_Window(mod, "Cocoa_Window", "This class defines Cocoa window");

// Constructors
// cls_Cocoa_Window.def(py::init<const Standard_CString, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theTitle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"));
// cls_Cocoa_Window.def(py::init<NSView *>(), py::arg("theViewNS"));

// Methods
cls_Cocoa_Window.def("Map", (void (Cocoa_Window::*)() const) &Cocoa_Window::Map, "Opens the window <me>");
cls_Cocoa_Window.def("Unmap", (void (Cocoa_Window::*)() const) &Cocoa_Window::Unmap, "Closes the window <me>");
cls_Cocoa_Window.def("DoResize", (Aspect_TypeOfResize (Cocoa_Window::*)() const) &Cocoa_Window::DoResize, "Applies the resizing to the window <me>");
cls_Cocoa_Window.def("DoMapping", (Standard_Boolean (Cocoa_Window::*)() const) &Cocoa_Window::DoMapping, "Apply the mapping change to the window <me>");
cls_Cocoa_Window.def("IsMapped", (Standard_Boolean (Cocoa_Window::*)() const) &Cocoa_Window::IsMapped, "Returns True if the window <me> is opened");
cls_Cocoa_Window.def("Ratio", (Standard_Real (Cocoa_Window::*)() const) &Cocoa_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions");
cls_Cocoa_Window.def("Position", [](Cocoa_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
cls_Cocoa_Window.def("Size", [](Cocoa_Window &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.Size(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns The Window SIZE in PIXEL", py::arg("theWidth"), py::arg("theHeight"));
// cls_Cocoa_Window.def("HView", (NSView * (Cocoa_Window::*)() const) &Cocoa_Window::HView, "Returns associated NSView");
// cls_Cocoa_Window.def("SetHView", (void (Cocoa_Window::*)(NSView *)) &Cocoa_Window::SetHView, "Setup new NSView.", py::arg("theView"));
cls_Cocoa_Window.def("NativeHandle", (Aspect_Drawable (Cocoa_Window::*)() const) &Cocoa_Window::NativeHandle, "Returns native Window handle");
cls_Cocoa_Window.def("NativeParentHandle", (Aspect_Drawable (Cocoa_Window::*)() const) &Cocoa_Window::NativeParentHandle, "Returns parent of native Window handle");
cls_Cocoa_Window.def("NativeFBConfig", (Aspect_FBConfig (Cocoa_Window::*)() const) &Cocoa_Window::NativeFBConfig, "Returns nothing on OS X");
cls_Cocoa_Window.def_static("get_type_name_", (const char * (*)()) &Cocoa_Window::get_type_name, "None");
// cls_Cocoa_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Cocoa_Window::get_type_descriptor, "None");
cls_Cocoa_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (Cocoa_Window::*)() const) &Cocoa_Window::DynamicType, "None");


}
