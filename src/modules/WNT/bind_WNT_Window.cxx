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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <WNT_WClass.hxx>
#include <WNT_Dword.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Aspect_Drawable.hxx>
#include <Aspect_FBConfig.hxx>
#include <WNT_Window.hxx>
#include <Standard_Type.hxx>

void bind_WNT_Window(py::module &mod){

py::class_<WNT_Window, opencascade::handle<WNT_Window>, Aspect_Window> cls_WNT_Window(mod, "WNT_Window", "This class defines Windows NT window");

// Constructors
cls_WNT_Window.def(py::init<const Standard_CString, const opencascade::handle<WNT_WClass> &, const WNT_Dword &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theTitle"), py::arg("theClass"), py::arg("theStyle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"));
cls_WNT_Window.def(py::init<const Standard_CString, const opencascade::handle<WNT_WClass> &, const WNT_Dword &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Quantity_NameOfColor>(), py::arg("theTitle"), py::arg("theClass"), py::arg("theStyle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"), py::arg("theBackColor"));
cls_WNT_Window.def(py::init<const Standard_CString, const opencascade::handle<WNT_WClass> &, const WNT_Dword &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Quantity_NameOfColor, const Aspect_Handle>(), py::arg("theTitle"), py::arg("theClass"), py::arg("theStyle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"), py::arg("theBackColor"), py::arg("theParent"));
cls_WNT_Window.def(py::init<const Standard_CString, const opencascade::handle<WNT_WClass> &, const WNT_Dword &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Quantity_NameOfColor, const Aspect_Handle, const Aspect_Handle>(), py::arg("theTitle"), py::arg("theClass"), py::arg("theStyle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"), py::arg("theBackColor"), py::arg("theParent"), py::arg("theMenu"));
cls_WNT_Window.def(py::init<const Standard_CString, const opencascade::handle<WNT_WClass> &, const WNT_Dword &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Quantity_NameOfColor, const Aspect_Handle, const Aspect_Handle, const Standard_Address>(), py::arg("theTitle"), py::arg("theClass"), py::arg("theStyle"), py::arg("thePxLeft"), py::arg("thePxTop"), py::arg("thePxWidth"), py::arg("thePxHeight"), py::arg("theBackColor"), py::arg("theParent"), py::arg("theMenu"), py::arg("theClientStruct"));
cls_WNT_Window.def(py::init<const Aspect_Handle>(), py::arg("aHandle"));
cls_WNT_Window.def(py::init<const Aspect_Handle, const Quantity_NameOfColor>(), py::arg("aHandle"), py::arg("aBackColor"));

// Fields

// Methods
cls_WNT_Window.def("SetCursor", (void (WNT_Window::*)(const Aspect_Handle) const) &WNT_Window::SetCursor, "Sets cursor <aCursor> for ENTIRE WINDOW CLASS to which the Window belongs.", py::arg("aCursor"));
cls_WNT_Window.def("Map", (void (WNT_Window::*)() const) &WNT_Window::Map, "Opens the window <me>.");
cls_WNT_Window.def("Map", (void (WNT_Window::*)(const Standard_Integer) const) &WNT_Window::Map, "Opens a window <me> according to <aMapMode>. This method is specific to Windows NT. <aMapMode> can be one of SW_xxx constants defined in <windows.h>. See documentation.", py::arg("aMapMode"));
cls_WNT_Window.def("Unmap", (void (WNT_Window::*)() const) &WNT_Window::Unmap, "Closes the window <me>.");
cls_WNT_Window.def("DoResize", (Aspect_TypeOfResize (WNT_Window::*)() const) &WNT_Window::DoResize, "Applies the resizing to the window <me>.");
cls_WNT_Window.def("DoMapping", (Standard_Boolean (WNT_Window::*)() const) &WNT_Window::DoMapping, "Apply the mapping change to the window <me> and returns TRUE if the window is mapped at screen.");
cls_WNT_Window.def("SetPos", (void (WNT_Window::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &WNT_Window::SetPos, "Changes variables due to window position.", py::arg("X"), py::arg("Y"), py::arg("X1"), py::arg("Y1"));
cls_WNT_Window.def("IsMapped", (Standard_Boolean (WNT_Window::*)() const) &WNT_Window::IsMapped, "Returns True if the window <me> is opened and False if the window is closed.");
cls_WNT_Window.def("Ratio", (Standard_Real (WNT_Window::*)() const) &WNT_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions.");
cls_WNT_Window.def("Position", [](WNT_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
cls_WNT_Window.def("Size", [](WNT_Window &self, Standard_Integer & Width, Standard_Integer & Height){ self.Size(Width, Height); return std::tuple<Standard_Integer &, Standard_Integer &>(Width, Height); }, "Returns The Window SIZE in PIXEL", py::arg("Width"), py::arg("Height"));
cls_WNT_Window.def("HWindow", (Aspect_Handle (WNT_Window::*)() const) &WNT_Window::HWindow, "Returns the Windows NT handle of the created window <me>.");
cls_WNT_Window.def("HParentWindow", (Aspect_Handle (WNT_Window::*)() const) &WNT_Window::HParentWindow, "Returns the Windows NT handle parent of the created window <me>.");
cls_WNT_Window.def("NativeHandle", (Aspect_Drawable (WNT_Window::*)() const) &WNT_Window::NativeHandle, "Returns native Window handle (HWND)");
cls_WNT_Window.def("NativeParentHandle", (Aspect_Drawable (WNT_Window::*)() const) &WNT_Window::NativeParentHandle, "Returns parent of native Window handle (HWND on Windows, Window with Xlib, and so on)");
cls_WNT_Window.def("NativeFBConfig", (Aspect_FBConfig (WNT_Window::*)() const) &WNT_Window::NativeFBConfig, "Returns nothing on Windows");
cls_WNT_Window.def_static("get_type_name_", (const char * (*)()) &WNT_Window::get_type_name, "None");
cls_WNT_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &WNT_Window::get_type_descriptor, "None");
cls_WNT_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (WNT_Window::*)() const) &WNT_Window::DynamicType, "None");

// Enums

}