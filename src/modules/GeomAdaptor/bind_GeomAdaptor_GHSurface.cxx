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
#include <Adaptor3d_HSurface.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_Handle.hxx>
#include <GeomAdaptor_GHSurface.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_GHSurface(py::module &mod){

py::class_<GeomAdaptor_GHSurface, opencascade::handle<GeomAdaptor_GHSurface>, Adaptor3d_HSurface> cls_GeomAdaptor_GHSurface(mod, "GeomAdaptor_GHSurface", "None");

// Constructors
cls_GeomAdaptor_GHSurface.def(py::init<>());
cls_GeomAdaptor_GHSurface.def(py::init<const GeomAdaptor_Surface &>(), py::arg("S"));

// Fields

// Methods
cls_GeomAdaptor_GHSurface.def("Set", (void (GeomAdaptor_GHSurface::*)(const GeomAdaptor_Surface &)) &GeomAdaptor_GHSurface::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_GHSurface.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_GHSurface::*)() const) &GeomAdaptor_GHSurface::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_GHSurface.def("ChangeSurface", (GeomAdaptor_Surface & (GeomAdaptor_GHSurface::*)()) &GeomAdaptor_GHSurface::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_GHSurface.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_GHSurface::get_type_name, "None");
cls_GeomAdaptor_GHSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_GHSurface::get_type_descriptor, "None");
cls_GeomAdaptor_GHSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_GHSurface::*)() const) &GeomAdaptor_GHSurface::DynamicType, "None");

// Enums

}