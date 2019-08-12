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
#include <Plate_Array1OfPinpointConstraint.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <Plate_PinpointConstraint.hxx>
#include <Standard_Handle.hxx>
#include <Plate_HArray1OfPinpointConstraint.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Plate_LinearXYZConstraint.hxx>

void bind_Plate_LinearXYZConstraint(py::module &mod){

py::class_<Plate_LinearXYZConstraint, std::unique_ptr<Plate_LinearXYZConstraint, Deleter<Plate_LinearXYZConstraint>>> cls_Plate_LinearXYZConstraint(mod, "Plate_LinearXYZConstraint", "define on or several constraints as linear combination of PinPointConstraint unlike the LinearScalarConstraint, usage of this kind of constraint preserve the X,Y and Z uncoupling.");

// Constructors
cls_Plate_LinearXYZConstraint.def(py::init<>());
cls_Plate_LinearXYZConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColStd_Array1OfReal &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearXYZConstraint.def(py::init<const Plate_Array1OfPinpointConstraint &, const TColStd_Array2OfReal &>(), py::arg("thePPC"), py::arg("theCoeff"));
cls_Plate_LinearXYZConstraint.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("ColLen"), py::arg("RowLen"));

// Fields

// Methods
// cls_Plate_LinearXYZConstraint.def_static("operator new_", (void * (*)(size_t)) &Plate_LinearXYZConstraint::operator new, "None", py::arg("theSize"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete_", (void (*)(void *)) &Plate_LinearXYZConstraint::operator delete, "None", py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator new[]_", (void * (*)(size_t)) &Plate_LinearXYZConstraint::operator new[], "None", py::arg("theSize"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete[]_", (void (*)(void *)) &Plate_LinearXYZConstraint::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_LinearXYZConstraint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_LinearXYZConstraint.def_static("operator delete_", (void (*)(void *, void *)) &Plate_LinearXYZConstraint::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_LinearXYZConstraint.def("GetPPC", (const Plate_Array1OfPinpointConstraint & (Plate_LinearXYZConstraint::*)() const) &Plate_LinearXYZConstraint::GetPPC, "None");
cls_Plate_LinearXYZConstraint.def("Coeff", (const TColStd_Array2OfReal & (Plate_LinearXYZConstraint::*)() const) &Plate_LinearXYZConstraint::Coeff, "None");
cls_Plate_LinearXYZConstraint.def("SetPPC", (void (Plate_LinearXYZConstraint::*)(const Standard_Integer, const Plate_PinpointConstraint &)) &Plate_LinearXYZConstraint::SetPPC, "Sets the PinPointConstraint of index Index to Value raise if Index is greater than the length of PPC or the Row length of coeff or lower than 1", py::arg("Index"), py::arg("Value"));
cls_Plate_LinearXYZConstraint.def("SetCoeff", (void (Plate_LinearXYZConstraint::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &Plate_LinearXYZConstraint::SetCoeff, "Sets the coeff of index (Row,Col) to Value raise if Row (respectively Col) is greater than the Row (respectively Column) length of coeff", py::arg("Row"), py::arg("Col"), py::arg("Value"));

// Enums

}