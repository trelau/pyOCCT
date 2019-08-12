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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESGeom_BSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_BSplineSurface(py::module &mod){

py::class_<IGESGeom_BSplineSurface, opencascade::handle<IGESGeom_BSplineSurface>, IGESData_IGESEntity> cls_IGESGeom_BSplineSurface(mod, "IGESGeom_BSplineSurface", "defines IGESBSplineSurface, Type <128> Form <0-9> in package IGESGeom A parametric equation obtained by dividing two summations involving weights (which are real numbers), the control points, and B-Spline basis functions");

// Constructors
cls_IGESGeom_BSplineSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_BSplineSurface.def("Init", (void (IGESGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColgp_HArray2OfXYZ> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IGESGeom_BSplineSurface::Init, "This method is used to set the fields of the class BSplineSurface - anIndexU : Upper index of first sum - anIndexV : Upper index of second sum - aDegU, aDegV : Degrees of first and second sets of basis functions - aCloseU, aCloseV : 1 = Closed in U, V directions 0 = open in U, V directions - aPolynom : 0 = Rational, 1 = polynomial - aPeriodU, aPeriodV : 0 = Non periodic in U or V direction 1 = Periodic in U or V direction - allKnotsU, allKnotsV : Knots in U and V directions - allWeights : Array of weights - allPoles : XYZ coordinates of all control points - aUmin : Starting value of U direction - aUmax : Ending value of U direction - aVmin : Starting value of V direction - aVmax : Ending value of V direction raises exception if allWeights & allPoles are not of same size.", py::arg("anIndexU"), py::arg("anIndexV"), py::arg("aDegU"), py::arg("aDegV"), py::arg("aCloseU"), py::arg("aCloseV"), py::arg("aPolynom"), py::arg("aPeriodU"), py::arg("aPeriodV"), py::arg("allKnotsU"), py::arg("allKnotsV"), py::arg("allWeights"), py::arg("allPoles"), py::arg("aUmin"), py::arg("aUmax"), py::arg("aVmin"), py::arg("aVmax"));
cls_IGESGeom_BSplineSurface.def("SetFormNumber", (void (IGESGeom_BSplineSurface::*)(const Standard_Integer)) &IGESGeom_BSplineSurface::SetFormNumber, "Changes FormNumber (indicates the Shape of the Surface) Error if not in range [0-9]", py::arg("form"));
cls_IGESGeom_BSplineSurface.def("UpperIndexU", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::UpperIndexU, "returns the upper index of the first sum (U)");
cls_IGESGeom_BSplineSurface.def("UpperIndexV", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::UpperIndexV, "returns the upper index of the second sum (V)");
cls_IGESGeom_BSplineSurface.def("DegreeU", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::DegreeU, "returns degree of first set of basis functions");
cls_IGESGeom_BSplineSurface.def("DegreeV", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::DegreeV, "returns degree of second set of basis functions");
cls_IGESGeom_BSplineSurface.def("IsClosedU", (Standard_Boolean (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::IsClosedU, "True if closed in U direction else False");
cls_IGESGeom_BSplineSurface.def("IsClosedV", (Standard_Boolean (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::IsClosedV, "True if closed in V direction else False");
cls_IGESGeom_BSplineSurface.def("IsPolynomial", [](IGESGeom_BSplineSurface &self) -> Standard_Boolean { return self.IsPolynomial(); });
cls_IGESGeom_BSplineSurface.def("IsPolynomial", (Standard_Boolean (IGESGeom_BSplineSurface::*)(const Standard_Boolean) const) &IGESGeom_BSplineSurface::IsPolynomial, "True if polynomial, False if rational <flag> False (D) : computed from Weights <flag> True : recorded", py::arg("flag"));
cls_IGESGeom_BSplineSurface.def("IsPeriodicU", (Standard_Boolean (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::IsPeriodicU, "True if periodic in U direction else False");
cls_IGESGeom_BSplineSurface.def("IsPeriodicV", (Standard_Boolean (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::IsPeriodicV, "True if periodic in V direction else False");
cls_IGESGeom_BSplineSurface.def("NbKnotsU", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::NbKnotsU, "returns number of knots in U direction KnotsU are numbered from -DegreeU");
cls_IGESGeom_BSplineSurface.def("NbKnotsV", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::NbKnotsV, "returns number of knots in V direction KnotsV are numbered from -DegreeV");
cls_IGESGeom_BSplineSurface.def("KnotU", (Standard_Real (IGESGeom_BSplineSurface::*)(const Standard_Integer) const) &IGESGeom_BSplineSurface::KnotU, "returns the value of knot referred to by anIndex in U direction raises exception if anIndex < -DegreeU() or anIndex > (NbKnotsU() - DegreeU())", py::arg("anIndex"));
cls_IGESGeom_BSplineSurface.def("KnotV", (Standard_Real (IGESGeom_BSplineSurface::*)(const Standard_Integer) const) &IGESGeom_BSplineSurface::KnotV, "returns the value of knot referred to by anIndex in V direction raises exception if anIndex < -DegreeV() or anIndex > (NbKnotsV() - DegreeV())", py::arg("anIndex"));
cls_IGESGeom_BSplineSurface.def("NbPolesU", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::NbPolesU, "returns number of poles in U direction");
cls_IGESGeom_BSplineSurface.def("NbPolesV", (Standard_Integer (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::NbPolesV, "returns number of poles in V direction");
cls_IGESGeom_BSplineSurface.def("Weight", (Standard_Real (IGESGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_BSplineSurface::Weight, "returns the weight referred to by anIndex1, anIndex2 raises exception if anIndex1 <= 0 or anIndex1 > NbPolesU() or if anIndex2 <= 0 or anIndex2 > NbPolesV()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_BSplineSurface.def("Pole", (gp_Pnt (IGESGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_BSplineSurface::Pole, "returns the control point referenced by anIndex1, anIndex2 raises exception if anIndex1 <= 0 or anIndex1 > NbPolesU() or if anIndex2 <= 0 or anIndex2 > NbPolesV()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_BSplineSurface.def("TransformedPole", (gp_Pnt (IGESGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_BSplineSurface::TransformedPole, "returns the control point referenced by anIndex1, anIndex2 after applying the Transf.Matrix raises exception if anIndex1 <= 0 or anIndex1 > NbPolesU() or if anIndex2 <= 0 or anIndex2 > NbPolesV()", py::arg("anIndex1"), py::arg("anIndex2"));
cls_IGESGeom_BSplineSurface.def("UMin", (Standard_Real (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::UMin, "returns starting value in the U direction");
cls_IGESGeom_BSplineSurface.def("UMax", (Standard_Real (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::UMax, "returns ending value in the U direction");
cls_IGESGeom_BSplineSurface.def("VMin", (Standard_Real (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::VMin, "returns starting value in the V direction");
cls_IGESGeom_BSplineSurface.def("VMax", (Standard_Real (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::VMax, "returns ending value in the V direction");
cls_IGESGeom_BSplineSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_BSplineSurface::get_type_name, "None");
cls_IGESGeom_BSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_BSplineSurface::get_type_descriptor, "None");
cls_IGESGeom_BSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_BSplineSurface::*)() const) &IGESGeom_BSplineSurface::DynamicType, "None");

// Enums

}