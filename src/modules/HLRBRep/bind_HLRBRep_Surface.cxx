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
#include <HLRAlgo_Projector.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <gp_Pln.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Sphere.hxx>
#include <gp_Torus.hxx>
#include <gp_Ax1.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <HLRBRep_Surface.hxx>

void bind_HLRBRep_Surface(py::module &mod){

py::class_<HLRBRep_Surface, std::unique_ptr<HLRBRep_Surface, Deleter<HLRBRep_Surface>>> cls_HLRBRep_Surface(mod, "HLRBRep_Surface", "None");

// Constructors
cls_HLRBRep_Surface.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_Surface.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_Surface::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_Surface.def_static("operator delete_", (void (*)(void *)) &HLRBRep_Surface::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_Surface::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_Surface.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_Surface.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_Surface.def("Projector", (void (HLRBRep_Surface::*)(const HLRAlgo_Projector *)) &HLRBRep_Surface::Projector, "None", py::arg("Proj"));
cls_HLRBRep_Surface.def("Surface", (BRepAdaptor_Surface & (HLRBRep_Surface::*)()) &HLRBRep_Surface::Surface, "Returns the 3D Surface.");
cls_HLRBRep_Surface.def("Surface", (void (HLRBRep_Surface::*)(const TopoDS_Face &)) &HLRBRep_Surface::Surface, "Sets the 3D Surface to be projected.", py::arg("F"));
cls_HLRBRep_Surface.def("IsSide", (Standard_Boolean (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real) const) &HLRBRep_Surface::IsSide, "returns true if it is a side face", py::arg("tolf"), py::arg("toler"));
cls_HLRBRep_Surface.def("IsAbove", (Standard_Boolean (HLRBRep_Surface::*)(const Standard_Boolean, const HLRBRep_Curve *, const Standard_Real) const) &HLRBRep_Surface::IsAbove, "None", py::arg("back"), py::arg("A"), py::arg("tolC"));
cls_HLRBRep_Surface.def("FirstUParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::FirstUParameter, "None");
cls_HLRBRep_Surface.def("LastUParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::LastUParameter, "None");
cls_HLRBRep_Surface.def("FirstVParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::FirstVParameter, "None");
cls_HLRBRep_Surface.def("LastVParameter", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::LastVParameter, "None");
cls_HLRBRep_Surface.def("UContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UContinuity, "None");
cls_HLRBRep_Surface.def("VContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VContinuity, "None");
cls_HLRBRep_Surface.def("NbUIntervals", (Standard_Integer (HLRBRep_Surface::*)(const GeomAbs_Shape)) &HLRBRep_Surface::NbUIntervals, "If necessary, breaks the surface in U intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
cls_HLRBRep_Surface.def("NbVIntervals", (Standard_Integer (HLRBRep_Surface::*)(const GeomAbs_Shape)) &HLRBRep_Surface::NbVIntervals, "If necessary, breaks the surface in V intervals of continuity <S>. And returns the number of intervals.", py::arg("S"));
// cls_HLRBRep_Surface.def("UIntervalContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UIntervalContinuity, "None");
// cls_HLRBRep_Surface.def("VIntervalContinuity", (GeomAbs_Shape (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VIntervalContinuity, "None");
cls_HLRBRep_Surface.def("IsUClosed", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsUClosed, "None");
cls_HLRBRep_Surface.def("IsVClosed", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsVClosed, "None");
cls_HLRBRep_Surface.def("IsUPeriodic", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsUPeriodic, "None");
cls_HLRBRep_Surface.def("UPeriod", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UPeriod, "None");
cls_HLRBRep_Surface.def("IsVPeriodic", (Standard_Boolean (HLRBRep_Surface::*)() const) &HLRBRep_Surface::IsVPeriodic, "None");
cls_HLRBRep_Surface.def("VPeriod", (Standard_Real (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VPeriod, "None");
cls_HLRBRep_Surface.def("Value", (gp_Pnt (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real) const) &HLRBRep_Surface::Value, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"));
cls_HLRBRep_Surface.def("D0", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &HLRBRep_Surface::D0, "Computes the point of parameters U,V on the surface.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_HLRBRep_Surface.def("D1", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D1, "Computes the point and the first derivatives on the surface. Raised if the continuity of the current intervals is not C1.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_HLRBRep_Surface.def("D2", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D2, "Computes the point, the first and second derivatives on the surface. Raised if the continuity of the current intervals is not C2.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_HLRBRep_Surface.def("D3", (void (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &HLRBRep_Surface::D3, "Computes the point, the first, second and third derivatives on the surface. Raised if the continuity of the current intervals is not C3.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_HLRBRep_Surface.def("DN", (gp_Vec (HLRBRep_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &HLRBRep_Surface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V). Raised if the current U interval is not not CNu and the current V interval is not CNv. Raised if Nu + Nv < 1 or Nu < 0 or Nv < 0.", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_HLRBRep_Surface.def("GetType", (GeomAbs_SurfaceType (HLRBRep_Surface::*)() const) &HLRBRep_Surface::GetType, "Returns the type of the surface : Plane, Cylinder, Cone, Sphere, Torus, BezierSurface, BSplineSurface, SurfaceOfRevolution, SurfaceOfExtrusion, OtherSurface");
cls_HLRBRep_Surface.def("Plane", (gp_Pln (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Plane, "None");
cls_HLRBRep_Surface.def("Cylinder", (gp_Cylinder (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Cylinder, "None");
cls_HLRBRep_Surface.def("Cone", (gp_Cone (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Cone, "None");
cls_HLRBRep_Surface.def("Sphere", (gp_Sphere (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Sphere, "None");
cls_HLRBRep_Surface.def("Torus", (gp_Torus (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Torus, "None");
cls_HLRBRep_Surface.def("UDegree", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::UDegree, "None");
cls_HLRBRep_Surface.def("NbUPoles", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbUPoles, "None");
cls_HLRBRep_Surface.def("VDegree", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::VDegree, "None");
cls_HLRBRep_Surface.def("NbVPoles", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbVPoles, "None");
cls_HLRBRep_Surface.def("NbUKnots", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbUKnots, "None");
cls_HLRBRep_Surface.def("NbVKnots", (Standard_Integer (HLRBRep_Surface::*)() const) &HLRBRep_Surface::NbVKnots, "None");
cls_HLRBRep_Surface.def("Axis", (gp_Ax1 (HLRBRep_Surface::*)() const) &HLRBRep_Surface::Axis, "None");

// Enums

}