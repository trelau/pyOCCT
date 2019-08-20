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
#include <gp_Pnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <GCPnts_UniformDeflection.hxx>

void bind_GCPnts_UniformDeflection(py::module &mod){

py::class_<GCPnts_UniformDeflection, std::unique_ptr<GCPnts_UniformDeflection>> cls_GCPnts_UniformDeflection(mod, "GCPnts_UniformDeflection", "Provides an algorithm to compute a distribution of points on a 'C2' continuous curve. The algorithm respects a criterion of maximum deflection between the curve and the polygon that results from the computed points. Note: This algorithm is relatively time consuming. A GCPnts_QuasiUniformDeflection algorithm is quicker; it can also work with non-'C2' continuous curves, but it generates more points in the distribution.");

// Constructors
cls_GCPnts_UniformDeflection.def(py::init<>());
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));

// Fields

// Methods
// cls_GCPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_UniformDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_UniformDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_UniformDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_UniformDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_UniformDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_UniformDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_UniformDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2> This and the above methods initialize (or reinitialize) this algorithm and compute a distribution of points: - on the curve C, or - on the part of curve C limited by the two parameter values U1 and U2, where the maximum distance between C and the polygon that results from the points of the distribution is not greater than Deflection. The first point of the distribution is either the origin of curve C or the point of parameter U1. The last point of the distribution is either the end point of curve C or the point of parameter U2. Intermediate points of the distribution are built using interpolations of segments of the curve limited at the 2nd degree. The construction ensures, in a first step, that the chordal deviation for this interpolation of the curve is less than or equal to Deflection. However, it does not ensure that the chordal deviation for the curve itself is less than or equal to Deflection. To do this a check is necessary, which may generate (second step) additional intermediate points. This check is time consuming, and can be avoided by setting WithControl to false. Note that by default WithControl is true and check is performed. Use the function IsDone to verify that the computation was successful, the function NbPoints to obtain the number of points of the computed distribution, and the function Parameter to read the parameter of each point. Warning - C is necessary, 'C2' continuous. This property is not checked at construction time. - The roles of U1 and U2 are inverted if U1 > U2. Warning C is an adapted curve, i.e. an object which is an interface between: - the services provided by either a 2D curve from the package Geom2d (in the case of an Adaptor2d_Curve2d curve) or a 3D curve from the package Geom (in the case of an Adaptor3d_Curve curve), - and those required on the curve by the computation algorithm.", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("IsDone", (Standard_Boolean (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_UniformDeflection.def("NbPoints", (Standard_Integer (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::NbPoints, "Returns the number of points of the distribution computed by this algorithm. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_UniformDeflection.def("Parameter", (Standard_Real (GCPnts_UniformDeflection::*)(const Standard_Integer) const) &GCPnts_UniformDeflection::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_UniformDeflection.def("Value", (gp_Pnt (GCPnts_UniformDeflection::*)(const Standard_Integer) const) &GCPnts_UniformDeflection::Value, "Returns the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFAil_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_UniformDeflection.def("Deflection", (Standard_Real (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::Deflection, "Returns the deflection between the curve and the polygon resulting from the points of the distribution computed by this algorithm. This value is the one given to the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");

// Enums

}