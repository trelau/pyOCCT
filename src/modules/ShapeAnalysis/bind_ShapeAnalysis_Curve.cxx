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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Bnd_Box2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_XYZ.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <ShapeAnalysis_Curve.hxx>

void bind_ShapeAnalysis_Curve(py::module &mod){

py::class_<ShapeAnalysis_Curve, std::unique_ptr<ShapeAnalysis_Curve, Deleter<ShapeAnalysis_Curve>>> cls_ShapeAnalysis_Curve(mod, "ShapeAnalysis_Curve", "Analyzing tool for 2d or 3d curve. Computes parameters of projected point onto a curve.");

// Constructors

// Fields

// Methods
// cls_ShapeAnalysis_Curve.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_Curve::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_Curve.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_Curve::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Curve.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_Curve::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_Curve.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_Curve.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_Curve.def("Project", [](ShapeAnalysis_Curve &self, const opencascade::handle<Geom_Curve> & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param, const Standard_Boolean AdjustToEnds){ Standard_Real rv = self.Project(C3D, P3D, preci, proj, param, AdjustToEnds); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "Projects a Point on a Curve. Computes the projected point and its parameter on the curve. <preci> is used as 3d precision (hence, 0 will produce reject unless exact confusion). The number of iterations is limited. If AdjustToEnds is True, point will be adjusted to the end of the curve if distance is less than <preci>", py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"), py::arg("AdjustToEnds"));
cls_ShapeAnalysis_Curve.def("Project", [](ShapeAnalysis_Curve &self, const Adaptor3d_Curve & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param, const Standard_Boolean AdjustToEnds){ Standard_Real rv = self.Project(C3D, P3D, preci, proj, param, AdjustToEnds); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "Projects a Point on a Curve. Computes the projected point and its parameter on the curve. <preci> is used as 3d precision (hence, 0 will produce reject unless exact confusion). The number of iterations is limited.", py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"), py::arg("AdjustToEnds"));
cls_ShapeAnalysis_Curve.def("Project", [](ShapeAnalysis_Curve &self, const opencascade::handle<Geom_Curve> & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param, const Standard_Real cf, const Standard_Real cl, const Standard_Boolean AdjustToEnds){ Standard_Real rv = self.Project(C3D, P3D, preci, proj, param, cf, cl, AdjustToEnds); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "Projects a Point on a Curve, but parameters are limited between <cf> and <cl>. The range [cf, cl] is extended with help of Adaptor3d on the basis of 3d precision <preci>. If AdjustToEnds is True, point will be adjusted to the end of the curve if distance is less than <preci>", py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"), py::arg("cf"), py::arg("cl"), py::arg("AdjustToEnds"));
cls_ShapeAnalysis_Curve.def("ProjectAct", [](ShapeAnalysis_Curve &self, const Adaptor3d_Curve & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param){ Standard_Real rv = self.ProjectAct(C3D, P3D, preci, proj, param); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "None", py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"));
cls_ShapeAnalysis_Curve.def("NextProject", [](ShapeAnalysis_Curve &self, const Standard_Real paramPrev, const opencascade::handle<Geom_Curve> & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param, const Standard_Real cf, const Standard_Real cl, const Standard_Boolean AdjustToEnds){ Standard_Real rv = self.NextProject(paramPrev, C3D, P3D, preci, proj, param, cf, cl, AdjustToEnds); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "Projects a Point on a Curve using Newton method. <paramPrev> is taken as the first approximation of solution. If Newton algorithm fails the method Project() is used. If AdjustToEnds is True, point will be adjusted to the end of the curve if distance is less than <preci>", py::arg("paramPrev"), py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"), py::arg("cf"), py::arg("cl"), py::arg("AdjustToEnds"));
cls_ShapeAnalysis_Curve.def("NextProject", [](ShapeAnalysis_Curve &self, const Standard_Real paramPrev, const Adaptor3d_Curve & C3D, const gp_Pnt & P3D, const Standard_Real preci, gp_Pnt & proj, Standard_Real & param){ Standard_Real rv = self.NextProject(paramPrev, C3D, P3D, preci, proj, param); return std::tuple<Standard_Real, Standard_Real &>(rv, param); }, "Projects a Point on a Curve using Newton method. <paramPrev> is taken as the first approximation of solution. If Newton algorithm fails the method Project() is used.", py::arg("paramPrev"), py::arg("C3D"), py::arg("P3D"), py::arg("preci"), py::arg("proj"), py::arg("param"));
cls_ShapeAnalysis_Curve.def("ValidateRange", [](ShapeAnalysis_Curve &self, const opencascade::handle<Geom_Curve> & Crv, Standard_Real & First, Standard_Real & Last, const Standard_Real prec){ Standard_Boolean rv = self.ValidateRange(Crv, First, Last, prec); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, First, Last); }, "Validate parameters First and Last for the given curve in order to make them valid for creation of edge. This includes: - limiting range [First,Last] by range of curve - adjusting range [First,Last] for periodic (or closed) curve if Last < First Returns True if parameters are OK or are successfully corrected, or False if parameters cannot be corrected. In the latter case, parameters are reset to range of curve.", py::arg("Crv"), py::arg("First"), py::arg("Last"), py::arg("prec"));
cls_ShapeAnalysis_Curve.def("FillBndBox", (void (ShapeAnalysis_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, Bnd_Box2d &) const) &ShapeAnalysis_Curve::FillBndBox, "Computes a boundary box on segment of curve C2d from First to Last. This is done by taking NPoints points from the curve and, if Exact is True, by searching for exact extrema. All these points are added to Box.", py::arg("C2d"), py::arg("First"), py::arg("Last"), py::arg("NPoints"), py::arg("Exact"), py::arg("Box"));
cls_ShapeAnalysis_Curve.def("SelectForwardSeam", (Standard_Integer (ShapeAnalysis_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &) const) &ShapeAnalysis_Curve::SelectForwardSeam, "Defines which pcurve (C1 or C2) should be chosen for FORWARD seam edge.", py::arg("C1"), py::arg("C2"));
cls_ShapeAnalysis_Curve.def_static("IsPlanar_", [](const TColgp_Array1OfPnt & a0, gp_XYZ & a1) -> Standard_Boolean { return ShapeAnalysis_Curve::IsPlanar(a0, a1); });
cls_ShapeAnalysis_Curve.def_static("IsPlanar_", (Standard_Boolean (*)(const TColgp_Array1OfPnt &, gp_XYZ &, const Standard_Real)) &ShapeAnalysis_Curve::IsPlanar, "Checks if points are planar with given preci. If Normal has not zero modulus, checks with given normal", py::arg("pnts"), py::arg("Normal"), py::arg("preci"));
cls_ShapeAnalysis_Curve.def_static("IsPlanar_", [](const opencascade::handle<Geom_Curve> & a0, gp_XYZ & a1) -> Standard_Boolean { return ShapeAnalysis_Curve::IsPlanar(a0, a1); });
cls_ShapeAnalysis_Curve.def_static("IsPlanar_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, gp_XYZ &, const Standard_Real)) &ShapeAnalysis_Curve::IsPlanar, "Checks if curve is planar with given preci. If Normal has not zero modulus, checks with given normal", py::arg("curve"), py::arg("Normal"), py::arg("preci"));
cls_ShapeAnalysis_Curve.def_static("GetSamplePoints_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, TColgp_SequenceOfPnt2d &)) &ShapeAnalysis_Curve::GetSamplePoints, "Returns sample points which will serve as linearisation of the2d curve in range (first, last) The distribution of sample points is consystent with what is used by BRepTopAdaptor_FClass2d", py::arg("curve"), py::arg("first"), py::arg("last"), py::arg("seq"));
cls_ShapeAnalysis_Curve.def_static("GetSamplePoints_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, TColgp_SequenceOfPnt &)) &ShapeAnalysis_Curve::GetSamplePoints, "Returns sample points which will serve as linearisation of the curve in range (first, last)", py::arg("curve"), py::arg("first"), py::arg("last"), py::arg("seq"));
cls_ShapeAnalysis_Curve.def_static("IsClosed_", [](const opencascade::handle<Geom_Curve> & a0) -> Standard_Boolean { return ShapeAnalysis_Curve::IsClosed(a0); });
cls_ShapeAnalysis_Curve.def_static("IsClosed_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &ShapeAnalysis_Curve::IsClosed, "Tells if the Curve is closed with given precision. If <preci> < 0 then Precision::Confusion is used.", py::arg("curve"), py::arg("preci"));
cls_ShapeAnalysis_Curve.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Geom_Curve> &)) &ShapeAnalysis_Curve::IsPeriodic, "This method was implemented as fix for changes in trimmed curve behaviour. For the moment trimmed curve returns false anyway. So it is necessary to adapt all Data exchange tools for this behaviour. Current implementation takes into account that curve may be offset.", py::arg("curve"));
cls_ShapeAnalysis_Curve.def_static("IsPeriodic_", (Standard_Boolean (*)(const opencascade::handle<Geom2d_Curve> &)) &ShapeAnalysis_Curve::IsPeriodic, "The same as for Curve3d.", py::arg("curve"));

// Enums

}