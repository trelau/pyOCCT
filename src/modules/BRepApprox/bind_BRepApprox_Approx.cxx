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
#include <Standard_TypeDef.hxx>
#include <Approx_ParametrizationType.hxx>
#include <Standard.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <Standard_Handle.hxx>
#include <BRepApprox_ApproxLine.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <IntSurf_Quadric.hxx>
#include <BRepApprox_TheComputeLineOfApprox.hxx>
#include <BRepApprox_TheComputeLineBezierOfApprox.hxx>
#include <Approx_MCurvesToBSpCurve.hxx>
#include <BRepApprox_Approx.hxx>
#include <NCollection_Vector.hxx>

void bind_BRepApprox_Approx(py::module &mod){

py::class_<BRepApprox_Approx> cls_BRepApprox_Approx(mod, "BRepApprox_Approx", "None");

// Constructors
cls_BRepApprox_Approx.def(py::init<>());

// Fields

// Methods
// cls_BRepApprox_Approx.def_static("operator new_", (void * (*)(size_t)) &BRepApprox_Approx::operator new, "None", py::arg("theSize"));
// cls_BRepApprox_Approx.def_static("operator delete_", (void (*)(void *)) &BRepApprox_Approx::operator delete, "None", py::arg("theAddress"));
// cls_BRepApprox_Approx.def_static("operator new[]_", (void * (*)(size_t)) &BRepApprox_Approx::operator new[], "None", py::arg("theSize"));
// cls_BRepApprox_Approx.def_static("operator delete[]_", (void (*)(void *)) &BRepApprox_Approx::operator delete[], "None", py::arg("theAddress"));
// cls_BRepApprox_Approx.def_static("operator new_", (void * (*)(size_t, void *)) &BRepApprox_Approx::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepApprox_Approx.def_static("operator delete_", (void (*)(void *, void *)) &BRepApprox_Approx::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const BRepAdaptor_Surface & a0, const BRepAdaptor_Surface & a1, const opencascade::handle<BRepApprox_ApproxLine> & a2) -> void { return self.Perform(a0, a1, a2); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const BRepAdaptor_Surface & a0, const BRepAdaptor_Surface & a1, const opencascade::handle<BRepApprox_ApproxLine> & a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const BRepAdaptor_Surface & a0, const BRepAdaptor_Surface & a1, const opencascade::handle<BRepApprox_ApproxLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const BRepAdaptor_Surface & a0, const BRepAdaptor_Surface & a1, const opencascade::handle<BRepApprox_ApproxLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const BRepAdaptor_Surface & a0, const BRepAdaptor_Surface & a1, const opencascade::handle<BRepApprox_ApproxLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5, const Standard_Integer a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepApprox_Approx.def("Perform", (void (BRepApprox_Approx::*)(const BRepAdaptor_Surface &, const BRepAdaptor_Surface &, const opencascade::handle<BRepApprox_ApproxLine> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &BRepApprox_Approx::Perform, "None", py::arg("Surf1"), py::arg("Surf2"), py::arg("aLine"), py::arg("ApproxXYZ"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("indicemin"), py::arg("indicemax"));
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const opencascade::handle<BRepApprox_ApproxLine> & a0) -> void { return self.Perform(a0); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const opencascade::handle<BRepApprox_ApproxLine> & a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const opencascade::handle<BRepApprox_ApproxLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Perform(a0, a1, a2); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const opencascade::handle<BRepApprox_ApproxLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_BRepApprox_Approx.def("Perform", [](BRepApprox_Approx &self, const opencascade::handle<BRepApprox_ApproxLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Integer a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_BRepApprox_Approx.def("Perform", (void (BRepApprox_Approx::*)(const opencascade::handle<BRepApprox_ApproxLine> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &BRepApprox_Approx::Perform, "None", py::arg("aLine"), py::arg("ApproxXYZ"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("indicemin"), py::arg("indicemax"));
cls_BRepApprox_Approx.def("SetParameters", [](BRepApprox_Approx &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4) -> void { return self.SetParameters(a0, a1, a2, a3, a4); });
cls_BRepApprox_Approx.def("SetParameters", [](BRepApprox_Approx &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> void { return self.SetParameters(a0, a1, a2, a3, a4, a5); });
cls_BRepApprox_Approx.def("SetParameters", [](BRepApprox_Approx &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Boolean a6) -> void { return self.SetParameters(a0, a1, a2, a3, a4, a5, a6); });
cls_BRepApprox_Approx.def("SetParameters", (void (BRepApprox_Approx::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType)) &BRepApprox_Approx::SetParameters, "None", py::arg("Tol3d"), py::arg("Tol2d"), py::arg("DegMin"), py::arg("DegMax"), py::arg("NbIterMax"), py::arg("NbPntMax"), py::arg("ApproxWithTangency"), py::arg("Parametrization"));
// cls_BRepApprox_Approx.def("Perform", (void (BRepApprox_Approx::*)()) &BRepApprox_Approx::Perform, "None");
cls_BRepApprox_Approx.def("TolReached3d", (Standard_Real (BRepApprox_Approx::*)() const) &BRepApprox_Approx::TolReached3d, "None");
cls_BRepApprox_Approx.def("TolReached2d", (Standard_Real (BRepApprox_Approx::*)() const) &BRepApprox_Approx::TolReached2d, "None");
cls_BRepApprox_Approx.def("IsDone", (Standard_Boolean (BRepApprox_Approx::*)() const) &BRepApprox_Approx::IsDone, "None");
cls_BRepApprox_Approx.def("NbMultiCurves", (Standard_Integer (BRepApprox_Approx::*)() const) &BRepApprox_Approx::NbMultiCurves, "None");
cls_BRepApprox_Approx.def("Value", (const AppParCurves_MultiBSpCurve & (BRepApprox_Approx::*)(const Standard_Integer) const) &BRepApprox_Approx::Value, "None", py::arg("Index"));

// Enums

}