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
#include <GeomAdaptor_SurfaceOfRevolution.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_Handle.hxx>
#include <GeomAdaptor_HSurfaceOfRevolution.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_HSurfaceOfRevolution(py::module &mod){

py::class_<GeomAdaptor_HSurfaceOfRevolution, opencascade::handle<GeomAdaptor_HSurfaceOfRevolution>, Adaptor3d_HSurface> cls_GeomAdaptor_HSurfaceOfRevolution(mod, "GeomAdaptor_HSurfaceOfRevolution", "None");

// Constructors
cls_GeomAdaptor_HSurfaceOfRevolution.def(py::init<>());
cls_GeomAdaptor_HSurfaceOfRevolution.def(py::init<const GeomAdaptor_SurfaceOfRevolution &>(), py::arg("S"));

// Fields

// Methods
cls_GeomAdaptor_HSurfaceOfRevolution.def("Set", (void (GeomAdaptor_HSurfaceOfRevolution::*)(const GeomAdaptor_SurfaceOfRevolution &)) &GeomAdaptor_HSurfaceOfRevolution::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_HSurfaceOfRevolution.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_HSurfaceOfRevolution::*)() const) &GeomAdaptor_HSurfaceOfRevolution::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_HSurfaceOfRevolution.def("ChangeSurface", (GeomAdaptor_SurfaceOfRevolution & (GeomAdaptor_HSurfaceOfRevolution::*)()) &GeomAdaptor_HSurfaceOfRevolution::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_HSurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurfaceOfRevolution::get_type_name, "None");
cls_GeomAdaptor_HSurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurfaceOfRevolution::get_type_descriptor, "None");
cls_GeomAdaptor_HSurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurfaceOfRevolution::*)() const) &GeomAdaptor_HSurfaceOfRevolution::DynamicType, "None");

// Enums

}