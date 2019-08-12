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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <Geom_Curve.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Type.hxx>
#include <Extrema_ExtPS.hxx>

void bind_ShapeAnalysis_Surface(py::module &mod){

py::class_<ShapeAnalysis_Surface, opencascade::handle<ShapeAnalysis_Surface>, Standard_Transient> cls_ShapeAnalysis_Surface(mod, "ShapeAnalysis_Surface", "Complements standard tool Geom_Surface by providing additional functionality for detection surface singularities, checking spatial surface closure and computing projections of 3D points onto a surface.");

// Constructors
cls_ShapeAnalysis_Surface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));

// Fields

// Methods
cls_ShapeAnalysis_Surface.def("Init", (void (ShapeAnalysis_Surface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeAnalysis_Surface::Init, "Loads existing surface", py::arg("S"));
cls_ShapeAnalysis_Surface.def("Init", (void (ShapeAnalysis_Surface::*)(const opencascade::handle<ShapeAnalysis_Surface> &)) &ShapeAnalysis_Surface::Init, "Reads all the data from another Surface, without recomputing", py::arg("other"));
cls_ShapeAnalysis_Surface.def("SetDomain", (void (ShapeAnalysis_Surface::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ShapeAnalysis_Surface::SetDomain, "None", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_ShapeAnalysis_Surface.def("Surface", (const opencascade::handle<Geom_Surface> & (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::Surface, "Returns a surface being analyzed");
cls_ShapeAnalysis_Surface.def("Adaptor3d", (const opencascade::handle<GeomAdaptor_HSurface> & (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::Adaptor3d, "Returns the Adaptor. Creates it if not yet done.");
cls_ShapeAnalysis_Surface.def("TrueAdaptor3d", (const opencascade::handle<GeomAdaptor_HSurface> & (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::TrueAdaptor3d, "Returns the Adaptor (may be Null if method Adaptor() was not called)");
cls_ShapeAnalysis_Surface.def("Gap", (Standard_Real (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::Gap, "Returns 3D distance found by one of the following methods. IsDegenerated, DegeneratedValues, ProjectDegenerated (distance between 3D point and found or last (if not found) singularity), IsUClosed, IsVClosed (minimum value of precision to consider the surface to be closed), ValueOfUV (distance between 3D point and found solution).");
cls_ShapeAnalysis_Surface.def("Value", (gp_Pnt (ShapeAnalysis_Surface::*)(const Standard_Real, const Standard_Real)) &ShapeAnalysis_Surface::Value, "Returns a 3D point specified by parameters in surface parametrical space", py::arg("u"), py::arg("v"));
cls_ShapeAnalysis_Surface.def("Value", (gp_Pnt (ShapeAnalysis_Surface::*)(const gp_Pnt2d &)) &ShapeAnalysis_Surface::Value, "Returns a 3d point specified by a point in surface parametrical space", py::arg("p2d"));
cls_ShapeAnalysis_Surface.def("HasSingularities", (Standard_Boolean (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::HasSingularities, "Returns True if the surface has singularities for the given precision (i.e. if there are surface singularities with sizes not greater than precision).", py::arg("preci"));
cls_ShapeAnalysis_Surface.def("NbSingularities", (Standard_Integer (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::NbSingularities, "Returns the number of singularities for the given precision (i.e. number of surface singularities with sizes not greater than precision).", py::arg("preci"));
cls_ShapeAnalysis_Surface.def("Singularity", [](ShapeAnalysis_Surface &self, const Standard_Integer num, Standard_Real & preci, gp_Pnt & P3d, gp_Pnt2d & firstP2d, gp_Pnt2d & lastP2d, Standard_Real & firstpar, Standard_Real & lastpar, Standard_Boolean & uisodeg){ Standard_Boolean rv = self.Singularity(num, preci, P3d, firstP2d, lastP2d, firstpar, lastpar, uisodeg); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &>(rv, preci, firstpar, lastpar, uisodeg); }, "Returns the characteristics of the singularity specified by its rank number <num>. That means, that it is not neccessary for <num> to be in the range [1, NbSingularities] but must be not greater than possible (see ComputeSingularities). The returned characteristics are: preci: the smallest precision with which the iso-line is considered as degenerated, P3d: 3D point of singularity (middle point of the surface iso-line), firstP2d and lastP2d: first and last 2D points of the iso-line in parametrical surface, firstpar and lastpar: first and last parameters of the iso-line in parametrical surface, uisodeg: if the degenerated iso-line is U-iso (True) or V-iso (False). Returns False if <num> is out of range, else returns True.", py::arg("num"), py::arg("preci"), py::arg("P3d"), py::arg("firstP2d"), py::arg("lastP2d"), py::arg("firstpar"), py::arg("lastpar"), py::arg("uisodeg"));
cls_ShapeAnalysis_Surface.def("IsDegenerated", (Standard_Boolean (ShapeAnalysis_Surface::*)(const gp_Pnt &, const Standard_Real)) &ShapeAnalysis_Surface::IsDegenerated, "Returns True if there is at least one surface boundary which is considered as degenerated with <preci> and distance between P3d and corresponding singular point is less than <preci>", py::arg("P3d"), py::arg("preci"));
cls_ShapeAnalysis_Surface.def("DegeneratedValues", [](ShapeAnalysis_Surface &self, const gp_Pnt & P3d, const Standard_Real preci, gp_Pnt2d & firstP2d, gp_Pnt2d & lastP2d, Standard_Real & firstpar, Standard_Real & lastpar, const Standard_Boolean forward){ Standard_Boolean rv = self.DegeneratedValues(P3d, preci, firstP2d, lastP2d, firstpar, lastpar, forward); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, firstpar, lastpar); }, "Returns True if there is at least one surface iso-line which is considered as degenerated with <preci> and distance between P3d and corresponding singular point is less than <preci> (like IsDegenerated). Returns characteristics of the first found boundary matching those criteria.", py::arg("P3d"), py::arg("preci"), py::arg("firstP2d"), py::arg("lastP2d"), py::arg("firstpar"), py::arg("lastpar"), py::arg("forward"));
cls_ShapeAnalysis_Surface.def("ProjectDegenerated", (Standard_Boolean (ShapeAnalysis_Surface::*)(const gp_Pnt &, const Standard_Real, const gp_Pnt2d &, gp_Pnt2d &)) &ShapeAnalysis_Surface::ProjectDegenerated, "Projects a point <P3d> on a singularity by computing one of the coordinates of preliminary computed <result>.", py::arg("P3d"), py::arg("preci"), py::arg("neighbour"), py::arg("result"));
cls_ShapeAnalysis_Surface.def("ProjectDegenerated", (Standard_Boolean (ShapeAnalysis_Surface::*)(const Standard_Integer, const TColgp_SequenceOfPnt &, TColgp_SequenceOfPnt2d &, const Standard_Real, const Standard_Boolean)) &ShapeAnalysis_Surface::ProjectDegenerated, "Checks points at the beginning (direct is True) or end (direct is False) of array <points> to lie in singularity of surface, and if yes, adjusts the indeterminate 2d coordinate of these points by nearest point which is not in singularity. Returns True if some points were adjusted.", py::arg("nbrPnt"), py::arg("points"), py::arg("pnt2d"), py::arg("preci"), py::arg("direct"));
cls_ShapeAnalysis_Surface.def("IsDegenerated", (Standard_Boolean (ShapeAnalysis_Surface::*)(const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &ShapeAnalysis_Surface::IsDegenerated, "Returns True if straight pcurve going from point p2d1 to p2d2 is degenerate, i.e. lies in the singularity of the surface. NOTE: it uses another method of detecting singularity than used by ComputeSingularities() et al.! For that, maximums of distances between points p2d1, p2d2 and 0.5*(p2d1+p2d2) and between corresponding 3d points are computed. The pcurve (p2d1, p2d2) is considered as degenerate if: - max distance in 3d is less than <tol> - max distance in 2d is at least <ratio> times greather than the Resolution computed from max distance in 3d (max3d < tol && max2d > ratio * Resolution(max3d)) NOTE: <ratio> should be >1 (e.g. 10)", py::arg("p2d1"), py::arg("p2d2"), py::arg("tol"), py::arg("ratio"));
cls_ShapeAnalysis_Surface.def("Bounds", [](ShapeAnalysis_Surface &self, Standard_Real & ufirst, Standard_Real & ulast, Standard_Real & vfirst, Standard_Real & vlast){ self.Bounds(ufirst, ulast, vfirst, vlast); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(ufirst, ulast, vfirst, vlast); }, "Returns the bounds of the surface (from Bounds from Surface, but buffered)", py::arg("ufirst"), py::arg("ulast"), py::arg("vfirst"), py::arg("vlast"));
cls_ShapeAnalysis_Surface.def("ComputeBoundIsos", (void (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::ComputeBoundIsos, "Computes bound isos (protected against exceptions)");
cls_ShapeAnalysis_Surface.def("UIso", (opencascade::handle<Geom_Curve> (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::UIso, "Returns a U-Iso. Null if not possible or failed Remark : bound isos are buffered", py::arg("U"));
cls_ShapeAnalysis_Surface.def("VIso", (opencascade::handle<Geom_Curve> (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::VIso, "Returns a V-Iso. Null if not possible or failed Remark : bound isos are buffered", py::arg("V"));
cls_ShapeAnalysis_Surface.def("IsUClosed", [](ShapeAnalysis_Surface &self) -> Standard_Boolean { return self.IsUClosed(); });
cls_ShapeAnalysis_Surface.def("IsUClosed", (Standard_Boolean (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::IsUClosed, "Tells if the Surface is spatially closed in U with given precision. If <preci> < 0 then Precision::Confusion is used. If Geom_Surface says that the surface is U-closed, this method also says this. Otherwise additional analysis is performed, comparing given precision with the following distances: - periodic B-Splines are closed, - polinomial B-Spline with boundary multiplicities degree+1 and Bezier - maximum distance between poles, - rational B-Spline or one with boundary multiplicities not degree+1 - maximum distance computed at knots and their middles, - surface of extrusion - distance between ends of basis curve, - other (RectangularTrimmed and Offset) - maximum distance computed at 100 equi-distanted points.", py::arg("preci"));
cls_ShapeAnalysis_Surface.def("IsVClosed", [](ShapeAnalysis_Surface &self) -> Standard_Boolean { return self.IsVClosed(); });
cls_ShapeAnalysis_Surface.def("IsVClosed", (Standard_Boolean (ShapeAnalysis_Surface::*)(const Standard_Real)) &ShapeAnalysis_Surface::IsVClosed, "Tells if the Surface is spatially closed in V with given precision. If <preci> < 0 then Precision::Confusion is used. If Geom_Surface says that the surface is V-closed, this method also says this. Otherwise additional analysis is performed, comparing given precision with the following distances: - periodic B-Splines are closed, - polinomial B-Spline with boundary multiplicities degree+1 and Bezier - maximum distance between poles, - rational B-Spline or one with boundary multiplicities not degree+1 - maximum distance computed at knots and their middles, - surface of revolution - distance between ends of basis curve, - other (RectangularTrimmed and Offset) - maximum distance computed at 100 equi-distanted points.", py::arg("preci"));
cls_ShapeAnalysis_Surface.def("ValueOfUV", (gp_Pnt2d (ShapeAnalysis_Surface::*)(const gp_Pnt &, const Standard_Real)) &ShapeAnalysis_Surface::ValueOfUV, "Computes the parameters in the surface parametrical space of 3D point. The result is parameters of the point projected onto the surface. This method enhances functionality provided by the standard tool GeomAPI_ProjectPointOnSurface by treatment of cases when the projected point is near to the surface boundaries and when this standard tool fails.", py::arg("P3D"), py::arg("preci"));
cls_ShapeAnalysis_Surface.def("NextValueOfUV", [](ShapeAnalysis_Surface &self, const gp_Pnt2d & a0, const gp_Pnt & a1, const Standard_Real a2) -> gp_Pnt2d { return self.NextValueOfUV(a0, a1, a2); });
cls_ShapeAnalysis_Surface.def("NextValueOfUV", (gp_Pnt2d (ShapeAnalysis_Surface::*)(const gp_Pnt2d &, const gp_Pnt &, const Standard_Real, const Standard_Real)) &ShapeAnalysis_Surface::NextValueOfUV, "Projects a point P3D on the surface. Does the same thing as ValueOfUV but tries to optimize computations by taking into account previous point <p2dPrev>: makes a step by UV and tries Newton algorithm. If <maxpreci> >0. and distance between solution and P3D is greater than <maxpreci>, that solution is considered as bad, and ValueOfUV() is used. If not succeded, calls ValueOfUV()", py::arg("p2dPrev"), py::arg("P3D"), py::arg("preci"), py::arg("maxpreci"));
cls_ShapeAnalysis_Surface.def("UVFromIso", [](ShapeAnalysis_Surface &self, const gp_Pnt & P3D, const Standard_Real preci, Standard_Real & U, Standard_Real & V){ Standard_Real rv = self.UVFromIso(P3D, preci, U, V); return std::tuple<Standard_Real, Standard_Real &, Standard_Real &>(rv, U, V); }, "Tries a refinement of an already computed couple (U,V) by using projecting 3D point on iso-lines: 1. boundaries of the surface, 2. iso-lines passing through (U,V) 3. iteratively received iso-lines passing through new U and new V (number of iterations is limited by 5 in each direction) Returns the best resulting distance between P3D and Value(U,V) in the case of success. Else, returns a very great value", py::arg("P3D"), py::arg("preci"), py::arg("U"), py::arg("V"));
cls_ShapeAnalysis_Surface.def("UCloseVal", (Standard_Real (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::UCloseVal, "Returns minimum value to consider the surface as U-closed");
cls_ShapeAnalysis_Surface.def("VCloseVal", (Standard_Real (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::VCloseVal, "Returns minimum value to consider the surface as V-closed");
cls_ShapeAnalysis_Surface.def("GetBoxUF", (const Bnd_Box & (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::GetBoxUF, "None");
cls_ShapeAnalysis_Surface.def("GetBoxUL", (const Bnd_Box & (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::GetBoxUL, "None");
cls_ShapeAnalysis_Surface.def("GetBoxVF", (const Bnd_Box & (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::GetBoxVF, "None");
cls_ShapeAnalysis_Surface.def("GetBoxVL", (const Bnd_Box & (ShapeAnalysis_Surface::*)()) &ShapeAnalysis_Surface::GetBoxVL, "None");
cls_ShapeAnalysis_Surface.def_static("get_type_name_", (const char * (*)()) &ShapeAnalysis_Surface::get_type_name, "None");
cls_ShapeAnalysis_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAnalysis_Surface::get_type_descriptor, "None");
cls_ShapeAnalysis_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAnalysis_Surface::*)() const) &ShapeAnalysis_Surface::DynamicType, "None");

// Enums

}