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
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESGeom_TabulatedCylinder.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_TabulatedCylinder(py::module &mod){

py::class_<IGESGeom_TabulatedCylinder, opencascade::handle<IGESGeom_TabulatedCylinder>, IGESData_IGESEntity> cls_IGESGeom_TabulatedCylinder(mod, "IGESGeom_TabulatedCylinder", "defines IGESTabulatedCylinder, Type <122> Form <0> in package IGESGeom A tabulated cylinder is a surface formed by moving a line segment called generatrix parallel to itself along a curve called directrix. The curve may be a line, circular arc, conic arc, parametric spline curve, rational B-spline curve or composite curve.");

// Constructors
cls_IGESGeom_TabulatedCylinder.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_TabulatedCylinder.def("Init", (void (IGESGeom_TabulatedCylinder::*)(const opencascade::handle<IGESData_IGESEntity> &, const gp_XYZ &)) &IGESGeom_TabulatedCylinder::Init, "This method is used to set the fields of the class TabulatedCylinder - aDirectrix : Directrix Curve of the tabulated cylinder - anEnd : Coordinates of the terminate point of the generatrix The start point of the directrix is identical to the start point of the generatrix", py::arg("aDirectrix"), py::arg("anEnd"));
cls_IGESGeom_TabulatedCylinder.def("Directrix", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_TabulatedCylinder::*)() const) &IGESGeom_TabulatedCylinder::Directrix, "returns the directrix curve of the tabulated cylinder");
cls_IGESGeom_TabulatedCylinder.def("EndPoint", (gp_Pnt (IGESGeom_TabulatedCylinder::*)() const) &IGESGeom_TabulatedCylinder::EndPoint, "returns end point of generatrix of the tabulated cylinder");
cls_IGESGeom_TabulatedCylinder.def("TransformedEndPoint", (gp_Pnt (IGESGeom_TabulatedCylinder::*)() const) &IGESGeom_TabulatedCylinder::TransformedEndPoint, "returns end point of generatrix of the tabulated cylinder after applying Transf. Matrix");
cls_IGESGeom_TabulatedCylinder.def_static("get_type_name_", (const char * (*)()) &IGESGeom_TabulatedCylinder::get_type_name, "None");
cls_IGESGeom_TabulatedCylinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_TabulatedCylinder::get_type_descriptor, "None");
cls_IGESGeom_TabulatedCylinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_TabulatedCylinder::*)() const) &IGESGeom_TabulatedCylinder::DynamicType, "None");

// Enums

}