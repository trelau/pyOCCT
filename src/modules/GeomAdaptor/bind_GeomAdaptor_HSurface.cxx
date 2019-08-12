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
#include <GeomAdaptor_GHSurface.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_HSurface(py::module &mod){

py::class_<GeomAdaptor_HSurface, opencascade::handle<GeomAdaptor_HSurface>, GeomAdaptor_GHSurface> cls_GeomAdaptor_HSurface(mod, "GeomAdaptor_HSurface", "An interface between the services provided by any surface from the package Geom and those required of the surface by algorithms which use it. Provides a surface handled by reference.");

// Constructors
cls_GeomAdaptor_HSurface.def(py::init<>());
cls_GeomAdaptor_HSurface.def(py::init<const GeomAdaptor_Surface &>(), py::arg("AS"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"));
cls_GeomAdaptor_HSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("TolU"), py::arg("TolV"));

// Fields

// Methods
cls_GeomAdaptor_HSurface.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurface::get_type_name, "None");
cls_GeomAdaptor_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurface::get_type_descriptor, "None");
cls_GeomAdaptor_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurface::*)() const) &GeomAdaptor_HSurface::DynamicType, "None");

// Enums

}