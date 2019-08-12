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
#include <FairCurve_Batten.hxx>
#include <Standard.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <FairCurve_AnalysisCode.hxx>
#include <Standard_OStream.hxx>
#include <gp_Vec2d.hxx>
#include <FairCurve_MinimalVariation.hxx>

void bind_FairCurve_MinimalVariation(py::module &mod){

py::class_<FairCurve_MinimalVariation, std::unique_ptr<FairCurve_MinimalVariation, Deleter<FairCurve_MinimalVariation>>, FairCurve_Batten> cls_FairCurve_MinimalVariation(mod, "FairCurve_MinimalVariation", "Computes a 2D curve using an algorithm which minimizes tension, sagging, and jerk energy. As in FairCurve_Batten, two reference points are used. Unlike that class, FairCurve_MinimalVariation requires curvature settings at the first and second reference points. These are defined by the rays of curvature desired at each point.");

// Constructors
cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"));
cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"), py::arg("Slope"));
cls_FairCurve_MinimalVariation.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Heigth"), py::arg("Slope"), py::arg("PhysicalRatio"));

// Fields

// Methods
// cls_FairCurve_MinimalVariation.def_static("operator new_", (void * (*)(size_t)) &FairCurve_MinimalVariation::operator new, "None", py::arg("theSize"));
// cls_FairCurve_MinimalVariation.def_static("operator delete_", (void (*)(void *)) &FairCurve_MinimalVariation::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_MinimalVariation.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_MinimalVariation::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_MinimalVariation.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_MinimalVariation::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_MinimalVariation.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_MinimalVariation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_MinimalVariation.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_MinimalVariation::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_MinimalVariation.def("SetCurvature1", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetCurvature1, "Allows you to set a new constraint on curvature at the first point.", py::arg("Curvature"));
cls_FairCurve_MinimalVariation.def("SetCurvature2", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetCurvature2, "Allows you to set a new constraint on curvature at the second point.", py::arg("Curvature"));
cls_FairCurve_MinimalVariation.def("SetPhysicalRatio", (void (FairCurve_MinimalVariation::*)(const Standard_Real)) &FairCurve_MinimalVariation::SetPhysicalRatio, "Allows you to set the physical ratio Ratio. The kinds of energy which you can specify include: 0 is only 'Jerk' Energy 1 is only 'Sagging' Energy like batten Warning: if Ratio is 1 it is impossible to impose curvature constraints. Raises DomainError if Ratio < 0 or Ratio > 1", py::arg("Ratio"));
cls_FairCurve_MinimalVariation.def("Compute", [](FairCurve_MinimalVariation &self, FairCurve_AnalysisCode & a0) -> Standard_Boolean { return self.Compute(a0); });
cls_FairCurve_MinimalVariation.def("Compute", [](FairCurve_MinimalVariation &self, FairCurve_AnalysisCode & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Compute(a0, a1); });
cls_FairCurve_MinimalVariation.def("Compute", (Standard_Boolean (FairCurve_MinimalVariation::*)(FairCurve_AnalysisCode &, const Standard_Integer, const Standard_Real)) &FairCurve_MinimalVariation::Compute, "Computes the curve with respect to the constraints, NbIterations and Tolerance. The tolerance setting allows you to control the precision of computation, and the maximum number of iterations allows you to set a limit on computation time.", py::arg("ACode"), py::arg("NbIterations"), py::arg("Tolerance"));
cls_FairCurve_MinimalVariation.def("GetCurvature1", (Standard_Real (FairCurve_MinimalVariation::*)() const) &FairCurve_MinimalVariation::GetCurvature1, "Returns the first established curvature.");
cls_FairCurve_MinimalVariation.def("GetCurvature2", (Standard_Real (FairCurve_MinimalVariation::*)() const) &FairCurve_MinimalVariation::GetCurvature2, "Returns the second established curvature.");
cls_FairCurve_MinimalVariation.def("GetPhysicalRatio", (Standard_Real (FairCurve_MinimalVariation::*)() const) &FairCurve_MinimalVariation::GetPhysicalRatio, "Returns the physical ratio, or kind of energy.");
cls_FairCurve_MinimalVariation.def("Dump", (void (FairCurve_MinimalVariation::*)(Standard_OStream &) const) &FairCurve_MinimalVariation::Dump, "Prints on the stream o information on the current state of the object. Is used to redefine the operator <<.", py::arg("o"));

// Enums

}