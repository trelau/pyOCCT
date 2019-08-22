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
#include <gp_Pnt.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GCPnts_TangentialDeflection.hxx>

void bind_GCPnts_TangentialDeflection(py::module &mod){

py::class_<GCPnts_TangentialDeflection> cls_GCPnts_TangentialDeflection(mod, "GCPnts_TangentialDeflection", "Computes a set of points on a curve from package Adaptor3d such as between two successive points P1(u1)and P2(u2) :");

// Constructors
cls_GCPnts_TangentialDeflection.def(py::init<>());
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));

// Fields

// Methods
// cls_GCPnts_TangentialDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_TangentialDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_TangentialDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_TangentialDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_TangentialDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_TangentialDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_TangentialDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("AddPoint", [](GCPnts_TangentialDeflection &self, const gp_Pnt & a0, const Standard_Real a1) -> Standard_Integer { return self.AddPoint(a0, a1); });
cls_GCPnts_TangentialDeflection.def("AddPoint", (Standard_Integer (GCPnts_TangentialDeflection::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &GCPnts_TangentialDeflection::AddPoint, "Add point to already calculated points (or replace existing) Returns index of new added point or founded with parametric tolerance (replaced if theIsReplace is true)", py::arg("thePnt"), py::arg("theParam"), py::arg("theIsReplace"));
cls_GCPnts_TangentialDeflection.def("NbPoints", (Standard_Integer (GCPnts_TangentialDeflection::*)() const) &GCPnts_TangentialDeflection::NbPoints, "None");
cls_GCPnts_TangentialDeflection.def("Parameter", (Standard_Real (GCPnts_TangentialDeflection::*)(const Standard_Integer) const) &GCPnts_TangentialDeflection::Parameter, "None", py::arg("I"));
cls_GCPnts_TangentialDeflection.def("Value", (gp_Pnt (GCPnts_TangentialDeflection::*)(const Standard_Integer) const) &GCPnts_TangentialDeflection::Value, "None", py::arg("I"));
cls_GCPnts_TangentialDeflection.def_static("ArcAngularStep_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::ArcAngularStep, "Computes angular step for the arc using the given parameters.", py::arg("theRadius"), py::arg("theLinearDeflection"), py::arg("theAngularDeflection"), py::arg("theMinLength"));

// Enums

}