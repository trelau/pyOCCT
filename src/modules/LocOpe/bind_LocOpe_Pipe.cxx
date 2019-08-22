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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <BRepFill_Pipe.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Pipe.hxx>

void bind_LocOpe_Pipe(py::module &mod){

py::class_<LocOpe_Pipe> cls_LocOpe_Pipe(mod, "LocOpe_Pipe", "Defines a pipe (near from Pipe from BRepFill), with modifications provided for the Pipe feature.");

// Constructors
cls_LocOpe_Pipe.def(py::init<const TopoDS_Wire &, const TopoDS_Shape &>(), py::arg("Spine"), py::arg("Profile"));

// Fields

// Methods
// cls_LocOpe_Pipe.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Pipe::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Pipe.def_static("operator delete_", (void (*)(void *)) &LocOpe_Pipe::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Pipe::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Pipe.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Pipe::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Pipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Pipe.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Pipe::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Pipe.def("Spine", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Spine, "None");
cls_LocOpe_Pipe.def("Profile", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Profile, "None");
cls_LocOpe_Pipe.def("FirstShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::FirstShape, "None");
cls_LocOpe_Pipe.def("LastShape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::LastShape, "None");
cls_LocOpe_Pipe.def("Shape", (const TopoDS_Shape & (LocOpe_Pipe::*)() const) &LocOpe_Pipe::Shape, "None");
cls_LocOpe_Pipe.def("Shapes", (const TopTools_ListOfShape & (LocOpe_Pipe::*)(const TopoDS_Shape &)) &LocOpe_Pipe::Shapes, "None", py::arg("S"));
cls_LocOpe_Pipe.def("Curves", (const TColGeom_SequenceOfCurve & (LocOpe_Pipe::*)(const TColgp_SequenceOfPnt &)) &LocOpe_Pipe::Curves, "None", py::arg("Spt"));
cls_LocOpe_Pipe.def("BarycCurve", (opencascade::handle<Geom_Curve> (LocOpe_Pipe::*)()) &LocOpe_Pipe::BarycCurve, "None");

// Enums

}