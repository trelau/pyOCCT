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
#include <Standard_Handle.hxx>
#include <V3d_View.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_Structure.hxx>
#include <V3d_Plane.hxx>
#include <Standard_Type.hxx>

void bind_V3d_Plane(py::module &mod){

py::class_<V3d_Plane, opencascade::handle<V3d_Plane>, Standard_Transient> cls_V3d_Plane(mod, "V3d_Plane", "Obsolete clip plane presentation class. Ported on new core of Graphic3d_ClipPlane approach. Please access Graphic3d_ClipPlane via ClipPlane() method to use it for standard clipping workflow. Example of use:");

// Constructors
cls_V3d_Plane.def(py::init<>());
cls_V3d_Plane.def(py::init<const Standard_Real>(), py::arg("theA"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"), py::arg("theC"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));

// Fields

// Methods
cls_V3d_Plane.def("SetPlane", (void (V3d_Plane::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_Plane::SetPlane, "Change plane equation.", py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));
cls_V3d_Plane.def("Display", [](V3d_Plane &self, const opencascade::handle<V3d_View> & a0) -> void { return self.Display(a0); });
cls_V3d_Plane.def("Display", (void (V3d_Plane::*)(const opencascade::handle<V3d_View> &, const Quantity_Color &)) &V3d_Plane::Display, "Display the plane representation in the choosen view.", py::arg("theView"), py::arg("theColor"));
cls_V3d_Plane.def("Erase", (void (V3d_Plane::*)()) &V3d_Plane::Erase, "Erase the plane representation.");
cls_V3d_Plane.def("Plane", [](V3d_Plane &self, Standard_Real & theA, Standard_Real & theB, Standard_Real & theC, Standard_Real & theD){ self.Plane(theA, theB, theC, theD); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theA, theB, theC, theD); }, "Returns the parameters of the plane.", py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));
cls_V3d_Plane.def("IsDisplayed", (Standard_Boolean (V3d_Plane::*)() const) &V3d_Plane::IsDisplayed, "Returns TRUE when the plane representation is displayed.");
cls_V3d_Plane.def("ClipPlane", (const opencascade::handle<Graphic3d_ClipPlane> & (V3d_Plane::*)() const) &V3d_Plane::ClipPlane, "Use this method to pass clipping plane implementation for standard clipping workflow.");
cls_V3d_Plane.def_static("get_type_name_", (const char * (*)()) &V3d_Plane::get_type_name, "None");
cls_V3d_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_Plane::get_type_descriptor, "None");
cls_V3d_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_Plane::*)() const) &V3d_Plane::DynamicType, "None");

// Enums

}