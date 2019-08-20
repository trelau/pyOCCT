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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <BRepFill_Evolved.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_DPrism.hxx>

void bind_LocOpe_DPrism(py::module &mod){

py::class_<LocOpe_DPrism, std::unique_ptr<LocOpe_DPrism>> cls_LocOpe_DPrism(mod, "LocOpe_DPrism", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");

// Constructors
cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height1"), py::arg("Height2"), py::arg("Angle"));
cls_LocOpe_DPrism.def(py::init<const TopoDS_Face &, const Standard_Real, const Standard_Real>(), py::arg("Spine"), py::arg("Height"), py::arg("Angle"));

// Fields

// Methods
// cls_LocOpe_DPrism.def_static("operator new_", (void * (*)(size_t)) &LocOpe_DPrism::operator new, "None", py::arg("theSize"));
// cls_LocOpe_DPrism.def_static("operator delete_", (void (*)(void *)) &LocOpe_DPrism::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_DPrism::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_DPrism.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_DPrism::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_DPrism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_DPrism.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_DPrism::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_DPrism.def("IsDone", (Standard_Boolean (LocOpe_DPrism::*)() const) &LocOpe_DPrism::IsDone, "None");
cls_LocOpe_DPrism.def("Spine", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Spine, "None");
cls_LocOpe_DPrism.def("Profile", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Profile, "None");
cls_LocOpe_DPrism.def("FirstShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::FirstShape, "None");
cls_LocOpe_DPrism.def("LastShape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::LastShape, "None");
cls_LocOpe_DPrism.def("Shape", (const TopoDS_Shape & (LocOpe_DPrism::*)() const) &LocOpe_DPrism::Shape, "None");
cls_LocOpe_DPrism.def("Shapes", (const TopTools_ListOfShape & (LocOpe_DPrism::*)(const TopoDS_Shape &) const) &LocOpe_DPrism::Shapes, "None", py::arg("S"));
cls_LocOpe_DPrism.def("Curves", (void (LocOpe_DPrism::*)(TColGeom_SequenceOfCurve &) const) &LocOpe_DPrism::Curves, "None", py::arg("SCurves"));
cls_LocOpe_DPrism.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_DPrism::*)() const) &LocOpe_DPrism::BarycCurve, "None");

// Enums

}