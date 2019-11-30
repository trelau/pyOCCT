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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_Modification.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_Modifier.hxx>
#include <Message_ProgressIndicator.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeCustom_RestrictionParameters.hxx>
#include <ShapeCustom_Surface.hxx>
#include <ShapeCustom_Curve.hxx>
#include <ShapeCustom_Curve2d.hxx>
#include <ShapeCustom_Modification.hxx>
#include <ShapeCustom_DirectModification.hxx>
#include <ShapeCustom_TrsfModification.hxx>
#include <ShapeCustom_BSplineRestriction.hxx>
#include <ShapeCustom_ConvertToRevolution.hxx>
#include <ShapeCustom_SweptToElementary.hxx>
#include <ShapeCustom_ConvertToBSpline.hxx>
#include <ShapeCustom.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Geom2d_Line.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_Transient.hxx>
#include <BRepTools_TrsfModification.hxx>
#include <gp_Trsf.hxx>

PYBIND11_MODULE(ShapeCustom, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepTools");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Message");
py::module::import("OCCT.ShapeBuild");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.ShapeExtend");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");

// CLASS: SHAPECUSTOM
py::class_<ShapeCustom> cls_ShapeCustom(mod, "ShapeCustom", "This package is intended to convert geometrical objects and topological. The modifications of one geometrical object to another (one) geometrical object are provided. The supported modifications are the following: conversion of BSpline and Bezier surfaces to analytical form, conversion of indirect elementary surfaces (with left-handed coordinate systems) into direct ones, conversion of elementary surfaces to surfaces of revolution, conversion of surface of linear extrusion, revolution, offset surface to bspline, modification of parameterization, degree, number of segments of bspline surfaces, scale the shape.");

// Methods
// cls_ShapeCustom.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom.def_static("operator delete_", (void (*)(void *)) &ShapeCustom::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<BRepTools_Modification> & a1, TopTools_DataMapOfShapeShape & a2, BRepTools_Modifier & a3) -> TopoDS_Shape { return ShapeCustom::ApplyModifier(a0, a1, a2, a3); });
cls_ShapeCustom.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<BRepTools_Modification> & a1, TopTools_DataMapOfShapeShape & a2, BRepTools_Modifier & a3, const opencascade::handle<Message_ProgressIndicator> & a4) -> TopoDS_Shape { return ShapeCustom::ApplyModifier(a0, a1, a2, a3, a4); });
cls_ShapeCustom.def_static("ApplyModifier_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<BRepTools_Modification> &, TopTools_DataMapOfShapeShape &, BRepTools_Modifier &, const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeCustom::ApplyModifier, "Applies modifier to shape and checks sharing in the case assemblies.", py::arg("S"), py::arg("M"), py::arg("context"), py::arg("MD"), py::arg("aProgress"), py::arg("aReShape"));
cls_ShapeCustom.def_static("DirectFaces_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::DirectFaces, "Returns a new shape without indirect surfaces.", py::arg("S"));
cls_ShapeCustom.def_static("ScaleShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Real)) &ShapeCustom::ScaleShape, "Returns a new shape which is scaled original", py::arg("S"), py::arg("scale"));
cls_ShapeCustom.def_static("BSplineRestriction_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<ShapeCustom_RestrictionParameters> &)) &ShapeCustom::BSplineRestriction, "Returns a new shape with all surfaces, curves and pcurves which type is BSpline/Bezier or based on them converted having Degree less than <MaxDegree> or number of spans less than <NbMaxSegment> in dependence on parameter priority <Degree>. <GmaxDegree> and <GMaxSegments> are maximum possible degree and number of spans correspondingly. These values will be used in those cases when approximation with specified parameters is impossible and one of GmaxDegree or GMaxSegments is selected in dependence on priority. Note that even if approximation is impossible with <GMaxDegree> then number of spans can exceed specified <GMaxSegment> <Rational> specifies if to convert Rational BSpline/Bezier into polynomial B-Spline. If flags ConvOffSurf,ConvOffCurve3d,ConvOffCurve2d are Standard_True there are means that Offset surfaces , Offset curves 3d and Offset curves 2d are converted to BSPline correspondingly.", py::arg("S"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("MaxDegree"), py::arg("MaxNbSegment"), py::arg("Continuity3d"), py::arg("Continuity2d"), py::arg("Degree"), py::arg("Rational"), py::arg("aParameters"));
cls_ShapeCustom.def_static("ConvertToRevolution_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::ConvertToRevolution, "Returns a new shape with all elementary periodic surfaces converted to Geom_SurfaceOfRevolution", py::arg("S"));
cls_ShapeCustom.def_static("SweptToElementary_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::SweptToElementary, "Returns a new shape with all surfaces of revolution and linear extrusion convert to elementary periodic surfaces", py::arg("S"));
cls_ShapeCustom.def_static("ConvertToBSpline_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> TopoDS_Shape { return ShapeCustom::ConvertToBSpline(a0, a1, a2, a3); });
cls_ShapeCustom.def_static("ConvertToBSpline_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &ShapeCustom::ConvertToBSpline, "Returns a new shape with all surfaces of linear extrusion, revolution, offset, and planar surfaces converted according to flags to Geom_BSplineSurface (with same parameterisation).", py::arg("S"), py::arg("extrMode"), py::arg("revolMode"), py::arg("offsetMode"), py::arg("planeMode"));

// CLASS: SHAPECUSTOM_MODIFICATION
py::class_<ShapeCustom_Modification, opencascade::handle<ShapeCustom_Modification>, BRepTools_Modification> cls_ShapeCustom_Modification(mod, "ShapeCustom_Modification", "A base class of Modification's from ShapeCustom. Implements message sending mechanism.");

// Methods
cls_ShapeCustom_Modification.def("SetMsgRegistrator", (void (ShapeCustom_Modification::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeCustom_Modification::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeCustom_Modification.def("MsgRegistrator", (opencascade::handle<ShapeExtend_BasicMsgRegistrator> (ShapeCustom_Modification::*)() const) &ShapeCustom_Modification::MsgRegistrator, "Returns message registrator");
cls_ShapeCustom_Modification.def("SendMsg", [](ShapeCustom_Modification &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.SendMsg(a0, a1); });
cls_ShapeCustom_Modification.def("SendMsg", (void (ShapeCustom_Modification::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity) const) &ShapeCustom_Modification::SendMsg, "Sends a message to be attached to the shape. Calls corresponding message of message registrator.", py::arg("shape"), py::arg("message"), py::arg("gravity"));
cls_ShapeCustom_Modification.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_Modification::get_type_name, "None");
cls_ShapeCustom_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_Modification::get_type_descriptor, "None");
cls_ShapeCustom_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_Modification::*)() const) &ShapeCustom_Modification::DynamicType, "None");

// CLASS: SHAPECUSTOM_BSPLINERESTRICTION
py::class_<ShapeCustom_BSplineRestriction, opencascade::handle<ShapeCustom_BSplineRestriction>, ShapeCustom_Modification> cls_ShapeCustom_BSplineRestriction(mod, "ShapeCustom_BSplineRestriction", "this tool intended for aproximation surfaces, curves and pcurves with specified degree , max number of segments, tolerance 2d, tolerance 3d. Specified continuity can be reduced if approximation with specified continuity was not done.");

// Constructors
cls_ShapeCustom_BSplineRestriction.def(py::init<>());
cls_ShapeCustom_BSplineRestriction.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("anApproxSurfaceFlag"), py::arg("anApproxCurve3dFlag"), py::arg("anApproxCurve2dFlag"), py::arg("aTol3d"), py::arg("aTol2d"), py::arg("aContinuity3d"), py::arg("aContinuity2d"), py::arg("aMaxDegree"), py::arg("aNbMaxSeg"), py::arg("Degree"), py::arg("Rational"));
cls_ShapeCustom_BSplineRestriction.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<ShapeCustom_RestrictionParameters> &>(), py::arg("anApproxSurfaceFlag"), py::arg("anApproxCurve3dFlag"), py::arg("anApproxCurve2dFlag"), py::arg("aTol3d"), py::arg("aTol2d"), py::arg("aContinuity3d"), py::arg("aContinuity2d"), py::arg("aMaxDegree"), py::arg("aNbMaxSeg"), py::arg("Degree"), py::arg("Rational"), py::arg("aModes"));

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

// CLASS: SHAPECUSTOM_CONVERTTOBSPLINE
py::class_<ShapeCustom_ConvertToBSpline, opencascade::handle<ShapeCustom_ConvertToBSpline>, ShapeCustom_Modification> cls_ShapeCustom_ConvertToBSpline(mod, "ShapeCustom_ConvertToBSpline", "implement a modification for BRepTools Modifier algortihm. Converts Surface of Linear Exctrusion, Revolution and Offset surfaces into BSpline Surface according to flags.");

// Constructors
cls_ShapeCustom_ConvertToBSpline.def(py::init<>());

// Methods
cls_ShapeCustom_ConvertToBSpline.def("SetExtrusionMode", (void (ShapeCustom_ConvertToBSpline::*)(const Standard_Boolean)) &ShapeCustom_ConvertToBSpline::SetExtrusionMode, "Sets mode for convertion of Surfaces of Linear extrusion.", py::arg("extrMode"));
cls_ShapeCustom_ConvertToBSpline.def("SetRevolutionMode", (void (ShapeCustom_ConvertToBSpline::*)(const Standard_Boolean)) &ShapeCustom_ConvertToBSpline::SetRevolutionMode, "Sets mode for convertion of Surfaces of Revolution.", py::arg("revolMode"));
cls_ShapeCustom_ConvertToBSpline.def("SetOffsetMode", (void (ShapeCustom_ConvertToBSpline::*)(const Standard_Boolean)) &ShapeCustom_ConvertToBSpline::SetOffsetMode, "Sets mode for convertion of Offset surfaces.", py::arg("offsetMode"));
cls_ShapeCustom_ConvertToBSpline.def("SetPlaneMode", (void (ShapeCustom_ConvertToBSpline::*)(const Standard_Boolean)) &ShapeCustom_ConvertToBSpline::SetPlaneMode, "Sets mode for convertion of Plane surfaces.", py::arg("planeMode"));
cls_ShapeCustom_ConvertToBSpline.def("NewSurface", [](ShapeCustom_ConvertToBSpline &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <S>, <L>, <Tol> are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_ConvertToBSpline.def("NewCurve", [](ShapeCustom_ConvertToBSpline &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_ConvertToBSpline.def("NewPoint", [](ShapeCustom_ConvertToBSpline &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_ConvertToBSpline.def("NewCurve2d", [](ShapeCustom_ConvertToBSpline &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_ConvertToBSpline.def("NewParameter", [](ShapeCustom_ConvertToBSpline &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_ConvertToBSpline.def("Continuity", (GeomAbs_Shape (ShapeCustom_ConvertToBSpline::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeCustom_ConvertToBSpline::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_ShapeCustom_ConvertToBSpline.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_ConvertToBSpline::get_type_name, "None");
cls_ShapeCustom_ConvertToBSpline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_ConvertToBSpline::get_type_descriptor, "None");
cls_ShapeCustom_ConvertToBSpline.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_ConvertToBSpline::*)() const) &ShapeCustom_ConvertToBSpline::DynamicType, "None");

// CLASS: SHAPECUSTOM_CONVERTTOREVOLUTION
py::class_<ShapeCustom_ConvertToRevolution, opencascade::handle<ShapeCustom_ConvertToRevolution>, ShapeCustom_Modification> cls_ShapeCustom_ConvertToRevolution(mod, "ShapeCustom_ConvertToRevolution", "implements a modification for the BRepTools Modifier algortihm. Converts all elementary surfaces into surfaces of revolution.");

// Constructors
cls_ShapeCustom_ConvertToRevolution.def(py::init<>());

// Methods
cls_ShapeCustom_ConvertToRevolution.def("NewSurface", [](ShapeCustom_ConvertToRevolution &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <S>, <L>, <Tol> are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_ConvertToRevolution.def("NewCurve", [](ShapeCustom_ConvertToRevolution &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_ConvertToRevolution.def("NewPoint", [](ShapeCustom_ConvertToRevolution &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_ConvertToRevolution.def("NewCurve2d", [](ShapeCustom_ConvertToRevolution &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_ConvertToRevolution.def("NewParameter", [](ShapeCustom_ConvertToRevolution &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_ConvertToRevolution.def("Continuity", (GeomAbs_Shape (ShapeCustom_ConvertToRevolution::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeCustom_ConvertToRevolution::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_ShapeCustom_ConvertToRevolution.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_ConvertToRevolution::get_type_name, "None");
cls_ShapeCustom_ConvertToRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_ConvertToRevolution::get_type_descriptor, "None");
cls_ShapeCustom_ConvertToRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_ConvertToRevolution::*)() const) &ShapeCustom_ConvertToRevolution::DynamicType, "None");

// CLASS: SHAPECUSTOM_CURVE
py::class_<ShapeCustom_Curve> cls_ShapeCustom_Curve(mod, "ShapeCustom_Curve", "Converts BSpline curve to periodic");

// Constructors
cls_ShapeCustom_Curve.def(py::init<>());
cls_ShapeCustom_Curve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));

// Methods
// cls_ShapeCustom_Curve.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Curve::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Curve.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Curve::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Curve::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Curve.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Curve.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Curve.def("Init", (void (ShapeCustom_Curve::*)(const opencascade::handle<Geom_Curve> &)) &ShapeCustom_Curve::Init, "None", py::arg("C"));
cls_ShapeCustom_Curve.def("ConvertToPeriodic", [](ShapeCustom_Curve &self, const Standard_Boolean a0) -> opencascade::handle<Geom_Curve> { return self.ConvertToPeriodic(a0); });
cls_ShapeCustom_Curve.def("ConvertToPeriodic", (opencascade::handle<Geom_Curve> (ShapeCustom_Curve::*)(const Standard_Boolean, const Standard_Real)) &ShapeCustom_Curve::ConvertToPeriodic, "Tries to convert the Curve to the Periodic form Returns the resulting curve Works only if the Curve is BSpline and is closed with Precision::Confusion() Else, or in case of failure, returns a Null Handle", py::arg("substitute"), py::arg("preci"));

// CLASS: SHAPECUSTOM_CURVE2D
py::class_<ShapeCustom_Curve2d> cls_ShapeCustom_Curve2d(mod, "ShapeCustom_Curve2d", "Converts curve2d to analytical form with given precision or simpify curve2d.");

// Methods
// cls_ShapeCustom_Curve2d.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Curve2d::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Curve2d.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Curve2d::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Curve2d::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Curve2d.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Curve2d::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Curve2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Curve2d.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Curve2d::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Curve2d.def_static("IsLinear_", [](const TColgp_Array1OfPnt2d & thePoles, const Standard_Real theTolerance, Standard_Real & theDeviation){ Standard_Boolean rv = ShapeCustom_Curve2d::IsLinear(thePoles, theTolerance, theDeviation); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDeviation); }, "Check if poleses is in the plane with given precision Returns false if no.", py::arg("thePoles"), py::arg("theTolerance"), py::arg("theDeviation"));
cls_ShapeCustom_Curve2d.def_static("ConvertToLine2d_", [](const opencascade::handle<Geom2d_Curve> & theCurve, const Standard_Real theFirstIn, const Standard_Real theLastIn, const Standard_Real theTolerance, Standard_Real & theNewFirst, Standard_Real & theNewLast, Standard_Real & theDeviation){ opencascade::handle<Geom2d_Line> rv = ShapeCustom_Curve2d::ConvertToLine2d(theCurve, theFirstIn, theLastIn, theTolerance, theNewFirst, theNewLast, theDeviation); return std::tuple<opencascade::handle<Geom2d_Line>, Standard_Real &, Standard_Real &, Standard_Real &>(rv, theNewFirst, theNewLast, theDeviation); }, "Try to convert BSpline2d or Bezier2d to line 2d only if it is linear. Recalculate first and last parameters. Returns line2d or null curve2d.", py::arg("theCurve"), py::arg("theFirstIn"), py::arg("theLastIn"), py::arg("theTolerance"), py::arg("theNewFirst"), py::arg("theNewLast"), py::arg("theDeviation"));
cls_ShapeCustom_Curve2d.def_static("SimplifyBSpline2d_", (Standard_Boolean (*)(opencascade::handle<Geom2d_BSplineCurve> &, const Standard_Real)) &ShapeCustom_Curve2d::SimplifyBSpline2d, "Try to remove knots from bspline where local derivatives are the same. Remove knots with given precision. Returns false if Bsplien was not modified", py::arg("theBSpline2d"), py::arg("theTolerance"));

// CLASS: SHAPECUSTOM_DIRECTMODIFICATION
py::class_<ShapeCustom_DirectModification, opencascade::handle<ShapeCustom_DirectModification>, ShapeCustom_Modification> cls_ShapeCustom_DirectModification(mod, "ShapeCustom_DirectModification", "implements a modification for the BRepTools Modifier algortihm. Will redress indirect surfaces.");

// Constructors
cls_ShapeCustom_DirectModification.def(py::init<>());

// Methods
cls_ShapeCustom_DirectModification.def("NewSurface", [](ShapeCustom_DirectModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <S>, <L>, <Tol> are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_DirectModification.def("NewCurve", [](ShapeCustom_DirectModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_DirectModification.def("NewPoint", [](ShapeCustom_DirectModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_DirectModification.def("NewCurve2d", [](ShapeCustom_DirectModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_DirectModification.def("NewParameter", [](ShapeCustom_DirectModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_DirectModification.def("Continuity", (GeomAbs_Shape (ShapeCustom_DirectModification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeCustom_DirectModification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_ShapeCustom_DirectModification.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_DirectModification::get_type_name, "None");
cls_ShapeCustom_DirectModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_DirectModification::get_type_descriptor, "None");
cls_ShapeCustom_DirectModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_DirectModification::*)() const) &ShapeCustom_DirectModification::DynamicType, "None");

// CLASS: SHAPECUSTOM_RESTRICTIONPARAMETERS
py::class_<ShapeCustom_RestrictionParameters, opencascade::handle<ShapeCustom_RestrictionParameters>, Standard_Transient> cls_ShapeCustom_RestrictionParameters(mod, "ShapeCustom_RestrictionParameters", "This class is axuluary tool which contains parameters for BSplineRestriction class.");

// Constructors
cls_ShapeCustom_RestrictionParameters.def(py::init<>());

// Methods
cls_ShapeCustom_RestrictionParameters.def("GMaxDegree", (Standard_Integer & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::GMaxDegree, "Returns (modifiable) maximal degree of approximation.");
cls_ShapeCustom_RestrictionParameters.def("GMaxSeg", (Standard_Integer & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::GMaxSeg, "Returns (modifiable) maximal number of spans of approximation.");
cls_ShapeCustom_RestrictionParameters.def("ConvertPlane", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertPlane, "Sets flag for define if Plane converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertBezierSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertBezierSurf, "Sets flag for define if Bezier surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertRevolutionSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertRevolutionSurf, "Sets flag for define if surface of Revolution converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertExtrusionSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertExtrusionSurf, "Sets flag for define if surface of LinearExtrusion converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetSurf, "Sets flag for define if Offset surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCylindricalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCylindricalSurf, "Sets flag for define if cylindrical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertConicalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertConicalSurf, "Sets flag for define if conical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertToroidalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertToroidalSurf, "Sets flag for define if toroidal surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertSphericalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertSphericalSurf, "Sets flag for define if spherical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("SegmentSurfaceMode", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::SegmentSurfaceMode, "Sets Segment mode for surface. If Segment is True surface is approximated in the bondaries of face lying on this surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCurve3d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCurve3d, "Sets flag for define if 3d curve converted to BSpline curve.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetCurv3d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetCurv3d, "Sets flag for define if Offset curve3d converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCurve2d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCurve2d, "Returns (modifiable) flag for define if 2d curve converted to BSpline curve.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetCurv2d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetCurv2d, "Returns (modifiable) flag for define if Offset curve2d converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_RestrictionParameters::get_type_name, "None");
cls_ShapeCustom_RestrictionParameters.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_RestrictionParameters::get_type_descriptor, "None");
cls_ShapeCustom_RestrictionParameters.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_RestrictionParameters::*)() const) &ShapeCustom_RestrictionParameters::DynamicType, "None");

// CLASS: SHAPECUSTOM_SURFACE
py::class_<ShapeCustom_Surface> cls_ShapeCustom_Surface(mod, "ShapeCustom_Surface", "Converts a surface to the analitical form with given precision. Conversion is done only the surface is bspline of bezier and this can be approximed by some analytical surface with that precision.");

// Constructors
cls_ShapeCustom_Surface.def(py::init<>());
cls_ShapeCustom_Surface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));

// Methods
// cls_ShapeCustom_Surface.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom_Surface::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom_Surface.def_static("operator delete_", (void (*)(void *)) &ShapeCustom_Surface::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom_Surface::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom_Surface.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom_Surface::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom_Surface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom_Surface.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom_Surface::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom_Surface.def("Init", (void (ShapeCustom_Surface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeCustom_Surface::Init, "None", py::arg("S"));
cls_ShapeCustom_Surface.def("Gap", (Standard_Real (ShapeCustom_Surface::*)() const) &ShapeCustom_Surface::Gap, "Returns maximal deviation of converted surface from the original one computed by last call to ConvertToAnalytical");
cls_ShapeCustom_Surface.def("ConvertToAnalytical", (opencascade::handle<Geom_Surface> (ShapeCustom_Surface::*)(const Standard_Real, const Standard_Boolean)) &ShapeCustom_Surface::ConvertToAnalytical, "Tries to convert the Surface to an Analytic form Returns the result Works only if the Surface is BSpline or Bezier. Else, or in case of failure, returns a Null Handle", py::arg("tol"), py::arg("substitute"));
cls_ShapeCustom_Surface.def("ConvertToPeriodic", [](ShapeCustom_Surface &self, const Standard_Boolean a0) -> opencascade::handle<Geom_Surface> { return self.ConvertToPeriodic(a0); });
cls_ShapeCustom_Surface.def("ConvertToPeriodic", (opencascade::handle<Geom_Surface> (ShapeCustom_Surface::*)(const Standard_Boolean, const Standard_Real)) &ShapeCustom_Surface::ConvertToPeriodic, "Tries to convert the Surface to the Periodic form Returns the resulting surface Works only if the Surface is BSpline and is closed with Precision::Confusion() Else, or in case of failure, returns a Null Handle", py::arg("substitute"), py::arg("preci"));

// CLASS: SHAPECUSTOM_SWEPTTOELEMENTARY
py::class_<ShapeCustom_SweptToElementary, opencascade::handle<ShapeCustom_SweptToElementary>, ShapeCustom_Modification> cls_ShapeCustom_SweptToElementary(mod, "ShapeCustom_SweptToElementary", "implements a modification for the BRepTools Modifier algortihm. Converts all elementary surfaces into surfaces of revolution.");

// Constructors
cls_ShapeCustom_SweptToElementary.def(py::init<>());

// Methods
cls_ShapeCustom_SweptToElementary.def("NewSurface", [](ShapeCustom_SweptToElementary &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <S>, <L>, <Tol> are not significant.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_SweptToElementary.def("NewCurve", [](ShapeCustom_SweptToElementary &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_SweptToElementary.def("NewPoint", [](ShapeCustom_SweptToElementary &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_SweptToElementary.def("NewCurve2d", [](ShapeCustom_SweptToElementary &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_SweptToElementary.def("NewParameter", [](ShapeCustom_SweptToElementary &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_SweptToElementary.def("Continuity", (GeomAbs_Shape (ShapeCustom_SweptToElementary::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &ShapeCustom_SweptToElementary::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_ShapeCustom_SweptToElementary.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_SweptToElementary::get_type_name, "None");
cls_ShapeCustom_SweptToElementary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_SweptToElementary::get_type_descriptor, "None");
cls_ShapeCustom_SweptToElementary.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_SweptToElementary::*)() const) &ShapeCustom_SweptToElementary::DynamicType, "None");

// CLASS: SHAPECUSTOM_TRSFMODIFICATION
py::class_<ShapeCustom_TrsfModification, opencascade::handle<ShapeCustom_TrsfModification>, BRepTools_TrsfModification> cls_ShapeCustom_TrsfModification(mod, "ShapeCustom_TrsfModification", "Complements BRepTools_TrsfModification to provide reversible scaling regarding tolerances. Uses actual tolerances (attached to the shapes) not ones returned by BRep_Tool::Tolerance to work with tolerances lower than Precision::Confusion.");

// Constructors
cls_ShapeCustom_TrsfModification.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Methods
cls_ShapeCustom_TrsfModification.def("NewSurface", [](ShapeCustom_TrsfModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Calls inherited method. Sets <Tol> as actual tolerance of <F> multiplied with scale factor.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_TrsfModification.def("NewCurve", [](ShapeCustom_TrsfModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <E> multiplied with scale factor.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewPoint", [](ShapeCustom_TrsfModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <V> multiplied with scale factor.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewCurve2d", [](ShapeCustom_TrsfModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <E> multiplied with scale factor.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewParameter", [](ShapeCustom_TrsfModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <V> multiplied with scale factor.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_TrsfModification::get_type_name, "None");
cls_ShapeCustom_TrsfModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_TrsfModification::get_type_descriptor, "None");
cls_ShapeCustom_TrsfModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_TrsfModification::*)() const) &ShapeCustom_TrsfModification::DynamicType, "None");


}
