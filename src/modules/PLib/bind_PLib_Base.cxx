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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <PLib_Base.hxx>
#include <Standard_Type.hxx>

void bind_PLib_Base(py::module &mod){

py::class_<PLib_Base, opencascade::handle<PLib_Base>, Standard_Transient> cls_PLib_Base(mod, "PLib_Base", "To work with different polynomial's Bases");

// Fields

// Methods
cls_PLib_Base.def("ToCoefficients", (void (PLib_Base::*)(const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &PLib_Base::ToCoefficients, "Convert the polynomial P(t) in the canonical base.", py::arg("Dimension"), py::arg("Degree"), py::arg("CoeffinBase"), py::arg("Coefficients"));
cls_PLib_Base.def("D0", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &)) &PLib_Base::D0, "Compute the values of the basis functions in u", py::arg("U"), py::arg("BasisValue"));
cls_PLib_Base.def("D1", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D1, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"));
cls_PLib_Base.def("D2", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D2, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"));
cls_PLib_Base.def("D3", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D3, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"), py::arg("BasisD3"));
cls_PLib_Base.def("WorkDegree", (Standard_Integer (PLib_Base::*)() const) &PLib_Base::WorkDegree, "returns WorkDegree");
cls_PLib_Base.def("ReduceDegree", [](PLib_Base &self, const Standard_Integer Dimension, const Standard_Integer MaxDegree, const Standard_Real Tol, Standard_Real & BaseCoeff, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(Dimension, MaxDegree, Tol, BaseCoeff, NewDegree, MaxError); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Real &>(BaseCoeff, NewDegree, MaxError); }, "Compute NewDegree <= MaxDegree so that MaxError is lower than Tol. MaxError can be greater than Tol if it is not possible to find a NewDegree <= MaxDegree. In this case NewDegree = MaxDegree", py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Tol"), py::arg("BaseCoeff"), py::arg("NewDegree"), py::arg("MaxError"));
cls_PLib_Base.def_static("get_type_name_", (const char * (*)()) &PLib_Base::get_type_name, "None");
cls_PLib_Base.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PLib_Base::get_type_descriptor, "None");
cls_PLib_Base.def("DynamicType", (const opencascade::handle<Standard_Type> & (PLib_Base::*)() const) &PLib_Base::DynamicType, "None");

// Enums

}