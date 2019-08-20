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
#include <gp_Pnt.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <LocOpe_LinearForm.hxx>

void bind_LocOpe_LinearForm(py::module &mod){

py::class_<LocOpe_LinearForm, std::unique_ptr<LocOpe_LinearForm>> cls_LocOpe_LinearForm(mod, "LocOpe_LinearForm", "Defines a linear form (using Prism from BRepSweep) with modifications provided for the LinearForm feature.");

// Constructors
cls_LocOpe_LinearForm.def(py::init<>());
cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def(py::init<const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));

// Fields

// Methods
// cls_LocOpe_LinearForm.def_static("operator new_", (void * (*)(size_t)) &LocOpe_LinearForm::operator new, "None", py::arg("theSize"));
// cls_LocOpe_LinearForm.def_static("operator delete_", (void (*)(void *)) &LocOpe_LinearForm::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_LinearForm::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_LinearForm.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_LinearForm::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_LinearForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_LinearForm.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_LinearForm::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def("Perform", (void (LocOpe_LinearForm::*)(const TopoDS_Shape &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &)) &LocOpe_LinearForm::Perform, "None", py::arg("Base"), py::arg("V"), py::arg("Vectra"), py::arg("Pnt1"), py::arg("Pnt2"));
cls_LocOpe_LinearForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::FirstShape, "None");
cls_LocOpe_LinearForm.def("LastShape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::LastShape, "None");
cls_LocOpe_LinearForm.def("Shape", (const TopoDS_Shape & (LocOpe_LinearForm::*)() const) &LocOpe_LinearForm::Shape, "None");
cls_LocOpe_LinearForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_LinearForm::*)(const TopoDS_Shape &) const) &LocOpe_LinearForm::Shapes, "None", py::arg("S"));

// Enums

}