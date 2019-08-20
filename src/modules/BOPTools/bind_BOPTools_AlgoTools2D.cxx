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
#include <Standard_Handle.hxx>
#include <IntTools_Context.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BOPTools_AlgoTools2D.hxx>

void bind_BOPTools_AlgoTools2D(py::module &mod){

py::class_<BOPTools_AlgoTools2D, std::unique_ptr<BOPTools_AlgoTools2D>> cls_BOPTools_AlgoTools2D(mod, "BOPTools_AlgoTools2D", "The class contains handy static functions dealing with the topology This is the copy of the BOPTools_AlgoTools2D.cdl");

// Constructors

// Fields

// Methods
// cls_BOPTools_AlgoTools2D.def_static("operator new_", (void * (*)(size_t)) &BOPTools_AlgoTools2D::operator new, "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete_", (void (*)(void *)) &BOPTools_AlgoTools2D::operator delete, "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator new[]_", (void * (*)(size_t)) &BOPTools_AlgoTools2D::operator new[], "None", py::arg("theSize"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete[]_", (void (*)(void *)) &BOPTools_AlgoTools2D::operator delete[], "None", py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator new_", (void * (*)(size_t, void *)) &BOPTools_AlgoTools2D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPTools_AlgoTools2D.def_static("operator delete_", (void (*)(void *, void *)) &BOPTools_AlgoTools2D::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPTools_AlgoTools2D.def_static("BuildPCurveForEdgeOnFace_", [](const TopoDS_Edge & a0, const TopoDS_Face & a1) -> void { return BOPTools_AlgoTools2D::BuildPCurveForEdgeOnFace(a0, a1); });
cls_BOPTools_AlgoTools2D.def_static("BuildPCurveForEdgeOnFace_", (void (*)(const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::BuildPCurveForEdgeOnFace, "Compute P-Curve for the edge <aE> on the face <aF>. Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("EdgeTangent_", (Standard_Boolean (*)(const TopoDS_Edge &, const Standard_Real, gp_Vec &)) &BOPTools_AlgoTools2D::EdgeTangent, "Compute tangent for the edge <aE> [in 3D] at parameter <aT>", py::arg("anE"), py::arg("aT"), py::arg("Tau"));
cls_BOPTools_AlgoTools2D.def_static("PointOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, const Standard_Real aT, Standard_Real & U, Standard_Real & V, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::PointOnSurface(aE, aF, aT, U, V, theContext); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Compute surface parameters <U,V> of the face <aF> for the point from the edge <aE> at parameter <aT>. If <aE> has't pcurve on surface, algorithm tries to get it by projection and can raise exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aT"), py::arg("U"), py::arg("V"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("CurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::CurveOnSurface(aE, aF, aC, aToler, theContext); return aToler; }, "Get P-Curve <aC> for the edge <aE> on surface <aF> . If the P-Curve does not exist, build it using Make2D(). [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm Make2D() fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("CurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::CurveOnSurface(aE, aF, aC, aFirst, aLast, aToler, theContext); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(aFirst, aLast, aToler); }, "Get P-Curve <aC> for the edge <aE> on surface <aF> . If the P-Curve does not exist, build it using Make2D(). [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm Make2D() fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("HasCurveOnSurface_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler){ Standard_Boolean rv = BOPTools_AlgoTools2D::HasCurveOnSurface(aE, aF, aC, aFirst, aLast, aToler); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, aFirst, aLast, aToler); }, "Returns TRUE if the edge <aE> has P-Curve <aC> on surface <aF> . [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance If the P-Curve does not exist, aC.IsNull()=TRUE.", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"));
cls_BOPTools_AlgoTools2D.def_static("HasCurveOnSurface_", (Standard_Boolean (*)(const TopoDS_Edge &, const TopoDS_Face &)) &BOPTools_AlgoTools2D::HasCurveOnSurface, "Returns TRUE if the edge <aE> has P-Curve <aC> on surface <aF> . If the P-Curve does not exist, aC.IsNull()=TRUE.", py::arg("aE"), py::arg("aF"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", [](const TopoDS_Face & a0, const opencascade::handle<Geom_Curve> & a1, const opencascade::handle<Geom2d_Curve> & a2, opencascade::handle<Geom2d_Curve> & a3) -> void { return BOPTools_AlgoTools2D::AdjustPCurveOnFace(a0, a1, a2, a3); });
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", (void (*)(const TopoDS_Face &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnFace, "Adjust P-Curve <theC2D> (3D-curve <theC3D>) on surface of the face <theF>. <theContext> - storage for caching the geometrical tools", py::arg("theF"), py::arg("theC3D"), py::arg("theC2D"), py::arg("theC2DA"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", [](const TopoDS_Face & a0, const Standard_Real a1, const Standard_Real a2, const opencascade::handle<Geom2d_Curve> & a3, opencascade::handle<Geom2d_Curve> & a4) -> void { return BOPTools_AlgoTools2D::AdjustPCurveOnFace(a0, a1, a2, a3, a4); });
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnFace_", (void (*)(const TopoDS_Face &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnFace, "Adjust P-Curve <aC2D> (3D-curve <C3D>) on surface <aF> . [aT1, aT2] - range to adjust <theContext> - storage for caching the geometrical tools", py::arg("theF"), py::arg("theFirst"), py::arg("theLast"), py::arg("theC2D"), py::arg("theC2DA"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AdjustPCurveOnSurf_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &)) &BOPTools_AlgoTools2D::AdjustPCurveOnSurf, "Adjust P-Curve <aC2D> (3D-curve <C3D>) on surface <aF> . [aT1, aT2] - range to adjust", py::arg("aF"), py::arg("aT1"), py::arg("aT2"), py::arg("aC2D"), py::arg("aC2DA"));
cls_BOPTools_AlgoTools2D.def_static("IntermediatePoint_", (Standard_Real (*)(const Standard_Real, const Standard_Real)) &BOPTools_AlgoTools2D::IntermediatePoint, "Compute intermediate value in between [aFirst, aLast] .", py::arg("aFirst"), py::arg("aLast"));
cls_BOPTools_AlgoTools2D.def_static("IntermediatePoint_", (Standard_Real (*)(const TopoDS_Edge &)) &BOPTools_AlgoTools2D::IntermediatePoint, "Compute intermediate value of parameter for the edge <anE>.", py::arg("anE"));
cls_BOPTools_AlgoTools2D.def_static("Make2D_", [](const TopoDS_Edge & aE, const TopoDS_Face & aF, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aFirst, Standard_Real & aLast, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::Make2D(aE, aF, aC, aFirst, aLast, aToler, theContext); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(aFirst, aLast, aToler); }, "Make P-Curve <aC> for the edge <aE> on surface <aF> . [aFirst, aLast] - range of the P-Curve [aToler] - reached tolerance Raises exception Standard_ConstructionError if algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aE"), py::arg("aF"), py::arg("aC"), py::arg("aFirst"), py::arg("aLast"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("MakePCurveOnFace_", [](const TopoDS_Face & aF, const opencascade::handle<Geom_Curve> & C3D, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::MakePCurveOnFace(aF, C3D, aC, aToler, theContext); return aToler; }, "Make P-Curve <aC> for the 3D-curve <C3D> on surface <aF> . [aToler] - reached tolerance Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aF"), py::arg("C3D"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("MakePCurveOnFace_", [](const TopoDS_Face & aF, const opencascade::handle<Geom_Curve> & C3D, const Standard_Real aT1, const Standard_Real aT2, opencascade::handle<Geom2d_Curve> & aC, Standard_Real & aToler, const opencascade::handle<IntTools_Context> & theContext){ BOPTools_AlgoTools2D::MakePCurveOnFace(aF, C3D, aT1, aT2, aC, aToler, theContext); return aToler; }, "Make P-Curve <aC> for the 3D-curve <C3D> on surface <aF> . [aT1, aT2] - range to build [aToler] - reached tolerance Raises exception Standard_ConstructionError if projection algorithm fails. <theContext> - storage for caching the geometrical tools", py::arg("aF"), py::arg("C3D"), py::arg("aT1"), py::arg("aT2"), py::arg("aC"), py::arg("aToler"), py::arg("theContext"));
cls_BOPTools_AlgoTools2D.def_static("AttachExistingPCurve_", (Standard_Integer (*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &, const opencascade::handle<IntTools_Context> &)) &BOPTools_AlgoTools2D::AttachExistingPCurve, "Attach P-Curve from the edge <aEold> on surface <aF> to the edge <aEnew> Returns 0 in case of success", py::arg("aEold"), py::arg("aEnew"), py::arg("aF"), py::arg("aCtx"));
cls_BOPTools_AlgoTools2D.def_static("IsEdgeIsoline_", [](const TopoDS_Edge & theE, const TopoDS_Face & theF, Standard_Boolean & isTheUIso, Standard_Boolean & isTheVIso){ BOPTools_AlgoTools2D::IsEdgeIsoline(theE, theF, isTheUIso, isTheVIso); return std::tuple<Standard_Boolean &, Standard_Boolean &>(isTheUIso, isTheVIso); }, "Checks if CurveOnSurface of theE on theF matches with isoline of theF surface. Sets corresponding values for isTheUIso and isTheVIso variables. ATTENTION!!! This method is based on comparation between direction of surface (which theF is based on) iso-lines and the direction of the edge p-curve (on theF) in middle-point of the p-curve. This method should be used carefully (e.g. BRep_Tool::IsClosed(...) together) in order to avoid false classification some p-curves as isoline (e.g. circle on a plane).", py::arg("theE"), py::arg("theF"), py::arg("isTheUIso"), py::arg("isTheVIso"));

// Enums

}