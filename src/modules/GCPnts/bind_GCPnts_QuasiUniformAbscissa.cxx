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
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <StdFail_NotDone.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <GCPnts_QuasiUniformAbscissa.hxx>

void bind_GCPnts_QuasiUniformAbscissa(py::module &mod){

py::class_<GCPnts_QuasiUniformAbscissa> cls_GCPnts_QuasiUniformAbscissa(mod, "GCPnts_QuasiUniformAbscissa", "This class provides an algorithm to compute a uniform abscissa distribution of points on a curve, i.e. a sequence of equidistant points. The distance between two consecutive points is measured along the curve. The distribution is defined: - either by the curvilinear distance between two consecutive points - or by a number of points.");

// Constructors
cls_GCPnts_QuasiUniformAbscissa.def(py::init<>());
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));

// Fields

// Methods
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new_", (void * (*)(size_t)) &GCPnts_QuasiUniformAbscissa::operator new, "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete_", (void (*)(void *)) &GCPnts_QuasiUniformAbscissa::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_QuasiUniformAbscissa::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_QuasiUniformAbscissa::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_QuasiUniformAbscissa::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_QuasiUniformAbscissa::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints> and", py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints> and", py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def("IsDone", (Standard_Boolean (GCPnts_QuasiUniformAbscissa::*)() const) &GCPnts_QuasiUniformAbscissa::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_QuasiUniformAbscissa.def("NbPoints", (Standard_Integer (GCPnts_QuasiUniformAbscissa::*)() const) &GCPnts_QuasiUniformAbscissa::NbPoints, "Returns the number of points of the distribution computed by this algorithm. This value is either: - the one imposed on the algorithm at the time of construction (or initialization), or - the one computed by the algorithm when the curvilinear distance between two consecutive points of the distribution is imposed on the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_QuasiUniformAbscissa.def("Parameter", (Standard_Real (GCPnts_QuasiUniformAbscissa::*)(const Standard_Integer) const) &GCPnts_QuasiUniformAbscissa::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));

// Enums

}