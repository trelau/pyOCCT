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
#include <gp_XY.hxx>
#include <gp_Pln.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_LinearScalarConstraint.hxx>
#include <Plate_PlaneConstraint.hxx>

void bind_Plate_PlaneConstraint(py::module &mod){

py::class_<Plate_PlaneConstraint, std::unique_ptr<Plate_PlaneConstraint>> cls_Plate_PlaneConstraint(mod, "Plate_PlaneConstraint", "constraint a point to belong to a Plane");

// Constructors
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &>(), py::arg("point2d"), py::arg("pln"));
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &, const Standard_Integer>(), py::arg("point2d"), py::arg("pln"), py::arg("iu"));
cls_Plate_PlaneConstraint.def(py::init<const gp_XY &, const gp_Pln &, const Standard_Integer, const Standard_Integer>(), py::arg("point2d"), py::arg("pln"), py::arg("iu"), py::arg("iv"));

// Fields

// Methods
// cls_Plate_PlaneConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_PlaneConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_PlaneConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_PlaneConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_PlaneConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_PlaneConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_PlaneConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_PlaneConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_PlaneConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_PlaneConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_PlaneConstraint.def("LSC", (const Plate_LinearScalarConstraint & (Plate_PlaneConstraint::*)() const) &Plate_PlaneConstraint::LSC, "None");

// Enums

}