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
#include <IMeshData_Status.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <IMeshData_ParametersList.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <IMeshData_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <IMeshData_Shape.hxx>
#include <IMeshData_TessellatedShape.hxx>
#include <IMeshData_StatusOwner.hxx>
#include <IMeshData_Types.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS.hxx>
#include <IMeshData_Face.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <IMeshData_PCurve.hxx>
#include <TopoDS_Edge.hxx>
#include <IMeshData_Edge.hxx>
#include <BRep_Tool.hxx>
#include <IMeshData_Wire.hxx>
#include <IMeshData_Model.hxx>

PYBIND11_MODULE(IMeshData, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRep");

// ENUM: IMESHDATA_STATUS
py::enum_<IMeshData_Status>(mod, "IMeshData_Status", "Enumerates statuses used to notify state of discrete model.")
	.value("IMeshData_NoError", IMeshData_Status::IMeshData_NoError)
	.value("IMeshData_OpenWire", IMeshData_Status::IMeshData_OpenWire)
	.value("IMeshData_SelfIntersectingWire", IMeshData_Status::IMeshData_SelfIntersectingWire)
	.value("IMeshData_Failure", IMeshData_Status::IMeshData_Failure)
	.value("IMeshData_ReMesh", IMeshData_Status::IMeshData_ReMesh)
	.value("IMeshData_UnorientedWire", IMeshData_Status::IMeshData_UnorientedWire)
	.value("IMeshData_TooFewPoints", IMeshData_Status::IMeshData_TooFewPoints)
	.value("IMeshData_Outdated", IMeshData_Status::IMeshData_Outdated)
	.value("IMeshData_Reused", IMeshData_Status::IMeshData_Reused)
	.export_values();


// CLASS: IMESHDATA_PARAMETERSLIST
py::class_<IMeshData_ParametersList, opencascade::handle<IMeshData_ParametersList>, Standard_Transient> cls_IMeshData_ParametersList(mod, "IMeshData_ParametersList", "Interface class representing list of parameters on curve.");

// Methods
cls_IMeshData_ParametersList.def("GetParameter", (Standard_Real & (IMeshData_ParametersList::*)(const Standard_Integer)) &IMeshData_ParametersList::GetParameter, "Returns parameter with the given index.", py::arg("theIndex"));
cls_IMeshData_ParametersList.def("ParametersNb", (Standard_Integer (IMeshData_ParametersList::*)() const) &IMeshData_ParametersList::ParametersNb, "Returns number of parameters.");
cls_IMeshData_ParametersList.def("Clear", (void (IMeshData_ParametersList::*)(const Standard_Boolean)) &IMeshData_ParametersList::Clear, "Clears parameters list.", py::arg("isKeepEndPoints"));
cls_IMeshData_ParametersList.def_static("get_type_name_", (const char * (*)()) &IMeshData_ParametersList::get_type_name, "None");
cls_IMeshData_ParametersList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_ParametersList::get_type_descriptor, "None");
cls_IMeshData_ParametersList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_ParametersList::*)() const) &IMeshData_ParametersList::DynamicType, "None");

// CLASS: IMESHDATA_CURVE
py::class_<IMeshData_Curve, opencascade::handle<IMeshData_Curve>, IMeshData_ParametersList> cls_IMeshData_Curve(mod, "IMeshData_Curve", "Interface class representing discrete 3d curve of edge. Indexation of points starts from zero.");

// Methods
cls_IMeshData_Curve.def("InsertPoint", (void (IMeshData_Curve::*)(const Standard_Integer, const gp_Pnt &, const Standard_Real)) &IMeshData_Curve::InsertPoint, "Inserts new discretization point at the given position.", py::arg("thePosition"), py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_IMeshData_Curve.def("AddPoint", (void (IMeshData_Curve::*)(const gp_Pnt &, const Standard_Real)) &IMeshData_Curve::AddPoint, "Adds new discretization point to curve.", py::arg("thePoint"), py::arg("theParamOnCurve"));
cls_IMeshData_Curve.def("GetPoint", (gp_Pnt & (IMeshData_Curve::*)(const Standard_Integer)) &IMeshData_Curve::GetPoint, "Returns discretization point with the given index.", py::arg("theIndex"));
cls_IMeshData_Curve.def("RemovePoint", (void (IMeshData_Curve::*)(const Standard_Integer)) &IMeshData_Curve::RemovePoint, "Removes point with the given index.", py::arg("theIndex"));
cls_IMeshData_Curve.def_static("get_type_name_", (const char * (*)()) &IMeshData_Curve::get_type_name, "None");
cls_IMeshData_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Curve::get_type_descriptor, "None");
cls_IMeshData_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Curve::*)() const) &IMeshData_Curve::DynamicType, "None");

// CLASS: IMESHDATA_SHAPE
py::class_<IMeshData_Shape, opencascade::handle<IMeshData_Shape>, Standard_Transient> cls_IMeshData_Shape(mod, "IMeshData_Shape", "Interface class representing model with associated TopoDS_Shape. Intended for inheritance by structures and algorithms keeping reference TopoDS_Shape.");

// Methods
cls_IMeshData_Shape.def("SetShape", (void (IMeshData_Shape::*)(const TopoDS_Shape &)) &IMeshData_Shape::SetShape, "Assigns shape to discrete shape.", py::arg("theShape"));
cls_IMeshData_Shape.def("GetShape", (const TopoDS_Shape & (IMeshData_Shape::*)() const) &IMeshData_Shape::GetShape, "Returns shape assigned to discrete shape.");
cls_IMeshData_Shape.def_static("get_type_name_", (const char * (*)()) &IMeshData_Shape::get_type_name, "None");
cls_IMeshData_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Shape::get_type_descriptor, "None");
cls_IMeshData_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Shape::*)() const) &IMeshData_Shape::DynamicType, "None");

// CLASS: IMESHDATA_TESSELLATEDSHAPE
py::class_<IMeshData_TessellatedShape, opencascade::handle<IMeshData_TessellatedShape>, IMeshData_Shape> cls_IMeshData_TessellatedShape(mod, "IMeshData_TessellatedShape", "Interface class representing shaped model with deflection.");

// Methods
cls_IMeshData_TessellatedShape.def("GetDeflection", (Standard_Real (IMeshData_TessellatedShape::*)() const) &IMeshData_TessellatedShape::GetDeflection, "Gets deflection value for the discrete model.");
cls_IMeshData_TessellatedShape.def("SetDeflection", (void (IMeshData_TessellatedShape::*)(const Standard_Real)) &IMeshData_TessellatedShape::SetDeflection, "Sets deflection value for the discrete model.", py::arg("theValue"));
cls_IMeshData_TessellatedShape.def_static("get_type_name_", (const char * (*)()) &IMeshData_TessellatedShape::get_type_name, "None");
cls_IMeshData_TessellatedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_TessellatedShape::get_type_descriptor, "None");
cls_IMeshData_TessellatedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_TessellatedShape::*)() const) &IMeshData_TessellatedShape::DynamicType, "None");

// CLASS: IMESHDATA_STATUSOWNER
py::class_<IMeshData_StatusOwner> cls_IMeshData_StatusOwner(mod, "IMeshData_StatusOwner", "Extension interface class providing status functionality.");

// Methods
cls_IMeshData_StatusOwner.def("IsEqual", (Standard_Boolean (IMeshData_StatusOwner::*)(const IMeshData_Status) const) &IMeshData_StatusOwner::IsEqual, "Returns true in case if status is strictly equal to the given value.", py::arg("theValue"));
cls_IMeshData_StatusOwner.def("IsSet", (Standard_Boolean (IMeshData_StatusOwner::*)(const IMeshData_Status) const) &IMeshData_StatusOwner::IsSet, "Returns true in case if status is set.", py::arg("theValue"));
cls_IMeshData_StatusOwner.def("SetStatus", (void (IMeshData_StatusOwner::*)(const IMeshData_Status)) &IMeshData_StatusOwner::SetStatus, "Adds status to status flags of a face.", py::arg("theValue"));
cls_IMeshData_StatusOwner.def("UnsetStatus", (void (IMeshData_StatusOwner::*)(const IMeshData_Status)) &IMeshData_StatusOwner::UnsetStatus, "Adds status to status flags of a face.", py::arg("theValue"));
cls_IMeshData_StatusOwner.def("GetStatusMask", (Standard_Integer (IMeshData_StatusOwner::*)() const) &IMeshData_StatusOwner::GetStatusMask, "Returns complete status mask.");

// CLASS: IMESHDATA_FACE
py::class_<IMeshData_Face, opencascade::handle<IMeshData_Face>, IMeshData_TessellatedShape> cls_IMeshData_Face(mod, "IMeshData_Face", "Interface class representing discrete model of a face. Face model contains one or several wires. First wire is always outer one.", py::multiple_inheritance());

// Methods
cls_IMeshData_Face.def("WiresNb", (Standard_Integer (IMeshData_Face::*)() const) &IMeshData_Face::WiresNb, "Returns number of wires.");
cls_IMeshData_Face.def("AddWire", [](IMeshData_Face &self, const TopoDS_Wire & a0) -> const IMeshData::IWireHandle & { return self.AddWire(a0); });
cls_IMeshData_Face.def("AddWire", (const IMeshData::IWireHandle & (IMeshData_Face::*)(const TopoDS_Wire &, const Standard_Integer)) &IMeshData_Face::AddWire, "Adds wire to discrete model of face.", py::arg("theWire"), py::arg("theEdgeNb"));
cls_IMeshData_Face.def("GetWire", (const IMeshData::IWireHandle & (IMeshData_Face::*)(const Standard_Integer) const) &IMeshData_Face::GetWire, "Returns discrete edge with the given index.", py::arg("theIndex"));
cls_IMeshData_Face.def("GetSurface", (const opencascade::handle<BRepAdaptor_HSurface> & (IMeshData_Face::*)() const) &IMeshData_Face::GetSurface, "Returns face's surface.");
cls_IMeshData_Face.def("GetFace", (const TopoDS_Face & (IMeshData_Face::*)() const) &IMeshData_Face::GetFace, "Returns TopoDS_Face attached to model.");
cls_IMeshData_Face.def("IsValid", (Standard_Boolean (IMeshData_Face::*)() const) &IMeshData_Face::IsValid, "Returns whether the face discrete model is valid.");
cls_IMeshData_Face.def_static("get_type_name_", (const char * (*)()) &IMeshData_Face::get_type_name, "None");
cls_IMeshData_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Face::get_type_descriptor, "None");
cls_IMeshData_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Face::*)() const) &IMeshData_Face::DynamicType, "None");

// CLASS: IMESHDATA_PCURVE
py::class_<IMeshData_PCurve, opencascade::handle<IMeshData_PCurve>, IMeshData_ParametersList> cls_IMeshData_PCurve(mod, "IMeshData_PCurve", "Interface class representing pcurve of edge associated with discrete face. Indexation of points starts from zero.");

// Methods
cls_IMeshData_PCurve.def("InsertPoint", (void (IMeshData_PCurve::*)(const Standard_Integer, const gp_Pnt2d &, const Standard_Real)) &IMeshData_PCurve::InsertPoint, "Inserts new discretization point at the given position.", py::arg("thePosition"), py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_IMeshData_PCurve.def("AddPoint", (void (IMeshData_PCurve::*)(const gp_Pnt2d &, const Standard_Real)) &IMeshData_PCurve::AddPoint, "Adds new discretization point to pcurve.", py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_IMeshData_PCurve.def("GetPoint", (gp_Pnt2d & (IMeshData_PCurve::*)(const Standard_Integer)) &IMeshData_PCurve::GetPoint, "Returns discretization point with the given index.", py::arg("theIndex"));
cls_IMeshData_PCurve.def("GetIndex", (Standard_Integer & (IMeshData_PCurve::*)(const Standard_Integer)) &IMeshData_PCurve::GetIndex, "Returns index in mesh corresponded to discretization point with the given index.", py::arg("theIndex"));
cls_IMeshData_PCurve.def("RemovePoint", (void (IMeshData_PCurve::*)(const Standard_Integer)) &IMeshData_PCurve::RemovePoint, "Removes point with the given index.", py::arg("theIndex"));
cls_IMeshData_PCurve.def("IsForward", (Standard_Boolean (IMeshData_PCurve::*)() const) &IMeshData_PCurve::IsForward, "Returns forward flag of this pcurve.");
cls_IMeshData_PCurve.def("IsInternal", (Standard_Boolean (IMeshData_PCurve::*)() const) &IMeshData_PCurve::IsInternal, "Returns internal flag of this pcurve.");
cls_IMeshData_PCurve.def("GetOrientation", (TopAbs_Orientation (IMeshData_PCurve::*)() const) &IMeshData_PCurve::GetOrientation, "Returns orientation of the edge associated with current pcurve.");
cls_IMeshData_PCurve.def("GetFace", (const IMeshData::IFacePtr & (IMeshData_PCurve::*)() const) &IMeshData_PCurve::GetFace, "Returns discrete face pcurve is associated to.");
cls_IMeshData_PCurve.def_static("get_type_name_", (const char * (*)()) &IMeshData_PCurve::get_type_name, "None");
cls_IMeshData_PCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_PCurve::get_type_descriptor, "None");
cls_IMeshData_PCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_PCurve::*)() const) &IMeshData_PCurve::DynamicType, "None");

// CLASS: IMESHDATA_EDGE
py::class_<IMeshData_Edge, opencascade::handle<IMeshData_Edge>, IMeshData_TessellatedShape> cls_IMeshData_Edge(mod, "IMeshData_Edge", "Interface class representing discrete model of an edge.", py::multiple_inheritance());

// Methods
cls_IMeshData_Edge.def("GetEdge", (const TopoDS_Edge & (IMeshData_Edge::*)() const) &IMeshData_Edge::GetEdge, "Returns TopoDS_Edge attached to model.");
cls_IMeshData_Edge.def("PCurvesNb", (Standard_Integer (IMeshData_Edge::*)() const) &IMeshData_Edge::PCurvesNb, "Returns number of pcurves assigned to current edge.");
cls_IMeshData_Edge.def("AddPCurve", (const IMeshData::IPCurveHandle & (IMeshData_Edge::*)(const IMeshData::IFacePtr &, const TopAbs_Orientation)) &IMeshData_Edge::AddPCurve, "Adds discrete pcurve for the specifed discrete face.", py::arg("theDFace"), py::arg("theOrientation"));
cls_IMeshData_Edge.def("GetPCurve", (const IMeshData::IPCurveHandle & (IMeshData_Edge::*)(const IMeshData::IFacePtr &, const TopAbs_Orientation) const) &IMeshData_Edge::GetPCurve, "Returns pcurve for the specified discrete face.", py::arg("theDFace"), py::arg("theOrientation"));
cls_IMeshData_Edge.def("GetPCurve", (const IMeshData::IPCurveHandle & (IMeshData_Edge::*)(const Standard_Integer) const) &IMeshData_Edge::GetPCurve, "Returns pcurve with the given index.", py::arg("theIndex"));
cls_IMeshData_Edge.def("Clear", (void (IMeshData_Edge::*)(const Standard_Boolean)) &IMeshData_Edge::Clear, "Clears curve and all pcurves assigned to the edge from discretization.", py::arg("isKeepEndPoints"));
cls_IMeshData_Edge.def("IsFree", (Standard_Boolean (IMeshData_Edge::*)() const) &IMeshData_Edge::IsFree, "Returns true in case if the edge is free one, i.e. it does not have pcurves.");
cls_IMeshData_Edge.def("SetCurve", (void (IMeshData_Edge::*)(const IMeshData::ICurveHandle &)) &IMeshData_Edge::SetCurve, "Sets 3d curve associated with current edge.", py::arg("theCurve"));
cls_IMeshData_Edge.def("GetCurve", (const IMeshData::ICurveHandle & (IMeshData_Edge::*)() const) &IMeshData_Edge::GetCurve, "Returns 3d curve associated with current edge.");
cls_IMeshData_Edge.def("GetAngularDeflection", (Standard_Real (IMeshData_Edge::*)() const) &IMeshData_Edge::GetAngularDeflection, "Gets value of angular deflection for the discrete model.");
cls_IMeshData_Edge.def("SetAngularDeflection", (void (IMeshData_Edge::*)(const Standard_Real)) &IMeshData_Edge::SetAngularDeflection, "Sets value of angular deflection for the discrete model.", py::arg("theValue"));
cls_IMeshData_Edge.def("GetSameParam", (Standard_Boolean (IMeshData_Edge::*)() const) &IMeshData_Edge::GetSameParam, "Returns same param flag. By default equals to flag stored in topological shape.");
cls_IMeshData_Edge.def("SetSameParam", (void (IMeshData_Edge::*)(const Standard_Boolean)) &IMeshData_Edge::SetSameParam, "Updates same param flag.", py::arg("theValue"));
cls_IMeshData_Edge.def("GetSameRange", (Standard_Boolean (IMeshData_Edge::*)() const) &IMeshData_Edge::GetSameRange, "Returns same range flag. By default equals to flag stored in topological shape.");
cls_IMeshData_Edge.def("SetSameRange", (void (IMeshData_Edge::*)(const Standard_Boolean)) &IMeshData_Edge::SetSameRange, "Updates same range flag.", py::arg("theValue"));
cls_IMeshData_Edge.def("GetDegenerated", (Standard_Boolean (IMeshData_Edge::*)() const) &IMeshData_Edge::GetDegenerated, "Returns degenerative flag. By default equals to flag stored in topological shape.");
cls_IMeshData_Edge.def("SetDegenerated", (void (IMeshData_Edge::*)(const Standard_Boolean)) &IMeshData_Edge::SetDegenerated, "Updates degenerative flag.", py::arg("theValue"));
cls_IMeshData_Edge.def_static("get_type_name_", (const char * (*)()) &IMeshData_Edge::get_type_name, "None");
cls_IMeshData_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Edge::get_type_descriptor, "None");
cls_IMeshData_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Edge::*)() const) &IMeshData_Edge::DynamicType, "None");

// CLASS: IMESHDATA_WIRE
py::class_<IMeshData_Wire, opencascade::handle<IMeshData_Wire>, IMeshData_TessellatedShape> cls_IMeshData_Wire(mod, "IMeshData_Wire", "Interface class representing discrete model of a wire. Wire should represent an ordered set of edges.", py::multiple_inheritance());

// Methods
cls_IMeshData_Wire.def("GetWire", (const TopoDS_Wire & (IMeshData_Wire::*)() const) &IMeshData_Wire::GetWire, "Returns TopoDS_Face attached to model.");
cls_IMeshData_Wire.def("EdgesNb", (Standard_Integer (IMeshData_Wire::*)() const) &IMeshData_Wire::EdgesNb, "Returns number of edges.");
cls_IMeshData_Wire.def("AddEdge", (Standard_Integer (IMeshData_Wire::*)(const IMeshData::IEdgePtr &, const TopAbs_Orientation)) &IMeshData_Wire::AddEdge, "Adds new discrete edge with specified orientation to wire chain.", py::arg("theDEdge"), py::arg("theOrientation"));
cls_IMeshData_Wire.def("GetEdge", (const IMeshData::IEdgePtr & (IMeshData_Wire::*)(const Standard_Integer) const) &IMeshData_Wire::GetEdge, "Returns discrete edge with the given index.", py::arg("theIndex"));
cls_IMeshData_Wire.def("GetEdgeOrientation", (TopAbs_Orientation (IMeshData_Wire::*)(const Standard_Integer) const) &IMeshData_Wire::GetEdgeOrientation, "Returns True if orientation of discrete edge with the given index is forward.", py::arg("theIndex"));
cls_IMeshData_Wire.def_static("get_type_name_", (const char * (*)()) &IMeshData_Wire::get_type_name, "None");
cls_IMeshData_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Wire::get_type_descriptor, "None");
cls_IMeshData_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Wire::*)() const) &IMeshData_Wire::DynamicType, "None");

// CLASS: IMESHDATA_MODEL
py::class_<IMeshData_Model, opencascade::handle<IMeshData_Model>, IMeshData_Shape> cls_IMeshData_Model(mod, "IMeshData_Model", "Interface class representing discrete model of a shape.");

// Methods
cls_IMeshData_Model.def("GetMaxSize", (Standard_Real (IMeshData_Model::*)() const) &IMeshData_Model::GetMaxSize, "Returns maximum size of shape model.");
cls_IMeshData_Model.def_static("get_type_name_", (const char * (*)()) &IMeshData_Model::get_type_name, "None");
cls_IMeshData_Model.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IMeshData_Model::get_type_descriptor, "None");
cls_IMeshData_Model.def("DynamicType", (const opencascade::handle<Standard_Type> & (IMeshData_Model::*)() const) &IMeshData_Model::DynamicType, "None");
cls_IMeshData_Model.def("FacesNb", (Standard_Integer (IMeshData_Model::*)() const) &IMeshData_Model::FacesNb, "Returns number of faces in discrete model.");
cls_IMeshData_Model.def("AddFace", (const IMeshData::IFaceHandle & (IMeshData_Model::*)(const TopoDS_Face &)) &IMeshData_Model::AddFace, "Adds new face to shape model.", py::arg("theFace"));
cls_IMeshData_Model.def("GetFace", (const IMeshData::IFaceHandle & (IMeshData_Model::*)(const Standard_Integer) const) &IMeshData_Model::GetFace, "Gets model's face with the given index.", py::arg("theIndex"));
cls_IMeshData_Model.def("EdgesNb", (Standard_Integer (IMeshData_Model::*)() const) &IMeshData_Model::EdgesNb, "Returns number of edges in discrete model.");
cls_IMeshData_Model.def("AddEdge", (const IMeshData::IEdgeHandle & (IMeshData_Model::*)(const TopoDS_Edge &)) &IMeshData_Model::AddEdge, "Adds new edge to shape model.", py::arg("theEdge"));
cls_IMeshData_Model.def("GetEdge", (const IMeshData::IEdgeHandle & (IMeshData_Model::*)(const Standard_Integer) const) &IMeshData_Model::GetEdge, "Gets model's edge with the given index.", py::arg("theIndex"));


}
