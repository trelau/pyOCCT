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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <NLPlate_HGPPConstraint.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <NLPlate_SequenceOfHGPPConstraint.hxx>
#include <NLPlate_StackOfPlate.hxx>
#include <NLPlate_NLPlate.hxx>

void bind_NLPlate_NLPlate(py::module &mod){

py::class_<NLPlate_NLPlate> cls_NLPlate_NLPlate(mod, "NLPlate_NLPlate", "None");

// Constructors
cls_NLPlate_NLPlate.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("InitialSurface"));

// Fields

// Methods
// cls_NLPlate_NLPlate.def_static("operator new_", (void * (*)(size_t)) &NLPlate_NLPlate::operator new, "None", py::arg("theSize"));
// cls_NLPlate_NLPlate.def_static("operator delete_", (void (*)(void *)) &NLPlate_NLPlate::operator delete, "None", py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator new[]_", (void * (*)(size_t)) &NLPlate_NLPlate::operator new[], "None", py::arg("theSize"));
// cls_NLPlate_NLPlate.def_static("operator delete[]_", (void (*)(void *)) &NLPlate_NLPlate::operator delete[], "None", py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator new_", (void * (*)(size_t, void *)) &NLPlate_NLPlate::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_NLPlate_NLPlate.def_static("operator delete_", (void (*)(void *, void *)) &NLPlate_NLPlate::operator delete, "None", py::arg(""), py::arg(""));
cls_NLPlate_NLPlate.def("Load", (void (NLPlate_NLPlate::*)(const opencascade::handle<NLPlate_HGPPConstraint> &)) &NLPlate_NLPlate::Load, "None", py::arg("GConst"));
cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self) -> void { return self.Solve(); });
cls_NLPlate_NLPlate.def("Solve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve(a0); });
cls_NLPlate_NLPlate.def("Solve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self) -> void { return self.Solve2(); });
cls_NLPlate_NLPlate.def("Solve2", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.Solve2(a0); });
cls_NLPlate_NLPlate.def("Solve2", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer)) &NLPlate_NLPlate::Solve2, "None", py::arg("ord"), py::arg("InitialConsraintOrder"));
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self) -> void { return self.IncrementalSolve(); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0) -> void { return self.IncrementalSolve(a0); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.IncrementalSolve(a0, a1); });
cls_NLPlate_NLPlate.def("IncrementalSolve", [](NLPlate_NLPlate &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2) -> void { return self.IncrementalSolve(a0, a1, a2); });
cls_NLPlate_NLPlate.def("IncrementalSolve", (void (NLPlate_NLPlate::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &NLPlate_NLPlate::IncrementalSolve, "None", py::arg("ord"), py::arg("InitialConsraintOrder"), py::arg("NbIncrements"), py::arg("UVSliding"));
cls_NLPlate_NLPlate.def("IsDone", (Standard_Boolean (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::IsDone, "returns True if all has been correctly done.");
cls_NLPlate_NLPlate.def("destroy", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::destroy, "None");
cls_NLPlate_NLPlate.def("Init", (void (NLPlate_NLPlate::*)()) &NLPlate_NLPlate::Init, "reset the Plate in the initial state ( same as after Create((Surface))");
cls_NLPlate_NLPlate.def("Evaluate", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &) const) &NLPlate_NLPlate::Evaluate, "None", py::arg("point2d"));
cls_NLPlate_NLPlate.def("EvaluateDerivative", (gp_XYZ (NLPlate_NLPlate::*)(const gp_XY &, const Standard_Integer, const Standard_Integer) const) &NLPlate_NLPlate::EvaluateDerivative, "None", py::arg("point2d"), py::arg("iu"), py::arg("iv"));
cls_NLPlate_NLPlate.def("Continuity", (Standard_Integer (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::Continuity, "None");
cls_NLPlate_NLPlate.def("ConstraintsSliding", [](NLPlate_NLPlate &self) -> void { return self.ConstraintsSliding(); });
cls_NLPlate_NLPlate.def("ConstraintsSliding", (void (NLPlate_NLPlate::*)(const Standard_Integer)) &NLPlate_NLPlate::ConstraintsSliding, "None", py::arg("NbIterations"));
cls_NLPlate_NLPlate.def("MaxActiveConstraintOrder", (Standard_Integer (NLPlate_NLPlate::*)() const) &NLPlate_NLPlate::MaxActiveConstraintOrder, "None");

// Enums

}