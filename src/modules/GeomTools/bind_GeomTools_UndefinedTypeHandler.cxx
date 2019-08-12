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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_IStream.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <GeomTools_UndefinedTypeHandler.hxx>
#include <Standard_Type.hxx>

void bind_GeomTools_UndefinedTypeHandler(py::module &mod){

py::class_<GeomTools_UndefinedTypeHandler, opencascade::handle<GeomTools_UndefinedTypeHandler>, Standard_Transient> cls_GeomTools_UndefinedTypeHandler(mod, "GeomTools_UndefinedTypeHandler", "None");

// Constructors
cls_GeomTools_UndefinedTypeHandler.def(py::init<>());

// Fields

// Methods
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintCurve, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadCurve", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Curve> &) const) &GeomTools_UndefinedTypeHandler::ReadCurve, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom2d_Curve> & a0, Standard_OStream & a1) -> void { return self.PrintCurve2d(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintCurve2d", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintCurve2d, "None", py::arg("C"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadCurve2d", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom2d_Curve> &) const) &GeomTools_UndefinedTypeHandler::ReadCurve2d, "None", py::arg("ctype"), py::arg("IS"), py::arg("C"));
cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", [](GeomTools_UndefinedTypeHandler &self, const opencascade::handle<Geom_Surface> & a0, Standard_OStream & a1) -> void { return self.PrintSurface(a0, a1); });
cls_GeomTools_UndefinedTypeHandler.def("PrintSurface", (void (GeomTools_UndefinedTypeHandler::*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &, const Standard_Boolean) const) &GeomTools_UndefinedTypeHandler::PrintSurface, "None", py::arg("S"), py::arg("OS"), py::arg("compact"));
cls_GeomTools_UndefinedTypeHandler.def("ReadSurface", (Standard_IStream & (GeomTools_UndefinedTypeHandler::*)(const Standard_Integer, Standard_IStream &, opencascade::handle<Geom_Surface> &) const) &GeomTools_UndefinedTypeHandler::ReadSurface, "None", py::arg("ctype"), py::arg("IS"), py::arg("S"));
cls_GeomTools_UndefinedTypeHandler.def_static("get_type_name_", (const char * (*)()) &GeomTools_UndefinedTypeHandler::get_type_name, "None");
cls_GeomTools_UndefinedTypeHandler.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomTools_UndefinedTypeHandler::get_type_descriptor, "None");
cls_GeomTools_UndefinedTypeHandler.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomTools_UndefinedTypeHandler::*)() const) &GeomTools_UndefinedTypeHandler::DynamicType, "None");

// Enums

}