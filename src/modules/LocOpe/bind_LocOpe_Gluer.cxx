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
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <LocOpe_Operation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_Gluer.hxx>

void bind_LocOpe_Gluer(py::module &mod){

py::class_<LocOpe_Gluer> cls_LocOpe_Gluer(mod, "LocOpe_Gluer", "None");

// Constructors
cls_LocOpe_Gluer.def(py::init<>());
cls_LocOpe_Gluer.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("Sbase"), py::arg("Snew"));

// Fields

// Methods
// cls_LocOpe_Gluer.def_static("operator new_", (void * (*)(size_t)) &LocOpe_Gluer::operator new, "None", py::arg("theSize"));
// cls_LocOpe_Gluer.def_static("operator delete_", (void (*)(void *)) &LocOpe_Gluer::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_Gluer::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_Gluer.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_Gluer::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_Gluer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_Gluer.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_Gluer::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_Gluer.def("Init", (void (LocOpe_Gluer::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &LocOpe_Gluer::Init, "None", py::arg("Sbase"), py::arg("Snew"));
cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Face &, const TopoDS_Face &)) &LocOpe_Gluer::Bind, "None", py::arg("Fnew"), py::arg("Fbase"));
cls_LocOpe_Gluer.def("Bind", (void (LocOpe_Gluer::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &LocOpe_Gluer::Bind, "None", py::arg("Enew"), py::arg("Ebase"));
cls_LocOpe_Gluer.def("OpeType", (LocOpe_Operation (LocOpe_Gluer::*)() const) &LocOpe_Gluer::OpeType, "None");
cls_LocOpe_Gluer.def("Perform", (void (LocOpe_Gluer::*)()) &LocOpe_Gluer::Perform, "None");
cls_LocOpe_Gluer.def("IsDone", (Standard_Boolean (LocOpe_Gluer::*)() const) &LocOpe_Gluer::IsDone, "None");
cls_LocOpe_Gluer.def("ResultingShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::ResultingShape, "None");
cls_LocOpe_Gluer.def("DescendantFaces", (const TopTools_ListOfShape & (LocOpe_Gluer::*)(const TopoDS_Face &) const) &LocOpe_Gluer::DescendantFaces, "None", py::arg("F"));
cls_LocOpe_Gluer.def("BasisShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::BasisShape, "None");
cls_LocOpe_Gluer.def("GluedShape", (const TopoDS_Shape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::GluedShape, "None");
cls_LocOpe_Gluer.def("Edges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::Edges, "None");
cls_LocOpe_Gluer.def("TgtEdges", (const TopTools_ListOfShape & (LocOpe_Gluer::*)() const) &LocOpe_Gluer::TgtEdges, "None");

// Enums

}