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
#include <IMeshData_Curve.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IncAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Std.hxx>
#include <BRepMeshData_Curve.hxx>
#include <Standard_Type.hxx>
#include <IMeshData_Types.hxx>
#include <IMeshData_Edge.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepMeshData_Edge.hxx>
#include <IMeshData_Face.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <BRepMeshData_Face.hxx>
#include <IMeshData_Model.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepMeshData_Model.hxx>
#include <IMeshData_PCurve.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepMeshData_PCurve.hxx>
#include <IMeshData_Wire.hxx>
#include <BRepMeshData_Wire.hxx>

PYBIND11_MODULE(BRepMeshData, mod) {

py::module::import("OCCT.IMeshData");
py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");

// CLASS: BREPMESHDATA_CURVE
py::class_<BRepMeshData_Curve, opencascade::handle<BRepMeshData_Curve>, IMeshData_Curve> cls_BRepMeshData_Curve(mod, "BRepMeshData_Curve", "Default implementation of curve data model entity.");

// Constructors
// cls_BRepMeshData_Curve.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));

// Methods
// cls_BRepMeshData_Curve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Curve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_BRepMeshData_Curve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Curve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
// cls_BRepMeshData_Curve.def_static("operator delete_", (void (*)(void *)) &BRepMeshData_Curve::operator delete, "None", py::arg(""));
cls_BRepMeshData_Curve.def("InsertPoint", (void (BRepMeshData_Curve::*)(const Standard_Integer, const gp_Pnt &, const Standard_Real)) &BRepMeshData_Curve::InsertPoint, "Inserts new discretization point at the given position.", py::arg("thePosition"), py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_BRepMeshData_Curve.def("AddPoint", (void (BRepMeshData_Curve::*)(const gp_Pnt &, const Standard_Real)) &BRepMeshData_Curve::AddPoint, "Adds new discretization point to pcurve.", py::arg("thePoint"), py::arg("theParamOnCurve"));
cls_BRepMeshData_Curve.def("GetPoint", (gp_Pnt & (BRepMeshData_Curve::*)(const Standard_Integer)) &BRepMeshData_Curve::GetPoint, "Returns discretization point with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Curve.def("RemovePoint", (void (BRepMeshData_Curve::*)(const Standard_Integer)) &BRepMeshData_Curve::RemovePoint, "Removes point with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Curve.def("GetParameter", (Standard_Real & (BRepMeshData_Curve::*)(const Standard_Integer)) &BRepMeshData_Curve::GetParameter, "Returns parameter with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Curve.def("ParametersNb", (Standard_Integer (BRepMeshData_Curve::*)() const) &BRepMeshData_Curve::ParametersNb, "Returns number of parameters stored in curve.");
cls_BRepMeshData_Curve.def("Clear", (void (BRepMeshData_Curve::*)(const Standard_Boolean)) &BRepMeshData_Curve::Clear, "Clears parameters list.", py::arg("isKeepEndPoints"));
cls_BRepMeshData_Curve.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_Curve::get_type_name, "None");
cls_BRepMeshData_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_Curve::get_type_descriptor, "None");
cls_BRepMeshData_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_Curve::*)() const) &BRepMeshData_Curve::DynamicType, "None");

// CLASS: BREPMESHDATA_EDGE
py::class_<BRepMeshData_Edge, opencascade::handle<BRepMeshData_Edge>, IMeshData_Edge> cls_BRepMeshData_Edge(mod, "BRepMeshData_Edge", "Default implementation of edge data model entity.");

// Constructors
// cls_BRepMeshData_Edge.def(py::init<const TopoDS_Edge &, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theEdge"), py::arg("theAllocator"));

// Methods
// cls_BRepMeshData_Edge.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Edge::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_BRepMeshData_Edge.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Edge::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
// cls_BRepMeshData_Edge.def_static("operator delete_", (void (*)(void *)) &BRepMeshData_Edge::operator delete, "None", py::arg(""));
cls_BRepMeshData_Edge.def("PCurvesNb", (Standard_Integer (BRepMeshData_Edge::*)() const) &BRepMeshData_Edge::PCurvesNb, "Returns number of pcurves assigned to current edge.");
cls_BRepMeshData_Edge.def("AddPCurve", (const IMeshData::IPCurveHandle & (BRepMeshData_Edge::*)(const IMeshData::IFacePtr &, const TopAbs_Orientation)) &BRepMeshData_Edge::AddPCurve, "Adds disrete pcurve for the specifed discrete face.", py::arg("theDFace"), py::arg("theOrientation"));
cls_BRepMeshData_Edge.def("GetPCurve", (const IMeshData::IPCurveHandle & (BRepMeshData_Edge::*)(const IMeshData::IFacePtr &, const TopAbs_Orientation) const) &BRepMeshData_Edge::GetPCurve, "Returns pcurve for the specified discrete face.", py::arg("theDFace"), py::arg("theOrientation"));
cls_BRepMeshData_Edge.def("GetPCurve", (const IMeshData::IPCurveHandle & (BRepMeshData_Edge::*)(const Standard_Integer) const) &BRepMeshData_Edge::GetPCurve, "Returns pcurve with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Edge.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_Edge::get_type_name, "None");
cls_BRepMeshData_Edge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_Edge::get_type_descriptor, "None");
cls_BRepMeshData_Edge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_Edge::*)() const) &BRepMeshData_Edge::DynamicType, "None");

// CLASS: BREPMESHDATA_FACE
py::class_<BRepMeshData_Face, opencascade::handle<BRepMeshData_Face>, IMeshData_Face> cls_BRepMeshData_Face(mod, "BRepMeshData_Face", "Default implementation of face data model entity.");

// Constructors
// cls_BRepMeshData_Face.def(py::init<const TopoDS_Face &, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theFace"), py::arg("theAllocator"));

// Methods
// cls_BRepMeshData_Face.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Face::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_BRepMeshData_Face.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Face::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
// cls_BRepMeshData_Face.def_static("operator delete_", (void (*)(void *)) &BRepMeshData_Face::operator delete, "None", py::arg(""));
cls_BRepMeshData_Face.def("WiresNb", (Standard_Integer (BRepMeshData_Face::*)() const) &BRepMeshData_Face::WiresNb, "Gets number of children.");
cls_BRepMeshData_Face.def("GetWire", (const IMeshData::IWireHandle & (BRepMeshData_Face::*)(const Standard_Integer) const) &BRepMeshData_Face::GetWire, "Gets wire with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Face.def("AddWire", [](BRepMeshData_Face &self, const TopoDS_Wire & a0) -> const IMeshData::IWireHandle & { return self.AddWire(a0); });
cls_BRepMeshData_Face.def("AddWire", (const IMeshData::IWireHandle & (BRepMeshData_Face::*)(const TopoDS_Wire &, const Standard_Integer)) &BRepMeshData_Face::AddWire, "Adds wire to discrete model of face.", py::arg("theWire"), py::arg("theEdgeNb"));
cls_BRepMeshData_Face.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_Face::get_type_name, "None");
cls_BRepMeshData_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_Face::get_type_descriptor, "None");
cls_BRepMeshData_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_Face::*)() const) &BRepMeshData_Face::DynamicType, "None");

// CLASS: BREPMESHDATA_MODEL
py::class_<BRepMeshData_Model, opencascade::handle<BRepMeshData_Model>, IMeshData_Model> cls_BRepMeshData_Model(mod, "BRepMeshData_Model", "Default implementation of model entity.");

// Constructors
cls_BRepMeshData_Model.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_BRepMeshData_Model.def("GetMaxSize", (Standard_Real (BRepMeshData_Model::*)() const) &BRepMeshData_Model::GetMaxSize, "Returns maximum size of shape's bounding box.");
cls_BRepMeshData_Model.def("SetMaxSize", (void (BRepMeshData_Model::*)(const Standard_Real)) &BRepMeshData_Model::SetMaxSize, "Sets maximum size of shape's bounding box.", py::arg("theValue"));
cls_BRepMeshData_Model.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_Model::get_type_name, "None");
cls_BRepMeshData_Model.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_Model::get_type_descriptor, "None");
cls_BRepMeshData_Model.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_Model::*)() const) &BRepMeshData_Model::DynamicType, "None");
cls_BRepMeshData_Model.def("FacesNb", (Standard_Integer (BRepMeshData_Model::*)() const) &BRepMeshData_Model::FacesNb, "Returns number of faces in discrete model.");
cls_BRepMeshData_Model.def("AddFace", (const IMeshData::IFaceHandle & (BRepMeshData_Model::*)(const TopoDS_Face &)) &BRepMeshData_Model::AddFace, "Adds new face to shape model.", py::arg("theFace"));
cls_BRepMeshData_Model.def("GetFace", (const IMeshData::IFaceHandle & (BRepMeshData_Model::*)(const Standard_Integer) const) &BRepMeshData_Model::GetFace, "Gets model's face with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Model.def("EdgesNb", (Standard_Integer (BRepMeshData_Model::*)() const) &BRepMeshData_Model::EdgesNb, "Returns number of edges in discrete model.");
cls_BRepMeshData_Model.def("AddEdge", (const IMeshData::IEdgeHandle & (BRepMeshData_Model::*)(const TopoDS_Edge &)) &BRepMeshData_Model::AddEdge, "Adds new edge to shape model.", py::arg("theEdge"));
cls_BRepMeshData_Model.def("GetEdge", (const IMeshData::IEdgeHandle & (BRepMeshData_Model::*)(const Standard_Integer) const) &BRepMeshData_Model::GetEdge, "Gets model's edge with the given index.", py::arg("theIndex"));

// CLASS: BREPMESHDATA_PCURVE
py::class_<BRepMeshData_PCurve, opencascade::handle<BRepMeshData_PCurve>, IMeshData_PCurve> cls_BRepMeshData_PCurve(mod, "BRepMeshData_PCurve", "Default implementation of pcurve data model entity.");

// Constructors
// cls_BRepMeshData_PCurve.def(py::init<const IMeshData::IFacePtr &, const TopAbs_Orientation, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theDFace"), py::arg("theOrientation"), py::arg("theAllocator"));

// Methods
// cls_BRepMeshData_PCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_PCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_BRepMeshData_PCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_PCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
// cls_BRepMeshData_PCurve.def_static("operator delete_", (void (*)(void *)) &BRepMeshData_PCurve::operator delete, "None", py::arg(""));
cls_BRepMeshData_PCurve.def("InsertPoint", (void (BRepMeshData_PCurve::*)(const Standard_Integer, const gp_Pnt2d &, const Standard_Real)) &BRepMeshData_PCurve::InsertPoint, "Inserts new discretization point at the given position.", py::arg("thePosition"), py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_BRepMeshData_PCurve.def("AddPoint", (void (BRepMeshData_PCurve::*)(const gp_Pnt2d &, const Standard_Real)) &BRepMeshData_PCurve::AddPoint, "Adds new discretization point to pcurve.", py::arg("thePoint"), py::arg("theParamOnPCurve"));
cls_BRepMeshData_PCurve.def("GetPoint", (gp_Pnt2d & (BRepMeshData_PCurve::*)(const Standard_Integer)) &BRepMeshData_PCurve::GetPoint, "Returns discretization point with the given index.", py::arg("theIndex"));
cls_BRepMeshData_PCurve.def("GetIndex", (Standard_Integer & (BRepMeshData_PCurve::*)(const Standard_Integer)) &BRepMeshData_PCurve::GetIndex, "Returns index in mesh corresponded to discretization point with the given index.", py::arg("theIndex"));
cls_BRepMeshData_PCurve.def("RemovePoint", (void (BRepMeshData_PCurve::*)(const Standard_Integer)) &BRepMeshData_PCurve::RemovePoint, "Removes point with the given index.", py::arg("theIndex"));
cls_BRepMeshData_PCurve.def("GetParameter", (Standard_Real & (BRepMeshData_PCurve::*)(const Standard_Integer)) &BRepMeshData_PCurve::GetParameter, "Returns parameter with the given index.", py::arg("theIndex"));
cls_BRepMeshData_PCurve.def("ParametersNb", (Standard_Integer (BRepMeshData_PCurve::*)() const) &BRepMeshData_PCurve::ParametersNb, "Returns number of parameters stored in pcurve.");
cls_BRepMeshData_PCurve.def("Clear", (void (BRepMeshData_PCurve::*)(const Standard_Boolean)) &BRepMeshData_PCurve::Clear, "Clears parameters list.", py::arg("isKeepEndPoints"));
cls_BRepMeshData_PCurve.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_PCurve::get_type_name, "None");
cls_BRepMeshData_PCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_PCurve::get_type_descriptor, "None");
cls_BRepMeshData_PCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_PCurve::*)() const) &BRepMeshData_PCurve::DynamicType, "None");

// CLASS: BREPMESHDATA_WIRE
py::class_<BRepMeshData_Wire, opencascade::handle<BRepMeshData_Wire>, IMeshData_Wire> cls_BRepMeshData_Wire(mod, "BRepMeshData_Wire", "Default implementation of wire data model entity.");

// Constructors
// cls_BRepMeshData_Wire.def(py::init<const TopoDS_Wire &, const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theWire"), py::arg("theEdgeNb"), py::arg("theAllocator"));

// Methods
// cls_BRepMeshData_Wire.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Wire::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_BRepMeshData_Wire.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &BRepMeshData_Wire::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
// cls_BRepMeshData_Wire.def_static("operator delete_", (void (*)(void *)) &BRepMeshData_Wire::operator delete, "None", py::arg(""));
cls_BRepMeshData_Wire.def("EdgesNb", (Standard_Integer (BRepMeshData_Wire::*)() const) &BRepMeshData_Wire::EdgesNb, "Gets number of children.");
cls_BRepMeshData_Wire.def("AddEdge", (Standard_Integer (BRepMeshData_Wire::*)(const IMeshData::IEdgePtr &, const TopAbs_Orientation)) &BRepMeshData_Wire::AddEdge, "Adds new discrete edge with specified orientation to wire chain.", py::arg("theDEdge"), py::arg("theOrientation"));
cls_BRepMeshData_Wire.def("GetEdge", (const IMeshData::IEdgePtr & (BRepMeshData_Wire::*)(const Standard_Integer) const) &BRepMeshData_Wire::GetEdge, "Gets edge with the given index.", py::arg("theIndex"));
cls_BRepMeshData_Wire.def("GetEdgeOrientation", (TopAbs_Orientation (BRepMeshData_Wire::*)(const Standard_Integer) const) &BRepMeshData_Wire::GetEdgeOrientation, "Returns True if orientation of discrete edge with the given index is forward.", py::arg("theIndex"));
cls_BRepMeshData_Wire.def_static("get_type_name_", (const char * (*)()) &BRepMeshData_Wire::get_type_name, "None");
cls_BRepMeshData_Wire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepMeshData_Wire::get_type_descriptor, "None");
cls_BRepMeshData_Wire.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepMeshData_Wire::*)() const) &BRepMeshData_Wire::DynamicType, "None");


}
