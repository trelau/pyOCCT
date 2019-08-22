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
#include <Plate_D1.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <Plate_PinpointConstraint.hxx>
#include <Plate_LinearScalarConstraint.hxx>
#include <Plate_FreeGtoCConstraint.hxx>

void bind_Plate_FreeGtoCConstraint(py::module &mod){

py::class_<Plate_FreeGtoCConstraint> cls_Plate_FreeGtoCConstraint(mod, "Plate_FreeGtoCConstraint", "define a G1, G2 or G3 constraint on the Plate using weaker constraint than GtoCConstraint");

// Constructors
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("IncrementalLoad"), py::arg("orientation"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("IncrementalLoad"), py::arg("orientation"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const Standard_Real>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("IncrementalLoad"));
cls_Plate_FreeGtoCConstraint.def(py::init<const gp_XY &, const Plate_D1 &, const Plate_D1 &, const Plate_D2 &, const Plate_D2 &, const Plate_D3 &, const Plate_D3 &, const Standard_Real, const Standard_Integer>(), py::arg("point2d"), py::arg("D1S"), py::arg("D1T"), py::arg("D2S"), py::arg("D2T"), py::arg("D3S"), py::arg("D3T"), py::arg("IncrementalLoad"), py::arg("orientation"));

// Fields

// Methods
// cls_Plate_FreeGtoCConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_FreeGtoCConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_FreeGtoCConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_FreeGtoCConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_FreeGtoCConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_FreeGtoCConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_FreeGtoCConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_FreeGtoCConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_FreeGtoCConstraint.def("nb_PPC", (const Standard_Integer & (Plate_FreeGtoCConstraint::*)() const) &Plate_FreeGtoCConstraint::nb_PPC, "None");
cls_Plate_FreeGtoCConstraint.def("GetPPC", (const Plate_PinpointConstraint & (Plate_FreeGtoCConstraint::*)(const Standard_Integer) const) &Plate_FreeGtoCConstraint::GetPPC, "None", py::arg("Index"));
cls_Plate_FreeGtoCConstraint.def("nb_LSC", (const Standard_Integer & (Plate_FreeGtoCConstraint::*)() const) &Plate_FreeGtoCConstraint::nb_LSC, "None");
cls_Plate_FreeGtoCConstraint.def("LSC", (const Plate_LinearScalarConstraint & (Plate_FreeGtoCConstraint::*)(const Standard_Integer) const) &Plate_FreeGtoCConstraint::LSC, "None", py::arg("Index"));

// Enums

}