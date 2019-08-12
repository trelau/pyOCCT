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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Line.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_SurfaceOfRevolution.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_SurfaceOfRevolution(py::module &mod){

py::class_<IGESGeom_SurfaceOfRevolution, opencascade::handle<IGESGeom_SurfaceOfRevolution>, IGESData_IGESEntity> cls_IGESGeom_SurfaceOfRevolution(mod, "IGESGeom_SurfaceOfRevolution", "defines IGESSurfaceOfRevolution, Type <120> Form <0> in package IGESGeom A surface of revolution is defined by an axis of rotation a generatrix, and start and terminate rotation angles. The surface is created by rotating the generatrix about the axis of rotation through the start and terminate rotation angles.");

// Constructors
cls_IGESGeom_SurfaceOfRevolution.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_SurfaceOfRevolution.def("Init", (void (IGESGeom_SurfaceOfRevolution::*)(const opencascade::handle<IGESGeom_Line> &, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Real, const Standard_Real)) &IGESGeom_SurfaceOfRevolution::Init, "This method is used to set the fields of the class Line - anAxis : Axis of revolution - aGeneratrix : The curve which is revolved about the axis - aStartAngle : Start angle of the surface of revolution - anEndAngle : End angle of the surface of revolution", py::arg("anAxis"), py::arg("aGeneratrix"), py::arg("aStartAngle"), py::arg("anEndAngle"));
cls_IGESGeom_SurfaceOfRevolution.def("AxisOfRevolution", (opencascade::handle<IGESGeom_Line> (IGESGeom_SurfaceOfRevolution::*)() const) &IGESGeom_SurfaceOfRevolution::AxisOfRevolution, "returns the axis of revolution");
cls_IGESGeom_SurfaceOfRevolution.def("Generatrix", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_SurfaceOfRevolution::*)() const) &IGESGeom_SurfaceOfRevolution::Generatrix, "returns the curve which is revolved about the axis");
cls_IGESGeom_SurfaceOfRevolution.def("StartAngle", (Standard_Real (IGESGeom_SurfaceOfRevolution::*)() const) &IGESGeom_SurfaceOfRevolution::StartAngle, "returns start angle of revolution");
cls_IGESGeom_SurfaceOfRevolution.def("EndAngle", (Standard_Real (IGESGeom_SurfaceOfRevolution::*)() const) &IGESGeom_SurfaceOfRevolution::EndAngle, "returns end angle of revolution");
cls_IGESGeom_SurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &IGESGeom_SurfaceOfRevolution::get_type_name, "None");
cls_IGESGeom_SurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_SurfaceOfRevolution::get_type_descriptor, "None");
cls_IGESGeom_SurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_SurfaceOfRevolution::*)() const) &IGESGeom_SurfaceOfRevolution::DynamicType, "None");

// Enums

}