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
#include <GeomFill_LocationGuide.hxx>
#include <BRepFill_ACRLaw.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_BRepFill_ACRLaw(py::module &mod){

py::class_<BRepFill_ACRLaw, opencascade::handle<BRepFill_ACRLaw>, BRepFill_LocationLaw> cls_BRepFill_ACRLaw(mod, "BRepFill_ACRLaw", "Build Location Law, with a Wire. In the case of guided contour and trihedron by reduced curvilinear abscissa");

// Constructors
cls_BRepFill_ACRLaw.def(py::init<const TopoDS_Wire &, const opencascade::handle<GeomFill_LocationGuide> &>(), py::arg("Path"), py::arg("Law"));

// Fields

// Methods
cls_BRepFill_ACRLaw.def_static("get_type_name_", (const char * (*)()) &BRepFill_ACRLaw::get_type_name, "None");
cls_BRepFill_ACRLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepFill_ACRLaw::get_type_descriptor, "None");
cls_BRepFill_ACRLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepFill_ACRLaw::*)() const) &BRepFill_ACRLaw::DynamicType, "None");

// Enums

}