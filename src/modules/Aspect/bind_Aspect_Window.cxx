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
#include <Aspect_Background.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_TypeOfResize.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_FillMethod.hxx>
#include <Aspect_Drawable.hxx>
#include <Aspect_FBConfig.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_Window.hxx>
#include <Standard_Type.hxx>

void bind_Aspect_Window(py::module &mod){

py::class_<Aspect_Window, opencascade::handle<Aspect_Window>, Standard_Transient> cls_Aspect_Window(mod, "Aspect_Window", "Defines a window.");

// Fields

// Methods
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_Background &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("ABack"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &)) &Aspect_Window::SetBackground, "Modifies the window background.", py::arg("color"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Aspect_GradientBackground &)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("ABackground"));
cls_Aspect_Window.def("SetBackground", (void (Aspect_Window::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_Window::SetBackground, "Modifies the window gradient background.", py::arg("theFirstColor"), py::arg("theSecondColor"), py::arg("theFillMethod"));
cls_Aspect_Window.def("Map", (void (Aspect_Window::*)() const) &Aspect_Window::Map, "Opens the window <me>.");
cls_Aspect_Window.def("Unmap", (void (Aspect_Window::*)() const) &Aspect_Window::Unmap, "Closes the window <me>.");
cls_Aspect_Window.def("DoResize", (Aspect_TypeOfResize (Aspect_Window::*)() const) &Aspect_Window::DoResize, "Apply the resizing to the window <me>.");
cls_Aspect_Window.def("DoMapping", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::DoMapping, "Apply the mapping change to the window <me>. and returns TRUE if the window is mapped at screen.");
cls_Aspect_Window.def("Background", (Aspect_Background (Aspect_Window::*)() const) &Aspect_Window::Background, "Returns the window background.");
cls_Aspect_Window.def("BackgroundFillMethod", (Aspect_FillMethod (Aspect_Window::*)() const) &Aspect_Window::BackgroundFillMethod, "Returns the current image background fill mode.");
cls_Aspect_Window.def("GradientBackground", (Aspect_GradientBackground (Aspect_Window::*)() const) &Aspect_Window::GradientBackground, "Returns the window gradient background.");
cls_Aspect_Window.def("IsMapped", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::IsMapped, "Returns True if the window <me> is opened and False if the window is closed.");
cls_Aspect_Window.def("IsVirtual", (Standard_Boolean (Aspect_Window::*)() const) &Aspect_Window::IsVirtual, "Returns True if the window <me> is virtual");
cls_Aspect_Window.def("SetVirtual", (void (Aspect_Window::*)(const Standard_Boolean)) &Aspect_Window::SetVirtual, "Setup the virtual state", py::arg("theVirtual"));
cls_Aspect_Window.def("Ratio", (Standard_Real (Aspect_Window::*)() const) &Aspect_Window::Ratio, "Returns The Window RATIO equal to the physical WIDTH/HEIGHT dimensions");
cls_Aspect_Window.def("Position", [](Aspect_Window &self, Standard_Integer & X1, Standard_Integer & Y1, Standard_Integer & X2, Standard_Integer & Y2){ self.Position(X1, Y1, X2, Y2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(X1, Y1, X2, Y2); }, "Returns The Window POSITION in PIXEL", py::arg("X1"), py::arg("Y1"), py::arg("X2"), py::arg("Y2"));
cls_Aspect_Window.def("Size", [](Aspect_Window &self, Standard_Integer & Width, Standard_Integer & Height){ self.Size(Width, Height); return std::tuple<Standard_Integer &, Standard_Integer &>(Width, Height); }, "Returns The Window SIZE in PIXEL", py::arg("Width"), py::arg("Height"));
cls_Aspect_Window.def("NativeHandle", (Aspect_Drawable (Aspect_Window::*)() const) &Aspect_Window::NativeHandle, "Returns native Window handle (HWND on Windows, Window with Xlib, and so on)");
cls_Aspect_Window.def("NativeParentHandle", (Aspect_Drawable (Aspect_Window::*)() const) &Aspect_Window::NativeParentHandle, "Returns parent of native Window handle (HWND on Windows, Window with Xlib, and so on)");
cls_Aspect_Window.def("NativeFBConfig", (Aspect_FBConfig (Aspect_Window::*)() const) &Aspect_Window::NativeFBConfig, "Returns native Window FB config (GLXFBConfig on Xlib)");
cls_Aspect_Window.def_static("get_type_name_", (const char * (*)()) &Aspect_Window::get_type_name, "None");
cls_Aspect_Window.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_Window::get_type_descriptor, "None");
cls_Aspect_Window.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_Window::*)() const) &Aspect_Window::DynamicType, "None");

// Enums

}