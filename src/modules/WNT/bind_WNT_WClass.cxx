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
#include <WNT_Window.hxx>
#include <Standard_Handle.hxx>
#include <WNT_WClass.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Aspect_Handle.hxx>

void bind_WNT_WClass(py::module &mod){

py::class_<WNT_WClass, opencascade::handle<WNT_WClass>, Standard_Transient> cls_WNT_WClass(mod, "WNT_WClass", "This class defines a Windows NT window class. A window in Windows NT is always created based on a window class. The window class identifies the window procedure that processes messages to the window. Each window class has unique name ( character string ). More than one window can be created based on a single window class. For example, all button windows in Windows NT are created based on the same window class. The window class defines the window procedure and some other characteristics ( background, mouse cursor shape etc. ) of the windows that are created based on that class. When we create a window, we define additional characteristics of the window that are unique to that window. So, we have to create and register window class before creation of any window. Of course, it's possible to create a new window class for each window inside the Window class and do not use the WClass at all. We implemented this class for sake of flexibility of event processing.");

// Constructors
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"));
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int, const Standard_Integer>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"), py::arg("theClassExtra"));
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int, const Standard_Integer, const Standard_Integer>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"), py::arg("theClassExtra"), py::arg("theWindowExtra"));
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int, const Standard_Integer, const Standard_Integer, const Aspect_Handle>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"), py::arg("theClassExtra"), py::arg("theWindowExtra"), py::arg("theCursor"));
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int, const Standard_Integer, const Standard_Integer, const Aspect_Handle, const Aspect_Handle>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"), py::arg("theClassExtra"), py::arg("theWindowExtra"), py::arg("theCursor"), py::arg("theIcon"));
cls_WNT_WClass.def(py::init<const TCollection_AsciiString &, const Standard_Address, const unsigned int, const Standard_Integer, const Standard_Integer, const Aspect_Handle, const Aspect_Handle, const TCollection_AsciiString &>(), py::arg("theClassName"), py::arg("theWndProc"), py::arg("theStyle"), py::arg("theClassExtra"), py::arg("theWindowExtra"), py::arg("theCursor"), py::arg("theIcon"), py::arg("theMenuName"));

// Fields

// Methods
cls_WNT_WClass.def_static("get_type_name_", (const char * (*)()) &WNT_WClass::get_type_name, "None");
cls_WNT_WClass.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &WNT_WClass::get_type_descriptor, "None");
cls_WNT_WClass.def("DynamicType", (const opencascade::handle<Standard_Type> & (WNT_WClass::*)() const) &WNT_WClass::DynamicType, "None");
cls_WNT_WClass.def("WndProc", (Standard_Address (WNT_WClass::*)() const) &WNT_WClass::WndProc, "Returns address of window procedure.");
cls_WNT_WClass.def("Name", (const TCollection_AsciiString & (WNT_WClass::*)() const) &WNT_WClass::Name, "Returns a class name.");
cls_WNT_WClass.def("Instance", (Aspect_Handle (WNT_WClass::*)() const) &WNT_WClass::Instance, "Returns a program instance handle.");

// Enums

}