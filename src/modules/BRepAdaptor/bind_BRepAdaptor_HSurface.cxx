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
#include <BRepAdaptor_Surface.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRepAdaptor_HSurface(py::module &mod){

py::class_<BRepAdaptor_HSurface, opencascade::handle<BRepAdaptor_HSurface>, Adaptor3d_HSurface> cls_BRepAdaptor_HSurface(mod, "BRepAdaptor_HSurface", "None");

// Constructors
cls_BRepAdaptor_HSurface.def(py::init<>());
cls_BRepAdaptor_HSurface.def(py::init<const BRepAdaptor_Surface &>(), py::arg("S"));

// Fields

// Methods
cls_BRepAdaptor_HSurface.def("Set", (void (BRepAdaptor_HSurface::*)(const BRepAdaptor_Surface &)) &BRepAdaptor_HSurface::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_BRepAdaptor_HSurface.def("Surface", (const Adaptor3d_Surface & (BRepAdaptor_HSurface::*)() const) &BRepAdaptor_HSurface::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_BRepAdaptor_HSurface.def("ChangeSurface", (BRepAdaptor_Surface & (BRepAdaptor_HSurface::*)()) &BRepAdaptor_HSurface::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_BRepAdaptor_HSurface.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HSurface::get_type_name, "None");
cls_BRepAdaptor_HSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HSurface::get_type_descriptor, "None");
cls_BRepAdaptor_HSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HSurface::*)() const) &BRepAdaptor_HSurface::DynamicType, "None");

// Enums

}