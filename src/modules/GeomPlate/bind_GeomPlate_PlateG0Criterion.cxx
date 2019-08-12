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
#include <AdvApp2Var_Criterion.hxx>
#include <Standard.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <AdvApp2Var_CriterionType.hxx>
#include <AdvApp2Var_CriterionRepartition.hxx>
#include <AdvApp2Var_Patch.hxx>
#include <AdvApp2Var_Context.hxx>
#include <GeomPlate_PlateG0Criterion.hxx>

void bind_GeomPlate_PlateG0Criterion(py::module &mod){

py::class_<GeomPlate_PlateG0Criterion, std::unique_ptr<GeomPlate_PlateG0Criterion, Deleter<GeomPlate_PlateG0Criterion>>, AdvApp2Var_Criterion> cls_GeomPlate_PlateG0Criterion(mod, "GeomPlate_PlateG0Criterion", "this class contains a specific G0 criterion for GeomPlate_MakeApprox");

// Constructors
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"));
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"));
cls_GeomPlate_PlateG0Criterion.def(py::init<const TColgp_SequenceOfXY &, const TColgp_SequenceOfXYZ &, const Standard_Real, const AdvApp2Var_CriterionType, const AdvApp2Var_CriterionRepartition>(), py::arg("Data"), py::arg("G0Data"), py::arg("Maximum"), py::arg("Type"), py::arg("Repart"));

// Fields

// Methods
// cls_GeomPlate_PlateG0Criterion.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_PlateG0Criterion::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete_", (void (*)(void *)) &GeomPlate_PlateG0Criterion::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_PlateG0Criterion::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_PlateG0Criterion::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_PlateG0Criterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_PlateG0Criterion.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_PlateG0Criterion::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_PlateG0Criterion.def("Value", (void (GeomPlate_PlateG0Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const) &GeomPlate_PlateG0Criterion::Value, "None", py::arg("P"), py::arg("C"));
cls_GeomPlate_PlateG0Criterion.def("IsSatisfied", (Standard_Boolean (GeomPlate_PlateG0Criterion::*)(const AdvApp2Var_Patch &) const) &GeomPlate_PlateG0Criterion::IsSatisfied, "None", py::arg("P"));

// Enums

}