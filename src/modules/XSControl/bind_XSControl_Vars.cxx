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
#include <Geom_Geometry.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Shape.hxx>
#include <XSControl_Vars.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>

void bind_XSControl_Vars(py::module &mod){

py::class_<XSControl_Vars, opencascade::handle<XSControl_Vars>, Standard_Transient> cls_XSControl_Vars(mod, "XSControl_Vars", "Defines a receptacle for externally defined variables, each one has a name");

// Constructors
cls_XSControl_Vars.def(py::init<>());

// Fields

// Methods
cls_XSControl_Vars.def("Set", (void (XSControl_Vars::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &XSControl_Vars::Set, "None", py::arg("name"), py::arg("val"));
// cls_XSControl_Vars.def("Get", [](XSControl_Vars &self, Standard_CString & name){ opencascade::handle<Standard_Transient> rv = self.Get(name); return std::tuple<opencascade::handle<Standard_Transient>, Standard_CString &>(rv, name); }, "None", py::arg("name"));
// cls_XSControl_Vars.def("GetGeom", [](XSControl_Vars &self, Standard_CString & name){ opencascade::handle<Geom_Geometry> rv = self.GetGeom(name); return std::tuple<opencascade::handle<Geom_Geometry>, Standard_CString &>(rv, name); }, "None", py::arg("name"));
// cls_XSControl_Vars.def("GetCurve2d", [](XSControl_Vars &self, Standard_CString & name){ opencascade::handle<Geom2d_Curve> rv = self.GetCurve2d(name); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_CString &>(rv, name); }, "None", py::arg("name"));
// cls_XSControl_Vars.def("GetCurve", [](XSControl_Vars &self, Standard_CString & name){ opencascade::handle<Geom_Curve> rv = self.GetCurve(name); return std::tuple<opencascade::handle<Geom_Curve>, Standard_CString &>(rv, name); }, "None", py::arg("name"));
// cls_XSControl_Vars.def("GetSurface", [](XSControl_Vars &self, Standard_CString & name){ opencascade::handle<Geom_Surface> rv = self.GetSurface(name); return std::tuple<opencascade::handle<Geom_Surface>, Standard_CString &>(rv, name); }, "None", py::arg("name"));
cls_XSControl_Vars.def("SetPoint", (void (XSControl_Vars::*)(const Standard_CString, const gp_Pnt &)) &XSControl_Vars::SetPoint, "None", py::arg("name"), py::arg("val"));
cls_XSControl_Vars.def("SetPoint2d", (void (XSControl_Vars::*)(const Standard_CString, const gp_Pnt2d &)) &XSControl_Vars::SetPoint2d, "None", py::arg("name"), py::arg("val"));
// cls_XSControl_Vars.def("GetPoint", [](XSControl_Vars &self, Standard_CString & name, gp_Pnt & pnt){ Standard_Boolean rv = self.GetPoint(name, pnt); return std::tuple<Standard_Boolean, Standard_CString &>(rv, name); }, "None", py::arg("name"), py::arg("pnt"));
// cls_XSControl_Vars.def("GetPoint2d", [](XSControl_Vars &self, Standard_CString & name, gp_Pnt2d & pnt){ Standard_Boolean rv = self.GetPoint2d(name, pnt); return std::tuple<Standard_Boolean, Standard_CString &>(rv, name); }, "None", py::arg("name"), py::arg("pnt"));
cls_XSControl_Vars.def("SetShape", (void (XSControl_Vars::*)(const Standard_CString, const TopoDS_Shape &)) &XSControl_Vars::SetShape, "None", py::arg("name"), py::arg("val"));
// cls_XSControl_Vars.def("GetShape", [](XSControl_Vars &self, Standard_CString & name){ TopoDS_Shape rv = self.GetShape(name); return std::tuple<TopoDS_Shape, Standard_CString &>(rv, name); }, "None", py::arg("name"));
cls_XSControl_Vars.def_static("get_type_name_", (const char * (*)()) &XSControl_Vars::get_type_name, "None");
cls_XSControl_Vars.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_Vars::get_type_descriptor, "None");
cls_XSControl_Vars.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_Vars::*)() const) &XSControl_Vars::DynamicType, "None");

// Enums

}