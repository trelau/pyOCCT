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
#include <GccInt_Bisec.hxx>
#include <gp_Circ2d.hxx>
#include <GccInt_IType.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_BCirc.hxx>
#include <Standard_Type.hxx>

void bind_GccInt_BCirc(py::module &mod){

py::class_<GccInt_BCirc, opencascade::handle<GccInt_BCirc>, GccInt_Bisec> cls_GccInt_BCirc(mod, "GccInt_BCirc", "Describes a circle as a bisecting curve between two 2D geometric objects (such as circles or points).");

// Constructors
cls_GccInt_BCirc.def(py::init<const gp_Circ2d &>(), py::arg("Circ"));

// Fields

// Methods
cls_GccInt_BCirc.def("Circle", (gp_Circ2d (GccInt_BCirc::*)() const) &GccInt_BCirc::Circle, "Returns a 2D circle which is the geometry of this bisecting curve.");
cls_GccInt_BCirc.def("ArcType", (GccInt_IType (GccInt_BCirc::*)() const) &GccInt_BCirc::ArcType, "Returns GccInt_Cir, which is the type of any GccInt_BCirc bisecting curve.");
cls_GccInt_BCirc.def_static("get_type_name_", (const char * (*)()) &GccInt_BCirc::get_type_name, "None");
cls_GccInt_BCirc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BCirc::get_type_descriptor, "None");
cls_GccInt_BCirc.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BCirc::*)() const) &GccInt_BCirc::DynamicType, "None");

// Enums

}