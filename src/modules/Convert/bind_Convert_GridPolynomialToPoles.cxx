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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <Convert_GridPolynomialToPoles.hxx>

void bind_Convert_GridPolynomialToPoles(py::module &mod){

py::class_<Convert_GridPolynomialToPoles, std::unique_ptr<Convert_GridPolynomialToPoles, Deleter<Convert_GridPolynomialToPoles>>> cls_Convert_GridPolynomialToPoles(mod, "Convert_GridPolynomialToPoles", "Convert a grid of Polynomial Surfaces that are have continuity CM to an Bspline Surface that has continuity CM");

// Constructors
cls_Convert_GridPolynomialToPoles.def(py::init<const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("MaxUDegree"), py::arg("MaxVDegree"), py::arg("NumCoeff"), py::arg("Coefficients"), py::arg("PolynomialUIntervals"), py::arg("PolynomialVIntervals"));
cls_Convert_GridPolynomialToPoles.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray2OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &>(), py::arg("NbUSurfaces"), py::arg("NBVSurfaces"), py::arg("UContinuity"), py::arg("VContinuity"), py::arg("MaxUDegree"), py::arg("MaxVDegree"), py::arg("NumCoeffPerSurface"), py::arg("Coefficients"), py::arg("PolynomialUIntervals"), py::arg("PolynomialVIntervals"), py::arg("TrueUIntervals"), py::arg("TrueVIntervals"));

// Fields

// Methods
// cls_Convert_GridPolynomialToPoles.def_static("operator new_", (void * (*)(size_t)) &Convert_GridPolynomialToPoles::operator new, "None", py::arg("theSize"));
// cls_Convert_GridPolynomialToPoles.def_static("operator delete_", (void (*)(void *)) &Convert_GridPolynomialToPoles::operator delete, "None", py::arg("theAddress"));
// cls_Convert_GridPolynomialToPoles.def_static("operator new[]_", (void * (*)(size_t)) &Convert_GridPolynomialToPoles::operator new[], "None", py::arg("theSize"));
// cls_Convert_GridPolynomialToPoles.def_static("operator delete[]_", (void (*)(void *)) &Convert_GridPolynomialToPoles::operator delete[], "None", py::arg("theAddress"));
// cls_Convert_GridPolynomialToPoles.def_static("operator new_", (void * (*)(size_t, void *)) &Convert_GridPolynomialToPoles::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Convert_GridPolynomialToPoles.def_static("operator delete_", (void (*)(void *, void *)) &Convert_GridPolynomialToPoles::operator delete, "None", py::arg(""), py::arg(""));
cls_Convert_GridPolynomialToPoles.def("Perform", (void (Convert_GridPolynomialToPoles::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray2OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &Convert_GridPolynomialToPoles::Perform, "None", py::arg("UContinuity"), py::arg("VContinuity"), py::arg("MaxUDegree"), py::arg("MaxVDegree"), py::arg("NumCoeffPerSurface"), py::arg("Coefficients"), py::arg("PolynomialUIntervals"), py::arg("PolynomialVIntervals"), py::arg("TrueUIntervals"), py::arg("TrueVIntervals"));
cls_Convert_GridPolynomialToPoles.def("NbUPoles", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::NbUPoles, "None");
cls_Convert_GridPolynomialToPoles.def("NbVPoles", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::NbVPoles, "None");
cls_Convert_GridPolynomialToPoles.def("Poles", (const opencascade::handle<TColgp_HArray2OfPnt> & (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::Poles, "returns the poles of the BSpline Surface");
cls_Convert_GridPolynomialToPoles.def("UDegree", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::UDegree, "None");
cls_Convert_GridPolynomialToPoles.def("VDegree", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::VDegree, "None");
cls_Convert_GridPolynomialToPoles.def("NbUKnots", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::NbUKnots, "None");
cls_Convert_GridPolynomialToPoles.def("NbVKnots", (Standard_Integer (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::NbVKnots, "None");
cls_Convert_GridPolynomialToPoles.def("UKnots", (const opencascade::handle<TColStd_HArray1OfReal> & (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::UKnots, "Knots in the U direction");
cls_Convert_GridPolynomialToPoles.def("VKnots", (const opencascade::handle<TColStd_HArray1OfReal> & (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::VKnots, "Knots in the V direction");
cls_Convert_GridPolynomialToPoles.def("UMultiplicities", (const opencascade::handle<TColStd_HArray1OfInteger> & (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::UMultiplicities, "Multiplicities of the knots in the U direction");
cls_Convert_GridPolynomialToPoles.def("VMultiplicities", (const opencascade::handle<TColStd_HArray1OfInteger> & (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::VMultiplicities, "Multiplicities of the knots in the V direction");
cls_Convert_GridPolynomialToPoles.def("IsDone", (Standard_Boolean (Convert_GridPolynomialToPoles::*)() const) &Convert_GridPolynomialToPoles::IsDone, "None");

// Enums

}