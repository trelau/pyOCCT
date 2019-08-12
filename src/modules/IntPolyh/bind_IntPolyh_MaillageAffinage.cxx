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
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntPolyh_ArrayOfPointNormal.hxx>
#include <Bnd_Box.hxx>
#include <IntPolyh_Point.hxx>
#include <IntPolyh_Triangle.hxx>
#include <IntPolyh_StartPoint.hxx>
#include <IntPolyh_ArrayOfSectionLines.hxx>
#include <IntPolyh_ArrayOfTangentZones.hxx>
#include <IntPolyh_SectionLine.hxx>
#include <IntPolyh_ArrayOfPoints.hxx>
#include <IntPolyh_ArrayOfEdges.hxx>
#include <IntPolyh_ArrayOfTriangles.hxx>
#include <IntPolyh_ListOfCouples.hxx>
#include <IntPolyh_MaillageAffinage.hxx>

void bind_IntPolyh_MaillageAffinage(py::module &mod){

py::class_<IntPolyh_MaillageAffinage, std::unique_ptr<IntPolyh_MaillageAffinage, Deleter<IntPolyh_MaillageAffinage>>> cls_IntPolyh_MaillageAffinage(mod, "IntPolyh_MaillageAffinage", "Low-level algorithm to compute intersection of the surfaces by computing the intersection of their triangulations.");

// Constructors
cls_IntPolyh_MaillageAffinage.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S1"), py::arg("NbSU1"), py::arg("NbSV1"), py::arg("S2"), py::arg("NbSU2"), py::arg("NbSV2"), py::arg("PRINT"));
cls_IntPolyh_MaillageAffinage.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer>(), py::arg("S1"), py::arg("S2"), py::arg("PRINT"));

// Fields

// Methods
// cls_IntPolyh_MaillageAffinage.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_MaillageAffinage::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_MaillageAffinage.def_static("operator delete_", (void (*)(void *)) &IntPolyh_MaillageAffinage::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_MaillageAffinage.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_MaillageAffinage::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_MaillageAffinage.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_MaillageAffinage::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_MaillageAffinage.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_MaillageAffinage::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_MaillageAffinage.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_MaillageAffinage::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_MaillageAffinage.def("MakeSampling", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &IntPolyh_MaillageAffinage::MakeSampling, "Makes the sampling of the surface - Fills the arrays with the parametric values of the sampling points (triangulation nodes).", py::arg("SurfID"), py::arg("theUPars"), py::arg("theVPars"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "Computes points on one surface and fills an array of points; standard (default) method", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Boolean)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "isShiftFwd flag is added. The purpose is to define shift of points along normal to the surface in this point. The shift length represents maximal deflection of triangulation. The direction (forward or reversed regarding to normal direction) is defined by isShiftFwd flag. Compute points on one surface and fill an array of points; advanced method", py::arg("SurfID"), py::arg("isShiftFwd"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", [](IntPolyh_MaillageAffinage &self, const Standard_Integer a0, const TColStd_Array1OfReal & a1, const TColStd_Array1OfReal & a2) -> void { return self.FillArrayOfPnt(a0, a1, a2); });
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const Standard_Real *)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "Compute points on one surface and fill an array of points; If given, <theDeflTol> is the deflection tolerance of the given sampling. standard (default) method", py::arg("SurfID"), py::arg("Upars"), py::arg("Vpars"), py::arg("theDeflTol"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", [](IntPolyh_MaillageAffinage &self, const Standard_Integer a0, const Standard_Boolean a1, const TColStd_Array1OfReal & a2, const TColStd_Array1OfReal & a3) -> void { return self.FillArrayOfPnt(a0, a1, a2, a3); });
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Boolean, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const Standard_Real *)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "isShiftFwd flag is added. The purpose is to define shift of points along normal to the surface in this point. The shift length represents maximal deflection of triangulation. The direction (forward or reversed regarding to normal direction) is defined by isShiftFwd flag. Compute points on one surface and fill an array of points; If given, <theDeflTol> is the deflection tolerance of the given sampling. advanced method", py::arg("SurfID"), py::arg("isShiftFwd"), py::arg("Upars"), py::arg("Vpars"), py::arg("theDeflTol"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfPnt", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Boolean, const IntPolyh_ArrayOfPointNormal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const Standard_Real)) &IntPolyh_MaillageAffinage::FillArrayOfPnt, "Fills the array of points for the surface taking into account the shift", py::arg("SurfID"), py::arg("isShiftFwd"), py::arg("thePoints"), py::arg("theUPars"), py::arg("theVPars"), py::arg("theDeflTol"));
cls_IntPolyh_MaillageAffinage.def("CommonBox", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::CommonBox, "Looks for the common box of the surfaces and marks the points of the surfaces inside that common box for possible intersection");
cls_IntPolyh_MaillageAffinage.def("CommonBox", [](IntPolyh_MaillageAffinage &self, const Bnd_Box & B1, const Bnd_Box & B2, Standard_Real & xMin, Standard_Real & yMin, Standard_Real & zMin, Standard_Real & xMax, Standard_Real & yMax, Standard_Real & zMax){ self.CommonBox(B1, B2, xMin, yMin, zMin, xMax, yMax, zMax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xMin, yMin, zMin, xMax, yMax, zMax); }, "Compute the common box witch is the intersection of the two bounding boxes, and mark the points of the two surfaces that are inside.", py::arg("B1"), py::arg("B2"), py::arg("xMin"), py::arg("yMin"), py::arg("zMin"), py::arg("xMax"), py::arg("yMax"), py::arg("zMax"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfEdges", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfEdges, "Compute edges from the array of points", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("FillArrayOfTriangles", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::FillArrayOfTriangles, "Compute triangles from the array of points, and -- mark the triangles that use marked points by the CommonBox function.", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("CommonPartRefinement", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::CommonPartRefinement, "Refine systematicaly all marked triangles of both surfaces");
cls_IntPolyh_MaillageAffinage.def("LocalSurfaceRefinement", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::LocalSurfaceRefinement, "Refine systematicaly all marked triangles of ONE surface", py::arg("SurfId"));
cls_IntPolyh_MaillageAffinage.def("ComputeDeflections", (void (IntPolyh_MaillageAffinage::*)(const Standard_Integer)) &IntPolyh_MaillageAffinage::ComputeDeflections, "Compute deflection for all triangles of one surface,and sort min and max of deflections", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("TrianglesDeflectionsRefinementBSB", (void (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::TrianglesDeflectionsRefinementBSB, "Refine both surfaces using BoundSortBox as -- rejection. The criterions used to refine a -- triangle are: The deflection The size of the -- bounding boxes (one surface may be very small compared to the other)");
cls_IntPolyh_MaillageAffinage.def("TriContact", [](IntPolyh_MaillageAffinage &self, const IntPolyh_Point & P1, const IntPolyh_Point & P2, const IntPolyh_Point & P3, const IntPolyh_Point & Q1, const IntPolyh_Point & Q2, const IntPolyh_Point & Q3, Standard_Real & Angle){ Standard_Integer rv = self.TriContact(P1, P2, P3, Q1, Q2, Q3, Angle); return std::tuple<Standard_Integer, Standard_Real &>(rv, Angle); }, "This fonction Check if two triangles are in contact or no, return 1 if yes, return 0 if no.", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("Q1"), py::arg("Q2"), py::arg("Q3"), py::arg("Angle"));
cls_IntPolyh_MaillageAffinage.def("TriangleEdgeContact", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_Triangle &, const IntPolyh_Triangle &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, const IntPolyh_Point &, IntPolyh_StartPoint &, IntPolyh_StartPoint &) const) &IntPolyh_MaillageAffinage::TriangleEdgeContact, "None", py::arg("TriSurfID"), py::arg("EdgeIndice"), py::arg("Tri1"), py::arg("Tri2"), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Pe1"), py::arg("Pe2"), py::arg("E"), py::arg("N"), py::arg("SP1"), py::arg("SP2"));
cls_IntPolyh_MaillageAffinage.def("StartingPointsResearch", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, IntPolyh_StartPoint &, IntPolyh_StartPoint &) const) &IntPolyh_MaillageAffinage::StartingPointsResearch, "From two triangles compute intersection points. If I found more than two intersection points that's mean that those triangle are coplanar", py::arg("T1"), py::arg("T2"), py::arg("SP1"), py::arg("SP2"));
cls_IntPolyh_MaillageAffinage.def("NextStartingPointsResearch", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_StartPoint &, IntPolyh_StartPoint &) const) &IntPolyh_MaillageAffinage::NextStartingPointsResearch, "from two triangles and an intersection point I seach the other point (if it exist). This function is used by StartPointChain", py::arg("T1"), py::arg("T2"), py::arg("SPInit"), py::arg("SPNext"));
cls_IntPolyh_MaillageAffinage.def("TriangleCompare", (Standard_Integer (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::TriangleCompare, "Analyse each couple of triangles from the two -- array of triangles, to see if they are in contact, and compute the incidence. Then put couples in contact in the array of couples");
cls_IntPolyh_MaillageAffinage.def("StartPointsChain", (Standard_Integer (IntPolyh_MaillageAffinage::*)(IntPolyh_ArrayOfSectionLines &, IntPolyh_ArrayOfTangentZones &)) &IntPolyh_MaillageAffinage::StartPointsChain, "Loop on the array of couples. Compute StartPoints. Try to chain the StartPoints into SectionLines or put the point in the ArrayOfTangentZones if chaining it, is not possible.", py::arg("TSectionLines"), py::arg("TTangentZones"));
cls_IntPolyh_MaillageAffinage.def("GetNextChainStartPoint", [](IntPolyh_MaillageAffinage &self, const IntPolyh_StartPoint & a0, IntPolyh_StartPoint & a1, IntPolyh_SectionLine & a2, IntPolyh_ArrayOfTangentZones & a3) -> Standard_Integer { return self.GetNextChainStartPoint(a0, a1, a2, a3); });
cls_IntPolyh_MaillageAffinage.def("GetNextChainStartPoint", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const IntPolyh_StartPoint &, IntPolyh_StartPoint &, IntPolyh_SectionLine &, IntPolyh_ArrayOfTangentZones &, const Standard_Boolean)) &IntPolyh_MaillageAffinage::GetNextChainStartPoint, "Mainly used by StartPointsChain(), this function try to compute the next StartPoint.", py::arg("SPInit"), py::arg("SPNext"), py::arg("MySectionLine"), py::arg("TTangentZones"), py::arg("Prepend"));
cls_IntPolyh_MaillageAffinage.def("GetArrayOfPoints", (const IntPolyh_ArrayOfPoints & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetArrayOfPoints, "None", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("GetArrayOfEdges", (const IntPolyh_ArrayOfEdges & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetArrayOfEdges, "None", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("GetArrayOfTriangles", (const IntPolyh_ArrayOfTriangles & (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetArrayOfTriangles, "None", py::arg("SurfID"));
// cls_IntPolyh_MaillageAffinage.def("GetFinTE", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetFinTE, "None", py::arg("SurfID"));
// cls_IntPolyh_MaillageAffinage.def("GetFinTT", (Standard_Integer (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetFinTT, "None", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("GetBox", (Bnd_Box (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetBox, "None", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("GetCouples", (IntPolyh_ListOfCouples & (IntPolyh_MaillageAffinage::*)()) &IntPolyh_MaillageAffinage::GetCouples, "This method returns list of couples of contact triangles.");
cls_IntPolyh_MaillageAffinage.def("SetEnlargeZone", (void (IntPolyh_MaillageAffinage::*)(const Standard_Boolean)) &IntPolyh_MaillageAffinage::SetEnlargeZone, "None", py::arg("EnlargeZone"));
cls_IntPolyh_MaillageAffinage.def("GetEnlargeZone", (Standard_Boolean (IntPolyh_MaillageAffinage::*)() const) &IntPolyh_MaillageAffinage::GetEnlargeZone, "None");
cls_IntPolyh_MaillageAffinage.def("GetMinDeflection", (Standard_Real (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetMinDeflection, "returns FlecheMin", py::arg("SurfID"));
cls_IntPolyh_MaillageAffinage.def("GetMaxDeflection", (Standard_Real (IntPolyh_MaillageAffinage::*)(const Standard_Integer) const) &IntPolyh_MaillageAffinage::GetMaxDeflection, "returns FlecheMax", py::arg("SurfID"));

// Enums

}