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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Shape.hxx>
#include <Geom2d_Curve.hxx>
#include <BOPTools_AlgoTools3D.hxx>

void bind_BOPTools_AlgoTools3D(py::module &mod){

py::class_<BOPTools_AlgoTools3D, std::unique_ptr<BOPTools_AlgoTools3D, Deleter<BOPTools_AlgoTools3D>>> cls_BOPTools_AlgoTools3D(mod, "BOPTools_AlgoTools3D", "The class contains handy static functions dealing with the topology This is the copy of BOPTools_AlgoTools3D.cdl file");

// Constructors

// Fields

// Methods
// cls_BOPTools_AlgoTools3D.def_static("operator new_", (void * (*)(size_t)) &BOPTools_AlgoTools3D::operator new, "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete_", (void (*)(void *)) &BOPTools_AlgoTools3D::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_AlgoTools3D::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_AlgoTools3D::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_AlgoTools3D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_AlgoTools3D.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_AlgoTools3D::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_AlgoTools3D.def_static("DoSplitSEAMOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BOPTools_AlgoTools3D::DoSplitSEAMOnFace, "Make the edge <aSp> seam edge for the face <aF>", py::arg("aSp"), py::arg("aF"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, const Standard_Real a2, gp_Dir & a3) -> void { return BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(a0, a1, a2, a3); });
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetNormalToFaceOnEdge, "Computes normal to the face <aF> for the point on the edge <aE> at parameter <aT>. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1, gp_Dir & a2) -> void { return BOPTools_AlgoTools3D::GetNormalToFaceOnEdge(a0, a1, a2); });
cls_BOPTools_AlgoTools3D.def_static("GetNormalToFaceOnEdge_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetNormalToFaceOnEdge, "Computes normal to the face <aF> for the point on the edge <aE> at arbitrary intermediate parameter. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("SenseFlag_", (Standard_Integer (*)(const gp_Dir &, const gp_Dir &)) &BOPTools_AlgoTools3D::SenseFlag, "Returns 1 if scalar product aNF1* aNF2>0. Returns 0 if directions aNF1 aNF2 coincide Returns -1 if scalar product aNF1* aNF2<0.", py::arg("aNF1"), py::arg("aNF2"));
cls_BOPTools_AlgoTools3D.def_static("GetNormalToSurface_", (Standard_Boolean (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, gp_Dir &)) &BOPTools_AlgoTools3D::GetNormalToSurface, "Compute normal <aD> to surface <aS> in point (U,V) Returns TRUE if directions aD1U, aD1V coincide", py::arg("aS"), py::arg("U"), py::arg("V"), py::arg("aD"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function, with the shifting value BOPTools_AlgoTools3D::MinStepIn2d(), from the edge, but if this value is too big, the point will be computed using Hatcher (PointInFace function). Returns TRUE in case of success.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aPx"), py::arg("aD"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt &, gp_Dir &, const Standard_Real)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function with the shifting value <aDt2D> from the edge; No checks on this value will be done. Returns TRUE in case of success.", py::arg("theE"), py::arg("theF"), py::arg("aT"), py::arg("aP"), py::arg("aDNF"), py::arg("aDt2D"));
cls_BOPTools_AlgoTools3D.def_static("GetApproxNormalToFaceOnEdge_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Dir &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::GetApproxNormalToFaceOnEdge, "Computes normal to the face <aF> for the 3D-point that belongs to the edge <aE> at parameter <aT>. Output: aPx - the 3D-point where the normal computed aD - the normal; Warning: The normal is computed not exactly in the point on the edge, but in point that is near to the edge towards to the face material (so, we'll have approx. normal); The point is computed using PointNearEdge function with the shifting value <aDt2D> from the edge, but if this value is too big the point will be computed using Hatcher (PointInFace function). Returns TRUE in case of success.", py::arg("theE"), py::arg("theF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP"), py::arg("aDNF"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is <aDt2D> If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Real, gp_Pnt2d &, gp_Pnt &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is <aDt2D>. No checks on this value will be done. Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aDt2D"), py::arg("aP2D"), py::arg("aPx"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Computes the point <aPx>, (<aP2D>) that is near to the edge <aE> at parameter <aT> towards to the material of the face <aF>. The value of shifting in 2D is dt2D=BOPTools_AlgoTools3D::MinStepIn2d() If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointNearEdge_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Face &, gp_Pnt2d &, gp_Pnt &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointNearEdge, "Compute the point <aPx>, (<aP2D>) that is near to the edge <aE> at arbitrary parameter towards to the material of the face <aF>. The value of shifting in 2D is dt2D=BOPTools_AlgoTools3D::MinStepIn2d(). If the value of shifting is too big the point will be computed using Hatcher (PointInFace function). Returns error status: 0 - in case of success; 1 - <aE> does not have 2d curve on the face <aF>; 2 - the computed point is out of the face.", py::arg("aE"), py::arg("aF"), py::arg("aP2D"), py::arg("aPx"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("MinStepIn2d_", (Standard_Real (*)()) &BOPTools_AlgoTools3D::MinStepIn2d, "Returns simple step value that is used in 2D-computations = 1.e-5");
cls_BOPTools_AlgoTools3D.def_static("IsEmptyShape_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BOPTools_AlgoTools3D::IsEmptyShape, "Returns TRUE if the shape <aS> does not contain geometry information (e.g. empty compound)", py::arg("aS"));
cls_BOPTools_AlgoTools3D.def_static("OrientEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, TopoDS_Edge &)) &BOPTools_AlgoTools3D::OrientEdgeOnFace, "Get the edge <aER> from the face <aF> that is the same as the edge <aE>", py::arg("aE"), py::arg("aF"), py::arg("aER"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointInFace, "Computes arbitrary point <theP> inside the face <theF>. <theP2D> - 2D representation of <theP> on the surface of <theF> Returns 0 in case of success.", py::arg("theF"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, const TopoDS_Edge &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools3D::PointInFace, "Computes a point <theP> inside the face <theF> using starting point taken by the parameter <theT> from the 2d curve of the edge <theE> on the face <theF> in the direction perpendicular to the tangent vector of the 2d curve of the edge. The point will be distanced on <theDt2D> from the 2d curve. <theP2D> - 2D representation of <theP> on the surface of <theF> Returns 0 in case of success.", py::arg("theF"), py::arg("theE"), py::arg("theT"), py::arg("theDt2D"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"));
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", [](const TopoDS_Face & a0, const opencascade::handle<Geom2d_Curve> & a1, gp_Pnt & a2, gp_Pnt2d & a3, const opencascade::handle<IntTools_Context> & a4) -> Standard_Integer { return BOPTools_AlgoTools3D::PointInFace(a0, a1, a2, a3, a4); });
cls_BOPTools_AlgoTools3D.def_static("PointInFace_", (Standard_Integer (*)(const TopoDS_Face &, const opencascade::handle<Geom2d_Curve> &, gp_Pnt &, gp_Pnt2d &, const opencascade::handle<IntTools_Context> &, const Standard_Real)) &BOPTools_AlgoTools3D::PointInFace, "Computes a point <theP> inside the face <theF> using the line <theL> so that 2D point <theP2D>, 2D representation of <theP> on the surface of <theF>, lies on that line. Returns 0 in case of success.", py::arg("theF"), py::arg("theL"), py::arg("theP"), py::arg("theP2D"), py::arg("theContext"), py::arg("theDt2D"));

// Enums

}