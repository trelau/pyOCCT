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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Revol.hxx>

void bind_LocOpe_Revol(py::module &mod){

py::class_<LocOpe_Revol, std::unique_ptr<LocOpe_Revol>> cls_LocOpe_Revol(mod, "LocOpe_Revol", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");

// Constructors
cls_LocOpe_Revol.def(py::init<>());
// cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
// cls_LocOpe_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axis"), py::arg("Angle"));

// Fields

// Methods
// cls_LocOpe_Revol.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Revol::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Revol.def_static("operator delete_", (void (*)(void *)) &LocOpe_Revol::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Revol::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Revol.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Revol::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Revol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Revol.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Revol::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"), py::arg("angledec"));
cls_LocOpe_Revol.def("Perform", (void (LocOpe_Revol::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_Revol::Perform, "None", py::arg("Base"), py::arg("Axis"), py::arg("Angle"));
cls_LocOpe_Revol.def("FirstShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::FirstShape, "None");
cls_LocOpe_Revol.def("LastShape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::LastShape, "None");
cls_LocOpe_Revol.def("Shape", (const TopoDS_Shape & (LocOpe_Revol::*)() const) &LocOpe_Revol::Shape, "None");
cls_LocOpe_Revol.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Revol::*)(const TopoDS_Shape &) const) &LocOpe_Revol::Shapes, "None", py::arg("S"));
cls_LocOpe_Revol.def("Curves", (void (LocOpe_Revol::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_Revol::Curves, "None", py::arg("SCurves"));
cls_LocOpe_Revol.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Revol::*)() const) &LocOpe_Revol::BarycCurve, "None");

// Enums

}