/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Adaptor3d_HCurve.hxx>
#include <ChFiDS_ElSpine.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <gp_Circ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <ChFiDS_CircSection.hxx>
#include <NCollection_Array1.hxx>
#include <ChFiDS_SecArray1.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <ChFiDS_SecHArray1.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_ListOfShape.hxx>
#include <ChFiDS_Map.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <ChFiDS_CommonPoint.hxx>
#include <Geom2d_Curve.hxx>
#include <ChFiDS_FaceInterference.hxx>
#include <ChFiDS_SurfData.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <ChFiDS_SequenceOfSurfData.hxx>
#include <ChFiDS_HData.hxx>
#include <ChFiDS_State.hxx>
#include <ChFiDS_ListOfHElSpine.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <ChFiDS_ErrorStatus.hxx>
#include <ChFiDS_Spine.hxx>
#include <ChFiDS_Stripe.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <ChFiDS_ListOfStripe.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <ChFiDS_IndexedDataMapOfVertexListOfStripe.hxx>
#include <ChFiDS_StripeMap.hxx>
#include <ChFiDS_Regul.hxx>
#include <ChFiDS_Regularities.hxx>
#include <ChFiDS_ChamfMethod.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Ax1.hxx>
#include <Geom_Curve.hxx>
#include <gp_Elips.hxx>
#include <gp_Hypr.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <ChFiDS_ChamfSpine.hxx>
#include <gp_XY.hxx>
#include <Law_Function.hxx>
#include <Law_Composite.hxx>
#include <ChFiDS_FilSpine.hxx>
#include <ChFiDS_SequenceOfSpine.hxx>
#include <ChFiDS_StripeArray1.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(ChFiDS, mod) {

	// IMPORT
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.Law");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ErrorStatus.hxx
	py::enum_<ChFiDS_ErrorStatus>(mod, "ChFiDS_ErrorStatus", "--- Purpose statuts concernant la cause de l'erreur")
		.value("ChFiDS_Ok", ChFiDS_ErrorStatus::ChFiDS_Ok)
		.value("ChFiDS_Error", ChFiDS_ErrorStatus::ChFiDS_Error)
		.value("ChFiDS_WalkingFailure", ChFiDS_ErrorStatus::ChFiDS_WalkingFailure)
		.value("ChFiDS_StartsolFailure", ChFiDS_ErrorStatus::ChFiDS_StartsolFailure)
		.value("ChFiDS_TwistedSurface", ChFiDS_ErrorStatus::ChFiDS_TwistedSurface)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ChamfMethod.hxx
	py::enum_<ChFiDS_ChamfMethod>(mod, "ChFiDS_ChamfMethod", "None")
		.value("ChFiDS_Sym", ChFiDS_ChamfMethod::ChFiDS_Sym)
		.value("ChFiDS_TwoDist", ChFiDS_ChamfMethod::ChFiDS_TwoDist)
		.value("ChFiDS_DistAngle", ChFiDS_ChamfMethod::ChFiDS_DistAngle)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_State.hxx
	py::enum_<ChFiDS_State>(mod, "ChFiDS_State", "This enum describe the different kinds of extremities of a fillet. OnSame, Ondiff and AllSame are particular cases of BreakPoint for a corner with 3 edges and three faces : - AllSame means that the three concavities are on the same side of the Shape, - OnDiff means that the edge of the fillet has a concave side different than the two other edges, - OnSame means that the edge of the fillet has a concave side different than one of the two other edges and identical to the third edge.")
		.value("ChFiDS_OnSame", ChFiDS_State::ChFiDS_OnSame)
		.value("ChFiDS_OnDiff", ChFiDS_State::ChFiDS_OnDiff)
		.value("ChFiDS_AllSame", ChFiDS_State::ChFiDS_AllSame)
		.value("ChFiDS_BreakPoint", ChFiDS_State::ChFiDS_BreakPoint)
		.value("ChFiDS_FreeBoundary", ChFiDS_State::ChFiDS_FreeBoundary)
		.value("ChFiDS_Closed", ChFiDS_State::ChFiDS_Closed)
		.value("ChFiDS_Tangent", ChFiDS_State::ChFiDS_Tangent)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_HElSpine.hxx
	py::class_<ChFiDS_HElSpine, opencascade::handle<ChFiDS_HElSpine>, Adaptor3d_HCurve> cls_ChFiDS_HElSpine(mod, "ChFiDS_HElSpine", "None");
	cls_ChFiDS_HElSpine.def(py::init<>());
	cls_ChFiDS_HElSpine.def(py::init<const ChFiDS_ElSpine &>(), py::arg("C"));
	cls_ChFiDS_HElSpine.def("Set", (void (ChFiDS_HElSpine::*)(const ChFiDS_ElSpine &)) &ChFiDS_HElSpine::Set, "Sets the field of the GenHCurve.", py::arg("C"));
	cls_ChFiDS_HElSpine.def("Curve", (const Adaptor3d_Curve & (ChFiDS_HElSpine::*)() const ) &ChFiDS_HElSpine::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_ChFiDS_HElSpine.def("GetCurve", (Adaptor3d_Curve & (ChFiDS_HElSpine::*)()) &ChFiDS_HElSpine::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
	cls_ChFiDS_HElSpine.def("ChangeCurve", (ChFiDS_ElSpine & (ChFiDS_HElSpine::*)()) &ChFiDS_HElSpine::ChangeCurve, "Returns the curve used to create the GenHCurve.");
	cls_ChFiDS_HElSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_HElSpine::get_type_name, "None");
	cls_ChFiDS_HElSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_HElSpine::get_type_descriptor, "None");
	cls_ChFiDS_HElSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_HElSpine::*)() const ) &ChFiDS_HElSpine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_CircSection.hxx
	py::class_<ChFiDS_CircSection, std::unique_ptr<ChFiDS_CircSection, Deleter<ChFiDS_CircSection>>> cls_ChFiDS_CircSection(mod, "ChFiDS_CircSection", "A Section of fillet.");
	cls_ChFiDS_CircSection.def(py::init<>());
	cls_ChFiDS_CircSection.def("Set", (void (ChFiDS_CircSection::*)(const gp_Circ &, const Standard_Real, const Standard_Real)) &ChFiDS_CircSection::Set, "None", py::arg("C"), py::arg("F"), py::arg("L"));
	cls_ChFiDS_CircSection.def("Set", (void (ChFiDS_CircSection::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &ChFiDS_CircSection::Set, "None", py::arg("C"), py::arg("F"), py::arg("L"));
	cls_ChFiDS_CircSection.def("Get", [](ChFiDS_CircSection &self, gp_Circ & C, Standard_Real & F, Standard_Real & L){ self.Get(C, F, L); return std::tuple<Standard_Real &, Standard_Real &>(F, L); }, "None", py::arg("C"), py::arg("F"), py::arg("L"));
	cls_ChFiDS_CircSection.def("Get", [](ChFiDS_CircSection &self, gp_Lin & C, Standard_Real & F, Standard_Real & L){ self.Get(C, F, L); return std::tuple<Standard_Real &, Standard_Real &>(F, L); }, "None", py::arg("C"), py::arg("F"), py::arg("L"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_SecArray1.hxx
	bind_NCollection_Array1<ChFiDS_CircSection>(mod, "ChFiDS_SecArray1");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Map.hxx
	py::class_<ChFiDS_Map, std::unique_ptr<ChFiDS_Map, Deleter<ChFiDS_Map>>> cls_ChFiDS_Map(mod, "ChFiDS_Map", "Encapsulation of IndexedDataMapOfShapeListOfShape.");
	cls_ChFiDS_Map.def(py::init<>());
	cls_ChFiDS_Map.def("Fill", (void (ChFiDS_Map::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &ChFiDS_Map::Fill, "Fills the map with the subshapes of type T1 as keys and the list of ancestors of type T2 as items.", py::arg("S"), py::arg("T1"), py::arg("T2"));
	cls_ChFiDS_Map.def("Contains", (Standard_Boolean (ChFiDS_Map::*)(const TopoDS_Shape &) const ) &ChFiDS_Map::Contains, "None", py::arg("S"));
	cls_ChFiDS_Map.def("FindFromKey", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const TopoDS_Shape &) const ) &ChFiDS_Map::FindFromKey, "None", py::arg("S"));
	cls_ChFiDS_Map.def("__call__", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const TopoDS_Shape &) const ) &ChFiDS_Map::operator(), py::is_operator(), "None", py::arg("S"));
	cls_ChFiDS_Map.def("FindFromIndex", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const Standard_Integer) const ) &ChFiDS_Map::FindFromIndex, "None", py::arg("I"));
	cls_ChFiDS_Map.def("__call__", (const TopTools_ListOfShape & (ChFiDS_Map::*)(const Standard_Integer) const ) &ChFiDS_Map::operator(), py::is_operator(), "None", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_CommonPoint.hxx
	py::class_<ChFiDS_CommonPoint, std::unique_ptr<ChFiDS_CommonPoint, Deleter<ChFiDS_CommonPoint>>> cls_ChFiDS_CommonPoint(mod, "ChFiDS_CommonPoint", "point start/end of fillet common to 2 adjacent filets and to an edge on one of 2 faces participating in the construction of the fillet");
	cls_ChFiDS_CommonPoint.def(py::init<>());
	cls_ChFiDS_CommonPoint.def("Reset", (void (ChFiDS_CommonPoint::*)()) &ChFiDS_CommonPoint::Reset, "default value for all fields");
	cls_ChFiDS_CommonPoint.def("SetVertex", (void (ChFiDS_CommonPoint::*)(const TopoDS_Vertex &)) &ChFiDS_CommonPoint::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface.", py::arg("V"));
	cls_ChFiDS_CommonPoint.def("SetArc", (void (ChFiDS_CommonPoint::*)(const Standard_Real, const TopoDS_Edge &, const Standard_Real, const TopAbs_Orientation)) &ChFiDS_CommonPoint::SetArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("Tol"), py::arg("A"), py::arg("Param"), py::arg("TArc"));
	cls_ChFiDS_CommonPoint.def("SetParameter", (void (ChFiDS_CommonPoint::*)(const Standard_Real)) &ChFiDS_CommonPoint::SetParameter, "Sets the value of the parameter on the spine", py::arg("Param"));
	cls_ChFiDS_CommonPoint.def("SetPoint", (void (ChFiDS_CommonPoint::*)(const gp_Pnt &)) &ChFiDS_CommonPoint::SetPoint, "Set the 3d point for a commonpoint that is not a vertex or on an arc.", py::arg("Point"));
	cls_ChFiDS_CommonPoint.def("SetVector", (void (ChFiDS_CommonPoint::*)(const gp_Vec &)) &ChFiDS_CommonPoint::SetVector, "Set the output 3d vector", py::arg("Vector"));
	cls_ChFiDS_CommonPoint.def("SetTolerance", (void (ChFiDS_CommonPoint::*)(const Standard_Real)) &ChFiDS_CommonPoint::SetTolerance, "This method set the fuzziness on the point.", py::arg("Tol"));
	cls_ChFiDS_CommonPoint.def("Tolerance", (Standard_Real (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Tolerance, "This method returns the fuzziness on the point.");
	cls_ChFiDS_CommonPoint.def("IsVertex", (Standard_Boolean (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::IsVertex, "Returns TRUE if the point is a vertex on the initial restriction facet of the surface.");
	cls_ChFiDS_CommonPoint.def("Vertex", (const TopoDS_Vertex & (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Vertex, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertex returns True. Otherwise, an exception is raised.");
	cls_ChFiDS_CommonPoint.def("IsOnArc", (Standard_Boolean (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::IsOnArc, "Returns TRUE if the point is a on an edge of the initial restriction facet of the surface.");
	cls_ChFiDS_CommonPoint.def("Arc", (const TopoDS_Edge & (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Arc, "Returns the arc of restriction containing the vertex.");
	cls_ChFiDS_CommonPoint.def("TransitionOnArc", (TopAbs_Orientation (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::TransitionOnArc, "Returns the transition of the point on the arc returned by Arc().");
	cls_ChFiDS_CommonPoint.def("ParameterOnArc", (Standard_Real (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");
	cls_ChFiDS_CommonPoint.def("Parameter", (Standard_Real (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Parameter, "Returns the parameter the paramter on the spine");
	cls_ChFiDS_CommonPoint.def("Point", (const gp_Pnt & (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Point, "Returns the 3d point");
	cls_ChFiDS_CommonPoint.def("HasVector", (Standard_Boolean (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::HasVector, "Returns TRUE if the output vector is stored.");
	cls_ChFiDS_CommonPoint.def("Vector", (const gp_Vec & (ChFiDS_CommonPoint::*)() const ) &ChFiDS_CommonPoint::Vector, "Returns the output 3d vector");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_FaceInterference.hxx
	py::class_<ChFiDS_FaceInterference, std::unique_ptr<ChFiDS_FaceInterference, Deleter<ChFiDS_FaceInterference>>> cls_ChFiDS_FaceInterference(mod, "ChFiDS_FaceInterference", "interference face/fillet");
	cls_ChFiDS_FaceInterference.def(py::init<>());
	cls_ChFiDS_FaceInterference.def("SetInterference", (void (ChFiDS_FaceInterference::*)(const Standard_Integer, const TopAbs_Orientation, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &)) &ChFiDS_FaceInterference::SetInterference, "None", py::arg("LineIndex"), py::arg("Trans"), py::arg("PCurv1"), py::arg("PCurv2"));
	cls_ChFiDS_FaceInterference.def("SetTransition", (void (ChFiDS_FaceInterference::*)(const TopAbs_Orientation)) &ChFiDS_FaceInterference::SetTransition, "None", py::arg("Trans"));
	cls_ChFiDS_FaceInterference.def("SetFirstParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real)) &ChFiDS_FaceInterference::SetFirstParameter, "None", py::arg("U1"));
	cls_ChFiDS_FaceInterference.def("SetLastParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real)) &ChFiDS_FaceInterference::SetLastParameter, "None", py::arg("U1"));
	cls_ChFiDS_FaceInterference.def("SetParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real, const Standard_Boolean)) &ChFiDS_FaceInterference::SetParameter, "None", py::arg("U1"), py::arg("IsFirst"));
	cls_ChFiDS_FaceInterference.def("LineIndex", (Standard_Integer (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::LineIndex, "None");
	cls_ChFiDS_FaceInterference.def("SetLineIndex", (void (ChFiDS_FaceInterference::*)(const Standard_Integer)) &ChFiDS_FaceInterference::SetLineIndex, "None", py::arg("I"));
	cls_ChFiDS_FaceInterference.def("Transition", (TopAbs_Orientation (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::Transition, "None");
	cls_ChFiDS_FaceInterference.def("PCurveOnFace", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::PCurveOnFace, "None");
	cls_ChFiDS_FaceInterference.def("PCurveOnSurf", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::PCurveOnSurf, "None");
	cls_ChFiDS_FaceInterference.def("ChangePCurveOnFace", (opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)()) &ChFiDS_FaceInterference::ChangePCurveOnFace, "None");
	cls_ChFiDS_FaceInterference.def("ChangePCurveOnSurf", (opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)()) &ChFiDS_FaceInterference::ChangePCurveOnSurf, "None");
	cls_ChFiDS_FaceInterference.def("FirstParameter", (Standard_Real (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::FirstParameter, "None");
	cls_ChFiDS_FaceInterference.def("LastParameter", (Standard_Real (ChFiDS_FaceInterference::*)() const ) &ChFiDS_FaceInterference::LastParameter, "None");
	cls_ChFiDS_FaceInterference.def("Parameter", (Standard_Real (ChFiDS_FaceInterference::*)(const Standard_Boolean) const ) &ChFiDS_FaceInterference::Parameter, "None", py::arg("IsFirst"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_SurfData.hxx
	py::class_<ChFiDS_SurfData, opencascade::handle<ChFiDS_SurfData>, Standard_Transient> cls_ChFiDS_SurfData(mod, "ChFiDS_SurfData", "data structure for all information related to the fillet and to 2 faces vis a vis");
	cls_ChFiDS_SurfData.def(py::init<>());
	cls_ChFiDS_SurfData.def("Copy", (void (ChFiDS_SurfData::*)(const opencascade::handle<ChFiDS_SurfData> &)) &ChFiDS_SurfData::Copy, "None", py::arg("Other"));
	cls_ChFiDS_SurfData.def("IndexOfS1", (Standard_Integer (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IndexOfS1, "None");
	cls_ChFiDS_SurfData.def("IndexOfS2", (Standard_Integer (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IndexOfS2, "None");
	cls_ChFiDS_SurfData.def("IsOnCurve1", (Standard_Boolean (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IsOnCurve1, "None");
	cls_ChFiDS_SurfData.def("IsOnCurve2", (Standard_Boolean (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IsOnCurve2, "None");
	cls_ChFiDS_SurfData.def("IndexOfC1", (Standard_Integer (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IndexOfC1, "None");
	cls_ChFiDS_SurfData.def("IndexOfC2", (Standard_Integer (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::IndexOfC2, "None");
	cls_ChFiDS_SurfData.def("Surf", (Standard_Integer (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::Surf, "None");
	cls_ChFiDS_SurfData.def("Orientation", (TopAbs_Orientation (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::Orientation, "None");
	cls_ChFiDS_SurfData.def("InterferenceOnS1", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::InterferenceOnS1, "None");
	cls_ChFiDS_SurfData.def("InterferenceOnS2", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::InterferenceOnS2, "None");
	cls_ChFiDS_SurfData.def("VertexFirstOnS1", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::VertexFirstOnS1, "None");
	cls_ChFiDS_SurfData.def("VertexFirstOnS2", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::VertexFirstOnS2, "None");
	cls_ChFiDS_SurfData.def("VertexLastOnS1", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::VertexLastOnS1, "None");
	cls_ChFiDS_SurfData.def("VertexLastOnS2", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::VertexLastOnS2, "None");
	cls_ChFiDS_SurfData.def("ChangeIndexOfS1", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeIndexOfS1, "None", py::arg("Index"));
	cls_ChFiDS_SurfData.def("ChangeIndexOfS2", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeIndexOfS2, "None", py::arg("Index"));
	cls_ChFiDS_SurfData.def("ChangeSurf", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeSurf, "None", py::arg("Index"));
	cls_ChFiDS_SurfData.def("SetIndexOfC1", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::SetIndexOfC1, "None", py::arg("Index"));
	cls_ChFiDS_SurfData.def("SetIndexOfC2", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::SetIndexOfC2, "None", py::arg("Index"));
	cls_ChFiDS_SurfData.def("ChangeOrientation", (TopAbs_Orientation & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeOrientation, "None");
	cls_ChFiDS_SurfData.def("ChangeInterferenceOnS1", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeInterferenceOnS1, "None");
	cls_ChFiDS_SurfData.def("ChangeInterferenceOnS2", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeInterferenceOnS2, "None");
	cls_ChFiDS_SurfData.def("ChangeVertexFirstOnS1", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexFirstOnS1, "None");
	cls_ChFiDS_SurfData.def("ChangeVertexFirstOnS2", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexFirstOnS2, "None");
	cls_ChFiDS_SurfData.def("ChangeVertexLastOnS1", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexLastOnS1, "None");
	cls_ChFiDS_SurfData.def("ChangeVertexLastOnS2", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexLastOnS2, "None");
	cls_ChFiDS_SurfData.def("Interference", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)(const Standard_Integer) const ) &ChFiDS_SurfData::Interference, "None", py::arg("OnS"));
	cls_ChFiDS_SurfData.def("ChangeInterference", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeInterference, "None", py::arg("OnS"));
	cls_ChFiDS_SurfData.def("Index", (Standard_Integer (ChFiDS_SurfData::*)(const Standard_Integer) const ) &ChFiDS_SurfData::Index, "None", py::arg("OfS"));
	cls_ChFiDS_SurfData.def("Vertex", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer) const ) &ChFiDS_SurfData::Vertex, "returns one of the four vertices wether First is true or wrong and OnS equals 1 or 2.", py::arg("First"), py::arg("OnS"));
	cls_ChFiDS_SurfData.def("ChangeVertex", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer)) &ChFiDS_SurfData::ChangeVertex, "returns one of the four vertices wether First is true or wrong and OnS equals 1 or 2.", py::arg("First"), py::arg("OnS"));
	cls_ChFiDS_SurfData.def("IsOnCurve", (Standard_Boolean (ChFiDS_SurfData::*)(const Standard_Integer) const ) &ChFiDS_SurfData::IsOnCurve, "None", py::arg("OnS"));
	cls_ChFiDS_SurfData.def("IndexOfC", (Standard_Integer (ChFiDS_SurfData::*)(const Standard_Integer) const ) &ChFiDS_SurfData::IndexOfC, "None", py::arg("OnS"));
	cls_ChFiDS_SurfData.def("FirstSpineParam", (Standard_Real (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::FirstSpineParam, "None");
	cls_ChFiDS_SurfData.def("LastSpineParam", (Standard_Real (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::LastSpineParam, "None");
	cls_ChFiDS_SurfData.def("FirstSpineParam", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::FirstSpineParam, "None", py::arg("Par"));
	cls_ChFiDS_SurfData.def("LastSpineParam", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::LastSpineParam, "None", py::arg("Par"));
	cls_ChFiDS_SurfData.def("FirstExtensionValue", (Standard_Real (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::FirstExtensionValue, "None");
	cls_ChFiDS_SurfData.def("LastExtensionValue", (Standard_Real (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::LastExtensionValue, "None");
	cls_ChFiDS_SurfData.def("FirstExtensionValue", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::FirstExtensionValue, "None", py::arg("Extend"));
	cls_ChFiDS_SurfData.def("LastExtensionValue", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::LastExtensionValue, "None", py::arg("Extend"));
	cls_ChFiDS_SurfData.def("Simul", (opencascade::handle<Standard_Transient> (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::Simul, "None");
	cls_ChFiDS_SurfData.def("SetSimul", (void (ChFiDS_SurfData::*)(const opencascade::handle<Standard_Transient> &)) &ChFiDS_SurfData::SetSimul, "None", py::arg("S"));
	cls_ChFiDS_SurfData.def("ResetSimul", (void (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ResetSimul, "None");
	cls_ChFiDS_SurfData.def("Get2dPoints", (gp_Pnt2d (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer) const ) &ChFiDS_SurfData::Get2dPoints, "None", py::arg("First"), py::arg("OnS"));
	cls_ChFiDS_SurfData.def("Get2dPoints", (void (ChFiDS_SurfData::*)(gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &) const ) &ChFiDS_SurfData::Get2dPoints, "None", py::arg("P2df1"), py::arg("P2dl1"), py::arg("P2df2"), py::arg("P2dl2"));
	cls_ChFiDS_SurfData.def("Set2dPoints", (void (ChFiDS_SurfData::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiDS_SurfData::Set2dPoints, "None", py::arg("P2df1"), py::arg("P2dl1"), py::arg("P2df2"), py::arg("P2dl2"));
	cls_ChFiDS_SurfData.def("TwistOnS1", (Standard_Boolean (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::TwistOnS1, "None");
	cls_ChFiDS_SurfData.def("TwistOnS2", (Standard_Boolean (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::TwistOnS2, "None");
	cls_ChFiDS_SurfData.def("TwistOnS1", (void (ChFiDS_SurfData::*)(const Standard_Boolean)) &ChFiDS_SurfData::TwistOnS1, "None", py::arg("T"));
	cls_ChFiDS_SurfData.def("TwistOnS2", (void (ChFiDS_SurfData::*)(const Standard_Boolean)) &ChFiDS_SurfData::TwistOnS2, "None", py::arg("T"));
	cls_ChFiDS_SurfData.def_static("get_type_name_", (const char * (*)()) &ChFiDS_SurfData::get_type_name, "None");
	cls_ChFiDS_SurfData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_SurfData::get_type_descriptor, "None");
	cls_ChFiDS_SurfData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_SurfData::*)() const ) &ChFiDS_SurfData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_SequenceOfSurfData.hxx
	bind_NCollection_Sequence<opencascade::handle<ChFiDS_SurfData> >(mod, "ChFiDS_SequenceOfSurfData");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Spine.hxx
	py::class_<ChFiDS_Spine, opencascade::handle<ChFiDS_Spine>, Standard_Transient> cls_ChFiDS_Spine(mod, "ChFiDS_Spine", "Contains information necessary for construction of a 3D fillet or chamfer:");
	cls_ChFiDS_Spine.def(py::init<>());
	cls_ChFiDS_Spine.def(py::init<const Standard_Real>(), py::arg("Tol"));
	cls_ChFiDS_Spine.def("SetEdges", (void (ChFiDS_Spine::*)(const TopoDS_Edge &)) &ChFiDS_Spine::SetEdges, "store edges composing the guideline", py::arg("E"));
	cls_ChFiDS_Spine.def("PutInFirst", (void (ChFiDS_Spine::*)(const TopoDS_Edge &)) &ChFiDS_Spine::PutInFirst, "store the edge at the first position before all others", py::arg("E"));
	cls_ChFiDS_Spine.def("NbEdges", (Standard_Integer (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::NbEdges, "None");
	cls_ChFiDS_Spine.def("Edges", (const TopoDS_Edge & (ChFiDS_Spine::*)(const Standard_Integer) const ) &ChFiDS_Spine::Edges, "None", py::arg("I"));
	cls_ChFiDS_Spine.def("SetFirstStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State)) &ChFiDS_Spine::SetFirstStatus, "stores if the start of a set of edges starts on a section of free border or forms a closed contour", py::arg("S"));
	cls_ChFiDS_Spine.def("SetLastStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State)) &ChFiDS_Spine::SetLastStatus, "stores if the end of a set of edges starts on a section of free border or forms a closed contour", py::arg("S"));
	cls_ChFiDS_Spine.def("AppendElSpine", (void (ChFiDS_Spine::*)(const opencascade::handle<ChFiDS_HElSpine> &)) &ChFiDS_Spine::AppendElSpine, "None", py::arg("Els"));
	cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const Standard_Integer) const ) &ChFiDS_Spine::ElSpine, "None", py::arg("IE"));
	cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const TopoDS_Edge &) const ) &ChFiDS_Spine::ElSpine, "None", py::arg("E"));
	cls_ChFiDS_Spine.def("ElSpine", (opencascade::handle<ChFiDS_HElSpine> (ChFiDS_Spine::*)(const Standard_Real) const ) &ChFiDS_Spine::ElSpine, "None", py::arg("W"));
	cls_ChFiDS_Spine.def("ChangeElSpines", (ChFiDS_ListOfHElSpine & (ChFiDS_Spine::*)()) &ChFiDS_Spine::ChangeElSpines, "None");
	cls_ChFiDS_Spine.def("Reset", [](ChFiDS_Spine &self) -> void { return self.Reset(); });
	cls_ChFiDS_Spine.def("Reset", (void (ChFiDS_Spine::*)(const Standard_Boolean)) &ChFiDS_Spine::Reset, "None", py::arg("AllData"));
	cls_ChFiDS_Spine.def("SplitDone", (Standard_Boolean (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::SplitDone, "None");
	cls_ChFiDS_Spine.def("SplitDone", (void (ChFiDS_Spine::*)(const Standard_Boolean)) &ChFiDS_Spine::SplitDone, "None", py::arg("B"));
	cls_ChFiDS_Spine.def("Load", (void (ChFiDS_Spine::*)()) &ChFiDS_Spine::Load, "prepare the guideline depending on the edges that are elementary arks (take parameters from a single curvilinear abscissa); to be able to call methods on the geometry (first,last,value,d1,d2) it is necessary to start with preparation otherwise an exception will be raised");
	cls_ChFiDS_Spine.def("Resolution", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real) const ) &ChFiDS_Spine::Resolution, "None", py::arg("R3d"));
	cls_ChFiDS_Spine.def("IsClosed", (Standard_Boolean (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::IsClosed, "None");
	cls_ChFiDS_Spine.def("FirstParameter", (Standard_Real (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::FirstParameter, "None");
	cls_ChFiDS_Spine.def("LastParameter", (Standard_Real (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::LastParameter, "None");
	cls_ChFiDS_Spine.def("SetFirstParameter", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetFirstParameter, "None", py::arg("Par"));
	cls_ChFiDS_Spine.def("SetLastParameter", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetLastParameter, "None", py::arg("Par"));
	cls_ChFiDS_Spine.def("FirstParameter", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const ) &ChFiDS_Spine::FirstParameter, "gives the total length of all arcs before the number IndexSp", py::arg("IndexSpine"));
	cls_ChFiDS_Spine.def("LastParameter", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const ) &ChFiDS_Spine::LastParameter, "gives the total length till the ark with number IndexSpine (inclus)", py::arg("IndexSpine"));
	cls_ChFiDS_Spine.def("Length", (Standard_Real (ChFiDS_Spine::*)(const Standard_Integer) const ) &ChFiDS_Spine::Length, "gives the length of ark with number IndexSp", py::arg("IndexSpine"));
	cls_ChFiDS_Spine.def("IsPeriodic", (Standard_Boolean (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::IsPeriodic, "None");
	cls_ChFiDS_Spine.def("Period", (Standard_Real (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::Period, "None");
	cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::Absc, "None", py::arg("U"));
	cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const Standard_Real, const Standard_Integer)) &ChFiDS_Spine::Absc, "None", py::arg("U"), py::arg("I"));
	cls_ChFiDS_Spine.def("Parameter", [](ChFiDS_Spine &self, const Standard_Real AbsC, Standard_Real & U, const Standard_Boolean Oriented){ self.Parameter(AbsC, U, Oriented); return U; }, "None", py::arg("AbsC"), py::arg("U"), py::arg("Oriented"));
	cls_ChFiDS_Spine.def("Parameter", [](ChFiDS_Spine &self, const Standard_Integer Index, const Standard_Real AbsC, Standard_Real & U, const Standard_Boolean Oriented){ self.Parameter(Index, AbsC, U, Oriented); return U; }, "None", py::arg("Index"), py::arg("AbsC"), py::arg("U"), py::arg("Oriented"));
	cls_ChFiDS_Spine.def("Value", (gp_Pnt (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::Value, "None", py::arg("AbsC"));
	cls_ChFiDS_Spine.def("D0", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &)) &ChFiDS_Spine::D0, "None", py::arg("AbsC"), py::arg("P"));
	cls_ChFiDS_Spine.def("D1", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &ChFiDS_Spine::D1, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"));
	cls_ChFiDS_Spine.def("D2", (void (ChFiDS_Spine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &ChFiDS_Spine::D2, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ChFiDS_Spine.def("SetCurrent", (void (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::SetCurrent, "None", py::arg("Index"));
	cls_ChFiDS_Spine.def("CurrentElementarySpine", (const BRepAdaptor_Curve & (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::CurrentElementarySpine, "sets the current curve and returns it", py::arg("Index"));
	cls_ChFiDS_Spine.def("CurrentIndexOfElementarySpine", (Standard_Integer (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::CurrentIndexOfElementarySpine, "None");
	cls_ChFiDS_Spine.def("GetType", (GeomAbs_CurveType (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::GetType, "None");
	cls_ChFiDS_Spine.def("Line", (gp_Lin (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::Line, "None");
	cls_ChFiDS_Spine.def("Circle", (gp_Circ (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::Circle, "None");
	cls_ChFiDS_Spine.def("FirstStatus", (ChFiDS_State (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::FirstStatus, "returns if the set of edges starts on a free boundary or if the first vertex is a breakpoint or if the set is closed");
	cls_ChFiDS_Spine.def("LastStatus", (ChFiDS_State (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::LastStatus, "returns the state at the end of the set");
	cls_ChFiDS_Spine.def("Status", (ChFiDS_State (ChFiDS_Spine::*)(const Standard_Boolean) const ) &ChFiDS_Spine::Status, "None", py::arg("IsFirst"));
	cls_ChFiDS_Spine.def("SetStatus", (void (ChFiDS_Spine::*)(const ChFiDS_State, const Standard_Boolean)) &ChFiDS_Spine::SetStatus, "None", py::arg("S"), py::arg("IsFirst"));
	cls_ChFiDS_Spine.def("IsTangencyExtremity", (Standard_Boolean (ChFiDS_Spine::*)(const Standard_Boolean) const ) &ChFiDS_Spine::IsTangencyExtremity, "returns if the set of edges starts (or end) on Tangency point.", py::arg("IsFirst"));
	cls_ChFiDS_Spine.def("SetTangencyExtremity", (void (ChFiDS_Spine::*)(const Standard_Boolean, const Standard_Boolean)) &ChFiDS_Spine::SetTangencyExtremity, "None", py::arg("IsTangency"), py::arg("IsFirst"));
	cls_ChFiDS_Spine.def("Absc", (Standard_Real (ChFiDS_Spine::*)(const TopoDS_Vertex &) const ) &ChFiDS_Spine::Absc, "None", py::arg("V"));
	cls_ChFiDS_Spine.def("FirstVertex", (TopoDS_Vertex (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::FirstVertex, "None");
	cls_ChFiDS_Spine.def("LastVertex", (TopoDS_Vertex (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::LastVertex, "None");
	cls_ChFiDS_Spine.def("SetFirstTgt", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetFirstTgt, "None", py::arg("W"));
	cls_ChFiDS_Spine.def("SetLastTgt", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetLastTgt, "None", py::arg("W"));
	cls_ChFiDS_Spine.def("HasFirstTgt", (Standard_Boolean (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::HasFirstTgt, "None");
	cls_ChFiDS_Spine.def("HasLastTgt", (Standard_Boolean (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::HasLastTgt, "None");
	cls_ChFiDS_Spine.def("SetReference", (void (ChFiDS_Spine::*)(const Standard_Real)) &ChFiDS_Spine::SetReference, "set a parameter reference for the approx.", py::arg("W"));
	cls_ChFiDS_Spine.def("SetReference", (void (ChFiDS_Spine::*)(const Standard_Integer)) &ChFiDS_Spine::SetReference, "set a parameter reference for the approx, at the middle of edge I.", py::arg("I"));
	cls_ChFiDS_Spine.def("Index", [](ChFiDS_Spine &self, const Standard_Real a0) -> Standard_Integer { return self.Index(a0); }, py::arg("W"));
	cls_ChFiDS_Spine.def("Index", (Standard_Integer (ChFiDS_Spine::*)(const Standard_Real, const Standard_Boolean) const ) &ChFiDS_Spine::Index, "None", py::arg("W"), py::arg("Forward"));
	cls_ChFiDS_Spine.def("Index", (Standard_Integer (ChFiDS_Spine::*)(const TopoDS_Edge &) const ) &ChFiDS_Spine::Index, "None", py::arg("E"));
	cls_ChFiDS_Spine.def("UnsetReference", (void (ChFiDS_Spine::*)()) &ChFiDS_Spine::UnsetReference, "None");
	cls_ChFiDS_Spine.def("SetErrorStatus", (void (ChFiDS_Spine::*)(const ChFiDS_ErrorStatus)) &ChFiDS_Spine::SetErrorStatus, "None", py::arg("state"));
	cls_ChFiDS_Spine.def("ErrorStatus", (ChFiDS_ErrorStatus (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::ErrorStatus, "None");
	cls_ChFiDS_Spine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_Spine::get_type_name, "None");
	cls_ChFiDS_Spine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_Spine::get_type_descriptor, "None");
	cls_ChFiDS_Spine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_Spine::*)() const ) &ChFiDS_Spine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Stripe.hxx
	py::class_<ChFiDS_Stripe, opencascade::handle<ChFiDS_Stripe>, Standard_Transient> cls_ChFiDS_Stripe(mod, "ChFiDS_Stripe", "Data characterising a band of fillet.");
	cls_ChFiDS_Stripe.def(py::init<>());
	cls_ChFiDS_Stripe.def("Reset", (void (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::Reset, "Reset everything except Spine.");
	cls_ChFiDS_Stripe.def("SetOfSurfData", (const opencascade::handle<ChFiDS_HData> & (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::SetOfSurfData, "None");
	cls_ChFiDS_Stripe.def("Spine", (const opencascade::handle<ChFiDS_Spine> & (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::Spine, "None");
	cls_ChFiDS_Stripe.def("OrientationOnFace1", (TopAbs_Orientation (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::OrientationOnFace1, "None");
	cls_ChFiDS_Stripe.def("OrientationOnFace2", (TopAbs_Orientation (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::OrientationOnFace2, "None");
	cls_ChFiDS_Stripe.def("Choix", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::Choix, "None");
	cls_ChFiDS_Stripe.def("ChangeSetOfSurfData", (opencascade::handle<ChFiDS_HData> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeSetOfSurfData, "None");
	cls_ChFiDS_Stripe.def("ChangeSpine", (opencascade::handle<ChFiDS_Spine> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeSpine, "None");
	cls_ChFiDS_Stripe.def("OrientationOnFace1", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::OrientationOnFace1, "None", py::arg("Or1"));
	cls_ChFiDS_Stripe.def("OrientationOnFace2", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::OrientationOnFace2, "None", py::arg("Or2"));
	cls_ChFiDS_Stripe.def("Choix", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::Choix, "None", py::arg("C"));
	cls_ChFiDS_Stripe.def("FirstParameters", [](ChFiDS_Stripe &self, Standard_Real & Pdeb, Standard_Real & Pfin){ self.FirstParameters(Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("LastParameters", [](ChFiDS_Stripe &self, Standard_Real & Pdeb, Standard_Real & Pfin){ self.LastParameters(Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("ChangeFirstParameters", (void (ChFiDS_Stripe::*)(const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::ChangeFirstParameters, "None", py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("ChangeLastParameters", (void (ChFiDS_Stripe::*)(const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::ChangeLastParameters, "None", py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("FirstCurve", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::FirstCurve, "None");
	cls_ChFiDS_Stripe.def("LastCurve", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::LastCurve, "None");
	cls_ChFiDS_Stripe.def("ChangeFirstCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeFirstCurve, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("ChangeLastCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeLastCurve, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("FirstPCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::FirstPCurve, "None");
	cls_ChFiDS_Stripe.def("LastPCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::LastPCurve, "None");
	cls_ChFiDS_Stripe.def("ChangeFirstPCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeFirstPCurve, "None");
	cls_ChFiDS_Stripe.def("ChangeLastPCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeLastPCurve, "None");
	cls_ChFiDS_Stripe.def("FirstPCurveOrientation", (TopAbs_Orientation (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::FirstPCurveOrientation, "None");
	cls_ChFiDS_Stripe.def("LastPCurveOrientation", (TopAbs_Orientation (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::LastPCurveOrientation, "None");
	cls_ChFiDS_Stripe.def("FirstPCurveOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::FirstPCurveOrientation, "None", py::arg("O"));
	cls_ChFiDS_Stripe.def("LastPCurveOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::LastPCurveOrientation, "None", py::arg("O"));
	cls_ChFiDS_Stripe.def("IndexFirstPointOnS1", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::IndexFirstPointOnS1, "None");
	cls_ChFiDS_Stripe.def("IndexFirstPointOnS2", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::IndexFirstPointOnS2, "None");
	cls_ChFiDS_Stripe.def("IndexLastPointOnS1", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::IndexLastPointOnS1, "None");
	cls_ChFiDS_Stripe.def("IndexLastPointOnS2", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::IndexLastPointOnS2, "None");
	cls_ChFiDS_Stripe.def("ChangeIndexFirstPointOnS1", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexFirstPointOnS1, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("ChangeIndexFirstPointOnS2", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexFirstPointOnS2, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("ChangeIndexLastPointOnS1", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexLastPointOnS1, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("ChangeIndexLastPointOnS2", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexLastPointOnS2, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("Parameters", [](ChFiDS_Stripe &self, const Standard_Boolean First, Standard_Real & Pdeb, Standard_Real & Pfin){ self.Parameters(First, Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("First"), py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("SetParameters", (void (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::SetParameters, "None", py::arg("First"), py::arg("Pdeb"), py::arg("Pfin"));
	cls_ChFiDS_Stripe.def("Curve", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean) const ) &ChFiDS_Stripe::Curve, "None", py::arg("First"));
	cls_ChFiDS_Stripe.def("SetCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Stripe::SetCurve, "None", py::arg("Index"), py::arg("First"));
	cls_ChFiDS_Stripe.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)(const Standard_Boolean) const ) &ChFiDS_Stripe::PCurve, "None", py::arg("First"));
	cls_ChFiDS_Stripe.def("ChangePCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)(const Standard_Boolean)) &ChFiDS_Stripe::ChangePCurve, "None", py::arg("First"));
	cls_ChFiDS_Stripe.def("Orientation", (TopAbs_Orientation (ChFiDS_Stripe::*)(const Standard_Integer) const ) &ChFiDS_Stripe::Orientation, "None", py::arg("OnS"));
	cls_ChFiDS_Stripe.def("SetOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation, const Standard_Integer)) &ChFiDS_Stripe::SetOrientation, "None", py::arg("Or"), py::arg("OnS"));
	cls_ChFiDS_Stripe.def("Orientation", (TopAbs_Orientation (ChFiDS_Stripe::*)(const Standard_Boolean) const ) &ChFiDS_Stripe::Orientation, "None", py::arg("First"));
	cls_ChFiDS_Stripe.def("SetOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation, const Standard_Boolean)) &ChFiDS_Stripe::SetOrientation, "None", py::arg("Or"), py::arg("First"));
	cls_ChFiDS_Stripe.def("IndexPoint", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Integer) const ) &ChFiDS_Stripe::IndexPoint, "None", py::arg("First"), py::arg("OnS"));
	cls_ChFiDS_Stripe.def("SetIndexPoint", (void (ChFiDS_Stripe::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &ChFiDS_Stripe::SetIndexPoint, "None", py::arg("Index"), py::arg("First"), py::arg("OnS"));
	cls_ChFiDS_Stripe.def("SolidIndex", (Standard_Integer (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::SolidIndex, "None");
	cls_ChFiDS_Stripe.def("SetSolidIndex", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::SetSolidIndex, "None", py::arg("Index"));
	cls_ChFiDS_Stripe.def("InDS", [](ChFiDS_Stripe &self, const Standard_Boolean a0) -> void { return self.InDS(a0); }, py::arg("First"));
	cls_ChFiDS_Stripe.def("InDS", (void (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Integer)) &ChFiDS_Stripe::InDS, "Set nb of SurfData's at end put in DS", py::arg("First"), py::arg("Nb"));
	cls_ChFiDS_Stripe.def("IsInDS", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean) const ) &ChFiDS_Stripe::IsInDS, "Returns nb of SurfData's at end being in DS", py::arg("First"));
	cls_ChFiDS_Stripe.def_static("get_type_name_", (const char * (*)()) &ChFiDS_Stripe::get_type_name, "None");
	cls_ChFiDS_Stripe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_Stripe::get_type_descriptor, "None");
	cls_ChFiDS_Stripe.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_Stripe::*)() const ) &ChFiDS_Stripe::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_StripeMap.hxx
	py::class_<ChFiDS_StripeMap, std::unique_ptr<ChFiDS_StripeMap, Deleter<ChFiDS_StripeMap>>> cls_ChFiDS_StripeMap(mod, "ChFiDS_StripeMap", "encapsulation of IndexedDataMapOfVertexListOfStripe");
	cls_ChFiDS_StripeMap.def(py::init<>());
	cls_ChFiDS_StripeMap.def("Add", (void (ChFiDS_StripeMap::*)(const TopoDS_Vertex &, const opencascade::handle<ChFiDS_Stripe> &)) &ChFiDS_StripeMap::Add, "None", py::arg("V"), py::arg("F"));
	cls_ChFiDS_StripeMap.def("Extent", (Standard_Integer (ChFiDS_StripeMap::*)() const ) &ChFiDS_StripeMap::Extent, "None");
	cls_ChFiDS_StripeMap.def("FindFromKey", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const TopoDS_Vertex &) const ) &ChFiDS_StripeMap::FindFromKey, "None", py::arg("V"));
	cls_ChFiDS_StripeMap.def("__call__", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const TopoDS_Vertex &) const ) &ChFiDS_StripeMap::operator(), py::is_operator(), "None", py::arg("V"));
	cls_ChFiDS_StripeMap.def("FindFromIndex", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const Standard_Integer) const ) &ChFiDS_StripeMap::FindFromIndex, "None", py::arg("I"));
	cls_ChFiDS_StripeMap.def("__call__", (const ChFiDS_ListOfStripe & (ChFiDS_StripeMap::*)(const Standard_Integer) const ) &ChFiDS_StripeMap::operator(), py::is_operator(), "None", py::arg("I"));
	cls_ChFiDS_StripeMap.def("FindKey", (const TopoDS_Vertex & (ChFiDS_StripeMap::*)(const Standard_Integer) const ) &ChFiDS_StripeMap::FindKey, "None", py::arg("I"));
	cls_ChFiDS_StripeMap.def("Clear", (void (ChFiDS_StripeMap::*)()) &ChFiDS_StripeMap::Clear, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Regul.hxx
	py::class_<ChFiDS_Regul, std::unique_ptr<ChFiDS_Regul, Deleter<ChFiDS_Regul>>> cls_ChFiDS_Regul(mod, "ChFiDS_Regul", "Storage of a curve and its 2 faces or surfaces of support.");
	cls_ChFiDS_Regul.def(py::init<>());
	cls_ChFiDS_Regul.def("SetCurve", (void (ChFiDS_Regul::*)(const Standard_Integer)) &ChFiDS_Regul::SetCurve, "None", py::arg("IC"));
	cls_ChFiDS_Regul.def("SetS1", [](ChFiDS_Regul &self, const Standard_Integer a0) -> void { return self.SetS1(a0); }, py::arg("IS1"));
	cls_ChFiDS_Regul.def("SetS1", (void (ChFiDS_Regul::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Regul::SetS1, "None", py::arg("IS1"), py::arg("IsFace"));
	cls_ChFiDS_Regul.def("SetS2", [](ChFiDS_Regul &self, const Standard_Integer a0) -> void { return self.SetS2(a0); }, py::arg("IS2"));
	cls_ChFiDS_Regul.def("SetS2", (void (ChFiDS_Regul::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Regul::SetS2, "None", py::arg("IS2"), py::arg("IsFace"));
	cls_ChFiDS_Regul.def("IsSurface1", (Standard_Boolean (ChFiDS_Regul::*)() const ) &ChFiDS_Regul::IsSurface1, "None");
	cls_ChFiDS_Regul.def("IsSurface2", (Standard_Boolean (ChFiDS_Regul::*)() const ) &ChFiDS_Regul::IsSurface2, "None");
	cls_ChFiDS_Regul.def("Curve", (Standard_Integer (ChFiDS_Regul::*)() const ) &ChFiDS_Regul::Curve, "None");
	cls_ChFiDS_Regul.def("S1", (Standard_Integer (ChFiDS_Regul::*)() const ) &ChFiDS_Regul::S1, "None");
	cls_ChFiDS_Regul.def("S2", (Standard_Integer (ChFiDS_Regul::*)() const ) &ChFiDS_Regul::S2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ElSpine.hxx
	py::class_<ChFiDS_ElSpine, std::unique_ptr<ChFiDS_ElSpine, Deleter<ChFiDS_ElSpine>>, Adaptor3d_Curve> cls_ChFiDS_ElSpine(mod, "ChFiDS_ElSpine", "Elementary Spine for cheminements and approximations.");
	cls_ChFiDS_ElSpine.def(py::init<>());
	cls_ChFiDS_ElSpine.def("FirstParameter", (Standard_Real (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::FirstParameter, "None");
	cls_ChFiDS_ElSpine.def("LastParameter", (Standard_Real (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::LastParameter, "None");
	cls_ChFiDS_ElSpine.def("GetSavedFirstParameter", (Standard_Real (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::GetSavedFirstParameter, "None");
	cls_ChFiDS_ElSpine.def("GetSavedLastParameter", (Standard_Real (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::GetSavedLastParameter, "None");
	cls_ChFiDS_ElSpine.def("Continuity", (GeomAbs_Shape (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Continuity, "None");
	cls_ChFiDS_ElSpine.def("NbIntervals", (Standard_Integer (ChFiDS_ElSpine::*)(const GeomAbs_Shape) const ) &ChFiDS_ElSpine::NbIntervals, "None", py::arg("S"));
	cls_ChFiDS_ElSpine.def("Intervals", (void (ChFiDS_ElSpine::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &ChFiDS_ElSpine::Intervals, "None", py::arg("T"), py::arg("S"));
	cls_ChFiDS_ElSpine.def("Trim", (opencascade::handle<Adaptor3d_HCurve> (ChFiDS_ElSpine::*)(const Standard_Real, const Standard_Real, const Standard_Real) const ) &ChFiDS_ElSpine::Trim, "Returns a curve equivalent of <me> between parameters <First> and <Last>. <Tol> is used to test for 3d points confusion.", py::arg("First"), py::arg("Last"), py::arg("Tol"));
	cls_ChFiDS_ElSpine.def("Resolution", (Standard_Real (ChFiDS_ElSpine::*)(const Standard_Real) const ) &ChFiDS_ElSpine::Resolution, "None", py::arg("R3d"));
	cls_ChFiDS_ElSpine.def("GetType", (GeomAbs_CurveType (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::GetType, "None");
	cls_ChFiDS_ElSpine.def("IsPeriodic", (Standard_Boolean (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::IsPeriodic, "None");
	cls_ChFiDS_ElSpine.def("SetPeriodic", (void (ChFiDS_ElSpine::*)(const Standard_Boolean)) &ChFiDS_ElSpine::SetPeriodic, "None", py::arg("I"));
	cls_ChFiDS_ElSpine.def("Period", (Standard_Real (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Period, "None");
	cls_ChFiDS_ElSpine.def("Value", (gp_Pnt (ChFiDS_ElSpine::*)(const Standard_Real) const ) &ChFiDS_ElSpine::Value, "None", py::arg("AbsC"));
	cls_ChFiDS_ElSpine.def("D0", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &) const ) &ChFiDS_ElSpine::D0, "None", py::arg("AbsC"), py::arg("P"));
	cls_ChFiDS_ElSpine.def("D1", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const ) &ChFiDS_ElSpine::D1, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"));
	cls_ChFiDS_ElSpine.def("D2", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const ) &ChFiDS_ElSpine::D2, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"));
	cls_ChFiDS_ElSpine.def("D3", (void (ChFiDS_ElSpine::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &ChFiDS_ElSpine::D3, "None", py::arg("AbsC"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
	cls_ChFiDS_ElSpine.def("FirstParameter", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::FirstParameter, "None", py::arg("P"));
	cls_ChFiDS_ElSpine.def("LastParameter", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::LastParameter, "None", py::arg("P"));
	cls_ChFiDS_ElSpine.def("SaveFirstParameter", (void (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::SaveFirstParameter, "None");
	cls_ChFiDS_ElSpine.def("SaveLastParameter", (void (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::SaveLastParameter, "None");
	cls_ChFiDS_ElSpine.def("SetOrigin", (void (ChFiDS_ElSpine::*)(const Standard_Real)) &ChFiDS_ElSpine::SetOrigin, "None", py::arg("O"));
	cls_ChFiDS_ElSpine.def("FirstPointAndTgt", (void (ChFiDS_ElSpine::*)(gp_Pnt &, gp_Vec &) const ) &ChFiDS_ElSpine::FirstPointAndTgt, "None", py::arg("P"), py::arg("T"));
	cls_ChFiDS_ElSpine.def("LastPointAndTgt", (void (ChFiDS_ElSpine::*)(gp_Pnt &, gp_Vec &) const ) &ChFiDS_ElSpine::LastPointAndTgt, "None", py::arg("P"), py::arg("T"));
	cls_ChFiDS_ElSpine.def("NbVertices", (Standard_Integer (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::NbVertices, "None");
	cls_ChFiDS_ElSpine.def("VertexWithTangent", (const gp_Ax1 & (ChFiDS_ElSpine::*)(const Standard_Integer) const ) &ChFiDS_ElSpine::VertexWithTangent, "None", py::arg("Index"));
	cls_ChFiDS_ElSpine.def("SetFirstPointAndTgt", (void (ChFiDS_ElSpine::*)(const gp_Pnt &, const gp_Vec &)) &ChFiDS_ElSpine::SetFirstPointAndTgt, "None", py::arg("P"), py::arg("T"));
	cls_ChFiDS_ElSpine.def("SetLastPointAndTgt", (void (ChFiDS_ElSpine::*)(const gp_Pnt &, const gp_Vec &)) &ChFiDS_ElSpine::SetLastPointAndTgt, "None", py::arg("P"), py::arg("T"));
	cls_ChFiDS_ElSpine.def("AddVertexWithTangent", (void (ChFiDS_ElSpine::*)(const gp_Ax1 &)) &ChFiDS_ElSpine::AddVertexWithTangent, "None", py::arg("anAx1"));
	cls_ChFiDS_ElSpine.def("SetCurve", (void (ChFiDS_ElSpine::*)(const opencascade::handle<Geom_Curve> &)) &ChFiDS_ElSpine::SetCurve, "None", py::arg("C"));
	cls_ChFiDS_ElSpine.def("Previous", (const opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Previous, "None");
	cls_ChFiDS_ElSpine.def("ChangePrevious", (opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::ChangePrevious, "None");
	cls_ChFiDS_ElSpine.def("Next", (const opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Next, "None");
	cls_ChFiDS_ElSpine.def("ChangeNext", (opencascade::handle<ChFiDS_SurfData> & (ChFiDS_ElSpine::*)()) &ChFiDS_ElSpine::ChangeNext, "None");
	cls_ChFiDS_ElSpine.def("Line", (gp_Lin (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Line, "None");
	cls_ChFiDS_ElSpine.def("Circle", (gp_Circ (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Circle, "None");
	cls_ChFiDS_ElSpine.def("Ellipse", (gp_Elips (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Ellipse, "None");
	cls_ChFiDS_ElSpine.def("Hyperbola", (gp_Hypr (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Hyperbola, "None");
	cls_ChFiDS_ElSpine.def("Parabola", (gp_Parab (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Parabola, "None");
	cls_ChFiDS_ElSpine.def("Bezier", (opencascade::handle<Geom_BezierCurve> (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::Bezier, "None");
	cls_ChFiDS_ElSpine.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ChFiDS_ElSpine::*)() const ) &ChFiDS_ElSpine::BSpline, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ChamfSpine.hxx
	py::class_<ChFiDS_ChamfSpine, opencascade::handle<ChFiDS_ChamfSpine>, ChFiDS_Spine> cls_ChFiDS_ChamfSpine(mod, "ChFiDS_ChamfSpine", "Provides data specific to chamfers distances on each of faces.");
	cls_ChFiDS_ChamfSpine.def(py::init<>());
	cls_ChFiDS_ChamfSpine.def(py::init<const Standard_Real>(), py::arg("Tol"));
	cls_ChFiDS_ChamfSpine.def("SetDist", (void (ChFiDS_ChamfSpine::*)(const Standard_Real)) &ChFiDS_ChamfSpine::SetDist, "None", py::arg("Dis"));
	cls_ChFiDS_ChamfSpine.def("GetDist", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis){ self.GetDist(Dis); return Dis; }, "None", py::arg("Dis"));
	cls_ChFiDS_ChamfSpine.def("SetDists", (void (ChFiDS_ChamfSpine::*)(const Standard_Real, const Standard_Real)) &ChFiDS_ChamfSpine::SetDists, "None", py::arg("Dis1"), py::arg("Dis2"));
	cls_ChFiDS_ChamfSpine.def("Dists", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis1, Standard_Real & Dis2){ self.Dists(Dis1, Dis2); return std::tuple<Standard_Real &, Standard_Real &>(Dis1, Dis2); }, "None", py::arg("Dis1"), py::arg("Dis2"));
	cls_ChFiDS_ChamfSpine.def("GetDistAngle", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis, Standard_Real & Angle, Standard_Boolean & DisOnF1){ self.GetDistAngle(Dis, Angle, DisOnF1); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(Dis, Angle, DisOnF1); }, "None", py::arg("Dis"), py::arg("Angle"), py::arg("DisOnF1"));
	cls_ChFiDS_ChamfSpine.def("SetDistAngle", (void (ChFiDS_ChamfSpine::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFiDS_ChamfSpine::SetDistAngle, "None", py::arg("Dis"), py::arg("Angle"), py::arg("DisOnF1"));
	cls_ChFiDS_ChamfSpine.def("IsChamfer", (ChFiDS_ChamfMethod (ChFiDS_ChamfSpine::*)() const ) &ChFiDS_ChamfSpine::IsChamfer, "Return the method of chamfers used");
	cls_ChFiDS_ChamfSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_ChamfSpine::get_type_name, "None");
	cls_ChFiDS_ChamfSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_ChamfSpine::get_type_descriptor, "None");
	cls_ChFiDS_ChamfSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_ChamfSpine::*)() const ) &ChFiDS_ChamfSpine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_FilSpine.hxx
	py::class_<ChFiDS_FilSpine, opencascade::handle<ChFiDS_FilSpine>, ChFiDS_Spine> cls_ChFiDS_FilSpine(mod, "ChFiDS_FilSpine", "Provides data specific to the fillets - vector or rule of evolution (C2).");
	cls_ChFiDS_FilSpine.def(py::init<>());
	cls_ChFiDS_FilSpine.def(py::init<const Standard_Real>(), py::arg("Tol"));
	cls_ChFiDS_FilSpine.def("Reset", [](ChFiDS_FilSpine &self) -> void { return self.Reset(); });
	cls_ChFiDS_FilSpine.def("Reset", (void (ChFiDS_FilSpine::*)(const Standard_Boolean)) &ChFiDS_FilSpine::Reset, "None", py::arg("AllData"));
	cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real, const TopoDS_Edge &)) &ChFiDS_FilSpine::SetRadius, "initializes the constant vector on edge E.", py::arg("Radius"), py::arg("E"));
	cls_ChFiDS_FilSpine.def("UnSetRadius", (void (ChFiDS_FilSpine::*)(const TopoDS_Edge &)) &ChFiDS_FilSpine::UnSetRadius, "resets the constant vector on edge E.", py::arg("E"));
	cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real, const TopoDS_Vertex &)) &ChFiDS_FilSpine::SetRadius, "initializes the vector on Vertex V.", py::arg("Radius"), py::arg("V"));
	cls_ChFiDS_FilSpine.def("UnSetRadius", (void (ChFiDS_FilSpine::*)(const TopoDS_Vertex &)) &ChFiDS_FilSpine::UnSetRadius, "resets the vector on Vertex V.", py::arg("V"));
	cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const gp_XY &, const Standard_Integer)) &ChFiDS_FilSpine::SetRadius, "initializes the vector on the point of parameter W.", py::arg("UandR"), py::arg("IinC"));
	cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real)) &ChFiDS_FilSpine::SetRadius, "initializes the constant vector on all spine.", py::arg("Radius"));
	cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const opencascade::handle<Law_Function> &, const Standard_Integer)) &ChFiDS_FilSpine::SetRadius, "initializes the rule of evolution on all spine.", py::arg("C"), py::arg("IinC"));
	cls_ChFiDS_FilSpine.def("IsConstant", (Standard_Boolean (ChFiDS_FilSpine::*)() const ) &ChFiDS_FilSpine::IsConstant, "returns true if the radius is constant all along the spine.");
	cls_ChFiDS_FilSpine.def("IsConstant", (Standard_Boolean (ChFiDS_FilSpine::*)(const Standard_Integer) const ) &ChFiDS_FilSpine::IsConstant, "returns true if the radius is constant all along the edge E.", py::arg("IE"));
	cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)() const ) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the spine.");
	cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)(const Standard_Integer) const ) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the edge E.", py::arg("IE"));
	cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)(const TopoDS_Edge &) const ) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the edge E.", py::arg("E"));
	cls_ChFiDS_FilSpine.def("AppendElSpine", (void (ChFiDS_FilSpine::*)(const opencascade::handle<ChFiDS_HElSpine> &)) &ChFiDS_FilSpine::AppendElSpine, "None", py::arg("Els"));
	cls_ChFiDS_FilSpine.def("Law", (opencascade::handle<Law_Composite> (ChFiDS_FilSpine::*)(const opencascade::handle<ChFiDS_HElSpine> &) const ) &ChFiDS_FilSpine::Law, "None", py::arg("Els"));
	cls_ChFiDS_FilSpine.def("ChangeLaw", (opencascade::handle<Law_Function> & (ChFiDS_FilSpine::*)(const TopoDS_Edge &)) &ChFiDS_FilSpine::ChangeLaw, "returns the elementary law", py::arg("E"));
	cls_ChFiDS_FilSpine.def("MaxRadFromSeqAndLaws", (Standard_Real (ChFiDS_FilSpine::*)() const ) &ChFiDS_FilSpine::MaxRadFromSeqAndLaws, "returns the maximum radius if the fillet is non-constant");
	cls_ChFiDS_FilSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_FilSpine::get_type_name, "None");
	cls_ChFiDS_FilSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_FilSpine::get_type_descriptor, "None");
	cls_ChFiDS_FilSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_FilSpine::*)() const ) &ChFiDS_FilSpine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_SecHArray1.hxx
	py::class_<ChFiDS_SecHArray1, opencascade::handle<ChFiDS_SecHArray1>, ChFiDS_SecArray1, Standard_Transient> cls_ChFiDS_SecHArray1(mod, "ChFiDS_SecHArray1", "None");
	cls_ChFiDS_SecHArray1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_ChFiDS_SecHArray1.def(py::init<const Standard_Integer, const Standard_Integer, const ChFiDS_SecArray1::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_ChFiDS_SecHArray1.def(py::init<const ChFiDS_SecArray1 &>(), py::arg("theOther"));
	cls_ChFiDS_SecHArray1.def("Array1", (const ChFiDS_SecArray1 & (ChFiDS_SecHArray1::*)() const ) &ChFiDS_SecHArray1::Array1, "None");
	cls_ChFiDS_SecHArray1.def("ChangeArray1", (ChFiDS_SecArray1 & (ChFiDS_SecHArray1::*)()) &ChFiDS_SecHArray1::ChangeArray1, "None");
	cls_ChFiDS_SecHArray1.def_static("get_type_name_", (const char * (*)()) &ChFiDS_SecHArray1::get_type_name, "None");
	cls_ChFiDS_SecHArray1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_SecHArray1::get_type_descriptor, "None");
	cls_ChFiDS_SecHArray1.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_SecHArray1::*)() const ) &ChFiDS_SecHArray1::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_HData.hxx
	py::class_<ChFiDS_HData, opencascade::handle<ChFiDS_HData>, ChFiDS_SequenceOfSurfData, Standard_Transient> cls_ChFiDS_HData(mod, "ChFiDS_HData", "None");
	cls_ChFiDS_HData.def(py::init<>());
	cls_ChFiDS_HData.def(py::init<const ChFiDS_SequenceOfSurfData &>(), py::arg("theOther"));
	cls_ChFiDS_HData.def("Sequence", (const ChFiDS_SequenceOfSurfData & (ChFiDS_HData::*)() const ) &ChFiDS_HData::Sequence, "None");
	cls_ChFiDS_HData.def("Append", (void (ChFiDS_HData::*)(const ChFiDS_SequenceOfSurfData::value_type &)) &ChFiDS_HData::Append, "None", py::arg("theItem"));
	cls_ChFiDS_HData.def("Append", (void (ChFiDS_HData::*)(ChFiDS_SequenceOfSurfData &)) &ChFiDS_HData::Append, "None", py::arg("theSequence"));
	cls_ChFiDS_HData.def("ChangeSequence", (ChFiDS_SequenceOfSurfData & (ChFiDS_HData::*)()) &ChFiDS_HData::ChangeSequence, "None");
	cls_ChFiDS_HData.def_static("get_type_name_", (const char * (*)()) &ChFiDS_HData::get_type_name, "None");
	cls_ChFiDS_HData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_HData::get_type_descriptor, "None");
	cls_ChFiDS_HData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_HData::*)() const ) &ChFiDS_HData::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ListOfStripe.hxx
	bind_NCollection_List<opencascade::handle<ChFiDS_Stripe> >(mod, "ChFiDS_ListOfStripe");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ListOfStripe.hxx
	bind_NCollection_TListIterator<opencascade::handle<ChFiDS_Stripe> >(mod, "ChFiDS_ListIteratorOfListOfStripe");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_IndexedDataMapOfVertexListOfStripe.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Vertex, NCollection_List<opencascade::handle<ChFiDS_Stripe> >, TopTools_ShapeMapHasher>(mod, "ChFiDS_IndexedDataMapOfVertexListOfStripe");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Regularities.hxx
	bind_NCollection_List<ChFiDS_Regul>(mod, "ChFiDS_Regularities");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_Regularities.hxx
	bind_NCollection_TListIterator<ChFiDS_Regul>(mod, "ChFiDS_ListIteratorOfRegularities");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ListOfHElSpine.hxx
	bind_NCollection_List<opencascade::handle<ChFiDS_HElSpine> >(mod, "ChFiDS_ListOfHElSpine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_ListOfHElSpine.hxx
	bind_NCollection_TListIterator<opencascade::handle<ChFiDS_HElSpine> >(mod, "ChFiDS_ListIteratorOfListOfHElSpine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_SequenceOfSpine.hxx
	bind_NCollection_Sequence<opencascade::handle<ChFiDS_Spine> >(mod, "ChFiDS_SequenceOfSpine");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiDS_StripeArray1.hxx
	bind_NCollection_Array1<opencascade::handle<ChFiDS_Stripe> >(mod, "ChFiDS_StripeArray1");


}
