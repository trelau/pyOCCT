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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESGeom_Plane.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Plane(py::module &mod){

py::class_<IGESGeom_Plane, opencascade::handle<IGESGeom_Plane>, IGESData_IGESEntity> cls_IGESGeom_Plane(mod, "IGESGeom_Plane", "defines IGESPlane, Type <108> Form <-1,0,1> in package IGESGeom A plane entity can be used to represent unbounded plane, as well as bounded portion of a plane. In either of the above cases the plane is defined within definition space by means of coefficients A, B, C, D where at least one of A, B, C is non-zero and A * XT + B * YT + C * ZT = D");

// Constructors
cls_IGESGeom_Plane.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Plane.def("Init", (void (IGESGeom_Plane::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<IGESData_IGESEntity> &, const gp_XYZ &, const Standard_Real)) &IGESGeom_Plane::Init, "None", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("aCurve"), py::arg("attach"), py::arg("aSize"));
cls_IGESGeom_Plane.def("SetFormNumber", (void (IGESGeom_Plane::*)(const Standard_Integer)) &IGESGeom_Plane::SetFormNumber, "Changes FormNumber (indicates the Type of Bound : 0 no Bound, 1 (External) Bound, -1 Hole) Remark that Init keeps this Value and must be consistent : aCurve Null if FormNumber = 0, Non-Null else Error if not in ranges [0-1] or [10-12]", py::arg("form"));
cls_IGESGeom_Plane.def("Equation", [](IGESGeom_Plane &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D){ self.Equation(A, B, C, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D); }, "None", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_IGESGeom_Plane.def("TransformedEquation", [](IGESGeom_Plane &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D){ self.TransformedEquation(A, B, C, D); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D); }, "None", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_IGESGeom_Plane.def("HasBoundingCurve", (Standard_Boolean (IGESGeom_Plane::*)() const) &IGESGeom_Plane::HasBoundingCurve, "returns True if there exists a bounding curve");
cls_IGESGeom_Plane.def("HasBoundingCurveHole", (Standard_Boolean (IGESGeom_Plane::*)() const) &IGESGeom_Plane::HasBoundingCurveHole, "returns True if bounding curve exists and bounded portion is negative");
cls_IGESGeom_Plane.def("BoundingCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_Plane::*)() const) &IGESGeom_Plane::BoundingCurve, "returns Optional Bounding Curve, can be positive (normal clipping) or negative (hole) according to Form Number");
cls_IGESGeom_Plane.def("HasSymbolAttach", (Standard_Boolean (IGESGeom_Plane::*)() const) &IGESGeom_Plane::HasSymbolAttach, "returns True if SymbolSize() > 0, False if SymbolSize() = 0");
cls_IGESGeom_Plane.def("SymbolAttach", (gp_Pnt (IGESGeom_Plane::*)() const) &IGESGeom_Plane::SymbolAttach, "returns (X, Y, Z) if symbol exists else returns (0, 0, 0)");
cls_IGESGeom_Plane.def("TransformedSymbolAttach", (gp_Pnt (IGESGeom_Plane::*)() const) &IGESGeom_Plane::TransformedSymbolAttach, "returns (X, Y, Z) if symbol exists after applying Transf. Matrix else returns (0, 0, 0)");
cls_IGESGeom_Plane.def("SymbolSize", (Standard_Real (IGESGeom_Plane::*)() const) &IGESGeom_Plane::SymbolSize, "Size of optional display symbol");
cls_IGESGeom_Plane.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Plane::get_type_name, "None");
cls_IGESGeom_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Plane::get_type_descriptor, "None");
cls_IGESGeom_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Plane::*)() const) &IGESGeom_Plane::DynamicType, "None");

// Enums

}