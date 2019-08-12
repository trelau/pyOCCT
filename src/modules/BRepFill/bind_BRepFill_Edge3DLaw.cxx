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
#include <BRepFill_LocationLaw.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <BRepFill_Edge3DLaw.hxx>
#include <Standard_Type.hxx>

void bind_BRepFill_Edge3DLaw(py::module &mod){

py::class_<BRepFill_Edge3DLaw, opencascade::handle<BRepFill_Edge3DLaw>, BRepFill_LocationLaw> cls_BRepFill_Edge3DLaw(mod, "BRepFill_Edge3DLaw", "Build Location Law, with a Wire.");

// Constructors
cls_BRepFill_Edge3DLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Path"), py::arg("Law"));

// Fields

// Methods
cls_BRepFill_Edge3DLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_Edge3DLaw::get_type_name, "None");
cls_BRepFill_Edge3DLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_Edge3DLaw::get_type_descriptor, "None");
cls_BRepFill_Edge3DLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_Edge3DLaw::*)() const) &BRepFill_Edge3DLaw::DynamicType, "None");

// Enums

}