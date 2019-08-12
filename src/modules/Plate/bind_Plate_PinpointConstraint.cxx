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
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_PinpointConstraint.hxx>

void bind_Plate_PinpointConstraint(py::module &mod){

py::class_<Plate_PinpointConstraint, std::unique_ptr<Plate_PinpointConstraint, Deleter<Plate_PinpointConstraint>>> cls_Plate_PinpointConstraint(mod, "Plate_PinpointConstraint", "define a constraint on the Plate");

// Constructors
cls_Plate_PinpointConstraint.def(py::init<>());
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &>(), py::arg("point2d"), py::arg("ImposedValue"));
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &, const Standard_Integer>(), py::arg("point2d"), py::arg("ImposedValue"), py::arg("iu"));
cls_Plate_PinpointConstraint.def(py::init<const gp_XY &, const gp_XYZ &, const Standard_Integer, const Standard_Integer>(), py::arg("point2d"), py::arg("ImposedValue"), py::arg("iu"), py::arg("iv"));

// Fields

// Methods
// cls_Plate_PinpointConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_PinpointConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_PinpointConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_PinpointConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_PinpointConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_PinpointConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_PinpointConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_PinpointConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_PinpointConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_PinpointConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_PinpointConstraint.def("Pnt2d", (const gp_XY & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Pnt2d, "None");
cls_Plate_PinpointConstraint.def("Idu", (const Standard_Integer & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Idu, "None");
cls_Plate_PinpointConstraint.def("Idv", (const Standard_Integer & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Idv, "None");
cls_Plate_PinpointConstraint.def("Value", (const gp_XYZ & (Plate_PinpointConstraint::*)() const) &Plate_PinpointConstraint::Value, "None");

// Enums

}