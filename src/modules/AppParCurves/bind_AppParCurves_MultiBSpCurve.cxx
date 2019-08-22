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
#include <AppParCurves_MultiCurve.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <AppParCurves_Array1OfMultiPoint.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>

void bind_AppParCurves_MultiBSpCurve(py::module &mod){

py::class_<AppParCurves_MultiBSpCurve, AppParCurves_MultiCurve> cls_AppParCurves_MultiBSpCurve(mod, "AppParCurves_MultiBSpCurve", "This class describes a MultiBSpCurve approximating a Multiline. Just as a Multiline is a set of a given number of lines, a MultiBSpCurve is a set of a specified number of bsplines defined by: - A specified number of MultiPoints - the poles of a specified number of curves - The degree of approximation identical for each of the specified number of curves.");

// Constructors
cls_AppParCurves_MultiBSpCurve.def(py::init<>());
cls_AppParCurves_MultiBSpCurve.def(py::init<const Standard_Integer>(), py::arg("NbPol"));
cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_Array1OfMultiPoint &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("tabMU"), py::arg("Knots"), py::arg("Mults"));
cls_AppParCurves_MultiBSpCurve.def(py::init<const AppParCurves_MultiCurve &, const TColStd_Array1OfReal &, const TColStd_Array1OfInteger &>(), py::arg("SC"), py::arg("Knots"), py::arg("Mults"));

// Fields

// Methods
// cls_AppParCurves_MultiBSpCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_MultiBSpCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_MultiBSpCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_MultiBSpCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_MultiBSpCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_MultiBSpCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_MultiBSpCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_MultiBSpCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_MultiBSpCurve.def("SetKnots", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfReal &)) &AppParCurves_MultiBSpCurve::SetKnots, "Knots of the multiBSpCurve are assigned to <theknots>.", py::arg("theKnots"));
cls_AppParCurves_MultiBSpCurve.def("SetMultiplicities", (void (AppParCurves_MultiBSpCurve::*)(const TColStd_Array1OfInteger &)) &AppParCurves_MultiBSpCurve::SetMultiplicities, "Multiplicities of the multiBSpCurve are assigned to <theMults>.", py::arg("theMults"));
cls_AppParCurves_MultiBSpCurve.def("Knots", (const TColStd_Array1OfReal & (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Knots, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
cls_AppParCurves_MultiBSpCurve.def("Multiplicities", (const TColStd_Array1OfInteger & (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Multiplicities, "Returns an array of Reals containing the multiplicities of curves resulting from the approximation.");
cls_AppParCurves_MultiBSpCurve.def("Degree", (Standard_Integer (AppParCurves_MultiBSpCurve::*)() const) &AppParCurves_MultiBSpCurve::Degree, "returns the degree of the curve(s).");
cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &) const) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiBSpCurve.def("Value", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &) const) &AppParCurves_MultiBSpCurve::Value, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"));
cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &) const) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiBSpCurve.def("D1", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &AppParCurves_MultiBSpCurve::D1, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"));
cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 3d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiBSpCurve.def("D2", (void (AppParCurves_MultiBSpCurve::*)(const Standard_Integer, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &AppParCurves_MultiBSpCurve::D2, "returns the value of the point with a parameter U on the BSpline curve number CuIndex. An exception is raised if CuIndex <0 or > NbCurves. An exception is raised if the curve dimension is 2d.", py::arg("CuIndex"), py::arg("U"), py::arg("Pt"), py::arg("V1"), py::arg("V2"));
cls_AppParCurves_MultiBSpCurve.def("Dump", (void (AppParCurves_MultiBSpCurve::*)(Standard_OStream &) const) &AppParCurves_MultiBSpCurve::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}