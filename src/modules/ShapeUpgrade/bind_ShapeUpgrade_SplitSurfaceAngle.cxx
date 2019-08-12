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
#include <ShapeUpgrade_SplitSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_SplitSurfaceAngle.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitSurfaceAngle(py::module &mod){

py::class_<ShapeUpgrade_SplitSurfaceAngle, opencascade::handle<ShapeUpgrade_SplitSurfaceAngle>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceAngle(mod, "ShapeUpgrade_SplitSurfaceAngle", "Splits a surfaces of revolution, cylindrical, toroidal, conical, spherical so that each resulting segment covers not more than defined number of degrees.");

// Constructors
cls_ShapeUpgrade_SplitSurfaceAngle.def(py::init<const Standard_Real>(), py::arg("MaxAngle"));

// Fields

// Methods
cls_ShapeUpgrade_SplitSurfaceAngle.def("SetMaxAngle", (void (ShapeUpgrade_SplitSurfaceAngle::*)(const Standard_Real)) &ShapeUpgrade_SplitSurfaceAngle::SetMaxAngle, "Set maximal angle", py::arg("MaxAngle"));
cls_ShapeUpgrade_SplitSurfaceAngle.def("MaxAngle", (Standard_Real (ShapeUpgrade_SplitSurfaceAngle::*)() const) &ShapeUpgrade_SplitSurfaceAngle::MaxAngle, "Returns maximal angle");
cls_ShapeUpgrade_SplitSurfaceAngle.def("Compute", (void (ShapeUpgrade_SplitSurfaceAngle::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceAngle::Compute, "Performs splitting of the supporting surface(s). First defines splitting values, then calls inherited method.", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurfaceAngle.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceAngle::get_type_name, "None");
cls_ShapeUpgrade_SplitSurfaceAngle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceAngle::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitSurfaceAngle.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceAngle::*)() const) &ShapeUpgrade_SplitSurfaceAngle::DynamicType, "None");

// Enums

}