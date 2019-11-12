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

#ifndef _WIN32

#include <pyOCCT_Common.hxx>
#include <xTypes.h>
#include <Aspect_Window.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_FBConfig.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Aspect_Drawable.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Type.hxx>
#include <Xw_Window.hxx>

PYBIND11_MODULE(Xw, mod) {

py::module::import("OCCT.Aspect");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");

// CLASS: XW_WINDOW
py::class_<Xw_Window, opencascade::handle<Xw_Window>, Aspect_Window> cls_Xw_Window(mod, "Xw_Window", "This class defines XLib window intended for creation of OpenGL context.");

// Constructors
cls_Xw_Window.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Standard_CString, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theXDisplay"), py::arg("theTitle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"));
cls_Xw_Window.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Standard_CString, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Aspect_FBConfig>(), py::arg("theXDisplay"), py::arg("theTitle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"), py::arg("theFBConfig"));
cls_Xw_Window.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Window>(), py::arg("theXDisplay"), py::arg("theXWin"));
cls_Xw_Window.def(py::init<const opencascade::handle<Aspect_DisplayConnection> &, const Window, const Aspect_FBConfig>(), py::arg("theXDisplay"), py::arg("theXWin"), py::arg("theFBConfig"));

// Methods
cls_Xw_Window.def("Map", (void (Xw_Window::*)() const) &Xw_Window::Map, "Opens the window <me>");
cls_Xw_Window.def("Unmap", (void (Xw_Window::*)() const) &Xw_Window::Unmap, "Closes the window <me>");
cls_Xw_Window.def("DoResize", (Aspect_TypeOfResize (Xw_Window::*)() const) &Xw_Window::DoResize, "Applies the resizing to the window <me>");
cls_Xw_Window.def("DoMapping", (Standard_Boolean (Xw_Window::*)() const) &Xw_Window::DoMapping, "Apply the mapping change to the window <me>");
cls_Xw_Window.def("IsMapped", (Standard_Boolean (Xw_Window::*)() const) &Xw_Window::IsMapped, "Returns True if the window <me> is opened");
cls_Xw_Window.def("Ratio", (Standard_Real (Xw_Window::*)() const) &Xw_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions");
cls_Xw_Window.def("Position", [](Xw_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
cls_Xw_Window.def("Size", [](Xw_Window &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.Size(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns The Window SIZE in PIXEL", py::arg("theWidth"), py::arg("theHeight"));
cls_Xw_Window.def("XWindow", (Window (Xw_Window::*)() const) &Xw_Window::XWindow, "Returns native Window handle");
// cls_Xw_Window.def("DisplayConnection", (const opencascade::handle<Aspect_DisplayConnection> & (Xw_Window::*)() const) &Xw_Window::DisplayConnection, "Returns connection to X Display");
cls_Xw_Window.def("NativeHandle", (Aspect_Drawable (Xw_Window::*)() const) &Xw_Window::NativeHandle, "Returns native Window handle");
cls_Xw_Window.def("NativeParentHandle", (Aspect_Drawable (Xw_Window::*)() const) &Xw_Window::NativeParentHandle, "Returns parent of native Window handle");
cls_Xw_Window.def("NativeFBConfig", (Aspect_FBConfig (Xw_Window::*)() const) &Xw_Window::NativeFBConfig, "Returns native Window FB config (GLXFBConfig on Xlib)");
cls_Xw_Window.def_static("get_type_name_", (const char * (*)()) &Xw_Window::get_type_name, "None");
cls_Xw_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Xw_Window::get_type_descriptor, "None");
cls_Xw_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (Xw_Window::*)() const) &Xw_Window::DynamicType, "None");


}

#endif
