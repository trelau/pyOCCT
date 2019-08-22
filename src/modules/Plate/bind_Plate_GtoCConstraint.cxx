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
#include <Plate_GtoCConstraint.hxx>
#include <gp_XY.hxx>
#include <Plate_D1.hxx>
#include <gp_XYZ.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_PinpointConstraint.hxx>

void bind_Plate_GtoCConstraint(py::module &mod){

py::class_<Plate_GtoCConstraint> cls_Plate_GtoCConstraint(mod, "Plate_GtoCConstraint", "define a G1, G2 or G3 constraint on the Plate");

// Constructors
cls_Plate_GtoCConstraint.def(py::init<const Plate_GtoCConstraint &>(), py::arg("ref"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("nP"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("nP"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"));
cls_Plate_GtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const gp_XYZ &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("nP"));

// Fields

// Methods
// cls_Plate_GtoCConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_GtoCConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_GtoCConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_GtoCConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_GtoCConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_GtoCConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_GtoCConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_GtoCConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_GtoCConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_GtoCConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_GtoCConstraint.def("nb_PPC", (const Standard_Integer & (Plate_GtoCConstraint::*)() const) &Plate_GtoCConstraint::nb_PPC, "None");
cls_Plate_GtoCConstraint.def("GetPPC", (const Plate_PinpointConstraint & (Plate_GtoCConstraint::*)(const Standard_Integer) const) &Plate_GtoCConstraint::GetPPC, "None", py::arg("Index"));
cls_Plate_GtoCConstraint.def("D1SurfInit", (const Plate_D1 & (Plate_GtoCConstraint::*)() const) &Plate_GtoCConstraint::D1SurfInit, "None");

// Enums

}