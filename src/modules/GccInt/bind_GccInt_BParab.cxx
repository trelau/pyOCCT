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
#include <gp_Parab2d.hxx>
#include <GccInt_IType.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_BParab.hxx>
#include <Standard_Type.hxx>

void bind_GccInt_BParab(py::module &mod){

py::class_<GccInt_BParab, opencascade::handle<GccInt_BParab>, GccInt_Bisec> cls_GccInt_BParab(mod, "GccInt_BParab", "Describes a parabola as a bisecting curve between two 2D geometric objects (such as lines, circles or points).");

// Constructors
cls_GccInt_BParab.def(py::init<const gp_Parab2d &>(), py::arg("Parab"));

// Fields

// Methods
cls_GccInt_BParab.def("Parabola", (gp_Parab2d (GccInt_BParab::*)() const) &GccInt_BParab::Parabola, "Returns a 2D parabola which is the geometry of this bisecting curve.");
cls_GccInt_BParab.def("ArcType", (GccInt_IType (GccInt_BParab::*)() const) &GccInt_BParab::ArcType, "Returns GccInt_Par, which is the type of any GccInt_BParab bisecting curve.");
cls_GccInt_BParab.def_static("get_type_name_", (const char * (*)()) &GccInt_BParab::get_type_name, "None");
cls_GccInt_BParab.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BParab::get_type_descriptor, "None");
cls_GccInt_BParab.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BParab::*)() const) &GccInt_BParab::DynamicType, "None");

// Enums

}