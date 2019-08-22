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
#include <Plate_Plate.hxx>
#include <Plate_PinpointConstraint.hxx>
#include <Plate_LinearXYZConstraint.hxx>
#include <Plate_LinearScalarConstraint.hxx>
#include <Plate_GlobalTranslationConstraint.hxx>
#include <Plate_LineConstraint.hxx>
#include <Plate_PlaneConstraint.hxx>
#include <Plate_SampledCurveConstraint.hxx>
#include <Plate_GtoCConstraint.hxx>
#include <Plate_FreeGtoCConstraint.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <math_Matrix.hxx>
#include <Plate_SequenceOfPinpointConstraint.hxx>
#include <Plate_SequenceOfLinearXYZConstraint.hxx>
#include <Plate_SequenceOfLinearScalarConstraint.hxx>

void bind_Plate_Plate(py::module &mod){

py::class_<Plate_Plate> cls_Plate_Plate(mod, "Plate_Plate", "This class implement a variationnal spline algorithm able to define a two variable function satisfying some constraints and minimizing an energy like criterion.");

// Constructors
cls_Plate_Plate.def(py::init<>());
cls_Plate_Plate.def(py::init<const Plate_Plate &>(), py::arg("Ref"));

// Fields

// Methods
// cls_Plate_Plate.def_static("operator new_", (void * (*)(size_t)) &Plate_Plate::operator new, "None", py::arg("theSize"));
// cls_Plate_Plate.def_static("operator delete_", (void (*)(void *)) &Plate_Plate::operator delete, "None", py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator new[]_", (void * (*)(size_t)) &Plate_Plate::operator new[], "None", py::arg("theSize"));
// cls_Plate_Plate.def_static("operator delete[]_", (void (*)(void *)) &Plate_Plate::operator delete[], "None", py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator new_", (void * (*)(size_t, void *)) &Plate_Plate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Plate_Plate.def_static("operator delete_", (void (*)(void *, void *)) &Plate_Plate::operator delete, "None", py::arg(""), py::arg(""));
cls_Plate_Plate.def("Copy", (Plate_Plate & (Plate_Plate::*)(const Plate_Plate &)) &Plate_Plate::Copy, "None", py::arg("Ref"));
// cls_Plate_Plate.def("operator=", (Plate_Plate & (Plate_Plate::*)(const Plate_Plate &)) &Plate_Plate::operator=, "None", py::arg("Ref"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_PinpointConstraint &)) &Plate_Plate::Load, "None", py::arg("PConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LinearXYZConstraint &)) &Plate_Plate::Load, "None", py::arg("LXYZConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LinearScalarConstraint &)) &Plate_Plate::Load, "None", py::arg("LScalarConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_GlobalTranslationConstraint &)) &Plate_Plate::Load, "None", py::arg("GTConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_LineConstraint &)) &Plate_Plate::Load, "None", py::arg("LConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_PlaneConstraint &)) &Plate_Plate::Load, "None", py::arg("PConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_SampledCurveConstraint &)) &Plate_Plate::Load, "None", py::arg("SCConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_GtoCConstraint &)) &Plate_Plate::Load, "None", py::arg("GtoCConst"));
cls_Plate_Plate.def("Load", (void (Plate_Plate::*)(const Plate_FreeGtoCConstraint &)) &Plate_Plate::Load, "None", py::arg("FGtoCConst"));
cls_Plate_Plate.def("SolveTI", [](Plate_Plate &self) -> void { return self.SolveTI(); });
cls_Plate_Plate.def("SolveTI", [](Plate_Plate &self, const Standard_Integer a0) -> void { return self.SolveTI(a0); });
cls_Plate_Plate.def("SolveTI", (void (Plate_Plate::*)(const Standard_Integer, const Standard_Real)) &Plate_Plate::SolveTI, "None", py::arg("ord"), py::arg("anisotropie"));
cls_Plate_Plate.def("IsDone", (Standard_Boolean (Plate_Plate::*)() const) &Plate_Plate::IsDone, "returns True if all has been correctly done.");
cls_Plate_Plate.def("destroy", (void (Plate_Plate::*)()) &Plate_Plate::destroy, "None");
cls_Plate_Plate.def("Init", (void (Plate_Plate::*)()) &Plate_Plate::Init, "reset the Plate in the initial state ( same as after Create())");
cls_Plate_Plate.def("Evaluate", (gp_XYZ (Plate_Plate::*)(const gp_XY &) const) &Plate_Plate::Evaluate, "None", py::arg("point2d"));
cls_Plate_Plate.def("EvaluateDerivative", (gp_XYZ (Plate_Plate::*)(const gp_XY &, const Standard_Integer, const Standard_Integer) const) &Plate_Plate::EvaluateDerivative, "None", py::arg("point2d"), py::arg("iu"), py::arg("iv"));
cls_Plate_Plate.def("CoefPol", (void (Plate_Plate::*)(opencascade::handle<TColgp_HArray2OfXYZ> &) const) &Plate_Plate::CoefPol, "None", py::arg("Coefs"));
cls_Plate_Plate.def("SetPolynomialPartOnly", [](Plate_Plate &self) -> void { return self.SetPolynomialPartOnly(); });
cls_Plate_Plate.def("SetPolynomialPartOnly", (void (Plate_Plate::*)(const Standard_Boolean)) &Plate_Plate::SetPolynomialPartOnly, "None", py::arg("PPOnly"));
cls_Plate_Plate.def("Continuity", (Standard_Integer (Plate_Plate::*)() const) &Plate_Plate::Continuity, "None");
cls_Plate_Plate.def("UVBox", [](Plate_Plate &self, Standard_Real & UMin, Standard_Real & UMax, Standard_Real & VMin, Standard_Real & VMax){ self.UVBox(UMin, UMax, VMin, VMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(UMin, UMax, VMin, VMax); }, "None", py::arg("UMin"), py::arg("UMax"), py::arg("VMin"), py::arg("VMax"));
cls_Plate_Plate.def("UVConstraints", (void (Plate_Plate::*)(TColgp_SequenceOfXY &) const) &Plate_Plate::UVConstraints, "None", py::arg("Seq"));

// Enums

}