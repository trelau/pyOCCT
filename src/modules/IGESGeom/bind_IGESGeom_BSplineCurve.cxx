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
#include <TColgp_HArray1OfXYZ.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESGeom_BSplineCurve.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_BSplineCurve(py::module &mod){

py::class_<IGESGeom_BSplineCurve, opencascade::handle<IGESGeom_BSplineCurve>, IGESData_IGESEntity> cls_IGESGeom_BSplineCurve(mod, "IGESGeom_BSplineCurve", "defines IGESBSplineCurve, Type <126> Form <0-5> in package IGESGeom A parametric equation obtained by dividing two summations involving weights (which are real numbers), the control points, and B-Spline basis functions");

// Constructors
cls_IGESGeom_BSplineCurve.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_BSplineCurve.def("Init", (void (IGESGeom_BSplineCurve::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColgp_HArray1OfXYZ> &, const Standard_Real, const Standard_Real, const gp_XYZ &)) &IGESGeom_BSplineCurve::Init, "This method is used to set the fields of the class BSplineCurve. Beware about indexation of arrays - anIndex : Upper index of the sum - aDegree : Degree of basis functions - aPlanar : 0 = nonplanar curve, 1 = planar curve - aClosed : 0 = open curve, 1 = closed curve - aPolynom : 0 = rational, 1 = polynomial - aPeriodic : 0 = nonperiodic, 1 = periodic - allKnots : Knot sequence values [-Degree,Index+1] - allWeights : Array of weights [0,Index] - allPoles : X, Y, Z coordinates of all control points [0,Index] - aUmin, aUmax : Starting and ending parameter values - aNorm : Unit normal (if the curve is planar) raises exception if allWeights & allPoles are not of same size.", py::arg("anIndex"), py::arg("aDegree"), py::arg("aPlanar"), py::arg("aClosed"), py::arg("aPolynom"), py::arg("aPeriodic"), py::arg("allKnots"), py::arg("allWeights"), py::arg("allPoles"), py::arg("aUmin"), py::arg("aUmax"), py::arg("aNorm"));
cls_IGESGeom_BSplineCurve.def("SetFormNumber", (void (IGESGeom_BSplineCurve::*)(const Standard_Integer)) &IGESGeom_BSplineCurve::SetFormNumber, "Changes FormNumber (indicates the Shape of the Curve) Error if not in range [0-5]", py::arg("form"));
cls_IGESGeom_BSplineCurve.def("UpperIndex", (Standard_Integer (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::UpperIndex, "returns the upper index of the sum (see Knots,Poles)");
cls_IGESGeom_BSplineCurve.def("Degree", (Standard_Integer (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::Degree, "returns the degree of basis functions");
cls_IGESGeom_BSplineCurve.def("IsPlanar", (Standard_Boolean (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::IsPlanar, "returns True if the curve is Planar, False if non-planar");
cls_IGESGeom_BSplineCurve.def("IsClosed", (Standard_Boolean (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::IsClosed, "returns True if the curve is closed, False if open");
cls_IGESGeom_BSplineCurve.def("IsPolynomial", [](IGESGeom_BSplineCurve &self) -> Standard_Boolean { return self.IsPolynomial(); });
cls_IGESGeom_BSplineCurve.def("IsPolynomial", (Standard_Boolean (IGESGeom_BSplineCurve::*)(const Standard_Boolean) const) &IGESGeom_BSplineCurve::IsPolynomial, "returns True if the curve is polynomial, False if rational <flag> False (D) : computed from the list of weights (all must be equal) <flag> True : as recorded", py::arg("flag"));
cls_IGESGeom_BSplineCurve.def("IsPeriodic", (Standard_Boolean (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::IsPeriodic, "returns True if the curve is periodic, False otherwise");
cls_IGESGeom_BSplineCurve.def("NbKnots", (Standard_Integer (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::NbKnots, "returns the number of knots (i.e. Degree + UpperIndex + 2)");
cls_IGESGeom_BSplineCurve.def("Knot", (Standard_Real (IGESGeom_BSplineCurve::*)(const Standard_Integer) const) &IGESGeom_BSplineCurve::Knot, "returns the knot referred to by anIndex, inside the range [-Degree,UpperIndex+1] raises exception if anIndex < -Degree() or anIndex > (NbKnots() - Degree()) Note : Knots are numbered from -Degree (not from 1)", py::arg("anIndex"));
cls_IGESGeom_BSplineCurve.def("NbPoles", (Standard_Integer (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::NbPoles, "returns number of poles (i.e. UpperIndex + 1)");
cls_IGESGeom_BSplineCurve.def("Weight", (Standard_Real (IGESGeom_BSplineCurve::*)(const Standard_Integer) const) &IGESGeom_BSplineCurve::Weight, "returns the weight referred to by anIndex, in [0,UpperIndex] raises exception if anIndex < 0 or anIndex > UpperIndex()", py::arg("anIndex"));
cls_IGESGeom_BSplineCurve.def("Pole", (gp_Pnt (IGESGeom_BSplineCurve::*)(const Standard_Integer) const) &IGESGeom_BSplineCurve::Pole, "returns the pole referred to by anIndex, in [0,UpperIndex] raises exception if anIndex < 0 or anIndex > UpperIndex()", py::arg("anIndex"));
cls_IGESGeom_BSplineCurve.def("TransformedPole", (gp_Pnt (IGESGeom_BSplineCurve::*)(const Standard_Integer) const) &IGESGeom_BSplineCurve::TransformedPole, "returns the anIndex'th pole after applying Transf. Matrix raises exception if an Index < 0 or an Index > UpperIndex()", py::arg("anIndex"));
cls_IGESGeom_BSplineCurve.def("UMin", (Standard_Real (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::UMin, "returns starting parameter value");
cls_IGESGeom_BSplineCurve.def("UMax", (Standard_Real (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::UMax, "returns ending parameter value");
cls_IGESGeom_BSplineCurve.def("Normal", (gp_XYZ (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::Normal, "if the curve is nonplanar then (0, 0, 0) is returned");
cls_IGESGeom_BSplineCurve.def_static("get_type_name_", (const char * (*)()) &IGESGeom_BSplineCurve::get_type_name, "None");
cls_IGESGeom_BSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_BSplineCurve::get_type_descriptor, "None");
cls_IGESGeom_BSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_BSplineCurve::*)() const) &IGESGeom_BSplineCurve::DynamicType, "None");

// Enums

}