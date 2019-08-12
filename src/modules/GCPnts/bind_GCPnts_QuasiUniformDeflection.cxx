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
#include <GeomAbs_Shape.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <StdFail_NotDone.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <GCPnts_QuasiUniformDeflection.hxx>

void bind_GCPnts_QuasiUniformDeflection(py::module &mod){

py::class_<GCPnts_QuasiUniformDeflection, std::unique_ptr<GCPnts_QuasiUniformDeflection, Deleter<GCPnts_QuasiUniformDeflection>>> cls_GCPnts_QuasiUniformDeflection(mod, "GCPnts_QuasiUniformDeflection", "This class computes a distribution of points on a curve. The points may respect the deflection. The algorithm is not based on the classical prediction (with second derivative of curve), but either on the evaluation of the distance between the mid point and the point of mid parameter of the two points, or the distance between the mid point and the point at parameter 0.5 on the cubic interpolation of the two points and their tangents. Note: this algorithm is faster than a GCPnts_UniformDeflection algorithm, and is able to work with non-'C2' continuous curves. However, it generates more points in the distribution.");

// Constructors
cls_GCPnts_QuasiUniformDeflection.def(py::init<>());
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));

// Fields

// Methods
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_QuasiUniformDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_QuasiUniformDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_QuasiUniformDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_QuasiUniformDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_QuasiUniformDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_QuasiUniformDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, -- <U1>,<U2> This and the above algorithms initialize (or reinitialize) this algorithm and compute a distribution of points: - on the curve C, or - on the part of curve C limited by the two parameter values U1 and U2, where the deflection resulting from the distributed points is not greater than Deflection. The first point of the distribution is either the origin of curve C or the point of parameter U1. The last point of the distribution is either the end point of curve C or the point of parameter U2. Intermediate points of the distribution are built in such a way that the deflection is not greater than Deflection. Using the following evaluation of the deflection: if Pi and Pj are two consecutive points of the distribution, respectively of parameter ui and uj on the curve, the deflection is the distance between: - the mid-point of Pi and Pj (the center of the chord joining these two points) - and the point of mid-parameter of these two points (the point of parameter [(ui+uj) / 2 ] on curve C). Continuity, defaulted to GeomAbs_C1, gives the degree of continuity of the curve C. (Note that C is an Adaptor3d_Curve or an Adaptor2d_Curve2d object, and does not know the degree of continuity of the underlying curve). Use the function IsDone to verify that the computation was successful, the function NbPoints to obtain the number of points of the computed distribution, and the function Parameter to read the parameter of each point. Warning - The roles of U1 and U2 are inverted if U1 > U2. - Derivative functions on the curve are called according to Continuity. An error may occur if Continuity is greater than the real degree of continuity of the curve. Warning C is an adapted curve, i.e. an object which is an interface between: - the services provided by either a 2D curve from the package Geom2d (in the case of an Adaptor2d_Curve2d curve) or a 3D curve from the package Geom (in the case of an Adaptor3d_Curve curve), and those required on the curve by the computation algorithm.", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("IsDone", (Standard_Boolean (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_QuasiUniformDeflection.def("NbPoints", (Standard_Integer (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::NbPoints, "Returns the number of points of the distribution computed by this algorithm. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_QuasiUniformDeflection.def("Parameter", (Standard_Real (GCPnts_QuasiUniformDeflection::*)(const Standard_Integer) const) &GCPnts_QuasiUniformDeflection::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_QuasiUniformDeflection.def("Value", (gp_Pnt (GCPnts_QuasiUniformDeflection::*)(const Standard_Integer) const) &GCPnts_QuasiUniformDeflection::Value, "Returns the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_QuasiUniformDeflection.def("Deflection", (Standard_Real (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::Deflection, "Returns the deflection between the curve and the polygon resulting from the points of the distribution computed by this algorithm. This is the value given to the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");

// Enums

}