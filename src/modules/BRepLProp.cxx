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
#include <GeomAbs_Shape.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepLProp_CurveTool.hxx>
#include <BRepLProp_SurfaceTool.hxx>
#include <BRepLProp_CLProps.hxx>
#include <BRepLProp_SLProps.hxx>
#include <BRepLProp.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <LProp_Status.hxx>
#include <BRepAdaptor_Surface.hxx>

PYBIND11_MODULE(BRepLProp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.LProp");

// CLASS: BREPLPROP
py::class_<BRepLProp> cls_BRepLProp(mod, "BRepLProp", "These global functions compute the degree of continuity of a curve built by concatenation of two edges at their junction point.");

// Methods
// cls_BRepLProp.def_static("operator new_", (void * (*)(size_t)) &BRepLProp::operator new, "None", py::arg("theSize"));
// cls_BRepLProp.def_static("operator delete_", (void (*)(void *)) &BRepLProp::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &BRepLProp::Continuity, "Computes the regularity at the junction between C1 and C2. The point u1 on C1 and the point u2 on C2 must be confused. tl and ta are the linear and angular tolerance used two compare the derivative.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"), py::arg("tl"), py::arg("ta"));
cls_BRepLProp.def_static("Continuity_", (GeomAbs_Shape (*)(const BRepAdaptor_Curve &, const BRepAdaptor_Curve &, const Standard_Real, const Standard_Real)) &BRepLProp::Continuity, "The same as preciding but using the standard tolerances from package Precision.", py::arg("C1"), py::arg("C2"), py::arg("u1"), py::arg("u2"));

// CLASS: BREPLPROP_CLPROPS
py::class_<BRepLProp_CLProps> cls_BRepLProp_CLProps(mod, "BRepLProp_CLProps", "None");

// Constructors
cls_BRepLProp_CLProps.def(py::init<const BRepAdaptor_Curve &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_CLProps.def(py::init<const BRepAdaptor_Curve &, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("U"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_CLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Methods
// cls_BRepLProp_CLProps.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_CLProps::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_CLProps.def_static("operator delete_", (void (*)(void *)) &BRepLProp_CLProps::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_CLProps::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_CLProps.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_CLProps::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_CLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_CLProps.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_CLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_CLProps.def("SetParameter", (void (BRepLProp_CLProps::*)(const Standard_Real)) &BRepLProp_CLProps::SetParameter, "Initializes the local properties of the curve for the parameter value <U>.", py::arg("U"));
cls_BRepLProp_CLProps.def("SetCurve", (void (BRepLProp_CLProps::*)(const BRepAdaptor_Curve &)) &BRepLProp_CLProps::SetCurve, "Initializes the local properties of the curve for the new curve.", py::arg("C"));
cls_BRepLProp_CLProps.def("Value", (const gp_Pnt & (BRepLProp_CLProps::*)() const) &BRepLProp_CLProps::Value, "Returns the Point.");
cls_BRepLProp_CLProps.def("D1", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D1, "Returns the first derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("D2", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D2, "Returns the second derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("D3", (const gp_Vec & (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::D3, "Returns the third derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_CLProps.def("IsTangentDefined", (Standard_Boolean (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::IsTangentDefined, "Returns True if the tangent is defined. For example, the tangent is not defined if the three first derivatives are all null.");
cls_BRepLProp_CLProps.def("Tangent", (void (BRepLProp_CLProps::*)(gp_Dir &)) &BRepLProp_CLProps::Tangent, "output the tangent direction <D>", py::arg("D"));
cls_BRepLProp_CLProps.def("Curvature", (Standard_Real (BRepLProp_CLProps::*)()) &BRepLProp_CLProps::Curvature, "Returns the curvature.");
cls_BRepLProp_CLProps.def("Normal", (void (BRepLProp_CLProps::*)(gp_Dir &)) &BRepLProp_CLProps::Normal, "Returns the normal direction <N>.", py::arg("N"));
cls_BRepLProp_CLProps.def("CentreOfCurvature", (void (BRepLProp_CLProps::*)(gp_Pnt &)) &BRepLProp_CLProps::CentreOfCurvature, "Returns the centre of curvature <P>.", py::arg("P"));

// CLASS: BREPLPROP_CURVETOOL
py::class_<BRepLProp_CurveTool> cls_BRepLProp_CurveTool(mod, "BRepLProp_CurveTool", "None");

// Methods
// cls_BRepLProp_CurveTool.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_CurveTool::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_CurveTool.def_static("operator delete_", (void (*)(void *)) &BRepLProp_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_CurveTool.def_static("Value_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &)) &BRepLProp_CurveTool::Value, "Computes the point <P> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"));
cls_BRepLProp_CurveTool.def_static("D1_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &BRepLProp_CurveTool::D1, "Computes the point <P> and first derivative <V1> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
cls_BRepLProp_CurveTool.def_static("D2_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepLProp_CurveTool::D2, "Computes the point <P>, the first derivative <V1> and second derivative <V2> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_BRepLProp_CurveTool.def_static("D3_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepLProp_CurveTool::D3, "Computes the point <P>, the first derivative <V1>, the second derivative <V2> and third derivative <V3> of parameter <U> on the curve <C>.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_BRepLProp_CurveTool.def_static("Continuity_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &BRepLProp_CurveTool::Continuity, "returns the order of continuity of the curve <C>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable. returns 3 : first, second and third are computable.", py::arg("C"));
cls_BRepLProp_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &BRepLProp_CurveTool::FirstParameter, "returns the first parameter bound of the curve.", py::arg("C"));
cls_BRepLProp_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &BRepLProp_CurveTool::LastParameter, "returns the last parameter bound of the curve. FirstParameter must be less than LastParamenter.", py::arg("C"));

// CLASS: BREPLPROP_SLPROPS
py::class_<BRepLProp_SLProps> cls_BRepLProp_SLProps(mod, "BRepLProp_SLProps", "None");

// Constructors
cls_BRepLProp_SLProps.def(py::init<const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("U"), py::arg("V"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_SLProps.def(py::init<const BRepAdaptor_Surface &, const Standard_Integer, const Standard_Real>(), py::arg("S"), py::arg("N"), py::arg("Resolution"));
cls_BRepLProp_SLProps.def(py::init<const Standard_Integer, const Standard_Real>(), py::arg("N"), py::arg("Resolution"));

// Methods
// cls_BRepLProp_SLProps.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_SLProps::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_SLProps.def_static("operator delete_", (void (*)(void *)) &BRepLProp_SLProps::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_SLProps.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_SLProps::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_SLProps.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_SLProps::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_SLProps.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_SLProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_SLProps.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_SLProps::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_SLProps.def("SetSurface", (void (BRepLProp_SLProps::*)(const BRepAdaptor_Surface &)) &BRepLProp_SLProps::SetSurface, "Initializes the local properties of the surface S for the new surface.", py::arg("S"));
cls_BRepLProp_SLProps.def("SetParameters", (void (BRepLProp_SLProps::*)(const Standard_Real, const Standard_Real)) &BRepLProp_SLProps::SetParameters, "Initializes the local properties of the surface S for the new parameter values (<U>, <V>).", py::arg("U"), py::arg("V"));
cls_BRepLProp_SLProps.def("Value", (const gp_Pnt & (BRepLProp_SLProps::*)() const) &BRepLProp_SLProps::Value, "Returns the point.");
cls_BRepLProp_SLProps.def("D1U", (const gp_Vec & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::D1U, "Returns the first U derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_SLProps.def("D1V", (const gp_Vec & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::D1V, "Returns the first V derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_SLProps.def("D2U", (const gp_Vec & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::D2U, "Returns the second U derivatives The derivative is computed if it has not been yet.");
cls_BRepLProp_SLProps.def("D2V", (const gp_Vec & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::D2V, "Returns the second V derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_SLProps.def("DUV", (const gp_Vec & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::DUV, "Returns the second UV cross-derivative. The derivative is computed if it has not been yet.");
cls_BRepLProp_SLProps.def("IsTangentUDefined", (Standard_Boolean (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::IsTangentUDefined, "returns True if the U tangent is defined. For example, the tangent is not defined if the two first U derivatives are null.");
cls_BRepLProp_SLProps.def("TangentU", (void (BRepLProp_SLProps::*)(gp_Dir &)) &BRepLProp_SLProps::TangentU, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_BRepLProp_SLProps.def("IsTangentVDefined", (Standard_Boolean (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::IsTangentVDefined, "returns if the V tangent is defined. For example, the tangent is not defined if the two first V derivatives are null.");
cls_BRepLProp_SLProps.def("TangentV", (void (BRepLProp_SLProps::*)(gp_Dir &)) &BRepLProp_SLProps::TangentV, "Returns the tangent direction <D> on the iso-V.", py::arg("D"));
cls_BRepLProp_SLProps.def("IsNormalDefined", (Standard_Boolean (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::IsNormalDefined, "Tells if the normal is defined.");
cls_BRepLProp_SLProps.def("Normal", (const gp_Dir & (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::Normal, "Returns the normal direction.");
cls_BRepLProp_SLProps.def("IsCurvatureDefined", (Standard_Boolean (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::IsCurvatureDefined, "returns True if the curvature is defined.");
cls_BRepLProp_SLProps.def("IsUmbilic", (Standard_Boolean (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::IsUmbilic, "returns True if the point is umbilic (i.e. if the curvature is constant).");
cls_BRepLProp_SLProps.def("MaxCurvature", (Standard_Real (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::MaxCurvature, "Returns the maximum curvature");
cls_BRepLProp_SLProps.def("MinCurvature", (Standard_Real (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::MinCurvature, "Returns the minimum curvature");
cls_BRepLProp_SLProps.def("CurvatureDirections", (void (BRepLProp_SLProps::*)(gp_Dir &, gp_Dir &)) &BRepLProp_SLProps::CurvatureDirections, "Returns the direction of the maximum and minimum curvature <MaxD> and <MinD>", py::arg("MaxD"), py::arg("MinD"));
cls_BRepLProp_SLProps.def("MeanCurvature", (Standard_Real (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::MeanCurvature, "Returns the mean curvature.");
cls_BRepLProp_SLProps.def("GaussianCurvature", (Standard_Real (BRepLProp_SLProps::*)()) &BRepLProp_SLProps::GaussianCurvature, "Returns the Gaussian curvature");

// CLASS: BREPLPROP_SURFACETOOL
py::class_<BRepLProp_SurfaceTool> cls_BRepLProp_SurfaceTool(mod, "BRepLProp_SurfaceTool", "None");

// Methods
// cls_BRepLProp_SurfaceTool.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_SurfaceTool::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete_", (void (*)(void *)) &BRepLProp_SurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_SurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_SurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_SurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_SurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_SurfaceTool.def_static("Value_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &)) &BRepLProp_SurfaceTool::Value, "Computes the point <P> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"));
cls_BRepLProp_SurfaceTool.def_static("D1_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepLProp_SurfaceTool::D1, "Computes the point <P> and first derivative <D1*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_BRepLProp_SurfaceTool.def_static("D2_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepLProp_SurfaceTool::D2, "Computes the point <P>, the first derivative <D1*> and second derivative <D2*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("DUV"));
cls_BRepLProp_SurfaceTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &BRepLProp_SurfaceTool::DN, "None", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("IU"), py::arg("IV"));
cls_BRepLProp_SurfaceTool.def_static("Continuity_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &BRepLProp_SurfaceTool::Continuity, "returns the order of continuity of the Surface <S>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable.", py::arg("S"));
cls_BRepLProp_SurfaceTool.def_static("Bounds_", [](const BRepAdaptor_Surface & S, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ BRepLProp_SurfaceTool::Bounds(S, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "returns the bounds of the Surface.", py::arg("S"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));


}
