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
#include <gp_Vec.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Prism.hxx>

void bind_LocOpe_Prism(py::module &mod){

py::class_<LocOpe_Prism, std::unique_ptr<LocOpe_Prism>> cls_LocOpe_Prism(mod, "LocOpe_Prism", "Defines a prism (using Prism from BRepSweep) with modifications provided for the Prism feature.");

// Constructors
cls_LocOpe_Prism.def(py::init<>());
cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("Base"), py::arg("V"));
cls_LocOpe_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"));

// Fields

// Methods
// cls_LocOpe_Prism.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Prism::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Prism.def_static("operator delete_", (void (*)(void *)) &LocOpe_Prism::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Prism::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Prism.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Prism::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Prism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Prism.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Prism::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"));
cls_LocOpe_Prism.def("Perform", (void (LocOpe_Prism::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &)) &LocOpe_Prism::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vtra"));
cls_LocOpe_Prism.def("FirstShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::FirstShape, "None");
cls_LocOpe_Prism.def("LastShape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::LastShape, "None");
cls_LocOpe_Prism.def("Shape", (const TopoDS_Shape & (LocOpe_Prism::*)() const) &LocOpe_Prism::Shape, "None");
cls_LocOpe_Prism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Prism::*)(const TopoDS_Shape &) const) &LocOpe_Prism::Shapes, "None", py::arg("S"));
cls_LocOpe_Prism.def("Curves", (void (LocOpe_Prism::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_Prism::Curves, "None", py::arg("SCurves"));
cls_LocOpe_Prism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Prism::*)() const) &LocOpe_Prism::BarycCurve, "None");

// Enums

}