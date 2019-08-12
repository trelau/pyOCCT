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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPatch_WLine.hxx>
#include <AppParCurves_MultiBSpCurve.hxx>
#include <IntSurf_Quadric.hxx>
#include <GeomInt_TheComputeLineOfWLApprox.hxx>
#include <GeomInt_TheComputeLineBezierOfWLApprox.hxx>
#include <Approx_MCurvesToBSpCurve.hxx>
#include <GeomInt_WLApprox.hxx>
#include <NCollection_Vector.hxx>

void bind_GeomInt_WLApprox(py::module &mod){

py::class_<GeomInt_WLApprox, std::unique_ptr<GeomInt_WLApprox, Deleter<GeomInt_WLApprox>>> cls_GeomInt_WLApprox(mod, "GeomInt_WLApprox", "None");

// Constructors
cls_GeomInt_WLApprox.def(py::init<>());

// Fields

// Methods
// cls_GeomInt_WLApprox.def_static("operator new_", (void * (*)(size_t)) &GeomInt_WLApprox::operator new, "None", py::arg("theSize"));
// cls_GeomInt_WLApprox.def_static("operator delete_", (void (*)(void *)) &GeomInt_WLApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_WLApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_WLApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_WLApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_WLApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_WLApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_WLApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_WLApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_WLApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const opencascade::handle<IntPatch_WLine> & a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const opencascade::handle<IntPatch_WLine> & a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const opencascade::handle<IntPatch_WLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const opencascade::handle<IntPatch_WLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_HSurface> & a1, const opencascade::handle<IntPatch_WLine> & a2, const Standard_Boolean a3, const Standard_Boolean a4, const Standard_Boolean a5, const Standard_Integer a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_WLApprox.def("Perform", (void (GeomInt_WLApprox::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<IntPatch_WLine> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &GeomInt_WLApprox::Perform, "None", py::arg("Surf1"), py::arg("Surf2"), py::arg("aLine"), py::arg("ApproxXYZ"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("indicemin"), py::arg("indicemax"));
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<IntPatch_WLine> & a0) -> void { return self.Perform(a0); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<IntPatch_WLine> & a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<IntPatch_WLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<IntPatch_WLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomInt_WLApprox.def("Perform", [](GeomInt_WLApprox &self, const opencascade::handle<IntPatch_WLine> & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3, const Standard_Integer a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_GeomInt_WLApprox.def("Perform", (void (GeomInt_WLApprox::*)(const opencascade::handle<IntPatch_WLine> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &GeomInt_WLApprox::Perform, "None", py::arg("aLine"), py::arg("ApproxXYZ"), py::arg("ApproxU1V1"), py::arg("ApproxU2V2"), py::arg("indicemin"), py::arg("indicemax"));
cls_GeomInt_WLApprox.def("SetParameters", [](GeomInt_WLApprox &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4) -> void { return self.SetParameters(a0, a1, a2, a3, a4); });
cls_GeomInt_WLApprox.def("SetParameters", [](GeomInt_WLApprox &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> void { return self.SetParameters(a0, a1, a2, a3, a4, a5); });
cls_GeomInt_WLApprox.def("SetParameters", [](GeomInt_WLApprox &self, const Standard_Real a0, const Standard_Real a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Boolean a6) -> void { return self.SetParameters(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_WLApprox.def("SetParameters", (void (GeomInt_WLApprox::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Approx_ParametrizationType)) &GeomInt_WLApprox::SetParameters, "None", py::arg("Tol3d"), py::arg("Tol2d"), py::arg("DegMin"), py::arg("DegMax"), py::arg("NbIterMax"), py::arg("NbPntMax"), py::arg("ApproxWithTangency"), py::arg("Parametrization"));
// cls_GeomInt_WLApprox.def("Perform", (void (GeomInt_WLApprox::*)()) &GeomInt_WLApprox::Perform, "None");
cls_GeomInt_WLApprox.def("TolReached3d", (Standard_Real (GeomInt_WLApprox::*)() const) &GeomInt_WLApprox::TolReached3d, "None");
cls_GeomInt_WLApprox.def("TolReached2d", (Standard_Real (GeomInt_WLApprox::*)() const) &GeomInt_WLApprox::TolReached2d, "None");
cls_GeomInt_WLApprox.def("IsDone", (Standard_Boolean (GeomInt_WLApprox::*)() const) &GeomInt_WLApprox::IsDone, "None");
cls_GeomInt_WLApprox.def("NbMultiCurves", (Standard_Integer (GeomInt_WLApprox::*)() const) &GeomInt_WLApprox::NbMultiCurves, "None");
cls_GeomInt_WLApprox.def("Value", (const AppParCurves_MultiBSpCurve & (GeomInt_WLApprox::*)(const Standard_Integer) const) &GeomInt_WLApprox::Value, "None", py::arg("Index"));

// Enums

}