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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <FairCurve_AnalysisCode.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <gp_Vec2d.hxx>
#include <FairCurve_Batten.hxx>

void bind_FairCurve_Batten(py::module &mod){

py::class_<FairCurve_Batten, std::unique_ptr<FairCurve_Batten>> cls_FairCurve_Batten(mod, "FairCurve_Batten", "Constructs curves with a constant or linearly increasing section to be used in the design of wooden or plastic battens. These curves are two-dimensional, and simulate physical splines or battens.");

// Constructors
cls_FairCurve_Batten.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Height"));
cls_FairCurve_Batten.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("Height"), py::arg("Slope"));

// Fields

// Methods
// cls_FairCurve_Batten.def_static("operator new_", (void * (*)(size_t)) &FairCurve_Batten::operator new, "None", py::arg("theSize"));
// cls_FairCurve_Batten.def_static("operator delete_", (void (*)(void *)) &FairCurve_Batten::operator delete, "None", py::arg("theAddress"));
// cls_FairCurve_Batten.def_static("operator new[]_", (void * (*)(size_t)) &FairCurve_Batten::operator new[], "None", py::arg("theSize"));
// cls_FairCurve_Batten.def_static("operator delete[]_", (void (*)(void *)) &FairCurve_Batten::operator delete[], "None", py::arg("theAddress"));
// cls_FairCurve_Batten.def_static("operator new_", (void * (*)(size_t, void *)) &FairCurve_Batten::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_FairCurve_Batten.def_static("operator delete_", (void (*)(void *, void *)) &FairCurve_Batten::operator delete, "None", py::arg(""), py::arg(""));
cls_FairCurve_Batten.def("SetFreeSliding", (void (FairCurve_Batten::*)(const Standard_Boolean)) &FairCurve_Batten::SetFreeSliding, "Freesliding is initialized with the default setting false. When Freesliding is set to true and, as a result, sliding is free, the sliding factor is automatically computed to satisfy the equilibrium of the batten.", py::arg("FreeSliding"));
cls_FairCurve_Batten.def("SetConstraintOrder1", (void (FairCurve_Batten::*)(const Standard_Integer)) &FairCurve_Batten::SetConstraintOrder1, "Allows you to change the order of the constraint on the first point. ConstraintOrder has the default setting of 1. The following settings are available: - 0-the curve must pass through a point - 1-the curve must pass through a point and have a given tangent - 2-the curve must pass through a point, have a given tangent and a given curvature. The third setting is only valid for FairCurve_MinimalVariation curves. These constraints, though geometric, represent the mechanical constraints due, for example, to the resistance of the material the actual physical batten is made of.", py::arg("ConstraintOrder"));
cls_FairCurve_Batten.def("SetConstraintOrder2", (void (FairCurve_Batten::*)(const Standard_Integer)) &FairCurve_Batten::SetConstraintOrder2, "Allows you to change the order of the constraint on the second point. ConstraintOrder is initialized with the default setting of 1. The following settings are available: - 0-the curve must pass through a point - 1-the curve must pass through a point and have a given tangent - 2-the curve must pass through a point, have a given tangent and a given curvature. The third setting is only valid for FairCurve_MinimalVariation curves. These constraints, though geometric, represent the mechanical constraints due, for example, to the resistance of the material the actual physical batten is made of.", py::arg("ConstraintOrder"));
cls_FairCurve_Batten.def("SetP1", (void (FairCurve_Batten::*)(const gp_Pnt2d &)) &FairCurve_Batten::SetP1, "Allows you to change the location of the point, P1, and in doing so, modify the curve. Warning This method changes the angle as well as the point. Exceptions NullValue if the distance between P1 and P2 is less than or equal to the tolerance value for distance in Precision::Confusion: P1.IsEqual(P2, Precision::Confusion()). The function gp_Pnt2d::IsEqual tests to see if this is the case.", py::arg("P1"));
cls_FairCurve_Batten.def("SetP2", (void (FairCurve_Batten::*)(const gp_Pnt2d &)) &FairCurve_Batten::SetP2, "Allows you to change the location of the point, P1, and in doing so, modify the curve. Warning This method changes the angle as well as the point. Exceptions NullValue if the distance between P1 and P2 is less than or equal to the tolerance value for distance in Precision::Confusion: P1.IsEqual(P2, Precision::Confusion()). The function gp_Pnt2d::IsEqual tests to see if this is the case.", py::arg("P2"));
cls_FairCurve_Batten.def("SetAngle1", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetAngle1, "Allows you to change the angle Angle1 at the first point, P1. The default setting is 0.", py::arg("Angle1"));
cls_FairCurve_Batten.def("SetAngle2", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetAngle2, "Allows you to change the angle Angle2 at the second point, P2. The default setting is 0.", py::arg("Angle2"));
cls_FairCurve_Batten.def("SetHeight", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetHeight, "Allows you to change the height of the deformation. Raises NegativeValue; -- if Height <= 0 if Height <= 0", py::arg("Height"));
cls_FairCurve_Batten.def("SetSlope", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetSlope, "Allows you to set the slope value, Slope.", py::arg("Slope"));
cls_FairCurve_Batten.def("SetSlidingFactor", (void (FairCurve_Batten::*)(const Standard_Real)) &FairCurve_Batten::SetSlidingFactor, "Allows you to change the ratio SlidingFactor. This compares the length of the batten and the reference length, which is, in turn, a function of the constraints. This modification has one of the following two effects: - if you increase the value, it inflates the batten - if you decrease the value, it flattens the batten. When sliding is free, the sliding factor is automatically computed to satisfy the equilibrium of the batten. When sliding is imposed, a value is required for the sliding factor. SlidingFactor is initialized with the default setting of 1.", py::arg("SlidingFactor"));
cls_FairCurve_Batten.def("Compute", [](FairCurve_Batten &self, FairCurve_AnalysisCode & a0) -> Standard_Boolean { return self.Compute(a0); });
cls_FairCurve_Batten.def("Compute", [](FairCurve_Batten &self, FairCurve_AnalysisCode & a0, const Standard_Integer a1) -> Standard_Boolean { return self.Compute(a0, a1); });
cls_FairCurve_Batten.def("Compute", (Standard_Boolean (FairCurve_Batten::*)(FairCurve_AnalysisCode &, const Standard_Integer, const Standard_Real)) &FairCurve_Batten::Compute, "Performs the algorithm, using the arguments Code, NbIterations and Tolerance and computes the curve with respect to the constraints. Code will have one of the following values: - OK - NotConverged - InfiniteSliding - NullHeight The parameters Tolerance and NbIterations control how precise the computation is, and how long it will take.", py::arg("Code"), py::arg("NbIterations"), py::arg("Tolerance"));
cls_FairCurve_Batten.def("SlidingOfReference", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::SlidingOfReference, "Computes the real number value for length Sliding of Reference for new constraints. If you want to give a specific length to a batten curve, use the following syntax: b.SetSlidingFactor(L / b.SlidingOfReference()) where b is the name of the batten curve object.");
cls_FairCurve_Batten.def("GetFreeSliding", (Standard_Boolean (FairCurve_Batten::*)() const) &FairCurve_Batten::GetFreeSliding, "Returns the initial free sliding value, false by default. Free sliding is generally more aesthetically pleasing than constrained sliding. However, the computation can fail with values such as angles greater than PI/2. This is because the resulting batten length is theoretically infinite.");
cls_FairCurve_Batten.def("GetConstraintOrder1", (Standard_Integer (FairCurve_Batten::*)() const) &FairCurve_Batten::GetConstraintOrder1, "Returns the established first constraint order.");
cls_FairCurve_Batten.def("GetConstraintOrder2", (Standard_Integer (FairCurve_Batten::*)() const) &FairCurve_Batten::GetConstraintOrder2, "Returns the established second constraint order.");
cls_FairCurve_Batten.def("GetP1", (const gp_Pnt2d & (FairCurve_Batten::*)() const) &FairCurve_Batten::GetP1, "Returns the established location of the point P1.");
cls_FairCurve_Batten.def("GetP2", (const gp_Pnt2d & (FairCurve_Batten::*)() const) &FairCurve_Batten::GetP2, "Returns the established location of the point P2.");
cls_FairCurve_Batten.def("GetAngle1", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::GetAngle1, "Returns the established first angle.");
cls_FairCurve_Batten.def("GetAngle2", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::GetAngle2, "Returns the established second angle.");
cls_FairCurve_Batten.def("GetHeight", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::GetHeight, "Returns the thickness of the lathe.");
cls_FairCurve_Batten.def("GetSlope", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::GetSlope, "Returns the established slope value.");
cls_FairCurve_Batten.def("GetSlidingFactor", (Standard_Real (FairCurve_Batten::*)() const) &FairCurve_Batten::GetSlidingFactor, "Returns the initial sliding factor.");
cls_FairCurve_Batten.def("Curve", (opencascade::handle<Geom2d_BSplineCurve> (FairCurve_Batten::*)() const) &FairCurve_Batten::Curve, "Returns the computed curve a 2d BSpline.");
cls_FairCurve_Batten.def("Dump", (void (FairCurve_Batten::*)(Standard_OStream &) const) &FairCurve_Batten::Dump, "Prints on the stream o information on the current state of the object.", py::arg("o"));

// Enums

}