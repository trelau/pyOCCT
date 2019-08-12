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
#include <GeomAdaptor_SurfaceOfLinearExtrusion.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_Handle.hxx>
#include <GeomAdaptor_HSurfaceOfLinearExtrusion.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_HSurfaceOfLinearExtrusion(py::module &mod){

py::class_<GeomAdaptor_HSurfaceOfLinearExtrusion, opencascade::handle<GeomAdaptor_HSurfaceOfLinearExtrusion>, Adaptor3d_HSurface> cls_GeomAdaptor_HSurfaceOfLinearExtrusion(mod, "GeomAdaptor_HSurfaceOfLinearExtrusion", "None");

// Constructors
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def(py::init<>());
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def(py::init<const GeomAdaptor_SurfaceOfLinearExtrusion &>(), py::arg("S"));

// Fields

// Methods
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("Set", (void (GeomAdaptor_HSurfaceOfLinearExtrusion::*)(const GeomAdaptor_SurfaceOfLinearExtrusion &)) &GeomAdaptor_HSurfaceOfLinearExtrusion::Set, "Sets the field of the GenHSurface.", py::arg("S"));
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("Surface", (const Adaptor3d_Surface & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_HSurfaceOfLinearExtrusion::Surface, "Returns a reference to the Surface inside the HSurface. This is redefined from HSurface, cannot be inline.");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("ChangeSurface", (GeomAdaptor_SurfaceOfLinearExtrusion & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::ChangeSurface, "Returns the surface used to create the GenHSurface.");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::get_type_name, "None");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HSurfaceOfLinearExtrusion::get_type_descriptor, "None");
cls_GeomAdaptor_HSurfaceOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HSurfaceOfLinearExtrusion::*)() const) &GeomAdaptor_HSurfaceOfLinearExtrusion::DynamicType, "None");

// Enums

}