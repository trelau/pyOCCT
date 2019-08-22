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
#include <Plate_PinpointConstraint.hxx>
#include <gp_XYZ.hxx>
#include <Plate_Array1OfPinpointConstraint.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Plate_HArray1OfPinpointConstraint.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <Plate_LinearScalarConstraint.hxx>

void bind_Plate_LinearScalarConstraint(py::module &mod){

py::class_<Plate_LinearScalarConstraint> cls_Plate_LinearScalarConstraint(mod, "Plate_LinearScalarConstraint", "define on or several constraints as linear combination of the X,Y and Z components of a set of PinPointConstraint");

// Constructors
cls_Plate_LinearScalarConstraint.def(py::init<>());
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_PinpointConstraint &, const gp_XYZ &>(), py::arg("thePPC1"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColgp_Array1OfXYZ &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColgp_Array2OfXYZ &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearScalarConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("ColLen"), py::arg("RowLen"));

// Fields

// Methods
// cls_Plate_LinearScalarConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_LinearScalarConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_LinearScalarConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_LinearScalarConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_LinearScalarConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_LinearScalarConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_LinearScalarConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_LinearScalarConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_LinearScalarConstraint.def("GetPPC", (const Plate_Array1OfPinpointConstraint & (Plate_LinearScalarConstraint::*)() const) &Plate_LinearScalarConstraint::GetPPC, "None");
cls_Plate_LinearScalarConstraint.def("Coeff", (const TColgp_Array2OfXYZ & (Plate_LinearScalarConstraint::*)() const) &Plate_LinearScalarConstraint::Coeff, "None");
cls_Plate_LinearScalarConstraint.def("SetPPC", (void (Plate_LinearScalarConstraint::*)(const Standard_Integer, const Plate_PinpointConstraint &)) &Plate_LinearScalarConstraint::SetPPC, "Sets the PinPointConstraint of index Index to Value raise if Index is greater than the length of PPC or the Row length of coeff or lower than 1", py::arg("Index"), py::arg("Value"));
cls_Plate_LinearScalarConstraint.def("SetCoeff", (void (Plate_LinearScalarConstraint::*)(const Standard_Integer, const Standard_Integer, const gp_XYZ &)) &Plate_LinearScalarConstraint::SetCoeff, "Sets the coeff of index (Row,Col) to Value raise if Row (respectively Col) is greater than the Row (respectively Column) length of coeff", py::arg("Row"), py::arg("Col"), py::arg("Value"));

// Enums

}