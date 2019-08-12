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
#include <gp_Pnt2d.hxx>
#include <GccInt_IType.hxx>
#include <Standard_Handle.hxx>
#include <GccInt_BPoint.hxx>
#include <Standard_Type.hxx>

void bind_GccInt_BPoint(py::module &mod){

py::class_<GccInt_BPoint, opencascade::handle<GccInt_BPoint>, GccInt_Bisec> cls_GccInt_BPoint(mod, "GccInt_BPoint", "Describes a point as a bisecting object between two 2D geometric objects.");

// Constructors
cls_GccInt_BPoint.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));

// Fields

// Methods
cls_GccInt_BPoint.def("Point", (gp_Pnt2d (GccInt_BPoint::*)() const) &GccInt_BPoint::Point, "Returns a 2D point which is the geometry of this bisecting object.");
cls_GccInt_BPoint.def("ArcType", (GccInt_IType (GccInt_BPoint::*)() const) &GccInt_BPoint::ArcType, "Returns GccInt_Pnt, which is the type of any GccInt_BPoint bisecting object.");
cls_GccInt_BPoint.def_static("get_type_name_", (const char * (*)()) &GccInt_BPoint::get_type_name, "None");
cls_GccInt_BPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccInt_BPoint::get_type_descriptor, "None");
cls_GccInt_BPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccInt_BPoint::*)() const) &GccInt_BPoint::DynamicType, "None");

// Enums

}