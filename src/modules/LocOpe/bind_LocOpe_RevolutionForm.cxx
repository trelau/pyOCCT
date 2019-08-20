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
#include <gp_Vec.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <gp_Pnt.hxx>
#include <LocOpe_RevolutionForm.hxx>

void bind_LocOpe_RevolutionForm(py::module &mod){

py::class_<LocOpe_RevolutionForm, std::unique_ptr<LocOpe_RevolutionForm>> cls_LocOpe_RevolutionForm(mod, "LocOpe_RevolutionForm", "Defines a revolution form (using Revol from BRepSweep) with modifications provided for the RevolutionForm feature.");

// Constructors
cls_LocOpe_RevolutionForm.def(py::init<>());
// cls_LocOpe_RevolutionForm.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("Base"), py::arg("Axe"), py::arg("Angle"));

// Fields

// Methods
// cls_LocOpe_RevolutionForm.def_static("operator new_", (void * (*)(size_t)) &LocOpe_RevolutionForm::operator new, "None", py::arg("theSize"));
// cls_LocOpe_RevolutionForm.def_static("operator delete_", (void (*)(void *)) &LocOpe_RevolutionForm::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_RevolutionForm::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_RevolutionForm.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_RevolutionForm::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_RevolutionForm::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_RevolutionForm.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_RevolutionForm::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_RevolutionForm.def("Perform", (void (LocOpe_RevolutionForm::*)(const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real)) &LocOpe_RevolutionForm::Perform, "None", py::arg("Base"), py::arg("Axe"), py::arg("Angle"));
cls_LocOpe_RevolutionForm.def("FirstShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::FirstShape, "None");
cls_LocOpe_RevolutionForm.def("LastShape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::LastShape, "None");
cls_LocOpe_RevolutionForm.def("Shape", (const TopoDS_Shape & (LocOpe_RevolutionForm::*)() const) &LocOpe_RevolutionForm::Shape, "None");
cls_LocOpe_RevolutionForm.def("Shapes", (const TopTools_ListOfShape & (LocOpe_RevolutionForm::*)(const TopoDS_Shape &) const) &LocOpe_RevolutionForm::Shapes, "None", py::arg("S"));

// Enums

}