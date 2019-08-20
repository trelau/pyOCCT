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
#include <GCPnts_UniformAbscissa.hxx>

void bind_GCPnts_UniformAbscissa(py::module &mod){

py::class_<GCPnts_UniformAbscissa, std::unique_ptr<GCPnts_UniformAbscissa>> cls_GCPnts_UniformAbscissa(mod, "GCPnts_UniformAbscissa", "This class allows to compute a uniform distribution of points on a curve (ie the points will all be equally distant).");

// Constructors
cls_GCPnts_UniformAbscissa.def(py::init<>());
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));

// Fields

// Methods
// cls_GCPnts_UniformAbscissa.def_static("operator new_", (void * (*)(size_t)) &GCPnts_UniformAbscissa::operator new, "None", py::arg("theSize"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete_", (void (*)(void *)) &GCPnts_UniformAbscissa::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_UniformAbscissa::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_UniformAbscissa::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_UniformAbscissa::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_UniformAbscissa::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Integer a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints>, <Toler> and", py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Integer a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints>, <Toler> and", py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("IsDone", (Standard_Boolean (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::IsDone, "None");
cls_GCPnts_UniformAbscissa.def("NbPoints", (Standard_Integer (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::NbPoints, "None");
cls_GCPnts_UniformAbscissa.def("Parameter", (Standard_Real (GCPnts_UniformAbscissa::*)(const Standard_Integer) const) &GCPnts_UniformAbscissa::Parameter, "returns the computed Parameter of index <Index>.", py::arg("Index"));
cls_GCPnts_UniformAbscissa.def("Abscissa", (Standard_Real (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::Abscissa, "returne the current abscissa ie the distance between two consecutive points");

// Enums

}