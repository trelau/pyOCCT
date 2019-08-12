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
#include <ShapeCustom_Modification.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeCustom_RestrictionParameters.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <ShapeCustom_BSplineRestriction.hxx>
#include <Standard_Type.hxx>

void bind_ShapeCustom_BSplineRestriction(py::module &mod){

py::class_<ShapeCustom_BSplineRestriction, opencascade::handle<ShapeCustom_BSplineRestriction>, ShapeCustom_Modification> cls_ShapeCustom_BSplineRestriction(mod, "ShapeCustom_BSplineRestriction", "this tool intended for aproximation surfaces, curves and pcurves with specified degree , max number of segments, tolerance 2d, tolerance 3d. Specified continuity can be reduced if approximation with specified continuity was not done.");

// Constructors
cls_ShapeCustom_BSplineRestriction.def(py::init<>());
cls_ShapeCustom_BSplineRestriction.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("anApproxSurfaceFlag"), py::arg("anApproxCurve3dFlag"), py::arg("anApproxCurve2dFlag"), py::arg("aTol3d"), py::arg("aTol2d"), py::arg("aContinuity3d"), py::arg("aContinuity2d"), py::arg("aMaxDegree"), py::arg("aNbMaxSeg"), py::arg("Degree"), py::arg("Rational"));
cls_ShapeCustom_BSplineRestriction.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<ShapeCustom_RestrictionParameters> &>(), py::arg("anApproxSurfaceFlag"), py::arg("anApproxCurve3dFlag"), py::arg("anApproxCurve2dFlag"), py::arg("aTol3d"), py::arg("aTol2d"), py::arg("aContinuity3d"), py::arg("aContinuity2d"), py::arg("aMaxDegree"), py::arg("aNbMaxSeg"), py::arg("Degree"), py::arg("Rational"), py::arg("aModes"));

// Fields

// Methods
cls_ShapeCustom_BSplineRestriction.def("NewSurface", [](ShapeCustom_BSplineRestriction &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_BSplineRestriction.def("NewCurve", [](ShapeCustom_BSplineRestriction &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if curve from the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_True if Surface is modified or one of pcurves of edge is modified. In this case C is copy of geometric support of the edge. In other cases returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_BSplineRestriction.def("NewCurve2d", [](ShapeCustom_BSplineRestriction &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case,if curve on the surface is modified, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. If curve on the surface is not modified C is copy curve on surface from the edge <E>.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_BSplineRestriction.def("ConvertSurface", [](ShapeCustom_BSplineRestriction &self, const opencascade::handle<Geom_Surface> & a0, opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> Standard_Boolean { return self.ConvertSurface(a0, a1, a2, a3, a4, a5); });
cls_ShapeCustom_BSplineRestriction.def("ConvertSurface", (Standard_Boolean (ShapeCustom_BSplineRestriction::*)(const opencascade::handle<Geom_Surface> &, opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &ShapeCustom_BSplineRestriction::ConvertSurface, "Returns Standard_True if the surface has been modified. if flag IsOf equals Standard_True Offset surfaces are aproximated to Offset if Standard_False to BSpline", py::arg("aSurface"), py::arg("S"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"), py::arg("IsOf"));
cls_ShapeCustom_BSplineRestriction.def("ConvertCurve", [](ShapeCustom_BSplineRestriction &self, const opencascade::handle<Geom_Curve> & aCurve, opencascade::handle<Geom_Curve> & C, const Standard_Boolean IsConvert, const Standard_Real First, const Standard_Real Last, Standard_Real & TolCur, const Standard_Boolean IsOf){ Standard_Boolean rv = self.ConvertCurve(aCurve, C, IsConvert, First, Last, TolCur, IsOf); return std::tuple<Standard_Boolean, Standard_Real &>(rv, TolCur); }, "Returns Standard_True if the curve has been modified. if flag IsOf equals Standard_True Offset curves are aproximated to Offset if Standard_False to BSpline", py::arg("aCurve"), py::arg("C"), py::arg("IsConvert"), py::arg("First"), py::arg("Last"), py::arg("TolCur"), py::arg("IsOf"));
cls_ShapeCustom_BSplineRestriction.def("ConvertCurve2d", [](ShapeCustom_BSplineRestriction &self, const opencascade::handle<Geom2d_Curve> & aCurve, opencascade::handle<Geom2d_Curve> & C, const Standard_Boolean IsConvert, const Standard_Real First, const Standard_Real Last, Standard_Real & TolCur, const Standard_Boolean IsOf){ Standard_Boolean rv = self.ConvertCurve2d(aCurve, C, IsConvert, First, Last, TolCur, IsOf); return std::tuple<Standard_Boolean, Standard_Real &>(rv, TolCur); }, "Returns Standard_True if the pcurve has been modified. if flag IsOf equals Standard_True Offset pcurves are aproximated to Offset if Standard_False to BSpline", py::arg("aCurve"), py::arg("C"), py::arg("IsConvert"), py::arg("First"), py::arg("Last"), py::arg("TolCur"), py::arg("IsOf"));
cls_ShapeCustom_BSplineRestriction.def("SetTol3d", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Real)) &ShapeCustom_BSplineRestriction::SetTol3d, "Sets tolerance of aproximation for curve3d and surface", py::arg("Tol3d"));
cls_ShapeCustom_BSplineRestriction.def("SetTol2d", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Real)) &ShapeCustom_BSplineRestriction::SetTol2d, "Sets tolerance of aproximation for curve2d", py::arg("Tol2d"));
cls_ShapeCustom_BSplineRestriction.def("ModifyApproxSurfaceFlag", (Standard_Boolean & (ShapeCustom_BSplineRestriction::*)()) &ShapeCustom_BSplineRestriction::ModifyApproxSurfaceFlag, "Returns (modifiable) the flag which defines whether the surface is aproximated.");
cls_ShapeCustom_BSplineRestriction.def("ModifyApproxCurve3dFlag", (Standard_Boolean & (ShapeCustom_BSplineRestriction::*)()) &ShapeCustom_BSplineRestriction::ModifyApproxCurve3dFlag, "Returns (modifiable) the flag which defines whether the curve3d is aproximated.");
cls_ShapeCustom_BSplineRestriction.def("ModifyApproxCurve2dFlag", (Standard_Boolean & (ShapeCustom_BSplineRestriction::*)()) &ShapeCustom_BSplineRestriction::ModifyApproxCurve2dFlag, "Returns (modifiable) the flag which defines whether the curve2d is aproximated.");
cls_ShapeCustom_BSplineRestriction.def("SetContinuity3d", (void (ShapeCustom_BSplineRestriction::*)(const GeomAbs_Shape)) &ShapeCustom_BSplineRestriction::SetContinuity3d, "Sets continuity3d for aproximation curve3d and surface.", py::arg("Continuity3d"));
cls_ShapeCustom_BSplineRestriction.def("SetContinuity2d", (void (ShapeCustom_BSplineRestriction::*)(const GeomAbs_Shape)) &ShapeCustom_BSplineRestriction::SetContinuity2d, "Sets continuity3d for aproximation curve2d.", py::arg("Continuity2d"));
cls_ShapeCustom_BSplineRestriction.def("SetMaxDegree", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Integer)) &ShapeCustom_BSplineRestriction::SetMaxDegree, "Sets max degree for aproximation.", py::arg("MaxDegree"));
cls_ShapeCustom_BSplineRestriction.def("SetMaxNbSegments", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Integer)) &ShapeCustom_BSplineRestriction::SetMaxNbSegments, "Sets max number of segments for aproximation.", py::arg("MaxNbSegments"));
cls_ShapeCustom_BSplineRestriction.def("SetPriority", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Boolean)) &ShapeCustom_BSplineRestriction::SetPriority, "Sets priority for aproximation curves and surface. If Degree is True approximation is made with degree less then specified MaxDegree at the expense of number of spanes. If Degree is False approximation is made with number of spans less then specified MaxNbSegment at the expense of specified MaxDegree.", py::arg("Degree"));
cls_ShapeCustom_BSplineRestriction.def("SetConvRational", (void (ShapeCustom_BSplineRestriction::*)(const Standard_Boolean)) &ShapeCustom_BSplineRestriction::SetConvRational, "Sets flag for define if rational BSpline or Bezier is converted to polynomial. If Rational is True approximation for rational BSpline and Bezier is made to polynomial even if degree is less then MaxDegree and number of spans is less then specified MaxNbSegment.", py::arg("Rational"));
cls_ShapeCustom_BSplineRestriction.def("GetRestrictionParameters", (opencascade::handle<ShapeCustom_RestrictionParameters> (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::GetRestrictionParameters, "Returns the container of modes which defines what geometry should be converted to BSplines.");
cls_ShapeCustom_BSplineRestriction.def("SetRestrictionParameters", (void (ShapeCustom_BSplineRestriction::*)(const opencascade::handle<ShapeCustom_RestrictionParameters> &)) &ShapeCustom_BSplineRestriction::SetRestrictionParameters, "Sets the container of modes which defines what geometry should be converted to BSplines.", py::arg("aModes"));
cls_ShapeCustom_BSplineRestriction.def("Curve3dError", (Standard_Real (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::Curve3dError, "Returns error for aproximation curve3d.");
cls_ShapeCustom_BSplineRestriction.def("Curve2dError", (Standard_Real (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::Curve2dError, "Returns error for aproximation curve2d.");
cls_ShapeCustom_BSplineRestriction.def("SurfaceError", (Standard_Real (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::SurfaceError, "Returns error for aproximation surface.");
cls_ShapeCustom_BSplineRestriction.def("NewPoint", [](ShapeCustom_BSplineRestriction &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "None", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_BSplineRestriction.def("NewParameter", [](ShapeCustom_BSplineRestriction &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "None", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_BSplineRestriction.def("Continuity", (GeomAbs_Shape (ShapeCustom_BSplineRestriction::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeCustom_BSplineRestriction::Continuity, "None", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_ShapeCustom_BSplineRestriction.def("MaxErrors", [](ShapeCustom_BSplineRestriction &self, Standard_Real & aCurve3dErr, Standard_Real & aCurve2dErr){ Standard_Real rv = self.MaxErrors(aCurve3dErr, aCurve2dErr); return std::tuple<Standard_Real, Standard_Real &, Standard_Real &>(rv, aCurve3dErr, aCurve2dErr); }, "Returns error for aproximation surface, curve3d and curve2d.", py::arg("aCurve3dErr"), py::arg("aCurve2dErr"));
cls_ShapeCustom_BSplineRestriction.def("NbOfSpan", (Standard_Integer (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::NbOfSpan, "Returns number for aproximation surface, curve3d and curve2d.");
cls_ShapeCustom_BSplineRestriction.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_BSplineRestriction::get_type_name, "None");
cls_ShapeCustom_BSplineRestriction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_BSplineRestriction::get_type_descriptor, "None");
cls_ShapeCustom_BSplineRestriction.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_BSplineRestriction::*)() const) &ShapeCustom_BSplineRestriction::DynamicType, "None");

// Enums

}